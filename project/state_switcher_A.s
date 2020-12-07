        .arch msp430g2553
	.p2align 1,0
	.text
	.global colorScreen

	.data
	.extern state		
	.text
	.word neg 		;case less than -1, resets the screen with rainbo colors and music
jt:
	.word case0		; Init the drop me
	.word case1      	; Drops the drop me
	.word case2		; Pulls up the drop me
	
	.text
	.global switch_to_change_state
switch_to_change_state:		; test < -1           
	cmp #-1, r12 		; test (r12) - 1
	jge other_compare 	; test >= -1
	mov #-2, r14		; when test < -1
	mov jt(r14),r0 		; execute the easter egg function
	 			; jmp find_normal_cases

other_compare: 			; test > 2
	mov #2, r13
	cmp r12,r13		; 2 - test
	jc find_normal_cases 	; test <= 2
	jmp end_switch		; test is bigger than 1 so defualt case, defualt case does nothing
neg:		 		; if test is less than -1
	mov #-2, &state
	jmp  end_switch
	
find_normal_cases:		; jumping to normal cases
	add r12, r12
	mov jt(r12), r0
case0:				; if test is 0
	mov #0, &state
	jmp end_switch
case1:                		; if test is 1
	mov #1, &state
	jmp end_switch
case2:				; if test is 2
	mov #2, &state
	jmp end_switch
	
end_switch:
	ret			; pop r0
