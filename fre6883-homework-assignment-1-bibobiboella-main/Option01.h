#pragma once

namespace fre {
	//pricing European option
	double PriceByCRR(double S0, double U, double D, double R, unsigned int N, double K);
	
	//HW1 modified CRR function
	double PriceByCRRMod(double S0, double U, double D, double R, unsigned int N, double K);

	//computing call payoff
	double CallPayoff(double z, double K);
}