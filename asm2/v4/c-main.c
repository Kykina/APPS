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
void study_results(void);
void check_study(void);
void change_flags(void);

// Deklarace globálnách proměnných
uint8_t g_credit[16] = {26, 33, 42, 34, 29, 36, 25, 41, 34, 25, 29, 28, 38, 25, 32, 38}; // Zápočty
uint8_t g_exam[16] = {20, 36, 55, 46, 41, 35, 28, 52, 33, 0, 0, 36, 38, 40, 31, 34};  // Zkoušky
uint8_t g_score[16] = {0};  // sem ASM uloží výsledek
uint8_t g_avg = 0;  // sem ASM uloží průměr
uint32_t g_flags = 0;
uint32_t g_flags_v2 = 0x000C8060;  // 80600003

int main() {

  printf("\n=== 1)  Funkce pro výpočet studijních výsledků ===\n");

  study_results();  // ASM funkce, která sečte body za zápočet + výsledek zkoušky, 
                    // výsledeky uloží do globální proměnné g_score.
                    // Zároveň sečte všechy výsledky a vypočítá průměr, který uloží do globální proměnné g_avg.
  for (int i = 0; i < 16; i++) {
    printf("Zápočet: %d + zkouška: %d = celkem: %d bodů\n", g_credit[i], g_exam[i], g_score[i]);
  }
  printf("Studijní průměr: %d\n", g_avg);

  printf("\n=== 2) Funkce pro detekci neúspěšných studentů ===\n");

  check_study();  // ASM funkce, která projde výsledky studentů, 
                  // pokud je výsledek menší než 51 bodů, nastaví odpovídající bit na 1. 
                  // Zároveň spočítá počet bitů nastavených na 1 a tuto hodnotu uloží na nejnižší 4 bity

  printf("Výsledek g_flags v hexa formátu: 0x%08X\n", g_flags);


  printf("\n=== 3) Funkce, která upraví význam jednotlivých bitů ===\n");

  printf("Původní g_flags_2 v hexa formátu: 0x%08X\n", g_flags_v2);

  change_flags(); // Invertuje všechny bity.
                  // Prohodí horních a spodních 16 bitů,
                  // bity 4-15 nastaví na 0
                  // Invertuje pouze 16 nejvyšších bitů.
  
  printf("Po změně g_flags_v2 v hexa formátu: 0x%08X\n", g_flags_v2);

  return 0;

}

