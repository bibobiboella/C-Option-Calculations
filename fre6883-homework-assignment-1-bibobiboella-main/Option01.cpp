#include "Option01.h"
#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre {
    double PriceByCRR(double S0, double U, double D, double R, unsigned int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double Price[N+1];
        for (unsigned int i = 0; i < sizeof(Price) / sizeof(Price[0]); i++)
            Price[i] = 0.0;

        for (unsigned int i = 0; i <= N; i++)
        {
            Price[i] = CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }
        for (int n = N - 1; n >= 0; n--)
        {
            for (int i = 0; i <= n; i++)
            {
                Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / R;
            }
        }
        return Price[0];
    }
    
    //HW1 given CRR equation
    double PriceByCRRMod(double S0, double U, double D, double R, unsigned int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double currentPrice = 0;
        unsigned int NFac = 1;
        unsigned int iFac = 1;
        
        for (unsigned int j = 1; j <= N; j++){
            NFac *= j;
        }
        unsigned int NMinusiFac = NFac;
        
        
         for (unsigned int i = 0; i <= N; i++)
        {
            if(i != 0){
                iFac *= i;
                NMinusiFac /= (N - i + 1);
            }
            currentPrice += (NFac / (iFac * NMinusiFac) )
            *pow(q, i)*pow(1 - q, N - i)
            *CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }
        currentPrice *= 1 / pow(R,N);
        return currentPrice;
        
    }

    double CallPayoff(double z, double K)
    {
        if (z > K) return z - K;
        return 0.0;
    }
}
