#pragma once
#include <cmath>
namespace fre {
class Function
{
public:
    virtual double Value(double x) = 0;
    virtual double Deriv(double x) = 0;
    virtual ~Function() {}
};

class HW8PVFunc : public Function
{
private:
//need coupon, yield, Tn(maturity), calculate how much get back from maturity.
    double coupon;
    double FV; //fave value
    double Tn; //maturity time
public:
    HW8PVFunc(double coupon_, double FV_, double Tn_): coupon(coupon_), FV(FV_), Tn(Tn_){}
    double Value(double yield){
        double PV = FV * exp(-yield * Tn);
        for (int i = 1; i <= Tn; i++){
            PV += coupon * exp(-yield * i);
        }
        return PV;
    }; 
    double Deriv(double yield){
        double dPV = -Tn * FV * exp(-yield * Tn);
        for (int i = 1; i <= Tn; i++){
            dPV += -i * coupon * exp(-yield * i);
        }
        return dPV;
    }; 
};

}