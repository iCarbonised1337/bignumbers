#include"better_types.h"
#include<stdlib.h>
#include<stdio.h>

better_double assign_bd(long double input){
    // declare output
    better_double output = {0};
    // segregate integral and frac parts
    output.int_part = (long)input;
    double frac = input - output.int_part;

    for (size_t i = 0; i < PRECISION; ++i) {
        frac *= 10.0;
        int digit = (int)frac;          /* always 0–9 */
        output.frac_part[i] = (uint_fast8_t)digit;
        frac -= digit;                  /* keep only the remainder */
    }
    return output;
}

void print_bd(better_double input){
    size_t significance = PRECISION;
    for(size_t i = PRECISION-1; i != 0; i--){
        if(input.frac_part[i] != 0){
            break;
            significance--;
        }
    }
    printf("%ld", input.int_part);
    for(size_t i = 0; i<= significance; i++){
        printf("%d",input.frac_part[i]);
    }
}

better_double sum_bd(better_double A, better_double B){
    /*returns the sum of two better_double numbers*/
    better_double output = {0};
    unsigned carry = 0;
    for(int i = (PRECISION - 1); i >= 0; i--){
        unsigned tmp = A.frac_part[i] + B.frac_part[i] + carry;
        if(tmp>=10){    
            output.frac_part[i] = (tmp - 10);
            carry = 1;
        }    
        else{
            output.frac_part[i] = tmp;
            carry = 0; 
        }
    }
    
    output.int_part = A.int_part + B.int_part + carry;
    return output;

}

// to-do: think about how to handle multiplication of two better_double
better_double prod_bd(better_double A, better_double B){
    uint_fast8_t mult_buffer [2 * PRECISION] = {0};
    
    better_double output;
    unsigned int carry = 0;
    unsigned tmp = 0;

    for(size_t i = PRECISION - 1; i != 0; i--){
        carry = 0;
        for(size_t j = PRECISION - 1; j != 0; j--){

            tmp = A.frac_part[i] * B.frac_part[j] + carry;
            mult_buffer[j + i + 1] += tmp;
            carry = tmp / 10;
        }
        mult_buffer[i] += carry;
    }
    output.int_part = A.int_part * B.int_part + carry;
    for(size_t i = 0; i < PRECISION; i++ ){
        output.frac_part[i] = mult_buffer[i];
    }
    return output;
}


