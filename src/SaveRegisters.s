					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  taskSp
taskSp		DCD     1

					AREA		MyCode, CODE, READONLY
saveRegs	PROC
					EXPORT  saveRegs
						
					LDR			r4, =0x22224444
					LDR			r6, =0xBBBB5555
					LDR			r8, =0xCCCC6666
					LDR			r10, =0xDDDD7777
					LDR			r12, =0xEEEE8888
					
					LDR			r4, [r13]				;Remain the previous stack pointer
					LDR			r13, =taskSp		;Let SP point to 'taskSp'
					LDR			r13, [r13]			;Load value of 'task1Sp' into SP
					PUSH		{r0-r12}
					POP			{r0-r12}
					LDR			r3, =taskSp			;Let r3 point to taskSp
					STR			r13, [r3]				;Update new sp value to taskSp, same value in this case
					LDR			r13, [r4]				;Use back the previous stack pointer

					BX			lr									; Return to caller
								
					ENDP
								
					END