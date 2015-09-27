/*
 * WeatherStationWithWindAndRain.cpp
 *
 *  Created on: 05-Apr-2014
 *      Author: ABHI
 */

#include "WeatherStationWithWindAndRain.h"

WeatherStationWithWindAndRain::WeatherStationWithWindAndRain(const std::string &name,
                                                             const double &latitude,
                                                             const double &longitude): 
                               WeatherStation(name,latitude,longitude),
                               WeatherStationWithWind(name,latitude,longitude), 
                               WeatherStationWithRain(name,latitude,longitude){

	
}

WeatherStationWithWindAndRain::~WeatherStationWithWindAndRain() {
	
}

void WeatherStationWithWindAndRain::recordObservation( Time time, float temperature ,float windspeed, float direction, float rainAmount){

        WeatherStationWithWind::recordObservation(time,temperature,windspeed,direction);
        WeatherStationWithRain::recordRain(rainAmount);

}
