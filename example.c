#include<stdio.h>
#include<stdlib.h>
#include"better_types.h"

large_num factorial_of(size_t input){

    large_num output = {assign_bd(1), 0};
    
    for(size_t i = 1; i <= input ; i++){
        large_num iter = {assign_bd(i),0};
        output = prod_ln(iter,output);
        output = reduce_ln(output);
    }
    return output;
}

int main(){

    int to_fac;
    printf("input a number to take the factoral of: ");
    scanf("%d", &to_fac);
    if (to_fac < 0){
        printf("factorial of negative numbers is not defined\n");
        return 1;
    }
    if (to_fac > 100000){
        printf("you're killing me martha\n");
        return 1;
    }
    large_num result = factorial_of(to_fac);
    printf("the factorial of %d is ", to_fac);
    print_bd(result.coeff);
    printf(" * 10^%lld \n", result.pow);

    return 0;
}