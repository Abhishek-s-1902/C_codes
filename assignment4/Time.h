
#ifndef __TIME_H__
#define __TIME_H__
#include <stdlib.h>
#include <string>
#include<stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
 public:
 
 Time();
                          //@Operator overloading: >>
 friend istream& operator>>(istream& stream,  Time& time);
                          //@Operator overloading: <<
 friend ostream& operator<<(ostream& stream,  Time time);
                         //@Operator overloading: +
 Time operator+(Time param);
                         //@Operator overloading: ==
 bool operator==(Time param) const;
                          //@Operator overloading: <
  bool operator<(Time param) const;
  	  	  	  	  	  	//@convertTime: Breaking String into HH MM SS
 void convertTime(string str);
                       //@putSeconds: putter method for seconds
 void putSeconds(int sec);
                       //@TimeSeconds: Calculating the time in Seconds
void TimeSeconds(int hh,int mm,int ss);
                       //@getSeconds: getter method for Seconds
  int getSeconds();
    

     
  private:
        int Seconds;  
         int sum;     
};

#endif // __TIME_H_HH
