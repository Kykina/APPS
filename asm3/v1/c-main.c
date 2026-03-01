//***************************************************************************
//
//  @file c-main.c
//  @brief Hlavní C soubor pro cvičení 3v1
//
//  @author X<:3 )~ Ka
//
//***************************************************************************


#include <stdio.h>
#include <stdint.h>

int obvod_trojuhelniku(int t_strana_a, int t_strana_b, int t_strana_c);
int maximum(int *t_array, int t_N);
int count_item(int *t_array, int t_N, int t_item);
unsigned int get_network_address(unsigned int t_IP, int t_mask);

static void print_ip(uint32_t t_ip)
{
    printf("%u.%u.%u.%u",
           (t_ip >> 24) & 0xFF,
           (t_ip >> 16) & 0xFF,
           (t_ip >>  8) & 0xFF,
           (t_ip >>  0) & 0xFF);
}

int main(void)
{
    // 1) obvod trojuhelniku
    int a = 3, b = 4, c = 5;
    int o = obvod_trojuhelniku(a, b, c);
    printf("Obvod trojuhelniku (%d,%d,%d) = %d\n", a, b, c, o);

    a = -3;
    o = obvod_trojuhelniku(a, b, c);
    printf("Obvod trojuhelniku (%d,%d,%d) = %d\n", a, b, c, o);


    // 2) maximum v poli
    int g_arr[] = { 7, -2, 15, 15, 0, 9, -100, 3, 42, 15, 33, 20 };
    int N = (int)(sizeof(g_arr) / sizeof(g_arr[0]));
    int max = maximum(g_arr, N);
    printf("Maximum v poli = %d\n", max);

    // 3) count_item
    int item = 15;
    int cnt = count_item(g_arr, N, item);
    printf("Prvek %d se v poli vyskytuje %dx\n", item, cnt);

    // 4) network address (IP + /mask)
    uint32_t ip = (192u<<24) | (168u<<16) | (  1u<<8) | 123u; // 192.168.1.123
    int mask = 26;
    uint32_t net = get_network_address(ip, mask);

    printf("IP: ");  print_ip(ip);
    printf(" /%d -> sit: ", mask);
    print_ip(net);
    printf("\n");

    return 0;
}
