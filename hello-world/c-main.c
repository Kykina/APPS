/**
 *  @file main.c
 *  @brief Ukázkový program v jazyce C, který využívá assembler pro vrácení textového řetězce
 *
 *  @author X<:3 )~ Ka
 *
 *  @details
 *  Tento program ukazuje, jak lze využít assembler v jazyce C. Program volá externí funkci napsanou v
 *  assembleru, která vrací řetězec "Hello, World!". Tento řetězec je následně vypsán na obrazovku pomocí
 *  funkce printf.
 */

#include <stdio.h>

// Deklarace externí funkce napsané v assembleru
extern char* get_hello_world();

int main() {
    printf("%s\n", get_hello_world());  // Výpis řetězce vráceného z ASM
    return 0;
}

