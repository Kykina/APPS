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
void calc_grades(void);
void change_flags(void);

// Deklarace globálnách proměnných
uint8_t g_credit[16] = {26, 33, 42, 34, 29, 36, 25, 41, 34, 25, 29, 28, 38, 25, 32, 38}; // Zápočty
uint8_t g_exam[16] = {20, 36, 55, 46, 41, 35, 28, 52, 33, 0, 0, 36, 38, 40, 31, 34};  // Zkoušky
unsigned char g_grade[16] = {0};  // sem ASM uloží výsledek
uint64_t g_count_grades = 0;
uint64_t g_count_grades_v2 = 0x0000020004060103;  // 0x0200040601030000

int main() {

  printf("\n=== 1)  Funkce pro výpočet ECTS známky ===\n");

  study_results();  // ASM funkce, která sečte body za zápočet + výsledek zkoušky, vyhodnotí počet bodů podle ECTS:
                    // A	91-100
                    // B	81-90
                    // C	71-80
                    // D	61-70
                    // E	51-60
                    // F	0-50
                    // a uloží výslednou známku do globální proměné g_grade jako znak 'A' až 'F'
  for (int i = 0; i < 16; i++) {
    printf("Zápočet: %d + zkouška: %d = známka: %c\n", g_credit[i], g_exam[i], g_grade[i]);
  }

  printf("\n=== 2) Funkce která spočítá počet známek ===\n");

  calc_grades();  // ASM funkce, která projde známky studentů, 
                  // pro každou známku je vyhrazený 1 byte. 

  printf("Výsledek g_count_grades v hexa formátu: 0x%016lX\n", g_count_grades);


  printf("\n=== 3) Funkce, která upraví význam jednotlivých bitů ===\n");

  printf("Původní g_count_grades_2 v hexa formátu: 0x%016lX\n", g_count_grades_v2);

  change_flags(); // Invertuje všechny bity.
                  // Prohodí horních a spodních 16 bitů,
                  // bity 4-15 nastaví na 0
                  // Invertuje pouze 16 nejvyšších bitů.
  
  printf("Po změně g_count_grades_v2 v hexa formátu: 0x%016lX\n", g_count_grades_v2);

  return 0;

}

