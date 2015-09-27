/*
 * observation.h
 *
 *  Created on: 04-Feb-2014
 *      Author: ABHI
 */

#ifndef OBSERVATION_H_
#define OBSERVATION_H_
#include <string>
#include <stdlib.h>
using namespace std;
class observation {

private:
      struct ObservationStruct
      {
         std::string time;
         int temp;
      };



   public:
      observation();
      ObservationStruct observe[25];
      bool record( std::string timeOfObservation, int temperature );
      std::string getTimeOfHighTemp();
      std::string getTimeOfLowTemp();
      int getHighTemp();
      int getLowTemp();
      int getAverageTemp();
      void cal_HighTemp();
      void cal_LowTemp();
      bool validate_data(int time_valid, int temp_valid);
      int index,maxtemp_index,lowtemp_index,sum;


};

#endif /* OBSERVATION_H_ */
