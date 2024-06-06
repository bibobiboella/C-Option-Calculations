// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <cstring>
#include <math.h>

int main()
{
	/*
	// Call option on a stock
	EuropeanOption callOption;
	cout << "Call option on a stock: " << callOption.Price() << endl;
	cout << "Delta on a call option: " << callOption.Delta() << endl;

	// Put option on a stock index
	EuropeanOption indexOption;
	indexOption.optType = "P";
	indexOption.U = 100.0;
	indexOption.K = 95.0;
	indexOption.T = 0.5;
	indexOption.r = 0.10;
	indexOption.sig = 0.20;

	double q = 0.05;		// Dividend yield
	indexOption.b = indexOption.r - q;

	cout << "Put option on an index: " << indexOption.Price() << endl;
	cout << "Delta on a put option: " << indexOption.Delta() << endl;

*/

	double K1 = 65.0, U1 = 60.0, r1 = 0.08, sig1 = 0.3, T1 = 0.25;
	double b1 = r1;
	char * optType1 = strdup("C");
	EuropeanOption euroOpt1(r1, sig1, K1, T1, U1, b1, optType1);
	cout << "Q1: " << euroOpt1.GetOptType() << " option on a stock: " 
	<< euroOpt1.Price() << endl;
	
	
	
	//-------------HW9 Q2---------------
	double K2 = 50.0, U2 = 50.0, r2 = 0.1, sig2 = 0.3, T2 = 0.25;
	double b2 = r2;
	char * optType2 = strdup("P");
	EuropeanOption euroOpt2(r2, sig2, K2, T2, U2, b2, optType2);
	cout << "Q2: " << euroOpt2.GetOptType() << " option on a stock: " 
	<< euroOpt2.Price() << endl;
	
	
	//-------------HW9 Q3--------------- 1.5$divident in every t=2/12
	double dividend = 1.5;
	double U3 = U2 - dividend * exp(-r2 * 2/12);
	EuropeanOption euroOpt3(r2, sig2, K2, T2, U3, b2, optType2);
	cout << "Q3: " << euroOpt3.GetOptType() << " option on a stock: " 
	<< euroOpt3.Price() << endl;
	
	
	
	
	
	return 0;
	
	//output:
	//Q1: Call option on a stock: 2.13293
	//Q2: Put option on a stock: 2.37561
	//Q3: Put option on a stock: 3.03039
}

