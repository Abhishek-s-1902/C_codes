/*
 * @file
 * @Author: Abhishek Sharma
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * SAE class: to store the value of measurement in feet and inches
 * and do the basic arithmetic operations.
 */
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
    /**
     * Constructor that sets the variables to 0
     */
    SAE();
    /*
     * Constructor that store the variables in inches and feet
     */
    SAE(double x1,double x2);
    /*
     * get the total Inches
     *
     * returns the total length in terms of inches
     */
    double getInches() const;
    /*
     * put the total inches
     *
     * stores the total length in terms of inches
     */
    double putInches(double inches);
    /*
     * operator overloading '+'
     * does the addition between two SAE class lengths
     */
    SAE operator +(SAE S_add );
    /*
     * operator overloading '-'
     * does the subtraction between two SAE class lengths
     */
    SAE operator -(SAE S_add );
    /*
     * operator overloading '*'
     * does the subtraction between two SAE class lengths
     */
    SAE operator *(SAE S_mul );
	/*
	 * operator overloading '/'
	 * does the division between two SAE class lengths
	 */
    SAE operator /(SAE S_div );
		
	/*
	 * operator overloading '+='
	 * does the Inline addition for SAE object
	 */
    void operator +=(SAE S_div );
	/*
	 * operator overloading '-='
	 * does the Inline subtraction for SAE object
	 */
    void operator -=(SAE S_div );
	/*
	 * operator overloading '*='
	 * does the Inline multiplication for SAE object
	 */
    void operator *=(SAE S_div );
    /*
     * operator overloading '/='
     * does the Inline division for SAE object
     */
    void operator /=(SAE S_div );
    /*
     * operator overloading '<<'
     * does the out put overloading for printing the calculated length
     */
    friend std::ostream& operator<<(std::ostream& os, const SAE S_out);
	
	/*
	 * operator overloading '/'
	 * does the scalar division for SAE object
	 */
	 
   template< typename T > SAE operator /(T S_div)
    {
        SAE S1(0,0);
        double inches = this->getInches()/S_div ;
        if(S1.degree<1)
	    {
            throw underflow_error("Not enough dimensions");
        }
        else if(S_div==0)
	    {
            throw overflow_error("Divide by zero");
        }
	    else
	    {
            S1.putInches(inches);
            return S1;
        }
    }
   
   /*
	 * operator overloading '*'
	 * does the scalar multiplication for SAE object
	 */

   	 template< typename T > SAE operator *(T S_mul)
    {
	    SAE S1(0,0);
	    double inches = this->getInches() *S_mul ;

        S1.putInches(inches);
        return S1;
    }
	 
    public:
        double a,b,inches;
};
#endif
