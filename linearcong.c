// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define MOD 2147483647  // 2^31 - 1
#define MULTIPLIER 48271
#define INCREMENT 135743
#define SEED 1

unsigned long lcg(unsigned long seed) {
    return (MULTIPLIER * seed + INCREMENT) % MOD;
}

void initialize_lcg(unsigned long* seed_ptr) {
    *seed_ptr = SEED;
}

void generate_random_numbers(unsigned long* seed, unsigned long count, unsigned long min_value, unsigned long max_value) {
    printf("Generated random numbers:\n");
    for (unsigned long i = 0; i < count; i++) {
        unsigned long random_number = lcg(*seed);
        printf("%lu ", random_number);
        *seed = random_number;
    }
    printf("\n");
}

int main() {
    unsigned long seed;
    unsigned long count, min_value, max_value;

    printf("Enter the number of random numbers to generate: ");
    scanf("%lu", &count);

    printf("Enter minimum value: ");
    scanf("%lu", &min_value);

    printf("Enter maximum value: ");
    scanf("%lu", &max_value);

    initialize_lcg(&seed);

    generate_random_numbers(&seed, count, min_value, max_value);

    return 0;
}
