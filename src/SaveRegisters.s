					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  task1Sp
task1Sp		DCD     1

					AREA		MyCode, CODE, READONLY
saveRegs	PROC
					EXPORT  saveRegs
						
					LDR			r4, =0xAAAA4444
					LDR			r6, =0xBBBB5555
					LDR			r8, =0xCCCC6666
					LDR			r10, =0xDDDD7777
					LDR			r12, =0xEEEE8888
					
					LDR			r13, =task1Sp		;Let SP point to 'task1Sp'
					LDR			r13, [r13]			;Load value of 'task1Sp' into SP
					PUSH		{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r14}

					BX			lr									; Return to caller
								
					ENDP
								
					END