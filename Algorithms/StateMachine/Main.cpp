#include <iostream>
#include "StateMachine.h"

using namespace std;

int main() {	
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
	vector<Transition*> fromGuardToAttackTransitions;
	vector<Transition*> fromAttackingToOnGuardTransitions;

	State onGuard{ onGuardEntryActions, onGuardActions, onGuardExitActions, fromGuardToAttackTransitions };
	State attacking{ attackEntryActions, attackActions, attackExitActions, fromAttackingToOnGuardTransitions };
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
	// 
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

	return 0;
}