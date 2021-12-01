#include <iostream>
#include <cstdio>
#include <time.h>
#define NUM 1000000
using namespace std;

bool is_prime[NUM + 1];
int main() {
    clock_t start, end;
    double duration;
    start = clock();
    for (int m = 2; m < NUM; m++) {
        is_prime[m] = true;
    }
    for(int i = 2; i <= NUM; i++) {
        if(is_prime[i]) {
            for(int j = 2 * i; j < NUM; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= NUM; i++) {
        if(is_prime[i]) {
            printf("%d\n", i);
        }
    }
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f seconds.\n", duration);
    return 0;
}
