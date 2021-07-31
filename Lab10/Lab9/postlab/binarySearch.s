;Justin Liu, jl8wf 	Date:10/29/2020		Filename: binarySearch.s

	global binarySearch
	section .text
; Parameter 1 is a pointer to the int array, rdi
; Parameter 2 is the low of the array, rsi
; Parameter 3 is the high of the array, rdx
; Parameter 4 is the target number to be found, rcx 
	;; rdi, rsi, rdx, rcx, r8, r9
	;; int binarySearch(int low,int high,int key)
binarySearch:
	cmp	rsi, rdx	;compare low to high
	jg	LGTH		;low greater than high, else
	mov	r10, 0
	add	r10, rsi	;Making mid, adding low
	add	r10, rdx	;adding high
	shr	r10, 1		;divide by 2
	cmp	[rdi + 4*r10], ecx ;compares a[mid] to rcx, the target number
	jl	case1		   ;a[mid] < target 
	jg	case2		   ;a[mid] > target
	mov	rax, r10	   ;a[mid] == target
	ret
case1:
	inc	r10		;mid++
	mov	rsi, r10	;low = mid
	jmp	binarySearch
case2:
	dec	r10		;mid--
	mov	rdx, r10	;high = mid
	jmp	binarySearch
LGTH:
	
	mov	rax, -1
	ret
	
	
