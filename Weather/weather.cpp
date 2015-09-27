/*
 * weather.cpp
 *
 *  Created on: 04-Feb-2014
 *      Author: ABHI
 */


#include "observation.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
int main()
{
	string time;
	int temp = 0, maxtemp, mintemp;
	bool valid_data;
	int temperature = -1;
	int arr[5];

	observation ob1;

	while(!cin.eof()){

		cout<<"Enter time (hh:mm): ";
		cin>>time;

			if(cin.eof()&&ob1.index==0){
			cout<<"you have not provided any i/p for Time"<<endl;
			break;
			}
			else if(cin.eof())
				break;
		cout<<"Enter temperature: ";
		cin>>temp;
		if(cin.eof()&&ob1.index==0){
		cout<<"you have not provided any i/p for Temp "<<endl;
		 break;
		}

		valid_data = ob1.record(time,temp);

		if(valid_data==false)
		break;
	}

	cout<<endl<<endl;

	cout<<"Average Temperature: "<<ob1.getAverageTemp()<<endl;
	cout<<"High temperature observed at "<<ob1.getTimeOfHighTemp()<<" and was "<<ob1.getHighTemp()<<endl;
	cout<<"Low temperature observed at "<<ob1.getTimeOfLowTemp()<<" and was "<<ob1.getLowTemp()<<endl;

return 0;
}


