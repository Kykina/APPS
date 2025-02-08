;***************************************************************************
;
;  @file asm-module.asm
;  @brief Assemblerový modul pro demonstraci instrukcí MOV, MOVSX, MOVZX
;
;  @author X<:3 )~ Ka
;
;  @details
;  Tento assemblerový soubor obsahuje procedury pro operace s různými
;  datovými typy v jazyce C. Implementuje kopírování int, long, rozšíření
;  znaménka u char, nulové rozšíření unsigned char, kopírování stringů
;  a kopírování prvků pole pomocí instrukcí MOV, MOVSX a MOVZX.
;
;***************************************************************************

section .data
    extern global_value  ; Globální proměnná v C

section .text
    global copy_int
    global sign_extend_char
    global zero_extend_uchar
    global copy_long
    global copy_string
    global copy_two_ints

; Kopírování hodnoty typu int
copy_int:
    mov eax, edi
    ret

; Sign-extend: rozšíření znaménka pro hodnotu typu char
sign_extend_char:
    movsx eax, dil
    ret

; Zero-extend: nulové rozšíření pro hodnotu typu unsigned char
zero_extend_uchar:
    movzx eax, dil
    ret

; Kopírování hodnoty typu long
copy_long:
    mov rax, rdi
    ret

; Kopírování stringu (prvních 5 znaků)
copy_string:
    mov al, [rdi]
    mov [rsi], al
    mov al, [rdi+1]
    mov [rsi+1], al
    mov al, [rdi+2]
    mov [rsi+2], al
    mov al, [rdi+3]
    mov [rsi+3], al
    mov al, [rdi+4]
    mov [rsi+4], al
    mov byte [rsi+5], 0
    ret

; Kopírování prvních dvou intů z pole
copy_two_ints:
    mov eax, [rdi]
    mov [rsi], eax
    mov eax, [rdi+4]
    mov [rsi+4], eax
    ret

