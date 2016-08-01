/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f429xx.h"
#include "stm32f4xx_hal_cortex.h"
#include "AssemblyModule.h"
#include "TCB.h"
#include "SaveRegisters.h"
#include "RetrieveRegisters.h"
#include "LinkedList.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
extern int taskSp;							// Import from SaveRegisters.s

uint32_t variableInC = 0xdeaf;

void taskInit(Tcb* tcb, void* taskFunc){
	
}

int main() {
	int i = 0;
	fourBytes = 0xdeadbeef;
	taskSp	= 0xace0face;
	noArgFunc();
	
	initTcb1();
	taskSp = task1Tcb.sp;
	saveRegs();

	initLinkedList();
	initMainTcb();

	initSysTick();

	
	while(1) {
		i++;
	}

	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;		//
}

void task1(){
	int i = 0;
	
	while(1){
		i++;
	}
}

void task2(){
	int i = 0;
	
	while(1){
		i++;
	}
}

void task3(){
	int i = 0;
	
	while(1){
		i++;
	}
}