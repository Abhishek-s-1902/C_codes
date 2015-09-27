
#ifndef __TIME_H__
#define __TIME_H__
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
 public:
 
 Time();
  
 friend istream& operator>>(istream& stream,  Time& time);
 
 friend ostream& operator<<(ostream& stream,  Time time);
 
 Time operator+(Time param);
 
 bool operator==(Time param);
 
  bool operator<(Time param);
 
 void convertTime(Time& time);
 
  void putSeconds(int sec);
  
void TimeSeconds(int hh,int mm,int ss);
  int getSeconds();
    
void puttime();
     
  private:
        string Stime;
        int Seconds;  
         int sum;     
};

#endif // __TIME_H_HH
