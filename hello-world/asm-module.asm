;***************************************************************************
;
;  @file asm-module.asm
;  @brief Ukázka programu v assembleru pro zobrazení řetězce "Hello, World!"
;
;  @author X<:3 )~ Ka
;
;  @details
;  Jednoduchý příklad, který ukazuje, jak vrátit ukazatel na řetězec z assembleru do jazyka C.
;  Program obsahuje deklaraci proměnné `msg_asm_var`, která obsahuje řetězec "Hello, world!", 
;  a funkci `get_hello_world`, která tento řetězec vrací.
;
;***************************************************************************

    bits 64

    section .data

    ; proměnné
    global msg_asm_var
    msg_asm_var db "Hello, world!", 0

;***************************************************************************

    section .text

    ; funkce
    global get_hello_world

get_hello_world:
    mov rax, msg_asm_var              ; ukazatel na řetězec
    ret                               ; Návrat z funkce

