#include "Strangle.h"
namespace fre {
    double Strangle::Payoff(double z) const
    {
        if (z <= K1) return K1 - z;
        if (z > K2) return z - K2;
        return 0.0;
    }
}