					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  taskFunc, mainSp
taskFunc	DCD     1
mainSp		DCD			1

					AREA		MyCode, CODE, READONLY
initTask	PROC
					EXPORT  initTask
					IMPORT	taskSp
										
					LDR			r10, =mainSp					;Let r10 point to 'mainSp'
					STR			r13, [r10]						;Store main stack pointer into 'mainSp'
					LDR			r13, =taskSp					;Let SP point to 'taskSp'
					LDR			r13, [r13]						;Load value of 'task1Sp' into SP
					LDR			r6, =taskFunc
					LDR			r6, [r6]
					SUB			r5, r6, #1
					LDR			r7, =0x01000000
					
					PUSH		{r0-r7}
					LDR			r9, =taskSp			;Let r3 point to taskSp
					STR			r13, [r9]				;Update new sp value to taskSp
					LDR			r13, =mainSp
					LDR			r13, [r13]			;Use back the previous stack pointer

					BX			lr							; Return to caller
								
					ENDP
								
					END