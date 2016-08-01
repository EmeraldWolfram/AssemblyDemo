					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					IMPORT  taskSp

					AREA		MyCode, CODE, READONLY
getRegs		PROC
					EXPORT  getRegs
					
					LDR			r13, =taskSp		;Let SP point to 'taskSp'
					LDR			r13, [r13]			;Load value of 'task1Sp' into SP
					POP			{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r14}

					BX			lr									; Return to caller
								
					ENDP
								
					END