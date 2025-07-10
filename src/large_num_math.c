#include "better_types.h"
#include <stdlib.h>
#include <string.h>

large_num reduce_ln(large_num input){
    /* reduces the bd to scientific notation*/
    large_num output = input;
    while(output.coeff.int_part >= 10){

        memmove(&output.coeff.frac_part[1], &output.coeff.frac_part[0], (PRECISION - 1) * sizeof(output.coeff.frac_part[0]));
        output.coeff.frac_part[0] = output.coeff.int_part % 10;
        output.coeff.int_part /= 10;
        output.pow ++;         
    }
    return output;
}

large_num prod_ln(large_num A, large_num B){
    large_num output;
    output.coeff = prod_bd(A.coeff,B.coeff);
    output.pow = A.pow + B.pow;
    output = reduce_ln(output);
    return output;
}