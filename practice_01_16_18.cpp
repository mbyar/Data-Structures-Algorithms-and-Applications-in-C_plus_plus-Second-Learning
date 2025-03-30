#include<iostream>
using namespace std;
enum signType{plus, minus};
class currency
{
	friend istream& operator>>(istream& in, currency& x);
public:
	currency(signType theSign = signType::plus,
		unsigned long theDollars = 0,
		unsigned int theCents = 0);
	~currency(){}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const { return sign; }
	unsigned long getDollars() const { return dollars; }
	unsigned int getCents() const { return cents; }
	currency add(const currency&) const;
	currency& increment(const currency&);
	currency subtract(const currency& x)const;
	currency operator-(const currency& x)const;
	currency& operator=(double x);
	void output() const;
	void input();
private:
	signType sign;
	unsigned long dollars;
	unsigned int cents;
};
currency::currency(signType thesign, unsigned long theDollars, unsigned int theCents)
{
	setValue(thesign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw /*illegalParameterValue*/("Cents should be < 100");
	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}
void currency::setValue(double theAmount)
{
	if (theAmount < 0) { sign = signType::minus; theAmount = -theAmount; }
	else sign = signType::plus;
	dollars = (unsigned long)theAmount;
	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}
currency currency::add(const currency& x)const
{
	long a1, a2, a3;
	currency result;
	a1 = dollars * 100 + cents;
	if (sign == signType::minus)a1 = -a1;
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == signType::minus)a2 = -a2;
	a3 = a1 + a2;
	if (a3 < 0) { result.sign = signType::minus; a3 = -a3; }
	else result.sign = signType::plus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;
	return result;
}
currency& currency::increment(const currency& x)
{
	*this = add(x);
	return *this;
}
currency currency::subtract(const currency& x)const
{
	long a1, a2;
	currency result;
	a1 = dollars * 100 + cents;
	if (sign == signType::minus)
		a1 = -a1;
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == signType::minus)
		a2 = -a2;
	a1 = a1 - a2;
	result.setValue(1.0 * a1 / 100);
	return result;
}
currency currency:: operator-(const currency& x)const
{
	return subtract(x);
}
void currency::output()const
{
	if (sign == signType::minus)cout << '-';
	cout << '$' << dollars << '.';
	if (cents < 10)cout << '0';
	cout << cents << endl;
}
void currency::input()
{
	float amount;
	signType sign;
	cout << "ÇëÊäÈë£º";
	cin >> amount;
	if (amount < 0)
	{
		sign = signType::minus;
		amount = -amount;
	}
	else sign = signType::plus;
	setValue(sign, (long)amount, (0.001 + (amount - (long)amount)) * 100);
}
istream& operator>>(istream& in, currency& x)
{
	double result;
	in >> result;
	x.setValue(result);
	return in;
}
currency& currency::operator=(double x)
{
	setValue(x);
	return *this;
}
int main()
{
	currency c, b, a;
	a = -3.14;
	b = c = 2.22;
	a.output(); b.output(); c.output();
	return 0;
}