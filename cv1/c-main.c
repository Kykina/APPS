//***************************************************************************
//
//  @file c-main.c
//  @brief Hlavní C soubor pro demonstraci práce s MOV, MOVSX, MOVZX
//
//  @author X<:3 )~ Ka
//
//  @details
//  Tento soubor obsahuje hlavní funkci, která volá assemblerové procedury
//  pro práci s různými datovými typy v jazyce C. Ukazuje operace s int, char,
//  unsigned char, long a stringy pomocí MOV instrukcí.
//  S použitím globálních proměnných.
//
//***************************************************************************

#include <stdio.h>
#include <stdint.h>

// Deklarace funkcí z Assembleru
void copy_int();
void sign_extend_char();
void zero_extend_uchar();
void copy_long();
void copy_string();
void copy_two_ints();

int g_value;
int g_int;
char g_char;
unsigned char g_uchar;
unsigned int g_uint;
long g_long_value;
long g_long;
char g_source[];
char g_destination[];
int g_src[2];
int g_dest[2];
char g_source[] = "Hello, ASM!";
char g_destination[10] = {0};
int g_src[2] = {7, 42}; 
int g_dest[2] = {0, 0};   


int main() {
    // Kopírování hodnoty typu int
    g_value = 12345;
    g_int = 0;
    copy_int();
    printf("MOV (kopie int): %d\n", g_int);

    // Sign-extend: rozšíření znaménka pro hodnotu typu char
    g_char = -42;
    g_int = 0;
    sign_extend_char();
    printf("MOVSX (sign-extend -42): %d\n", g_int);

    // Zero-extend: nulové rozšíření pro hodnotu typu unsigned char
    g_uchar = 200;
    g_uint = 0;
    zero_extend_uchar();
    printf("MOVZX (zero-extend 200): %u\n", g_uint);

    // Kopírování hodnoty typu long
    g_long_value = 1234567890123;
    g_long = 0;
    copy_long();
    printf("MOV (kopie long): %ld\n", g_long);

    // Kopírování stringu
    copy_string();
    printf("MOV (kopírování stringu): %s\n",g_destination);

    // Kopírování prvních dvou intů z pole
    copy_two_ints();
    printf("MOV (kopírování pole): %d %d\n",g_dest[0], g_dest[1]);

    return 0;
}

