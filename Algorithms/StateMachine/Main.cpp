#include <iostream>
#include "StateMachine.h"
#include "PlayableCharacter.h"
#include "Boss.h"

using namespace std;

//v Functions ====================================================
void updatePlayer();
void updateBoss(StateMachine& smP);

//^ Functions ====================================================
//v Variables ====================================================
float fInf = 10000.0f;
int iInf = 10000;
float epsilon = 0.000001f;

bool gameEnded = false;
float gap = 16.0f;

Weapon baseWeapon{"Poing", 10.0f, 5.0f, 0.0f};
PlayableCharacter player{"Jean Jean", 100.0f, &baseWeapon, &gap};

Boss boss{ "Rydnir", 5000.0f, &gap};

// First phase ==========================
float midRange = 5.0f;
float closeRange = 3.0f;

// Second phase =========================

//^ Variables ====================================================



int main() {	
	#pragma region Prev Example
	/*
	//v On Guard to Attack ===========================================
	//v onGuard ======================================================
	Action onGuardEnter01{ "onGuard entering" };
	Action onGuard01{ "onGuard" };
	Action onGuardExit01{ "onGuard exiting" };

	vector<Action*> onGuardEntryActions;
	vector<Action*> onGuardActions;
	vector<Action*> onGuardExitActions;

	onGuardEntryActions.push_back(&onGuardEnter01);
	onGuardActions.push_back(&onGuard01);
	onGuardExitActions.push_back(&onGuardExit01);
	//v attacking ====================================================
	Action attackingEnter01{ "attacking entering" };
	Action attacking01{ "attacking" };
	Action attackingExit01{ "attacking exiting" };

	vector<Action*> attackEntryActions;
	vector<Action*> attackActions;
	vector<Action*> attackExitActions;

	attackEntryActions.push_back(&attackingEnter01);
	attackActions.push_back(&attacking01);
	attackExitActions.push_back(&attackingExit01);
	//v transitions ==================================================
	// =====
	Action placeholderAction{"placeholder"};
	FloatCondition placeholderCondition{0.0f, 1.0f, 2.0f};
	Transition placeholderTransition{&placeholderAction, &placeholderCondition};
	// =====

	vector<Transition*> fromGuardToAttackTransitions;
	fromGuardToAttackTransitions.push_back(&placeholderTransition);
	vector<Transition*> fromAttackingToOnGuardTransitions;
	fromAttackingToOnGuardTransitions.push_back(&placeholderTransition);

	State onGuard{ onGuardEntryActions, onGuardActions, onGuardExitActions, &fromGuardToAttackTransitions };
	State attacking{ attackEntryActions, attackActions, attackExitActions, &fromAttackingToOnGuardTransitions };
	//v transition from onGuard to attacking =============
	//v First transition ========================
	// Transition action
	Action seeEnemy{ "I'm seing an enemy!" };

	// Transition condition
	float testValue = 5.0f;
	FloatCondition floatCdt{ 0.0f, 10.0f, testValue };

	Transition fromOnGuardToAttacking01{&attacking, &seeEnemy, &floatCdt };
	fromGuardToAttackTransitions.push_back(&fromOnGuardToAttacking01);
	//^ First transition ========================

	//fromGuardToAttackTransitions[0]->setTargetState(&attacking);

	//^ transition from onGuard to attacking =============
	//v transition from attacking to onGuard =============
	//v First transition ========================
	// Transition action
	Action loosingEnemy{ "I lost the enemy!" };

	// Transition condition
	float testValue02 = 15.0f;
	FloatCondition floatCdt02{ 0.0f, 10.0f, testValue02 };

	Transition fromAttackingToOnGuard01{ &onGuard, &loosingEnemy, &floatCdt02 };
	fromAttackingToOnGuardTransitions.push_back(&fromAttackingToOnGuard01);
	//^ First transition ========================

	//fromAttackingToOnGuardTransitions[0]->setTargetState(&onGuard);
	
	//^ transition from attacking to onGuard =============
	// ===============================================================
	//^ On Guard to Attack ===========================================

	StateMachine stateMachineTest{ onGuard };
	
	vector<Action*> actions = stateMachineTest.update();
	stateMachineTest.executeActions(actions);
	actions = stateMachineTest.update();
	stateMachineTest.executeActions(actions);
	actions = stateMachineTest.update();
	stateMachineTest.executeActions(actions);
	*/
	#pragma endregion
	#pragma region Init
	//================================================================
	//v PLAYER INIT ==================================================
	//================================================================
	player.setTarget(&boss);
	boss.setTarget(&player);


	//================================================================
	//^ PLAYER INIT ==================================================
	//================================================================

	// ===============================================================
	//v FIRST PHASE INIT =============================================
	// ===============================================================
	// Forward ==============================
	Action forwardAction{ "forward" };

	vector<Action*> forwardActions;

	forwardActions.push_back(&forwardAction);
	// Mid range attacks ====================
	Action griffes{ "Griffes" }; // <--- TEMP
	Action ailes{ "Ailes" };
	Action queue{ "Queue" };

	vector<Action*> midRangeAttacksActions;

	midRangeAttacksActions.push_back(&griffes);
	midRangeAttacksActions.push_back(&ailes);
	midRangeAttacksActions.push_back(&queue);

	// Close range attacks ==================
	Action morsure{ "Morsure" }; // <--- TEMP AUSSI

	vector<Action*> closeRangeAttacksActions;
	closeRangeAttacksActions.push_back(&griffes);
	closeRangeAttacksActions.push_back(&ailes);
	closeRangeAttacksActions.push_back(&queue);
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
	Action seeEnemy{ "The enemy is close enough" };

	// Transition condition
	FloatCondition midDistanceCdt{ closeRange + epsilon, midRange, &gap };

	Transition fromForwardToMidRangeAttack{ &midRangeState, &seeEnemy, &midDistanceCdt };
	forwardOutTransitions.push_back(&fromForwardToMidRangeAttack);
	// Transition from forward to closeRangeAttack 
	Action closeToEnemy{ "I'm right next to the enemy" };

	FloatCondition closeDistanceCdt{ 0.0f, closeRange, &gap };

	Transition fromForwardToCloseRangeAttack{ &closeRangeState, &closeToEnemy, &closeDistanceCdt };
	forwardOutTransitions.push_back(&fromForwardToCloseRangeAttack);
	
	// MidRange attack transitions ==========
	// Transition from midRangeAttack to forward 
	Action loosingEnemy{ "The enemy is too far!" };

	FloatCondition farCdt{ midRange + epsilon, fInf, &gap };

	Transition fromMidRangeAttackToForward{ &forwardState, &loosingEnemy, &farCdt };
	midRangeAttacksOutTransitions.push_back(&fromMidRangeAttackToForward);
	
	// Transition from midRangeAttack to close range
	Transition fromMidRangeAttackToCloseRangeAttack{ &closeRangeState, &closeToEnemy, &closeDistanceCdt };
	midRangeAttacksOutTransitions.push_back(&fromMidRangeAttackToCloseRangeAttack);

	// Close range attack transitions =======
	// Transition from closeRangeAttack to midRangeAttack
	Action enemyStepOut{ "The enemy took a few steps away" };

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

	while (!gameEnded)
	{
		// Player actions
		// Player actions
		updatePlayer();

		// Boss actions
		(gap > 0) ? gap -= 2.0f : gap = 0;

		updateBoss(stateM);
	}

	return 0;
}

void updatePlayer() {
	cout << player.getName() << " is " << gap  << " steps away from " << boss.getName() << endl;


	// While the player can play
		// Display current condition

		// Let the player choose between actions
		player.chooseAction();

		// Do the action
	// 
}

void updateBoss(StateMachine& smP) {
	vector<Action*> actions = smP.update();
	smP.executeActions(actions);
}