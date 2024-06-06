// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003
//

#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp


#include "EuropeanOption.hpp"
#include <math.h>
#include <iostream>
#include <cstring>

//////////// Gaussian functions /////////////////////////////////

double EuropeanOption::n(double x) const
{ 

	double A = 1.0/sqrt(2.0 * 3.1415);
	return A * exp(-x*x*0.5);

}

double EuropeanOption::N(double x) const
{ // The approximation to the cumulative normal distribution


	double a1 = 0.4361836;
	double a2 = -0.1201676;
	double a3 = 0.9372980;

	double k = 1.0/(1.0 + (0.33267 * x));
	
	if (x >= 0.0)
	{
		return 1.0 - n(x)* (a1*k + (a2*k*k) + (a3*k*k*k));
	}
	else
	{
		return 1.0 - N(-x);
	}

}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice() const
{

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;


	return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));

}

double EuropeanOption::PutPrice() const
{

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));

}

double EuropeanOption::CallDelta() const
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;


	return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta() const
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * (N(d1) - 1.0);
}



/////////////////////////////////////////////////////////////////////////////////////
/*
void EuropeanOption::init()
{	// Initialise all default values

	// Default values
	r = 0.08;
	sig= 0.30;
	K = 65.0;
	T = 0.25;
	U = 60.0;		// U == stock in this case
	b = r;			// Black and Scholes stock option model (1973)

	optType = "C";		// European Call Option (this is the default type)



}


void EuropeanOption::copy(const EuropeanOption& o2)
{

	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	U	= o2.U;
	b	= o2.b;
	
	optType = o2.optType;


	
}
*/


EuropeanOption::EuropeanOption(double r_, double sig_, double K_, 
	double T_, double U_, double b_, char *optType_): 
	r(r_), sig(sig_), K(K_), T(T_), U(U_), b(b_)
	
{ // Default call option

	//init();
	optType = new char[strlen(optType_) + 1];
	strcpy(optType, optType_);
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2): r(o2.r), sig(o2.sig), K(o2.K), 
	 T(o2.T),  U(o2.U),  b(o2.b)
{ // Copy constructor
optType = new char[strlen(o2.optType) + 1];
strcpy(optType, o2.optType);
	
}

/*
EuropeanOption::EuropeanOption (const string& optionType)
{	// Create option type

	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";

}

*/

EuropeanOption::~EuropeanOption()
{
	//dynamic allocation
	if (optType){
		delete [] optType;
		optType = nullptr;
	}

}

const char* EuropeanOption:: GetOptType(){
	//get the optType in main() function. 
	//return optType;
	if (strcmp(optType, "C") == 0)
		return "Call";
	else
		return "Put";
}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

	if (this == &option2) return *this;

	//copy (option2);
	r = option2.r;
	sig = option2.sig;
	K = option2.K;
	T = option2.T;
	U = option2.U;
	b = option2.b;
	optType = new char[strlen(option2.optType) + 1];
	strcpy(optType,option2.optType);

	return *this;
}



// Functions that calculate option price and sensitivities
double EuropeanOption::Price() const 
{

	if (strcmp(optType, "C") == 0)
	{
		return CallPrice();
	}
	else
		return PutPrice();

}

double EuropeanOption::Delta() const 
{
	if (strcmp(optType, "C") == 0)
		return CallDelta();
	else
		return PutDelta();

}



// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

	if (strcmp(optType, "C") == 0)
		strcpy(optType, "P");
	else
		strcpy(optType, "C");
}

#endif
