;***************************************************************************
;
;  @file asm-module.asm
;  @brief Assemblerový modul pro demonstraci instrukcí 
;  ADD, SUB, CMP, INC, DEC, NEG, AND, TEST, OR, XOR, NOT, SHL, SHR.
;
;  @author X<:3 )~ Ka
;
;  @details
;  Praktické využití různých instrukcí, ukázka jednoduhé podmínky a cyklu.
;
;***************************************************************************

global add_points
global use_credit
global check_temp
global inc_packets
global dec_attempt
global invert_balance
global mask_value
global is_even
global enable_feature
global toggle_led
global invert_bits
global multiply_by_two
global divide_by_two
global if_negative
global loop_demo

extern g_score
extern g_credit
extern g_temperature
extern g_packets
extern g_attempts
extern g_balance
extern g_value
extern g_number
extern g_flags
extern g_led
extern g_mask
extern g_counter

section .text

;ADD - přičte 5 bodů
add_points:
    mov rbx, g_score
    add dword [rbx], 5
    ret

;SUB - odečte 10 kreditů
use_credit:
    mov rbx, g_credit
    sub dword [rbx], 10
    ret

;CMP - porovná teplotu s 0
check_temp:
    mov rbx, g_temperature
    mov eax, [rbx]
    cmp eax, 0
    jl .below
    mov eax, 0
    ret
.below:
    mov eax, 1
    ret

;INC - zvýší hodnotu paketu o 1
inc_packets:
    mov rbx, g_packets
    inc dword [rbx]
    ret

;DEC - sníží počet pokusů o 1
dec_attempt:
    mov rbx, g_attempts
    dec dword [rbx]
    ret

;NEG - zamění kladnou a zápornou hodnotu
invert_balance:
    mov rbx, g_balance
    neg dword [rbx]
    ret

;AND - vybere bity podle masky
mask_value:
    mov rbx, g_value
    and dword [rbx], 0xFF00
    ret

;TEST - otestuje bity podle masky, v tomto případě poslední na 0 nebo 1
is_even:
    mov rbx, g_number
    mov eax, [rbx]
    test eax, 1
    jz .even
    mov eax, 0
    ret
.even:
    mov eax, 1
    ret

;OR - nastaví bity na 1 podle masky, v tomto případě 0. a 7.
enable_feature:
    mov rbx, g_flags
    or dword [rbx], 0b10000001
    ret

;XOR - invertuje bity podle masky, v tomto případě posledních 16 bitů
toggle_led:
    mov rbx, g_led
    xor dword [rbx], 0xFF
    ret

;NOT - invertuje všechny bity
invert_bits:
    mov rbx, g_mask
    not dword [rbx]
    ret

;SHL - posune všechny bity doleva, v tomto případě o 1 bit
;tím dojde k žádanému efektu vynásobení hodnoty 2
multiply_by_two:
    mov rbx, g_value
    shl dword [rbx], 1
    ret

;SHR - posune všechny bity doprava, v tomto případě o 1 bit
;tím dojde k žádanému efektu vydělení hodnoty 2
divide_by_two:
    mov rbx, g_value
    shr dword [rbx], 1
    ret

;Ukázka podmíněného skoku
if_negative:
    mov rbx, g_number
    mov eax, [rbx]
    cmp eax, 0
    jl .neg
    mov eax, 0
    ret
.neg:
    mov eax, 1
    ret

;Ukázka jednoduchého cyklu
loop_demo:
    mov rbx, g_counter
.loop:
    cmp dword [rbx], 0
    jle .end
    dec dword [rbx]
    jmp .loop
.end:
    ret
