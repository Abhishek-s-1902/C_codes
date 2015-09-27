/**
 * @file
 * @author Abhishek Sharma
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * @WeatherStationWithWindAndRain: Class which handles the data
 * related to the Station which can record all the data for Wind 
 * and rain along with Time and temperature
 */

#ifndef WEATHERSTATIONWITHWINDANDRAIN_H_
#define WEATHERSTATIONWITHWINDANDRAIN_H_
#include "WeatherStationWithWind.h"
#include "WeatherStationWithRain.h"
#include <iostream>

class WeatherStationWithWindAndRain: public WeatherStationWithWind, public WeatherStationWithRain{

public:

/**
  * Constructor that takes the name, latitude and longitude of the station
  *
  * @param name Name of the station
  * @param latitude latitude of the station.  Negative values are south,
  * positive values are north
  * @param longitude longitude of the station. Negative values are west,
  * positive values are east
  */
       WeatherStationWithWindAndRain(const std::string &name,
                                     const double &latitude,
                                     const double &longitude);
       virtual ~WeatherStationWithWindAndRain();

           /**
             * Record temperature and wind data at a particular time
             *
	      * @param time Time of the observation
	      * @param temperature Temperature of the observation
	      * @param windspeed observation for windspeed
	      * @param direction observation for direction
	      * @param rainAmount observation for rain
	      */
       void recordObservation( Time time, float temperature ,float windspeed, float direction, float rainAmount);

protected:

       WeatherStationWithWind wind;
       WeatherStationWithRain Rain;
};

#endif /* WEATHERSTATIONWITHWINDANDRAIN_H_ */
