#pragma once
#include <stdint.h>

#ifndef SHINOBU_KISS_PRNG_H
#define SHINOBU_KISS_PRNG_H

void randk_seed(void);
uint64_t randk(void);
void randk_warmup(int rounds);

#endif // SHINOBU_KISS_PRNG_H