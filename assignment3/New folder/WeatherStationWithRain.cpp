/*
 * weatherStationRain.cpp
 *
 *  Created on: 26-Mar-2014
 *      Author: ABHI
 */

#include "WeatherStationWithRain.h"

WeatherStationWithRain::WeatherStationWithRain(const std::string &name,
                                               const double &latitude,
                                               const double &longitude):
                                               WeatherStation(name,latitude,longitude){

        currentObservationRain = 0;
}

WeatherStationWithRain::WeatherStationWithRain(){}

WeatherStationWithRain::~WeatherStationWithRain() {

}



void WeatherStationWithRain::recordObservation( Time time, float temperature , float rainAmount){

        WeatherStation::recordObservation(time, temperature);
        recordRain(rainAmount);
}

void WeatherStationWithRain::recordRain(float rainAmount){

       ObservationRain[currentObservationRain].rainAmount = rainAmount;

	currentObservationRain++;
}

float WeatherStationWithRain::getTotalRain(){

float Total = 0;

       for(int i=0;i<currentObservationRain;i++){

        Total = Total + ObservationRain[i].rainAmount;
       }
       return Total/100;
}
