	.arch msp430g2553
	.p2align 1,0
	.text
	.global colorScreen

colorScreen:
	sub #2, r1
	mov #0, 0(r1)	;int i = 0
whileLoop:
	cmp #100,0(r1) 		;if(i == 100) goto end;
	jz end

	call #drawPixel		;drawPixel(col, row, COLOR_MAGENTA);
	add.b #1, r12		;col++
	add #1, 0(r1)		;i++
	jmp whileLoop		;goto whileLoop;
end:
	add #2,r1
	pop r0
