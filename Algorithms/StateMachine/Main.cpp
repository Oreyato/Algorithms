#include <iostream>
#include "StateMachine.h"
#include "PlayableCharacter.h"
#include "Boss.h"

using namespace std;

//v Functions ====================================================
void updatePlayer();
void updateBoss(StateMachine& smP);
Action* pickBetween(vector<Action*> attacksP);

//^ Functions ====================================================
//v Variables ====================================================
float fInf = 10000.0f;
int iInf = 10000;
float epsilon = 0.000001f;

bool gameEnded = false;
float gap = 16.0f;
float token = 0.0f;

Weapon grandeHacheDouble{"Grande hache double", 67.f, 5.0f, 1.0f};
PlayableCharacter player{"Jean Jean", 625.0f, &grandeHacheDouble, &gap, &token};

Boss boss{ "Rydnir", 25.0f, &gap}; // <--- 4000.0f

// First phase ==========================
float interRange = 10.0f;
float midRange = 6.0f;
float closeRange = 4.0f;

// Second phase =========================
float secondPhaseTrigger = 3200.0f; // <--- 3200.0f

// Third phase ==========================
float thirdPhaseTrigger = 3400.0f; // <--- 800.0f

//^ Variables ====================================================

int main() {	
	
	//================================================================
	//v PLAYER INIT ==================================================
	//================================================================
	player.setTarget(&boss);
	boss.setTarget(&player);

	Weapon fleauEnAcier{ "Fleau en acier", 53.f, 3.f, 0.5f };
	Weapon arbaletePortative{ "Arbalete portative", 51.f, 14.f, 1.5f };

	player.addWeapon(&fleauEnAcier);
	player.addWeapon(&arbaletePortative);

	//================================================================
	//^ PLAYER INIT ==================================================
	//================================================================

	#pragma region First phase init
	// ===============================================================
	//v FIRST PHASE INIT =============================================
	// ===============================================================
	// Forward ==============================
	BossMovement forwardAction{ "forward", 2.0f, true, &gap, 1.5f, &token};

	vector<Action*> forwardActions;

	forwardActions.push_back(&forwardAction);
	// Mid range attacks ====================

	// name, damage, tokenCost, pickProb, missProb, player
	BossAttack griffes{ "laceration de griffes", 45.0f, 1.0f, 0.4f, 0.05f, &player };
	BossAttack ailes{ "coup d'ailes", 40.f, 2.0f, 0.3f, 0.05f, &player };
	BossAttack queue{ "balayage", 47.f, 2.5f, 0.3f, 0.1f, &player };

	vector<Action*> midRangeAttacksActions;

	midRangeAttacksActions.push_back(&griffes);
	midRangeAttacksActions.push_back(&ailes);
	midRangeAttacksActions.push_back(&queue);

	// Close range attacks ==================
	BossAttack morsure{ "morsure", 55.f, 1.5f, 0.2f, 0.2f, &player };
	BossAttack altGriffes = griffes;
	altGriffes.setPickProbability(0.3f);
	BossAttack altAiles = ailes;
	ailes.setPickProbability(0.25f);
	BossAttack altQueue = queue;
	altQueue.setPickProbability(0.25f);

	vector<Action*> closeRangeAttacksActions;
	closeRangeAttacksActions.push_back(&altGriffes);
	closeRangeAttacksActions.push_back(&altAiles);
	closeRangeAttacksActions.push_back(&altQueue);
	closeRangeAttacksActions.push_back(&morsure);

	// States and transitions init ==========
	vector<Transition*> forwardOutTransitions;
	vector<Transition*> midRangeAttacksOutTransitions;
	vector<Transition*> closeRangeAttacksOutTransitions;

	State forwardState{ &forwardActions,  &forwardOutTransitions };
	State midRangeState{ &midRangeAttacksActions, &midRangeAttacksOutTransitions };
	State closeRangeState{ &closeRangeAttacksActions, &closeRangeAttacksOutTransitions };

	//v Filling transitions ==========================================
	// Forward transitions ==================
	// Transition from forward to midRangeAttack 
	// Transition action
	Action seeEnemy{ boss.getName() + " is close to you" };

	// Transition condition
	FloatCondition midDistanceCdt{ closeRange + epsilon, midRange, &gap };

	Transition fromForwardToMidRangeAttack{ &midRangeState, &seeEnemy, &midDistanceCdt };
	forwardOutTransitions.push_back(&fromForwardToMidRangeAttack);
	// Transition from forward to closeRangeAttack 
	Action closeToEnemy{ boss.getName() + " is right next to you" };

	FloatCondition closeDistanceCdt{ 0.0f, closeRange, &gap };

	Transition fromForwardToCloseRangeAttack{ &closeRangeState, &closeToEnemy, &closeDistanceCdt };
	forwardOutTransitions.push_back(&fromForwardToCloseRangeAttack);
	
	// MidRange attack transitions ==========
	// Transition from midRangeAttack to forward 
	Action loosingEnemy{ boss.getName() + " can't reach you here" };

	FloatCondition farCdt{ midRange + epsilon, fInf, &gap };

	Transition fromMidRangeAttackToForward{ &forwardState, &loosingEnemy, &farCdt };
	midRangeAttacksOutTransitions.push_back(&fromMidRangeAttackToForward);
	
	// Transition from midRangeAttack to close range
	Transition fromMidRangeAttackToCloseRangeAttack{ &closeRangeState, &closeToEnemy, &closeDistanceCdt };
	midRangeAttacksOutTransitions.push_back(&fromMidRangeAttackToCloseRangeAttack);

	// Close range attack transitions =======
	// Transition from closeRangeAttack to midRangeAttack
	Action enemyStepOut{ boss.getName() + " is not right next to you anymore" };

	Transition fromCloseRangeAttackToMidRangeAttack{ &midRangeState, &enemyStepOut, &midDistanceCdt };
	closeRangeAttacksOutTransitions.push_back(&fromCloseRangeAttackToMidRangeAttack);

	// Transition from closeRangeAttack to forward
	Transition fromCloseRangeAttackToForward{ &forwardState, &loosingEnemy, &farCdt };
	closeRangeAttacksOutTransitions.push_back(&fromCloseRangeAttackToForward);
	//^ Filling transitions ==========================================

	StateMachine stateM{ forwardState };

	// ===============================================================
	//^ FIRST PHASE INIT =============================================
	// ===============================================================
	#pragma endregion
	#pragma region Third phase init
	// ===============================================================
	//v THIRD PHASE INIT =============================================
	// ===============================================================
	// Long range ===========================
	BossAttack souffleTenebreux{ "breath", 35.0f, 5.0f, 1.0f, 0.03f, &player };
	souffleTenebreux.addShadowBonus();

	vector<Action*> longRangeOutActions;
	longRangeOutActions.push_back(&souffleTenebreux);

	vector<Transition*> longRangeOutTransitions;
	State longRangeState{ &longRangeOutActions,  &longRangeOutTransitions };

	// Interm range =========================
	BossAttack souffleTenebreuxInter = souffleTenebreux;
	souffleTenebreuxInter.setPickProbability(0.5f);
	BossAttack sword{ "sword slash", 50.0f, 3.0f, 0.5f, 0.15f, &player };
	sword.addShadowBonus();

	vector<Action*> interRangeOutActions;
	interRangeOutActions.push_back(&souffleTenebreuxInter);
	interRangeOutActions.push_back(&sword);

	vector<Transition*> interRangeOutTransitions;
	State interRangeState{ &interRangeOutActions,  &interRangeOutTransitions };

	// Mid range ============================
	BossAttack souffleTenebreuxMid = souffleTenebreux;
	souffleTenebreuxMid.setPickProbability(0.45f);
	BossAttack explosion("explosion", 250.0f, 7.0f, 0.05f, 0.9f, &player);
	explosion.addShadowBonus();

	vector<Action*> midRangeOutActions;
	midRangeOutActions.push_back(&souffleTenebreuxMid);
	midRangeOutActions.push_back(&sword);
	midRangeOutActions.push_back(&explosion);

	vector<Transition*> midRangeOutTransitions;
	State midRangeThirdState{ &midRangeOutActions,  &midRangeOutTransitions };

	// Close range ==========================
	BossAttack griffesClose = griffes;
	BossAttack morsureClose = morsure;
	BossAttack swordClose = sword;

	griffesClose.setPickProbability(0.3f);
	morsureClose.setPickProbability(0.3f);
	swordClose.setPickProbability(0.35f);

	vector<Action*> closeRangeOutActions;
	closeRangeOutActions.push_back(&griffesClose);
	closeRangeOutActions.push_back(&morsureClose);
	closeRangeOutActions.push_back(&swordClose);
	closeRangeOutActions.push_back(&explosion);

	vector<Transition*> closeRangeOutTransitions;
	State closeRangeThirdState{ &closeRangeOutActions,  &closeRangeOutTransitions };

	#pragma region Filling Transitions
	//v Filling transitions ==========================================
	// Transit actions ======================
	Action toLong{ boss.getName() + " breathe heavily" };
	Action toInter{ boss.getName() + " is far from you" };
	Action toMid{ boss.getName() + " is close to you" };
	Action toClose{ boss.getName() + " is right next to you" };

	// Float conditions =====================
	FloatCondition longCdt{ interRange + epsilon, fInf, &gap };
	FloatCondition interCdt{ midRange + epsilon, interRange, &gap };
	FloatCondition midCdt{ closeRange + epsilon, midRange, &gap };
	FloatCondition closeCdt{ 0.0f, closeRange, &gap };

	// Long transitions =====================
	// From long to inter
	Transition fromLongToInter{ &interRangeState, &toInter, &interCdt };
	longRangeOutTransitions.push_back(&fromLongToInter);

	// From long to mid
	Transition fromLongToMid{ &midRangeThirdState, &toMid, &midCdt };
	longRangeOutTransitions.push_back(&fromLongToMid);

	// From long to close
	Transition fromLongToClose{ &closeRangeThirdState, &toClose, &closeCdt };
	longRangeOutTransitions.push_back(&fromLongToClose);

	// Inter transitions ====================
	// From inter to long
	Transition fromInterToLong{ &longRangeState, &toLong, &longCdt };
	interRangeOutTransitions.push_back(&fromInterToLong);

	// From inter to mid
	Transition fromInterToMid{ &midRangeThirdState, &toMid, &midCdt };
	interRangeOutTransitions.push_back(&fromInterToMid);

	// From inter to close
	Transition fromInterToClose{ &closeRangeThirdState, &toClose, &closeCdt };
	interRangeOutTransitions.push_back(&fromInterToClose);

	// Mid transitions ======================
	// From mid to long
	Transition fromMidToLong{ &longRangeState, &toLong, &longCdt };
	midRangeOutTransitions.push_back(&fromMidToLong);

	// From mid to inter
	Transition fromMidToInter{ &interRangeState, &toInter, &interCdt };
	midRangeOutTransitions.push_back(&fromMidToInter);

	// From mid to close
	Transition fromMidToClose{ &closeRangeThirdState, &toClose, &closeCdt };
	midRangeOutTransitions.push_back(&fromMidToClose);

	// Close transitions ====================
	// From close to long
	Transition fromClosetoLong{ &longRangeState, &toLong, &longCdt };
	closeRangeOutTransitions.push_back(&fromClosetoLong);

	// From close to inter
	Transition fromClosetoInter{ &interRangeState, &toInter, &interCdt };
	closeRangeOutTransitions.push_back(&fromClosetoInter);

	// From close to mid
	Transition fromClosetoMid{ &midRangeThirdState, &toMid, &midCdt };
	closeRangeOutTransitions.push_back(&fromClosetoMid);
	//^ Filling transitions ==========================================  
	#pragma endregion

	// ===============================================================
	//^ THIRD PHASE INIT =============================================
	// ===============================================================

	#pragma endregion

	int currentPhase = 1;
	
	while (!gameEnded)
	{
		if (currentPhase == 1 /*should be 2 ofc*/ && boss.getHealth() <= thirdPhaseTrigger) {
			cout << boss.getName() << " dashes out, wounded. Its eyes are filled with rage" << endl;
			cout << "It rises, like a mountain. And, threatening on its two legs, materializes a sword" << endl;
			cout << "\nThe last chapter of this fight now begins\n" << endl;

			gap = 9.0f;
			currentPhase = 3;

			stateM.setCurrentState(midRangeThirdState);
		}

		if (!boss.getDeathStatus())
		{
			updateBoss(stateM);

			if (!player.getDeathStatus()) {
				updatePlayer();
			}
			else {
				cout << "\n" << player.getName() << ", despite their courage, did not manage to overcome the powerful dragon..." << endl;
				cout << "\n==x==x== YOU LOSE ==x==x==x==" << endl;

				gameEnded = true;
			}
		}
		else {
			cout << "\n" << player.getName() << " eliminated the monstrous dragon. Peace can finally return to the continent" << endl;
			cout << "\n==x==x== CONGRATS ==x==x==x==" << endl;
		
			gameEnded = true;
		}
	}

	return 0;
}

void updateBoss(StateMachine& smP) {

	vector<Action*> actions = smP.update();
	vector<Action*> attacks;
	vector<Action*> others;

	vector<Action*> singleAttack;

	// Sort actions in two groups
	for (int i = 0; i < actions.size(); i++)
	{
		if (actions[i]->choosable()) {
			attacks.push_back(actions[i]);
		}
		else {
			others.push_back(actions[i]);
		}
	}

	// Execute everything but attacks
	if (others.size() > 0) smP.executeActions(others);

	// Execute attacks
	if (attacks.size() > 0) {
		singleAttack.push_back(pickBetween(attacks));

		smP.executeActions(singleAttack);
	}
}

Action* pickBetween(std::vector<Action*> attacksP)
{
	int randNum = rand() % 100 + 1;
	int out = 0;

	float totalPickProb{ 0.0f };
	
	for (int i = 0; i < attacksP.size(); i++)
	{
		totalPickProb += attacksP[i]->getPickProbability() * 100.0f;

		if (randNum <= totalPickProb)
		{
			out = i;

			break;
		}
	}

	return attacksP[out];
}

void updatePlayer() {
	cout << "\n" << player.getName() << " is " << gap << " steps away from " << boss.getName() << endl;

	player.chooseAction();
}