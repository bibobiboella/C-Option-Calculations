#include <iostream>
#include <iomanip>
using namespace std;

class DefInt{
    private:
    double a, b;
    double(*f)(double x);
    
    public:
    DefInt(double a_, double b_, double(*f_)(double x)): a(a_), b(b_), f(f_){}
    
    double ByTrapzoid(int N){
        double cumf = 0;
        double h = (b - a)/N;
        for (int k = 1; k <= N; k++){
            double xkMinus1 = a + (k - 1) * h;
            double xk = a + k * h;
            cumf += (f(xk) + f(xkMinus1));
        }
         return (h / 2) * cumf;
        
    }
    
    double BySimpson(int N){
        return (b - a)/6 * (f(a) + 4 * f((a + b) / 2) + f(b));
    }
};

int main()
{
    //example from the slide
	double (*f)(double x) = [](double x) {return x*x*x - x*x + 1;};
	int N = 1000;
	double a = 1.0; 
	double b = 2.0;
	
	DefInt MyInt(a, b, f);
	cout << "actual value is: 2.41666..." << endl;
	cout << "calculate by trapazoid: " << MyInt.ByTrapzoid(N) << setprecision(6) << endl;
	cout << "calculate by simpson: " << MyInt.BySimpson(N) << setprecision(6) << endl;


	//another example
	double (*f1)(double x) = [](double x) {return (x*x*x/4) * 2*x + 1;};
	
	DefInt MyInt1(a, b, f1);
	cout << "actual value is: 4.1" << endl;
	cout << "calculate by trapazoid: " << MyInt1.ByTrapzoid(N) << setprecision(6) << endl;
	cout << "calculate by simpson: " << MyInt1.BySimpson(N) << setprecision(6) << endl;
	
/*
actual value is: 2.41666...
calculate by trapazoid: 2.41667
calculate by simpson: 2.41667
actual value is: 4.1
calculate by trapazoid: 4.1
calculate by simpson: 4.10417
*/
}