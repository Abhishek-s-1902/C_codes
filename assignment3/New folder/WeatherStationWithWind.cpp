/*
 * WeatherStationWithWind.cpp
 *
 *  Created on: 26-Mar-2014
 *      Author: ABHI
 */

#include "WeatherStationWithWind.h"

WeatherStationWithWind::WeatherStationWithWind(){}

WeatherStationWithWind::WeatherStationWithWind( const std::string &name,
                                                const double &latitude,
                                                const double &longitude):
                                                WeatherStation(name,latitude,longitude){

        currentObservationWind = 0;
}

WeatherStationWithWind::~WeatherStationWithWind() {
	
}


void WeatherStationWithWind::recordObservation(Time time, float temperature ,float windspeed, float direction){

        WeatherStation::recordObservation(time, temperature);
        recordWind(windspeed, direction);

}

void WeatherStationWithWind::recordWind(float windspeed,float direction){

       ObservationWind[currentObservationWind].windspeed = windspeed;
  
 if(direction<0)
	ObservationWind[currentObservationWind].direction = 360-direction;
   else
	ObservationWind[currentObservationWind].direction = direction;

	currentObservationWind++;
}



float WeatherStationWithWind::getAverageWindSpeed() const{

float Avg = 0;

        for(int i=0;i<currentObservationWind;i++){
        
        Avg = Avg + ObservationWind[i].windspeed;
       }
        return Avg/currentObservationWind;
}


float WeatherStationWithWind::getAverageWindDirection() const{

float Avg = 0;
double radian;
double sinVal=0;
double cosVal=0;

       for(int i=0;i<currentObservationWind;i++){

        radian = (ObservationWind[i].direction)*M_PI/180;
        sinVal = sinVal + sin(radian);
        cosVal = cosVal+ cos(radian);
       }
		
       Avg = (atan2(sinVal,cosVal))*180/M_PI;
       return Avg-1;
}






