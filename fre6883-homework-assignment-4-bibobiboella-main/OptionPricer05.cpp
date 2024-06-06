#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.h"
#include "Option05.h"
using namespace std;
using namespace fre;
int main(){ 
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    double K1 = 100, K2 = 110;
    BinomialTreeModel Model(S0, U, D, R);
    
    
    Call call(N, K);
    OptionCalculation callCalculation(&call); //EurOption* pOption > &call
    cout << "European call = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
    
    
    Put put(N, K);
    OptionCalculation putCalculation(&put); //EurOption* pOption > &put
    cout << "European put = "<< fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
    
    BullSpread bull(N, K1, K2);
    OptionCalculation bullCalculation(&bull); 
    cout << "European bull spread = "<< fixed << setprecision(2) << bullCalculation.PriceByCRR(Model) << endl;
    
    BearSpread bear(N, K1, K2);
    OptionCalculation bearCalculation(&bear); 
    cout << "European bear spread = "<< fixed << setprecision(2) << bearCalculation.PriceByCRR(Model) << endl;
    
    
    return 0;
}
/*

int N = 8;

double U = 1.15125, D = 0.86862, R = 1.00545;

double S0 = 106.00, K = 100.00;

double K1 = 100, K2 = 110;

*/

/*

European call option price = 21.68

European put option price = 11.43

European bull spread option price = 4.72

European bear spread option price = 4.86


What my code got:

European call = 21.68
European put = 11.43
European bull spread = 4.72
European bear spread = 4.86
*/