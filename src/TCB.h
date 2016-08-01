#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	1024

typedef struct Tcb Tcb;

struct Tcb {
	char	*name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
	Tcb		*next;
};

extern Tcb mainTcb;
extern Tcb task1Tcb;
extern Tcb task2Tcb;
extern Tcb task3Tcb;

void initMainTcb();
void initTcb1();
void initTcb2();
void initTcb3();


#endif	// __TCB_H__
