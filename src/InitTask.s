					PRESERVE8
					THUMB
					AREA    MyData, DATA, READWRITE, ALIGN=2
					EXPORT  curSp
mainSp		DCD			1
curSp			DCD			1


					AREA		MyCode, CODE, READONLY
initTask	PROC
					EXPORT  initTask
					IMPORT	taskFunc
										
					LDR			r10, =mainSp					;Let r10 point to 'mainSp'
					STR			r13, [r10]						;Store main stack pointer into 'mainSp'

					LDR			r13, =curSp						;Let SP point to 'curSp'
					LDR			r13, [r13]						;Load value of 'task1Sp' into SP
					LDR			r1, =0xFFFFFFF9
					LDR			r2, =0x20000000
					LDR			r3, =0x11111111
					LDR			r4, =0x22222222
					LDR			r5, =0x33333333
					MOV			r6, #0x12
					LDR			r8, =taskFunc
					LDR			r8, [r8]
					SUB			r7, r8, #1
					LDR			r9, =0x01000000
					
					PUSH		{r0-r9}
					PUSH		{r4-r11}
					LDR			r9, =curSp			;Let r3 point to taskSp
					STR			r13, [r9]				;Update new sp value to taskSp
					LDR			r13, =mainSp
					LDR			r13, [r13]			;Use back the previous stack pointer

					BX			lr							; Return to caller
					ENDP

switchSp	PROC
					EXPORT	switchSp
				
					LDR			r1, =mainSp			;Let r1 point to 'mainSp'
					STR			r0, [r1]				;store r0 (the new SP brought in) into 'mainSp'
					LDR			r13, =mainSp		;Let r13 point to 'mainSp'
					LDR			r13, [r13]			;Load 'mainSp' into the SP
					
					BX			lr							;back to caller
					ENDP
	
querySp		PROC
					EXPORT	querySp					
					LDR			r0, =curSp			;Let r0 point to 'curSp'
					STR			r13,[r0]				;Store SP into 'curSp'
					
					BX			lr							;back to caller
					ENDP
						
pushRegs	PROC
					EXPORT	pushRegs
					PUSH		{r4-r11}
					BX			lr
					ENDP
						
popRegs		PROC
					EXPORT	popRegs
					POP			{r4-r11}
					BX			lr	
					ENDP
						
					END