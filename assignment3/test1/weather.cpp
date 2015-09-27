/**
 * @file
 * @author Abhishek Sharma
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * @weather : class which contains main function and
 * takes Input from user for for all the records   
 */

#include <iostream>
#include <stdexcept>
#include  <cmath>
#include "Time.h"
#include "WeatherStation.h"
#include "WeatherStationWithWind.h"
#include "WeatherStationWithRain.h"
#include "WeatherStationWithWindAndRain.h"

/*
 * @ExededValue: Structure for handling error
 *  when the value exceeded from 24
 */
 using namespace std;
 struct ExededValue : public exception
{

  const char * what () const throw ()
  {
   return "Maximum number of observations recorded ";
  }
};

 /*
  * @NoValue: Structure for handling error
  *  when their is no value provided by the user
  */

 using namespace std;
 struct NoValue : public exception
{
  const char * what () const throw ()
  {
   return "No data available";
  }
};

 /*
  * @main: to initialise the object of any class and taking
  * the parameter according to that class and presenting the 
  * output to the user
  */

using namespace std;
int main(){

Time t;
int i = 0;
int temp = 0, maxtemp, mintemp;

string station = "McMurdo Station";
float latitude = -77.85;
float longitude = 166.667;
float windSpeed;
float windDirection;
float rainAmount;

WeatherStationWithWindAndRain w1(station,latitude,longitude);


     while(!cin.eof()){

     try{
         cout<<"Enter time (hh:mm): ";
         cin>>t;
         if(cin.eof())
         break;

         cout<<"Enter temperature (deg C): ";
         cin>>temp;
         if(cin.eof())
         break;

         cout<<"Enter wind speed (mph): ";
         cin>>windSpeed;
         if(cin.eof())
         break;

         cout<<"Enter wind direction (deg): ";
	  cin>>windDirection;
         if(cin.eof())
         break;

         cout<<"Enter rain (1/100th inch): ";
         cin>>rainAmount;
         if(cin.eof()){
         break;
         }
         else if(i==23){
         throw ExededValue();
         break;
         }
         else {
         w1.recordObservation(t,temp,windSpeed,windDirection,rainAmount);
         cout<<endl;
         i++;
         }

         }catch(std::overflow_error e) {
         cerr <<"General exception occurred "<<e.what()<< endl;
         }catch(ExededValue e){
          cerr<<e.what()<<endl<<endl;
          break;
         }
}
         cout<<endl<<endl;

         cout<<"Weather Data for "<<w1.getStationName()<<" ("<<w1.getStationLatitude()<<", "<<w1.getStationLongitude()<<")"<<endl;
         cout<<"-------------------------------------------------------------"<<endl;
         
         if(i!=0){
         std::cout<<"Average Temperature: "<<w1.getAverageTemperature()<<" degree(s) C"<<endl;
         std::cout<<"High Temperature was "<<w1.getValueOfHighTemp()<<" degree(s) C at "<<w1.getTimeOfHighTemp()<<endl;
         std::cout<<"Low Temperature was "<<w1.getValueOfLowTemp()<<" degree(s) C at "<<w1.getTimeOfLowTemp()<<endl;
         std::cout<<"Average Wind Speed: "<<w1.getAverageWindSpeed()<<"mph"<<endl;
         cout<<"Average Wind Direction: "<<ceil(w1.getAverageWindDirection())<<" degree(s)"<<endl;
         cout<<"Total Rain: "<<w1.getTotalRain()<<"\""<<endl;
         }else{
          try{
          throw NoValue();
          }catch(NoValue e){
          cerr<<e.what()<<endl;
          return 0;
          }
          }
          return 0;
}




