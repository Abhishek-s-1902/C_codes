#include "Time.h"
#include <iomanip>
#include <string>
#include <sstream>
#include<stdexcept>
using namespace std;

 
  Time::Time(){
  Seconds=0;
 }
   

int Time::getSeconds (){
 return Seconds; 		//getter method for seconds
}

void Time::convertTime(string str){

      int pos1 = 0;       //@pos1,pos2 : for taking the position for the ":" in the string
      int pos2 = 0;
      int hh0=0;		 //@hh0,mm0,ss0: temporory variable for HH MM SS
      int mm0=0;
      int ss0=0;

      bool charTrue = false;

      for(int i=0;i<str.length();i++){
    	  if(str.at(i)<'0' || str.at(i)>'9' && str.at(i)!=':')
    		  charTrue = true;
  }
     if(charTrue == true){
    	 throw runtime_error("Invalid time entry");
     }
      else{

    	  if(str.length()==0){          //this block is for breaking the string into 3 int values

         hh0=0;                     //for  HH,MM,SS
         mm0=0;
         hh0=0;
         	  }else{

      pos1 = str.find(":");
      pos2 = str.find(":",pos1+1);

      if(pos1==-1){
    	  hh0 = atoi(str.substr(0,str.length()).c_str());
      }else{

      if(pos1==0 ){
    	  hh0 = 0;
      }else{hh0 = atoi(str.substr(0,pos1).c_str());}

      if(pos2==pos1+1){
    	  mm0=0;
      }else{
    	  mm0 = atoi(str.substr(pos1+1,pos2).c_str());
      }

      if(pos2 == -1){
    	  ss0 = 0;
      }else{
    	  ss0 = atoi(str.substr(pos2+1,str.length()-1).c_str());
      }

      }
                                     //throwing the error if the below condition occur
      if(hh0<0||mm0>60 || mm0<0 ||ss0>60 || ss0<0){
          	  throw runtime_error("Invalid time entry");

            }else{
          	  TimeSeconds(hh0,mm0,ss0);
      }

      }
}}


void Time::putSeconds(int sec){
     this->Seconds = sec;
     }

void Time::TimeSeconds(int hh, int mm,int ss){
     Seconds = (hh*3600 + mm*60 + ss);

  }

              //@Operator overloading: >>
istream& operator>>(istream& stream,  Time& time){

        string str;        //@str: taking each input of time string
         stream >> str;
         
         time.convertTime(str);   //calling of convertTime()
         return stream;
 }
               //@Operator overloading: << : converting again the String "Second Variable"into HH MM SS format
ostream& operator<<(ostream& stream,  Time time){
	int HHTemp=00;
	int MMTemp=00;
	int SSTemp =00;
	int tempTime=00;
         HHTemp = time.Seconds/3600;
         tempTime = time.Seconds%3600;
         MMTemp = tempTime/60;
        tempTime = tempTime%60;
         SSTemp = tempTime;
         stream<<setfill('0')<<setw(2)<<HHTemp <<":" <<setw(2)<<MMTemp<<":"<<setw(2)<<SSTemp;
         
         return stream;
}

Time Time::operator+(Time param){
  Time temp;
  int sec = this->getSeconds() + param.getSeconds();
  temp.putSeconds(sec);
  
  return temp;
}
                    //@Operator overloading: < :
 bool Time::operator<(Time param) const{
      if(this->Seconds<param.Seconds)
      return true;
      else return false;
      }
                   //@Operator overloading: == :
 bool Time::operator==(Time param) const{
  if(this->Seconds==param.Seconds)
  return true;
  else return false;    
 }

