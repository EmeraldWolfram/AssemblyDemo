#ifndef __INIT_TASK_H__
#define __INIT_TASK_H__

void initTask(void);

void updateStack(void);

void switchSp(int newSP);

void querySp(void);

void pushRegs(void);

void popRegs(void);

#endif	// __INIT_TASK_H__