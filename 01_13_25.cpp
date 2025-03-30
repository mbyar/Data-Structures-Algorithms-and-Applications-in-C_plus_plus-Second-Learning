//#include<iostream>
//using namespace std;
//enum signType{plus, minus};
//class currency
//{
//public:
//	currency(signType theSign = signType::plus,
//		unsigned long theDollars = 0,
//		unsigned int theCents = 0);
//	~currency(){}
//	void setValue(signType, unsigned long, unsigned int);
//	void setValue(double);
//	signType getSign() const { return sign; }
//	unsigned long getDollars() const { return dollars; }
//	unsigned int getCents() const { return cents; }
//	currency add(const currency&) const;
//	currency& increment(const currency&);
//	void output() const;
//private:
//	signType sign;
//	unsigned long dollars;
//	unsigned int cents;
//};
//currency::currency(signType thesign, unsigned long theDollars, unsigned int theCents)
//{
//	setValue(thesign, theDollars, theCents);
//}
//void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
//{
//	if (theCents > 99)
//		throw /*illegalParameterValue*/("Cents should be < 100");
//	sign = theSign;
//	dollars = theDollars;
//	cents = theCents;
//}
//void currency::setValue(double theAmount)
//{
//	if (theAmount < 0) { sign = signType::minus; theAmount = -theAmount; }
//	else sign = signType::plus;
//	dollars = (unsigned long)theAmount;
//	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
//}
//currency currency::add(const currency& x)const
//{
//	long a1, a2, a3;
//	currency result;
//	a1 = dollars * 100 + cents;
//	if (sign == signType::minus)a1 = -a1;
//	a2 = x.dollars * 100 + x.cents;
//	if (x.sign == signType::minus)a2 = -a2;
//	a3 = a1 + a2;
//	if (a3 < 0) { result.sign = signType::minus; a3 = -a3; }
//	else result.sign = signType::plus;
//	result.dollars = a3 / 100;
//	result.cents = a3 - result.dollars * 100;
//	return result;
//}
//currency& currency::increment(const currency& x)
//{
//	*this = add(x);
//	return *this;
//}
//void currency::output()const
//{
//	if (sign == signType::minus)cout << '-';
//	cout << '$' << dollars << '.';
//	cout << cents;
//}
//int main()
//{
//	currency g, h(signType::plus, 3, 50), i, j;
//	g.setValue(signType::minus, 2, 25);
//	i.setValue(-6.45);
//	j = h.add(g);
//	h.output();
//	cout << "+";
//	g.output();
//	cout << "=";
//	j.output(); cout << endl;
//	j = i.add(g).add(h);
//	j = i.increment(g).add(h);
//	cout << "Attempting to initialize with cents = 152" << endl;
//	/*try { i.setValue(signType::plus, 3, 152); }
//	catch (illegalParameterValue e)
//	{
//		cout << "Caught thrown exception" << endl;
//		e.outputMessage();
//	}*/
//	return 0;
//}
#include<iostream>
using namespace std;
enum signType{plus, minus};
#ifndef Currency_
#define Currency_
class currency
{
	friend ostream& operator<<(ostream&, const currency&);
public:
	currency(signType theSign = signType::plus,
		unsigned long theDollars = 0,
		unsigned int theCents = 0);
	~currency(){}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const 
	{
		if (amount < 0) return signType::minus;
		else return signType::plus;
	}
	unsigned long getDollars() const
	{
		if (amount < 0)return (-amount) / 100;
		else return amount / 100;
	}
	unsigned int getCents() const
	{
		if (amount < 0)return -amount - getDollars() * 100;
		else return amount - getDollars() * 100;
	}
	currency add(const currency&) const;
	currency& increment(const currency&x)
	{
		amount += x.amount; return *this;
	}
	currency operator+(const currency&)const;
	currency& operator+=(const currency&x)
	{
		amount += x.amount; 
		return *this;
	}
	void output(ostream&) const;
private:
	long amount;
};
#endif
currency::currency(signType thesign, unsigned long theDollars, unsigned int theCents)
{
	setValue(thesign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw /*illegalParameterValue*/("Cents should be < 100");
	amount = theDollars * 100 + theCents;
	if (theSign == signType::minus)amount = -amount;
}
void currency::setValue(double theAmount)
{
	if (theAmount < 0)
		amount = (long)((theAmount - 0.001) * 100);
	else
		amount = (long)((theAmount + 0.001) * 100);
}
currency currency::add(const currency& x)const
{
	currency y;
	y.amount = amount + x.amount;
	return y;
}
currency currency::operator+(const currency& x)const
{
	currency result;
	result.amount = amount + x.amount;
	return result;
}
ostream& operator<<(ostream& out, const currency& x)
{
	long theAmount = x.amount;
	if (theAmount < 0)
	{
		out << '-';
		theAmount = -theAmount;
	}
	long dollars = theAmount / 100;
	out << '$' << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10)out << '0';
	out << cents;
	return out;
}
void currency::output(ostream& out)const
{
	long theAmount = amount;
	if (theAmount < 0)
	{
		out << '-';
		theAmount = -theAmount;
	}
	long dollars = theAmount / 100;
	out << '$' << dollars << '.';
	int cents = theAmount - dollars * 100;
	if (cents < 10)out << '0';
	out << cents;
}
//ostream& operator<<(ostream& out, const currency& x)
//{
//	x.output(out);
//	return out;
//}
int main()
{
	currency g, h(signType::plus, 3, 50), i, j;
	g.setValue(signType::minus, 2, 25);
	i.setValue(-6.45);
	j = h + g;
	cout << h << " + " << g << "=" << j << endl;
	j = i + g + h;
	cout << i << "+" << g << "+" << h << " = " << j << endl;
	cout << "Increment " << i << " by " << g << " and then and " << h << endl;
	j = (i += g) + h;
	cout << "Result is" << j << endl;
	cout << "Incremented object is" << i << endl;
	cout << "Attempting to initialize with cents = 152" << endl;
	/*try { i.setValue(signType::plus, 3, 152); }
	catch (illegalParameterValue e)
	{
		cout << "Caught thrown exception" << endl;
		e.outputMessage();
	}*/
	return 0;
}