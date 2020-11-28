        .arch msp430g2553
	.p2align 1,0
	.text
	.text
	
jt_music:	.word a_note

	.global note_to_cycle
	.text
note_to_cycle:
	;; making room to store variables
	sub #6, r1
	;; storing freq  at 0(r1)
	;; storing cycle at 2(r1)
	;; storing note  at 4(r1)
	mov r12, 4(r1)		;note

a_note:
	;; freq = freq_finder (note);
	mov  4(r1), r12		; note to first param 
	call #freq_finder 	; function call
	mov r12, 0(r1)
	;; cycle_finder(freq)
	mov 0(r1), r12		; freq to first param
	call #cycle_finder
	mov r12, 2(r1)
end_note:
	mov 2(r1), r12
	add #6, r1
	pop r0
