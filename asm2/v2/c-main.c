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
void calculate_avg8y();
void check_low_player();
void change_flags();

// Deklarace globálnách proměnných
uint8_t g_goals[10]   = {92, 103, 112, 59, 90, 110, 120, 136, 76, 67}; // Počet gólů za 8 let
uint8_t g_assists[10] = {108, 137, 104, 101, 118, 146, 136, 120, 116, 141}; // Počet asistencí za 8 let
uint16_t g_avg8y[10] = {0};  // sem ASM uloží výsledek
uint16_t g_flags = 0; // 10 bitů pro jednotlivé hráče, 2 bity rezerva, 4 bity pro výsledek
uint16_t g_flags_v2 = 0xF043;  // 2 bity rezerva, 4 bity pro výsledek, 10 bitů pro jednotlivé hráče

int main() {

    printf("\n=== 1) Funkce pro výpočet průměrných statistik hokejistů za 8 let ===\n");

    calculate_avg8y();  // ASM funkce, která sečte počet gólů a počet asistencí
                        // výsledek pomocí bitového posunu vydělí 8 a uloží do globální proměnné.
    for (int i = 0; i < 10; i++) {
      printf("Počet gólů: %d + počet asistencí: %d za 8 let - tvoří průměr: %d ročně\n", g_goals[i], g_assists[i], g_avg8y[i]);
    }

    printf("\n=== 2) Funkce pro detekci mizerných hráčů ===\n");

    check_low_player();  // ASM funkce, která projde počet gólů, 
                         // pokud je počet menší jak 80, nastaví odpovídající bit na 1. 
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

