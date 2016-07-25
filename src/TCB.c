#include "TCB.h"
#include <stdlib.h>

Tcb task1Tcb;
Tcb task2Tcb;
Tcb task3Tcb;
Tcb task4Tcb;
Tcb task5Tcb;

/**
 * Must call this function first
 */
void initTcb(char* name, int taskSelection) {
	switch(taskSelection){
		case TASK_1:
			task1Tcb.name = name;
			task1Tcb.sp	  = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
			break;
		case TASK_2:
			task2Tcb.name = name;
			task2Tcb.sp	  = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE];
			break;
		case TASK_3:
			task3Tcb.name = name;
			task3Tcb.sp	  = (uint32_t)&task3Tcb.virtualStack[TASK_STACK_SIZE];
			break;
		case TASK_4:
			task4Tcb.name = name;
			task4Tcb.sp	  = (uint32_t)&task4Tcb.virtualStack[TASK_STACK_SIZE];
			break;
	}
}

uint32_t getTcbSp(int taskSelection){
	switch(taskSelection){
		case TASK_1:
			return task1Tcb.sp;
		case TASK_2:
			return task2Tcb.sp;
		case TASK_3:
			return task2Tcb.sp;
		case TASK_4:
			return task2Tcb.sp;
		default:
			return task1Tcb.sp;
	}
}

// Study the code in AsssemblyModule.s and take note of what
// how each instruction performs its job. You need that knowledge
// to do the following:
//
// 1) Create a new assembly file called 'SaveRegisters.s'.
// 2) Write a code in assembly [in (1)] to:
//    - load SP with the value in 'task1Tcb.sp'
//    - push all registers, except R13 to the stack
// 3) Name that function as 'saveRegs'
// 4) From main() call: 
//    - initTcb()
//    - saveRegs()
// 5) Verify that the registers are in 'task1Tcb.virtualStack'
// 6) Submit your work by pushing it to GitHub
