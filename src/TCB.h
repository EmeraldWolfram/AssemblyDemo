#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	1024
#define TASK_1	1
#define TASK_2	2
#define TASK_3	3
#define TASK_4	4
#define TASK_5	5


typedef struct {
	char *name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
} Tcb;

extern Tcb task1Tcb;
extern Tcb task2Tcb;
extern Tcb task3Tcb;
extern Tcb task4Tcb;
extern Tcb task5Tcb;

void initTcb(char* name, int taskSelection);
//void initTcb();
uint32_t getTcbSp(int taskSelection);

#endif	// __TCB_H__
