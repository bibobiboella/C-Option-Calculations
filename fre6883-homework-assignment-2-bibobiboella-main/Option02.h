#pragma once

namespace fre {
	//check valid input N and K
	int GetInputData(int& N, double& K);
	
	//pricing European option, pass different types of payoff functions as argument
	double * PriceByCRR(double S0, double U, double D, double R, int N, 
	double K, double (*Payoff)(double z, double K));

	//computing call payoff
	double CallPayoff(double z, double K);
	
	//computing put payoff
	double PutPayoff(double z, double K);
	
	//HW2 Compute Digital call Payoff
	double DigitCallPayoff(double z, double K);
	
	//HW2 Compute Digital put Payoff
	double DigitPutPayoff(double z, double K);
}