;Justin Liu, jl8wf  Date: 10/27/2020	Filename: treexplusone.s
	;; List of Optimazation:
	;; Used shifts to find whether odd or even instead of looping and dividing to find out on line 20-22
	;; Used shift instead of division on line 43
	;; Used lea instead of imul on line 36
	
	global threexplusone

	section .text

threexplusone:
	;; Given an input, should return number of iterations
	;; if odd, multiply by 3 and subtract 1
	;; if even, divide by 2
	xor	rax, rax	;rax is increment

	cmp 	rax, 1		;if input is 1, return 0. Also base case, deals with this at done
	je  	done
	push	rdi		;store for later
	shr 	rdi, 1		;shift input right
	shl 	rdi, 1		;shift input left
	mov	r11, rdi	;because shifting right and then left makes the very right bit 0, whatever was orginially in the input's far right will be XORed with 0, thus return the OG right bit
	pop	rdi		;get OG input to compare to the shifted stored in r11
	push	rdi		;store it again for later
	xor	rdi, r11	;should be a 1 or a 0
	cmp 	rdi, 1		;1 if odd, 0 if even
	je	odd		;je because 1 = 1
	jl	even		;jl because 0 < 1
odd:
	pop	rdi		;gets OG input
	cmp	rdi, 1		;wont mess with the base case of rdi = 1
	je	zero
	lea	rdi, [rdi*2 + rdi]

	inc	rdi
	call	threexplusone
	inc	rax
	ret

even:	
	pop 	rdi		;get OG input
	shr	rdi, 1		;divide by 2
	call	threexplusone
	inc	rax
	ret
	
done:
	mov 	rax, 1		;returns a 1 for recursive calls
	ret
zero:
	xor 	rax, rax	;set whatever rax is to 0 because if increment, r10, is 0, then input was 1
	ret 

