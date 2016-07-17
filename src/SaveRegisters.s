					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  task1Sp
task1Sp		DCD     1

					AREA		MyCode, CODE, READONLY
saveRegs	PROC
					EXPORT  saveRegs
								
					LDR			r13, =task1Sp		;Let SP point to 'task1Sp'
					LDR			r13, [r13]			;Load value of 'task1Sp' into SP
					PUSH		{r0, r1, r2, r3}
					PUSH		{r4, r5, r6, r7}
					PUSH		{r8, r9, r10, r11}
					PUSH		{r12, r14}

					BX			lr									; Return to caller
								
					ENDP
								
					END