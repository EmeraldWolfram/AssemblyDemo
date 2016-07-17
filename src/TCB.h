#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	1024

typedef struct {
	char *name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
} Tcb;

extern Tcb task1Tcb;
extern Tcb task2Tcb;

void initTcb();
uint32_t getTcbTask1Sp();

#endif	// __TCB_H__
