//***************************************************************************
//  @file c-main.c
//  @brief Hlavní C soubor pro demonstraci: volání ASM funkcí, parametry, 
//  návraty, ukazatele, nepřímé adresování, skoky, cykly, složené podmínky.
//  @author X<:3 )~ Ka
//***************************************************************************

#include <stdio.h>
#include <stdint.h>

/* --- sada funkcí z předchozího cvičení, ale s parametry místo globálů --- */
void add_points(int *score, int add);
void use_credit(int *credit, int cost);
int  check_temp(int temp_c);                  // 1 = mrzne, 0 = nemrzne
void inc_packets(int *packets);
void dec_attempt(int *attempts);
void invert_balance(int *balance);
uint32_t mask_value_u32(uint32_t value, uint32_t mask);  // návratová hodnota
int  is_even(int number);                     // 1 = sudé, 0 = liché
void enable_feature(uint32_t *flags, uint32_t mask);
void toggle_led(uint32_t *led, uint32_t mask);
uint32_t invert_bits_u32(uint32_t x);          // návratová hodnota
int  multiply_by_two(int x);                   // návratová hodnota
int  divide_by_two(int x);                     // návratová hodnota
int  if_negative(int x);                       // 1 = záporné, 0 = nezáporné
void loop_down_to_zero(int *counter);          // while(counter>0) counter--


int main(void)
{
    int score = 10;
    int credit = 100;
    int temp = -5;
    int packets = 0;
    int attempts = 3;
    int balance = -50;
    uint32_t value = 0xABCD;
    int number = 6;
    uint32_t flags = 0x3100;
    uint32_t led = 0xF0F0;
    uint32_t mask = 0xAAAAAAAA;
    int counter = 5;

    int a[] = { 10, -5, 3, -1, 7, 0, -9, 12 };
    long n = (long)(sizeof(a) / sizeof(a[0]));

    printf("\n=== ADD (parametry přes pointer) ===\n");
    printf("Score: %d\n", score);
    add_points(&score, 5);
    printf("// Přičtení 5 bodů\n");
    printf("Score: %d\n", score);

    printf("\n=== SUB (parametry přes pointer) ===\n");
    printf("Credit: %d\n", credit);
    use_credit(&credit, 10);
    printf("// Odečtení 10 kreditů\n");
    printf("Credit: %d\n", credit);

    printf("\n=== CMP (návratová hodnota) ===\n");
    printf("Teplota: %d°C => Mrzne? %d\n", temp, check_temp(temp));
    temp = 10;
    printf("Teplota: %d°C => Mrzne? %d\n", temp, check_temp(temp));

    printf("\n=== INC/DEC (pointer in/out) ===\n");
    printf("Packets: %d\n", packets);
    inc_packets(&packets);
    printf("// INC packets\nPackets: %d\n", packets);

    printf("Attempts: %d\n", attempts);
    dec_attempt(&attempts);
    printf("// DEC attempts\nAttempts: %d\n", attempts);

    printf("\n=== NEG (pointer in/out) ===\n");
    printf("Balance: %d\n", balance);
    invert_balance(&balance);
    printf("// NEG balance\nBalance: %d\n", balance);

    printf("\n=== AND (návratová hodnota) ===\n");
    printf("Value: 0x%08X\n", value);
    value = mask_value_u32(value, 0xFF00);
    printf("// value & 0xFF00\nValue: 0x%08X\n", value);

    printf("\n=== TEST (návratová hodnota) ===\n");
    number = 6;
    printf("Number: %d => even? %d\n", number, is_even(number));
    number = 11;
    printf("Number: %d => even? %d\n", number, is_even(number));

    printf("\n=== OR/XOR (pointer in/out) ===\n");
    printf("Flags: 0x%08X\n", flags);
    enable_feature(&flags, 0b10000001);
    printf("// OR mask 0b10000001\nFlags: 0x%08X\n", flags);

    printf("LED:   0x%08X\n", led);
    toggle_led(&led, 0xFF);
    printf("// XOR mask 0xFF\nLED:   0x%08X\n", led);

    printf("\n=== NOT (návratová hodnota) ===\n");
    printf("Mask:  0x%08X\n", mask);
    mask = invert_bits_u32(mask);
    printf("// NOT mask\nMask:  0x%08X\n", mask);

    printf("\n=== SHL/SHR (návratové hodnoty) ===\n");
    value = 12;
    printf("Value: %u\n", value);
    value = (uint32_t)multiply_by_two((int)value);
    printf("// *2 (SHL)\nValue: %u\n", value);
    value = (uint32_t)divide_by_two((int)value);
    printf("// /2 (SHR)\nValue: %u\n", value);

    printf("\n=== Podmíněný skok ===\n");
    printf("if_negative(%d) = %d\n", -3, if_negative(-3));
    printf("if_negative(%d) = %d\n",  5, if_negative(5));

    printf("\n=== Cyklus (while přes skoky) ===\n");
    printf("Counter start: %d\n", counter);
    loop_down_to_zero(&counter);
    printf("// while(counter>0) counter--\nCounter end: %d\n", counter);

    return 0;
}
