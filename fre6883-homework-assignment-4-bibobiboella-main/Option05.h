#pragma once
#include "BinomialTreeModel02.h"

namespace fre {
	class EurOption//base class
	{
	private:
		EurOption() : N(0) {}//default constructor
		EurOption(const EurOption& option) : N(option.N) {}
	protected:
		int N;
	public:
		EurOption(int N_) : N(N_) {}
		int GetN() const { return N; }
		virtual double Payoff(double z) const = 0; //Dynamic binding condition 1: must be virtual func
		
		
		//4. base class pointer/reference must be associated with a base/child class object/address
		virtual ~EurOption() = 0;
};

	class Call : public EurOption //child class
	{
	private:
		double K;
	public:
		Call(int N_, double K_) : EurOption(N_), K(K_) {} //can access N from parent class since it is protected
		~Call() {}
		double Payoff(double z) const; //2: must overwrite func
	};
	
	class Put : public EurOption //child class
	{
	private:
		double K;
	public:
		Put(int N_, double K_) : EurOption(N_) , K(K_) {} //constructor
		~Put() {} //destructor
		double Payoff(double z) const; //2: must overwrite func
	};
	
	//-------HW4: add bull spreads and bear spreads as new child class--------
	class BullSpread : public EurOption //child class
	{
	private:
		double K1;
		double K2;
	public:
		BullSpread(int N_, double K1_, double K2_) : EurOption(N_) , K1(K1_), K2(K2_)  {} //constructor
		~BullSpread() {} 
		double Payoff(double z) const; //2: must overwrite func
	};
	
	class BearSpread : public EurOption //child class
	{
	private:
		double K1;
		double K2;
	public:
		BearSpread(int N_, double K1_, double K2_) : EurOption(N_) , K1(K1_), K2(K2_)  {} //constructor
		~BearSpread() {} 
		double Payoff(double z) const; //2: must overwrite func
	};
	
	
	
	class OptionCalculation
	{
	private:
		EurOption* pOption; //base class pointer
		OptionCalculation() : pOption(0) {}
		OptionCalculation(const OptionCalculation& optionCalculation): pOption(optionCalculation.pOption) {} //???
	public:
		OptionCalculation(EurOption* pOption_) : pOption(pOption_) {}
		~OptionCalculation() {}
		double PriceByCRR(const BinomialTreeModel& model);
	};
}