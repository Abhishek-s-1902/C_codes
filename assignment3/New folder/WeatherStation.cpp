/*
 * weatherStation.cpp
 *
 *  Created on: 29-Mar-2014
 *      Author: ABHI
 */

#include "WeatherStation.h"
#include <iostream>


WeatherStation::WeatherStation(){}

WeatherStation::WeatherStation(const std::string &name,
                              const double &latitude,
                              const double &longitude){
       this->name = name;
	this->latitude= latitude;
	this->longitude= longitude;
	currentObservation = 0;

}

 /*WeatherStation::~WeatherStation() {
	// TODO Auto-generated destructor stub
}*/


void WeatherStation::recordObservation(Time time, float temperature){


       observations[currentObservation].time = time;
       observations[currentObservation].temperature = temperature;
       if(currentObservation==0)
       {
        maxtemp.temperature = temperature;
        mintemp.temperature = temperature;
        maxtemp.time = time;
        mintemp.time = time;
       }
       else if(maxtemp.temperature<observations[currentObservation].temperature)
       {
        maxtemp.temperature = observations[currentObservation].temperature;
        maxtemp.time = observations[currentObservation].time;
       }
       else if(mintemp.temperature>observations[currentObservation].temperature)
       {
        mintemp.temperature = observations[currentObservation].temperature;
        mintemp.time = observations[currentObservation].time;
       }
        currentObservation++;
}

float WeatherStation::getAverageTemperature(){

float Avg=0;

       for(int i=0;i<currentObservation;i++){

        Avg = Avg + observations[i].temperature;
       }

	return Avg/currentObservation;
}


Time WeatherStation::getTimeOfLowTemp() const{

        return mintemp.time;
}

float WeatherStation::getValueOfLowTemp() const{

        return mintemp.temperature;
}


Time WeatherStation::getTimeOfHighTemp() const{
        return maxtemp.time;
}

float WeatherStation::getValueOfHighTemp() const{

        return maxtemp.temperature;
}


std::string WeatherStation::getStationName() const{

        return name;
}

double WeatherStation::getStationLatitude() const{

        return latitude;
}


double WeatherStation::getStationLongitude() const{

        return longitude;
}

