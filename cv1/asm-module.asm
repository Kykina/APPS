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
;  Pomocí globálních proměnných.
;
;***************************************************************************

section .data
    extern g_value
    extern g_int
    extern g_char
    extern g_uchar
    extern g_uint
    extern g_long_value
    extern g_long
    extern g_source
    extern g_destination
    extern g_src
    extern g_dest

section .text
    global copy_int
    global sign_extend_char
    global zero_extend_uchar
    global copy_long
    global copy_string
    global copy_two_ints

; Kopírování hodnoty typu int
copy_int:
    mov eax, [g_value]
    mov [g_int], eax
    ret

; Sign-extend: rozšíření znaménka pro hodnotu typu char
sign_extend_char:
    movsx eax, byte [g_char]
    mov [g_int], eax
    ret

; Zero-extend: nulové rozšíření pro hodnotu typu unsigned char
zero_extend_uchar:
    movzx eax, byte [g_uchar]
    mov [g_uint], eax
    ret

; Kopírování hodnoty typu long
copy_long:
    mov rax, [g_long_value]
    mov [g_long], rax
    ret

; Kopírování stringu (prvních 5 znaků)
copy_string:
    mov al, [g_source]
    mov [g_destination], al
    mov al, [g_source+1]
    mov [g_destination+1], al
    mov al, [g_source+2]
    mov [g_destination+2], al
    mov al, [g_source+3]
    mov [g_destination+3], al
    mov al, [g_source+4]
    mov [g_destination+4], al
    ret

; Kopírování prvních dvou intů z pole
copy_two_ints:
    mov eax, [g_src]
    mov [g_dest], eax
    mov eax, [g_src+4]
    mov [g_dest+4], eax
    ret

