;***************************************************************************
;  @file asm-module.asm
;  @brief Assemblerový modul pro demonstraci volání ASM funkcí, parametry, 
;  návraty, ukazatele, nepřímé adresování, skoky, cykly, složené podmínky. 
;
;***************************************************************************

global add_points
global use_credit
global check_temp
global inc_packets
global dec_attempt
global invert_balance
global mask_value_u32
global is_even
global enable_feature
global toggle_led
global invert_bits_u32
global multiply_by_two
global divide_by_two
global if_negative
global loop_down_to_zero

section .text

; void add_points(int *score, int add)
add_points:
    add dword [rdi], esi
    ret

; void use_credit(int *credit, int cost)
use_credit:
    sub dword [rdi], esi
    ret

; int check_temp(int temp_c) -> 1 pokud <0 jinak 0
check_temp:
    cmp edi, 0
    jl  .below
    xor eax, eax
    ret
.below:
    mov eax, 1
    ret

; void inc_packets(int *packets)
inc_packets:
    inc dword [rdi]
    ret

; void dec_attempt(int *attempts)
dec_attempt:
    dec dword [rdi]
    ret

; void invert_balance(int *balance)
invert_balance:
    neg dword [rdi]
    ret

; uint32_t mask_value_u32(uint32_t value, uint32_t mask) -> value & mask
mask_value_u32:
    mov eax, edi
    and eax, esi
    ret

; int is_even(int number) -> 1 sudé, 0 liché
is_even:
    test edi, 1
    jz  .even
    xor eax, eax
    ret
.even:
    mov eax, 1
    ret

; void enable_feature(uint32_t *flags, uint32_t mask)
enable_feature:
    or dword [rdi], esi
    ret

; void toggle_led(uint32_t *led, uint32_t mask)
toggle_led:
    xor dword [rdi], esi
    ret

; uint32_t invert_bits_u32(uint32_t x) -> ~x
invert_bits_u32:
    mov eax, edi
    not eax
    ret

; int multiply_by_two(int x) -> x<<1
multiply_by_two:
    mov eax, edi
    shl eax, 1
    ret

; int divide_by_two(int x) -> (unsigned) x>>1
divide_by_two:
    mov eax, edi
    shr eax, 1
    ret

; int if_negative(int x) -> 1 pokud x<0 jinak 0
if_negative:
    cmp edi, 0
    jl  .neg
    xor eax, eax
    ret
.neg:
    mov eax, 1
    ret

; void loop_down_to_zero(int *counter)
loop_down_to_zero:
.loop:
    cmp dword [rdi], 0
    jle .end
    dec dword [rdi]
    jmp .loop
.end:
    ret

