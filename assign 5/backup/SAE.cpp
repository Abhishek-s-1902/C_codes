#include "SAE.h"
#include <cmath>
  SAE::SAE(float x1,float x2)
{
	    a = x1*12;
	    b = x2;
		inches = a+b;
		degree = 1;
}

float SAE::getInches() const{
return inches;
}

float SAE::putInches(float inches) {
return this->inches = inches;
}

SAE SAE::operator +( SAE S1){
	 SAE S2(0,0);
	  float inches = this->getInches() + S1.getInches();
	 // cout<<"in add"<<inches<<endl;
	  S1.putInches(inches);

	  return S1;
}

SAE SAE::operator -( SAE S1){
	 SAE S2(0,0);
	  float inches = this->getInches() - S1.getInches();
	 // cout<<"in add"<<inches<<endl;
	  S1.putInches(inches);

	  return S2;
}

SAE SAE::operator *(SAE S_mul ){
	  SAE S1(0,0);
	  float inches = this->getInches() * S_mul.getInches();
	  S1.putInches(inches);
	  S1.degree = this->degree+S_mul.degree;
	  cout<<"s mul.degree"<< S1.degree<<endl;
	  return S1;
}

SAE SAE::operator /(SAE S_div ){
	SAE S1(0,0);
	  float inches = this->getInches() / S_div.getInches();

	  S1.degree = this->degree-S_div.degree;
	  cout<<"s div.degree"<< S1.degree<<endl;
	  if(inches<1||S1.degree<1){
	  throw underflow_error("Not enough dimensions");
	  }
	  else{
	  S1.putInches(inches);
	  return S1;}
}

SAE SAE::operator *(float S_mul){
	SAE S1(0,0);
	  float inches = this->getInches() *S_mul ;

	  S1.putInches(inches);
	  return S1;
}

SAE SAE::operator /(float S_div){
	SAE S1(0,0);
	  float inches = this->getInches()/S_div ;
cout<<"scal div: "<<inches<<endl;
	  S1.putInches(inches);
	  return S1;
}

void SAE::operator +=(SAE S_div){
	//SAE S1(0,0);
		  float inches = this->getInches() + S_div.getInches() ;

		  this->putInches(inches);
		  //cout<<"this:+="<<inches<<endl;
}

void SAE::operator -=(SAE S_div){
	float inches = this->getInches() - S_div.getInches() ;

	this->putInches(inches);
	//cout<<"this:+="<<inches<<endl;

}

void SAE::operator *=(SAE S_mul){
	float inches = this->getInches() * S_mul.getInches() ;
	 this->degree = S_mul.degree+1;
		  cout<<"s1.degree"<< this->degree<<endl;
		this->putInches(inches);
		//cout<<"this:+="<<inches<<endl;
}

void SAE::operator /=(SAE S_div){
	float inches = this->getInches() / S_div.getInches() ;
	this->degree = this->degree-S_div.degree;
    cout<<"s1.degree"<< this->degree<<endl;
	if(inches<1||this->degree<1){
	throw underflow_error("Not enough dimensions");
	}
	this->putInches(inches);
		//cout<<"this:+="<<inches<<endl;
}

std::ostream& operator<<(std::ostream& os, const SAE S_out){
	ostringstream osstr ;

	if(S_out.degree>1){
		int degreetoDiv = pow(12,S_out.degree);
	os << setw(2)<<setfill('0') <<"inches :"<<S_out.getInches()/degreetoDiv<<" feet^"<<S_out.degree;
	}
	else
	{
	float in_feet = S_out.getInches()/12;
	//float mod_inches = S_out.getInches()-(int)in_feet;
	os << (int)in_feet<<" feet "<<(in_feet- (int)in_feet)*12<<" inches";
	}
	return os;
	//cout<<"operator<<"<<endl;
}
