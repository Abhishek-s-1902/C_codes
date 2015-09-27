#include "Time.h"
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

 
  Time::Time(){
  Seconds=0;
 }
   

void Time::puttime(){
  cout<<Stime<<endl; 
}

int Time::getSeconds (){
 return Seconds; 
}

void Time::convertTime(Time& time){
      
      cout<<"convert"<<endl;
     
      
      int i = 0;
      int pos = 0; 
      int hh0=0;
      int mm0=0;
      int ss0=0;
      int counter = 0;
     
         while(i<Stime.length()) //use iterator
     {
    
      if(Stime.at(i)==':' && counter == 0) 
      {
         istringstream hr_s(Stime.substr(pos,i));
           hr_s >> hh0; 
         cout<<"hh0"<<hh0<<endl; 
         pos = i+1;
          counter++;           
       }
       
       else if(Stime.at(i)==':' && counter == 1)  
        {
         istringstream mm_s(Stime.substr(pos,i));
         mm_s >> mm0;
         cout<<"mm0"<<mm0<<endl; 
          pos = i+1; 
          counter++;                 
          }
       if(i == Stime.length()-1 && counter == 0)  
        {
         istringstream hh_s(Stime.substr(pos,i+1)); 
         hh_s >> hh0;
         cout<<"hh0"<<hh0<<endl; 
                          
       }
       if(i == Stime.length()-1 && counter == 1)  
        {
         istringstream mm_s(Stime.substr(pos,i+1));
         mm_s >> mm0; 
         cout<<"mm0"<<mm0<<endl;                 
       }
       if(i == Stime.length()-1 && counter == 2)  
        {
         istringstream ss_s(Stime.substr(pos,i));
         ss_s >> ss0; 
         cout<<"ss0"<<ss0<<endl;                   
       }
       
       i++;      }
     //cout<<hh0<<mm0<<ss0<<endl;
      time.TimeSeconds(hh0,mm0,ss0); 
     
}

void Time::putSeconds(int sec){
     this->Seconds = sec;
     }

void Time::TimeSeconds(int hh, int mm,int ss){
     Seconds = (hh*3600 + mm*60 + ss);
     cout<<Seconds<<endl;
  }

//concept of dessy chain
istream& operator>>(istream& stream,  Time& time){
        cout<<"test";
         stream >> time.Stime;
         
         time.convertTime(time);
         return stream;
 }
 
ostream& operator<<(ostream& stream,  Time time){
        int HHTemp = time.Seconds/3600;
        int tempTime = time.Seconds%3600;
        int MMTemp = tempTime/60;
        tempTime = tempTime%60;
        int SSTemp = tempTime;
         stream<<HHTemp<<"  "<< MMTemp<<"  "<<SSTemp<<endl;
         
         return stream;
}

Time Time::operator+(Time param){
  Time temp;
  int sec = this->getSeconds() + param.getSeconds();
  temp.putSeconds(sec);
  
  return temp;
}

/* boolean Time::operator<(Time param){
      if(this.Seconds<param.Seconds)
      return true;
      else return false;
      }
      
 bool operator==(Time param){
  if(this.Seconds==param.Seconds)
  return true;
  else return false;    
 }
*/
