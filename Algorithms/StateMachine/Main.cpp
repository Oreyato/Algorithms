#include <iostream>
#include "StateMachine.h"

using namespace std;

//v Functions ====================================================
void updatePlayer();
void updateBoss(StateMachine& smP);

//^ Functions ====================================================
//v Variables ====================================================
bool gameEnded = false;
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
	// ===============================================================
	//v INIT =========================================================
	// ===============================================================
	
	//v On Guard to Attack ===========================================
	//v onGuard ======================================================
	Action onGuard01{ "onGuard" };

	vector<Action*> onGuardActions;

	onGuardActions.push_back(&onGuard01);
	//v attacking ====================================================
	Action attacking01{ "attacking" };

	vector<Action*> attackActions;

	attackActions.push_back(&attacking01);
	//v transitions ==================================================
	// =====
	Action placeholderAction{ "placeholder" };
	FloatCondition placeholderCondition{ 0.0f, 1.0f, 2.0f };
	Transition placeholderTransition{ &placeholderAction, &placeholderCondition };
	// =====

	vector<Transition*> fromGuardToAttackTransitions;
	fromGuardToAttackTransitions.push_back(&placeholderTransition);
	vector<Transition*> fromAttackingToOnGuardTransitions;
	fromAttackingToOnGuardTransitions.push_back(&placeholderTransition);

	State onGuard{ onGuardActions,  &fromGuardToAttackTransitions };
	State attacking{ attackActions, &fromAttackingToOnGuardTransitions };
	//v transition from onGuard to attacking =============
	//v First transition ========================
	// Transition action
	Action seeEnemy{ "I'm seing an enemy!" };

	// Transition condition
	float testValue = 5.0f;
	FloatCondition floatCdt{ 0.0f, 10.0f, testValue };

	Transition fromOnGuardToAttacking01{ &attacking, &seeEnemy, &floatCdt };
	fromGuardToAttackTransitions.push_back(&fromOnGuardToAttacking01);
	//^ First transition ========================
	//^ transition from onGuard to attacking =============
	//v transition from attacking to onGuard =============
	//v First transition ========================
	// Transition action
	Action loosingEnemy{ "I lost the enemy!" };

	// Transition condition
	float testValue02 = 5.0f;
	FloatCondition floatCdt02{ 0.0f, 10.0f, testValue02 };

	Transition fromAttackingToOnGuard01{ &onGuard, &loosingEnemy, &floatCdt02 };
	fromAttackingToOnGuardTransitions.push_back(&fromAttackingToOnGuard01);
	//^ First transition ========================
	//^ transition from attacking to onGuard =============
	// ===============================================================
	//^ On Guard to Attack ===========================================

	StateMachine stateM{ onGuard };

	// ===============================================================
	//^ INIT =========================================================
	// ===============================================================
	#pragma endregion

	while (!gameEnded)
	{
		// Player actions
		// Player actions
		updatePlayer();

		// Boss actions
		updateBoss(stateM);
	}

	return 0;
}

void updatePlayer() {
	// While the player can play
		// Display current condition

		// Let the player choose between actions

		// Do the action
	// 
}

void updateBoss(StateMachine& smP) {
	vector<Action*> actions = smP.update();
	smP.executeActions(actions);
}