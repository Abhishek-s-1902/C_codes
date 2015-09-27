
#ifndef SAE_H_
#define SAE_H_
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
class SAE {

    public:
		int degree;
        SAE(float x1,float x2);
        float getInches() const;
        float putInches(float inches);
       SAE operator +(SAE S_add );
       SAE operator -(SAE S_add );
	   SAE operator *(SAE S_mul );
	   SAE operator /(SAE S_div );
	   SAE operator *(float S_mul);
	   SAE operator /(float S_div );
	   void operator +=(SAE S_div );
	   void operator -=(SAE S_div );
	   void operator *=(SAE S_div );
	   void operator /=(SAE S_div );
	   friend std::ostream& operator<<(std::ostream& os, const SAE S_out);
	public:
	    float a,b,inches;
};

#endif
