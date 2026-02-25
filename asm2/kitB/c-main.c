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
void calc_diff(void);
void calc_avg_temp(void);
void check_high_temp(void);
void change_flags(void);

// Deklarace globálnách proměnných
int8_t g_temp_indoor[16] = { 18, 19, 22, 23, 17, 21, 24, 26, 28, 23, 25, 22, 19, 24, 25, 16 };
int8_t g_temp_outdoor[16] = { -4, 0, 7, 12, -2, 5, 15, 23, 30, 27, 20, 8, -1, 13, 26, 13 };
int16_t g_temp_diff[16] = {0};
int8_t g_avg_temp = 0;
uint32_t g_flags = 0;
uint32_t g_flags_v2 = 0x000C00C2;


int main() {

  printf("\n=== 1) Funkce pro výpočet rozdílu teplot uvnitř a venku ===\n");

  calc_diff();  // ASM funkce, která projde teploty uvnitř a venku a spočítá rozdíl, který uloží do globální proměnné.
  for (int i = 0; i < 16; i++) {
    printf("Teplota uvnitř: %d venku: %d - rozdíl: %d\n", g_temp_indoor[i], g_temp_outdoor[i], g_temp_diff[i]);
  }

  printf("\n=== 2) Funkce pro výpočet (B - venkovní) průměrné teploty za 16 dní ===\n");

  calc_avg_temp();  // ASM funkce, která projde teploty, sečte je
                    // pomocí bitového posunu vydělí 16 a uloží do globální proměnné

  printf("Průměrná teplota: %d\n", g_avg_temp);

  printf("\n=== 3-B) Funkce pro detekci horkých dní ===\n");

  check_high_temp();  // ASM funkce, která projde teploty, 
                      // pokud je teplota vyšší než 25 stupňů, nastaví odpovídající bit na 1. 
                      // Zároveň spočítá počet bitů nastavených na 1 a tuto hodnotu uloží na nejnižší 4 bity

  printf("Výsledek g_flags v hexa formátu: 0x%08X\n", g_flags);

  printf("\n=== 4) Funkce, která upraví význam jednotlivých bitů ===\n");

  printf("Původní g_flags_2 v hexa formátu: 0x%08X\n", g_flags_v2);

  change_flags(); // Invertuje všechny bity.
                  // Prohodí horních a spodních 16 bitů,
                  // bity 4-15 nastaví na 0
                  // Invertuje pouze 16 nejvyšších bitů.
  
  printf("Po změně g_flags_v2 v hexa formátu: 0x%08X\n", g_flags_v2);

  return 0;

}

