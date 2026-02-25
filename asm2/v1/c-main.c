//***************************************************************************
//
//  @file c-main.c
//  @brief Hlavní C soubor pro demonstraci práce s instrukcemi
//  ADD, SUB, CMP, INC, DEC, NEG, AND, TEST, OR, XOR, NOT, SHL, SHR.
//
//  @author X<:3 )~ Ka
//
//  @details
//  Jedno z mnoha řešení pro zadané úkoly
//
//***************************************************************************

#include <stdio.h>
#include <stdint.h>

// Deklarace funkcí z Assembleru
void calculate_pay();
void check_pay();
void change_flags();

// Deklarace globálnách proměnných
uint32_t g_base_pay[10] = {42969, 37036, 41512, 58241, 47589, 60022, 56817, 49288, 37856, 38892}; // Základní mzda
uint32_t g_bonus_pay[10] = {2899, 8700, 6952, 5831, 7759, 5002, 4683, 7928, 3788, 2888};  // Osobní ohodnocení
uint32_t g_final_pay[10] = {0};  // sem ASM uloží výsledek
uint16_t g_flags = 0; // 10 bitů pro jednotlivé zaměstnance, 2 bity rezerva, 4 bity pro výsledek
uint16_t g_flags_v2 = 0xEB83;  // 2 bity rezerva, 4 bity pro výsledek, 10 bitů pro jednotlivé zaměstnance

int main() {

    printf("\n=== 1) Funkce pro výpočet mezd zaměstanců ve firmě ===\n");

    calculate_pay();  // ASM funkce, která sečte základní mzdu + osobní ohodnocení, 
                      // z toho vypočítá ¼, kterou odečte jako daň a výsledek uloží do globální proměnné.

    for (int i = 0; i < 10; i++) {
      printf("Základ: %d + bonus: %d - daně ¼ = celkem: %d \n", g_base_pay[i], g_bonus_pay[i], g_final_pay[i]);
    }

    printf("\n=== 2) Funkce pro kontrolu podprůměrné mzdy ===\n");
    check_pay();  // ASM funkce, která projde základní mzdy zaměstnanců, 
                  // pokud je jeho základní mzda menší jak 45 tisíc, nastaví odpovídající bit na 1. 
                  // Zároveň spočítá počet bitů nastavených na 1 a tuto hodnotu uloží na nejnižší 4 bity

    printf("Výsledek g_flags v hexa formátu: 0x%04X\n", g_flags);
    printf("\n===3) Funkce, která upraví význam jednotlivých bitů===\n");

    printf("Původní g_flags_2 v hexa formátu: 0x%04X\n", g_flags_v2);

    change_flags(); // Invertuje všechny bity.
                    // Zarotuje bity tak, aby se 10 bitů pro zaměstnace a 4 bity pro výsledek dostaly do správné pozice,
                    // 2 rezervní bity nastaví na 1
                    // Invertuje pouze 12 nejvyšších bitů.

    printf("Po změně g_flags_v2 v hexa formátu: 0x%04X\n", g_flags_v2);

    return 0;

}

