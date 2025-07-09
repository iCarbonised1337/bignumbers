#include "better_types.h"
#include<stdlib.h>
#include<math.h>

better_double assign_bd(value){
    better_double output = {0};
    output.int_part = (long) value;
    for(size_t i = 0; i < PRECISION; i++){
        output.frac_part[i] = (value - output.int_part) * pow(10, i);
        value -= output.frac_part[i] / pow(10, i); 
    }
    return output;
}

void print_bd(better_double input){
    printf("%lld", input.int_part);
    for(size_t i = 0; i<PRECISION ; i++){
        printf("%d",input.frac_part[i]);
    }
    printf("\n");
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
    /*returns the product of two better_double numbers*/
    better_double output;
    better_double carry = {0};
    for(size_t i = PRECISION; i >=0; i--){
        output.frac_part[i] = A.frac_part[i] * B.frac_part[i] + carry.frac_part[i];

    }
}



better_double reduce_bd(better_double input){
    /* reduces the bd to scientific notation*/
    long integral_part = input.int_part;
    size_t length_of_int_part = 0;
    while(integral_part>10){
        integral_part /= 10;
        length_of_int_part++;
    }

}


// large_num reduce(large_num input){
//     int integral_part = input.coeff;
//     large_num input_buffer = input;
    
//     if (integral_part == 0){
//         input_buffer = input;
//     }
//     else{
//         while (integral_part >= 10){
//             integral_part/=10;
//             input_buffer.coeff/=10;
//             input_buffer.pow++;
//         }
//     }
//     return input_buffer;
// }

