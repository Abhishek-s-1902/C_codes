/*
 * observation.cpp
 *
 *  Created on: 04-Feb-2014
 *      Author: ABHI
 */

#include "observation.h"
#include <iostream>
#include <stdlib.h>
#include <iostream>

  observation::observation()
{
	  index= 0;
	  maxtemp_index= 0;
	  lowtemp_index= 0;
	  sum = 0;
}

bool observation::validate_data(int Hr,int min)
{
	if(Hr<0 || Hr>23|| min<0||min>59)
				return false;
		else
		return true;
}


bool observation::record( std::string timeOfObservation, int temperature )
{
	int HH,MM,pos;
	bool valid_data;

	pos = timeOfObservation.find(":");
	string a=timeOfObservation.substr(0,pos);

	string b=timeOfObservation.substr(pos+1,timeOfObservation.length());


	HH = atoi(timeOfObservation.substr(0,pos).c_str());
	MM = atoi(timeOfObservation.substr(pos+1,timeOfObservation.length()).c_str());


	if(index>23)
	{
		cout<<"Maximum number of observations recorded"<<endl<<endl<<endl;
		return false;
	}

	valid_data = validate_data(HH,MM);

	if(valid_data==false)
	{
		cout<<"Time is out of range"<<endl;
		return true;
	}

	else if(valid_data==true)
	{
	ObservationStruct ob;

	ob.time = timeOfObservation;
	ob.temp = temperature;
	observe[index]=ob;

	sum = sum + temperature;

	cal_HighTemp();
	cal_LowTemp();
	index++;
	return true;
	}

}

void observation::cal_HighTemp()
{
	if(index==0)
		maxtemp_index = index;

	else{
		if(observe[index].temp>observe[maxtemp_index].temp)
			maxtemp_index = index;
		else
		return;
		}

}


void observation::cal_LowTemp()
{

	if(index==0)
		lowtemp_index = index;

	else
	{
		if(observe[index].temp<observe[lowtemp_index].temp)
			lowtemp_index = index;
		else
			return;
	}

}


int observation::getAverageTemp()
{

if(index==0)
	return 0;
	return (sum/index) ;
}

int observation::getHighTemp()
{

	if(index==0)
		return -9999;
	return observe[maxtemp_index].temp;
}



string observation::getTimeOfHighTemp()
{
	return observe[maxtemp_index].time;
}

int observation::getLowTemp(){
	if(index==0)
		return 9999;
	return this->observe[lowtemp_index].temp;

}

string observation::getTimeOfLowTemp()
{
	return this->observe[lowtemp_index].time;
}



