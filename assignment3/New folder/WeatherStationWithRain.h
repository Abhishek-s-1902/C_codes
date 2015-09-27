
/**
 * @file
 * @author Abhishek Sharma
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * @WeatherStationWithRain: Class which handles the data
 * related to the Station which can record only the Rain data
 * along with Time and temperature
 */

#ifndef WEATHERSTATIONWITHRAIN_H_
#define WEATHERSTATIONWITHRAIN_H_

#include "Time.h"
#include "WeatherStation.h"


class WeatherStationWithRain: public virtual WeatherStation{

         /**
	    * Constructor that takes the name, latitude and longitude of the station
	    *
	    * @param name Name of the station
	    * @param latitude latitude of the station.  Negative values are south,
	    * positive values are north
	    * @param longitude longitude of the station. Negative values are west,
	    * positive values are east
	    */
public:
        WeatherStationWithRain();
        WeatherStationWithRain(const std::string &name,
        const double &latitude,
        const double &longitude);

        virtual ~WeatherStationWithRain();
         /**
	    * Record temperature and Rain at a particular time
	    *
	    * @param time Time of the observation
	    * @param temperature Temperature of the observation
	    * @param rainAmount observation for rain amount
	    */
        void recordObservation( Time time, float temperature , float rainAmount);
         /**
	    * Records Rain amount at a particular time
	    *
	    * @param rainAmount stores amount of rain
	    *
	    */
        void recordRain(float rainAmount);
         /**
           * Record total Rain amount for 24 observations
           */
        float getTotalRain();

protected:
          /** Maximum number of observations that can be recored */
   
static const int maxObservationsWind = 24;
         /**
           *Structure to stores each value for specific time
           */
       struct ObservationRain
       {
        float  rainAmount; 		      
       };

         /**Array of Structure to stores each value for specific time*/
ObservationRain ObservationRain[maxObservations];

int currentObservationRain;

};

#endif /* WEATHERSTATIONRAIN_H_ */
