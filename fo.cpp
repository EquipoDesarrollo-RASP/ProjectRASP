#include "fo.h"

double FuzzyOperator::FuzzyAND(double var1, double var2){

    if(var1 <= var2){
        return var1;
    }else{
        return var2;
    }
}

double FuzzyOperator::FuzzyOR(double var1, double var2){

    if(var1 >= var2){
        return var1;
    }else{
        return var2;
    }
}

double FuzzyOperator::FuzzyNOT(double var1){

    return (1.0 - var1);
}
