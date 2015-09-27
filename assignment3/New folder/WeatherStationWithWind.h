/**
 * @file
 * @author Abhishek Sharma
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * @WeatherStationWithWind: Class which handles the data
 * related to the Station which can record only the Wind data
 * along with Time and temperature
 *
 */

#ifndef WeatherStationWithWind_H_
#define WeatherStationWithWind_H_
#define _MATH_DEFINES_DEFINED
#include <iostream>
#include "Time.h"
#include <cmath>
#include "WeatherStation.h"


class WeatherStationWithWind: public virtual WeatherStation{
public:
       WeatherStationWithWind();
/**
  * Constructor that takes the name, latitude and longitude of the station
  *
  * @param name Name of the station
  * @param latitude latitude of the station.  Negative values are south,
  * positive values are north
  * @param longitude longitude of the station. Negative values are west,
  * positive values are east
  */

       WeatherStationWithWind( const std::string &name,
                               const double &latitude,
                               const double &longitude);

       virtual ~WeatherStationWithWind();
         /**
	    * Record temperature and wind data at a particular time
	    *
	    * @param time Time of the observation
	    * @param temperature Temperature of the observation
	    * @param windspeed observation for windspeed
	    * @param direction observation for direction
	    */
       void recordObservation( Time time, float temperature , float windspeed,float direction);
        
         /**
           * Records Wind data at a particular time
	    *
	    * @param rainAmount stores amount of rain
	    * @param direction stores direction of rain
	    */
       void recordWind(float windSpeed, float direction);

         /**
	    * Returns Average Wind Speed for all observations
	    */
       float getAverageWindSpeed() const;
         /**
	    * Returns Average Wind Direction for all observations
	    */
       float getAverageWindDirection() const;

      
protected:
   /** Maximum number of observations that can be recored */
static const int maxObservations = 24;
         /**
           *Structure to stores each value for specific time
           */
       struct ObservationWind
       {
        float   windspeed; 		        
        float  direction;   
       };

ObservationWind ObservationWind[maxObservations];


int currentObservationWind;



};

#endif /* WeatherStationWithWind_H_ */
