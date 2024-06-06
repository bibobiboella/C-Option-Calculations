#include "Function02.h"
#include "NonlinearSolver02.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace fre;

int main(){ 
 double F=100.0;    
 double T=3.0;    
 double C=1.2;    
 double P=98.56;

 double Acc=0.0001;    
 double LEnd=0.0;    
 double REnd=1.0;    
 double Guess=0.2;
 
 

 NonlinearSolver nonlinear(P, LEnd, REnd, Acc, Guess);
 HW8PVFunc F1(C, F, T);
 cout << "Yield by bisection method: " << setprecision(4)
 << nonlinear.SolveByBisect(& F1) <<  endl;
 cout << "Yield by Newton-Raphson method: " << setprecision(4) 
 << nonlinear.SolveByNR(& F1)  << endl;
 /*
  double F=100.0;    double T=3.0;    double C=1.2;    double P=98.56;

   double Acc=0.0001;    double LEnd=0.0;    double REnd=1.0;    double Guess=0.2;

Output:

Yield by bisection method: 0.0168 Yield by Newton-Raphson method: 0.0168
*/

}


