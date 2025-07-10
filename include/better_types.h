#ifndef BETTER_TYPES_H
#define BETTER_TYPES_H

#include<stdint.h>

#define PRECISION 100

struct better_double{
    long int_part;
    uint_fast8_t frac_part[PRECISION];
} typedef better_double;

struct large_num{
    better_double coeff;
    long long pow;
} typedef large_num;


// function prototypes for arb precision arithmatic
better_double sum_bd(better_double a, better_double b);

better_double prod_bd(better_double a, better_double b);

better_double assign_bd(value);

void print_bd(better_double input);

large_num reduce_ln(large_num input);

large_num prod_ln(large_num input);

large_num print_ln(large_num input);


#endif