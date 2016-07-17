/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "TCB.h"
#include "SaveRegisters.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
extern int task1Sp;							// Import from SaveRegisters.s

uint32_t variableInC = 0xdeaf;

void waitForever(void) {
	volatile int counter = 500000;
	while(counter--);
//	NVIC_DisableIRQ(SysTick_IRQn);
	disableSysTickInterrupt();
}

int main() {
	fourBytes = 0xdeadbeef;
	task1Sp	= 0xace0face;
	noArgFunc();

	initTcb();
	task1Sp	= getTcbTask1Sp();
	saveRegs();
	
	initSysTick();
  //waitForever();

	int i;
	while(1) {
		i++;
	}

	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;		//
}
