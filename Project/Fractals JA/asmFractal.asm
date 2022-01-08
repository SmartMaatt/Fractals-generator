.CODE

CheckMMXCapability PROC C
	push rbx			; Zapisz RBX
	pushfq				; Wypchnij flagi
	pop rax				; Pobierz je do RAX
	mov rbx, rax		; Zapisz do RBX na pozniej
	xor rax, 200000h	; Przelacz id flagi
	push rax			; Wypchnij przelaczone flagi
	popfq				; Pobierz je z powrotem do flag, zresetowały sie?
	pushfq				; Wypchnij flagi
	pop rax				; Pobierz je z powrotem do RAX
	cmp rax, rbx		; Porownaj aktualne flagi z wczesniej zapisanymi
	jz ThatsABity		; Jesli się zresetowały, nie mozesz uzywać CPUID

	pop rbx				; Przywracam RBX
	mov eax, 1			; Nie zresetowało sie wiec...
	cpuid				; CPUID_0000_0001
	shr rdx, 23			; Shiftuj bit MMX do pozycji najbardziej po prawej
	and rdx, 1			; Wykonuje AND na rdx (jesli bylo 1, pozostanie 1)
	mov rax, rdx		; Przenosze RDX do akumulatora
	ret					; Zwracam 0/1

ThatsABity:
	pop rbx				; Procesor nie obsluguje CPUID lub MMX
	xor rax, rax		; Resetuj akumulator do 0
	ret
CheckMMXCapability ENDP



;void AsmFractalsGenerate(unsigned char* bmpData, int r, int g, int b, int x, int y, int width, int height);
AsmFractalsGenerate PROC C 
	;rcx - bmpData
	;rdx - r
	;r8 - g
	;r9 - b

	xor rsi, rsi	; czyszczenie rejestrów
	xor rdi, rdi
	xor r10, r10
	xor r11, r11

	mov esi, DWORD PTR [RSP+48] ; - x
	mov edi, DWORD PTR [RSP+56] ; - y
	mov r10d, DWORD PTR [RSP+64] ; - width
	mov r11d, DWORD PTR [RSP+72] ; - height
	mov r12, rdx; 

	mov rax, r11	; height
	sub rax, 1		; height - 1
	sub rax, rdi	; (height - 1) - y
	mov r11, rax	; zwolnienie rejestru rax celem mnozenia
	mov rax, r10
	mul r11			; ((height - 1) - y) * width
	add rax, rsi	; x + ((height - 1) - y) * width
	mov r11, rax	; zwolnienie rejestru rax celem mnozenia
	mov rax, 3
	mul r11			; (x + ((height - 1) - y) * width) * 3
	add rcx, rax	; przesunięcie wskaźnika na tablicę o indeks

	mov BYTE PTR [rcx], r9b		; wpisanie koloru blue piksela
	inc rcx
	mov BYTE PTR [rcx], r8b		; wpisanie koloru green piksela
	inc rcx
	mov BYTE PTR [rcx], r12b	; wpisanie koloru red piksela

endProc:
    ret 

AsmFractalsGenerate ENDP
END