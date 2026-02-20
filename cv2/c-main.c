//***************************************************************************
//
//  @file c-main.c
//  @brief Hlavní C soubor pro demonstraci práce s instrukcemi:
//  ADD, SUB, CMP, INC, DEC, NEG, AND, TEST, OR, XOR, NOT, SHL, SHR.
//
//  @author X<:3 )~ Ka
//
//  @details
//  Praktické využití různých instrukcí, ukázka jednoduhé podmínky a cyklu.
//
//***************************************************************************

#include <stdio.h>
#include <stdint.h>

/* Globální proměnné */

int g_score = 10;
int g_credit = 100;
int g_temperature = -5;
int g_packets = 0;
int g_attempts = 3;
int g_balance = -50;
int g_value = 0xABCD;
int g_number = 6;
int g_flags = 0x3100;
int g_led = 0xF0F0;
int g_mask = 0xAAAAAAAA;
int g_counter = 5;

/* ASM funkce */

void add_points();
void use_credit();
int  check_temp();
void inc_packets();
void dec_attempt();
void invert_balance();
void mask_value();
int  is_even();
void enable_feature();
void toggle_led();
void invert_bits();
void multiply_by_two();
void divide_by_two();
int  if_negative();
void loop_demo();

int main(void)
{
    printf ("\n=== ADD  ===\n");
    printf("Score: %d\n", g_score);
    add_points();
    printf ("// Přičtení 5 bodů\n");
    printf("Score: %d\n", g_score);

    printf ("\n=== SUB ===\n");
    printf("Credit: %d\n", g_credit);
    use_credit();
    printf ("// Využití 10 kreditů - odečtení\n");
    printf("Credit: %d\n", g_credit);

    printf ("\n=== CMP ===\n");
    printf("Mrzne? 1 - ano, 0 - ne: %d\n", check_temp());
    g_temperature = 10;
    printf("Mrzne? 1 - ano, 0 - ne: %d\n", check_temp());

    printf ("\n=== INC ===\n");
    printf("Packets: %d\n", g_packets);
    inc_packets();
    printf ("// Inkrementace paketů\n");
    printf("Packets: %d\n", g_packets);
    
    printf ("\n=== DEC ===\n");
    printf("Zbývá: %d pokusů\n", g_attempts);
    dec_attempt();
    printf ("// Sníží počet pokusů\n");
    printf("Zbývá: %d pokusů\n", g_attempts);

    printf ("\n=== NEG ===\n");
    printf("Na účtu máte: %d Kč\n", g_balance);
    invert_balance();
    printf("// Neguje stav na účtu - mění znaménko\n");
    printf("Na účtu máte: %d Kč\n", g_balance);

    printf ("\n=== AND ===\n");
    printf("Původní hodnota v hexa formátu: 0x%04X\n", g_value);
    mask_value();
    printf("// Aplikuje masku 0xFF00\n");
    printf("Nová hodnota v hexa formátu: 0x%04X\n", g_value);

    printf ("\n=== TEST ===\n");
    printf("Je číslo: %d sudé? %d\n", g_number, is_even());
    g_number = 11;
    printf("Je číslo: %d sudé? %d\n", g_number, is_even());

    printf("\n=== OR ===\n");
    printf("Původní flagy v hexa formátu: 0x%04X\n", g_flags);
    enable_feature();
    printf("// Aplikuje OR 0b10000001 - nastaví 0. a 7. bit na 1\n");
    printf("Nové flagy po OR v hexa formátu: 0x%04X\n", g_flags);

    printf("\n=== XOR ===\n");
    printf("Stav LED v hexa formátu: 0x%04X\n", g_led);
    toggle_led();
    printf("// Aplikuje XOR 0xFF na LEDky - neguje bity 0. až 7.\n");
    printf("Stav LED po XOR v hexa formátu: 0x%04X\n", g_led);

    printf("\n=== NOT ===\n");
    printf("Původní hodnota v hexa formátu: 0x%04X\n", g_mask);
    invert_bits();
    printf("// Invertuje všechny bity\n");
    printf("Nový stav po NOT v hexa formátu: %X\n", g_mask);

    printf("\n=== SHL ===\n");
    g_value = 12;
    printf("Původní hodnota: %d\n", g_value);
    multiply_by_two();
    printf("// Krát dvě - bitový posun o 1 vlevo\n");
    printf("Výsledek po SHL: %d\n", g_value);

    printf("\n=== SHR ===\n");
    divide_by_two();
    printf("// Děleno dvěma - bitový posun o 1 vpravo\n");
    printf("Výsledek po SHR: %d\n", g_value);

    printf("\n=== Podmíněný skok ===\n");
    g_number = -3;
    printf("Je číslo: %d záporne?: %d\n", g_number, if_negative());
    g_number = 5;
    printf("Je číslo: %d záporne?: %d\n", g_number, if_negative());

    printf("\n=== Cyklus ===\n");
    printf("Počáteční stav počítadla: %d\n", g_counter);
    loop_demo();
    printf("// Cyklus běží\n");
    printf("Stav počítadla na konci cyklu: %d\n", g_counter);

    return 0;
}
