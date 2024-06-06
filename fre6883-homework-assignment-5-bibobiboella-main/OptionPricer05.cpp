#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"
#include "DoubDigitOpt.h"
#include "Butterfly.h"
#include "Strangle.h"
using namespace std;
using namespace fre;
int main(){ 
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K1 = 100, K2 = 110;
    
    BinomialTreeModel Model(S0, U, D, R);
    
    DoubDigitOpt doubDigitOpt(N, K1, K2);
    OptionCalculation optCalculation(&doubDigitOpt);
    cout << "European double digit option price = " << fixed << setprecision(2) << optCalculation.PriceByCRR(Model) << endl;
    
    Strangle strangle(N, K1, K2);
    OptionCalculation strangleOptCalculation(&strangle);
    cout << "European strangle option price = " << fixed << setprecision(2) << strangleOptCalculation.PriceByCRR(Model) << endl;
    
    Butterfly butterfly(N, K1, K2);
    OptionCalculation butterflyOptCalculation(&butterfly);
    cout << "European butterfly option price = " << fixed << setprecision(2) << butterflyOptCalculation.PriceByCRR(Model) << endl;
    
    return 0;
}

/* 

    int N = 8;

    double U = 1.15125, D = 0.86862, R = 1.00545;

    double S0 = 106.00, K1 = 100, K2 = 110;

*/

/*

European double digit option price = 0.26

European strangle option price = 28.39

European butterfly option price = 1.04

What my code got:
European double digit option price = 0.26
European strangle option price = 28.39
European butterfly option price = 1.04

*/