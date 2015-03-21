#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int rdrand16_step (uint16_t *rand)
{
    unsigned char ok;
    asm volatile ("rdrand %0; setc %1" : "=r" (*rand), "=qm" (ok));
    return (int)ok;
}

int rdrand32_step (uint32_t *rand)
{
    unsigned char ok;
    asm volatile ("rdrand %0; setc %1" : "=r" (*rand), "=qm" (ok));
    return (int)ok;
}

int rdrand64_step (uint64_t *rand)
{
    unsigned char ok;
    asm volatile ("rdrand %0; setc %1" : "=r" (*rand), "=qm" (ok));
    return (int)ok;
}

int main (int argc, char *argv[])
{
    uint16_t t0 = 0;
    rdrand16_step(&t0);
    printf("uint16: %" PRIu16 "\n", t0);

    uint32_t t1 = 0;
    rdrand32_step(&t1);
    printf("uint32: %" PRIu32 "\n", t1);

    uint64_t t2 = 0;
    rdrand64_step(&t2);
    printf("uint64: %" PRIu64  "\n", t2);

    return 0;
}
