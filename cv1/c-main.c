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
//
//***************************************************************************

#include <stdio.h>
#include <stdint.h>

// Deklarace funkcí z Assembleru
extern int copy_int(int a);
extern int sign_extend_char(char a);
extern unsigned int zero_extend_uchar(unsigned char a);
extern long copy_long(long a);
extern void copy_string(char *src, char *dest);
extern void copy_two_ints(int *src, int *dest);

// Globální proměnná
int global_value = 10;

int main() {
    // Kopírování hodnoty typu int
    int a = 12345;
    int result = copy_int(a);
    printf("MOV (kopie int): %d\n", result);

    // Sign-extend: rozšíření znaménka pro hodnotu typu char
    char small_signed = -42;
    int sign_result = sign_extend_char(small_signed);
    printf("MOVSX (sign-extend -42): %d\n", sign_result);

    // Zero-extend: nulové rozšíření pro hodnotu typu unsigned char
    unsigned char small_unsigned = 200;
    unsigned int zero_result = zero_extend_uchar(small_unsigned);
    printf("MOVZX (zero-extend 200): %u\n", zero_result);

    // Kopírování hodnoty typu long
    long big_number = 1234567890123;
    long long_result = copy_long(big_number);
    printf("MOV (kopie long): %ld\n", long_result);

    // Kopírování stringu
    char source[] = "Hello, ASM!";
    char destination[10] = {0};
    copy_string(source, destination);
    printf("MOV (kopírování stringu): %s\n", destination);

    // Kopírování prvních dvou intů z pole
    int src[2] = {7, 42};
    int dest[2] = {0, 0};
    copy_two_ints(src, dest);
    printf("MOV (kopírování pole): %d %d\n", dest[0], dest[1]);

    return 0;
}

