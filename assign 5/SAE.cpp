#include "SAE.h"
#include <cmath>

SAE::SAE()
{
    a=0;
    b=0;
    inches = 0;
    degree = 0;
}

SAE::SAE(double x1,double x2)
{
    a = x1*12;
    b = x2;
    inches = a+b;
    degree = 1;
}

double SAE::getInches() const
{
    return inches;
}

double SAE::putInches(double inches)
{
    return this->inches = inches;
}

SAE SAE::operator +( SAE S1)
{
    SAE S2(0,0);
    double inches = this->getInches() + S1.getInches();
	S1.putInches(inches);

    return S1;
}

SAE SAE::operator -( SAE S1)
{
    SAE S2(0,0);
    double inches = this->getInches() - S1.getInches();
	S2.putInches(inches);

    return S2;
}

SAE SAE::operator *(SAE S_mul )
{
    SAE S1(0,0);
    double inches = this->getInches() * S_mul.getInches();
	S1.putInches(inches);
    S1.degree = this->degree+S_mul.degree;
 
    return S1;
}

SAE SAE::operator /(SAE S_div )
{
    SAE S1(0,0);
    double inches = this->getInches() / S_div.getInches();

    S1.degree = this->degree-S_div.degree;
    if(S1.degree<1)
	{
        throw underflow_error("Not enough dimensions");
    }
    else
	{
        S1.putInches(inches);
        return S1;
    }
}

void SAE::operator +=(SAE S_div)
{
    double inches = this->getInches() + S_div.getInches() ;
    this->putInches(inches);
}

void SAE::operator -=(SAE S_div)
{
	double inches = this->getInches() - S_div.getInches() ;
    this->putInches(inches);
}

void SAE::operator *=(SAE S_mul)
{
    double inches = this->getInches() * S_mul.getInches() ;
    this->degree = S_mul.degree+1;
    this->putInches(inches);
}

void SAE::operator /=(SAE S_div)
{
    double inches = this->getInches() / S_div.getInches() ;
    this->degree = this->degree-S_div.degree;
    if(this->degree<1)
    {
        throw underflow_error("Not enough dimensions");
	}
    this->putInches(inches);
}

std::ostream& operator<<(std::ostream& os, const SAE S_out)
{
    ostringstream osstr ;

    if(S_out.degree>1)
    {
        int degreetoDiv = pow(12,S_out.degree);
        os << setw(2)<<setfill('0') <<S_out.getInches()/degreetoDiv<<" feet^"<<S_out.degree;
	}
	else
	{
        double in_feet = (int)(S_out.getInches()/12);
		double in_inches = S_out.getInches() - (in_feet*12);
		os << (int)in_feet<<" feet "<<in_inches<<" inches";
	}
    return os;
}
