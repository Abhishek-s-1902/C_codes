/*
 * Statistics.h
 *
 * @Author: ABHI
 *
 *Source for algorithm: http://www.purplemath.com/modules/meanmode.htm
 *	                    http://en.wikipedia.org/wiki/Standard_deviation
 *Reason for using Vector: Simple and increases automatically at run time which 
 * other container doesn't have this property. good for mode calculation
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_
#define foreach BOOST_FOREACH
#include <vector>
#include <set>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include  <cmath>

using namespace std;
template<typename T>

class Statistics: public std::vector<T>{

    typedef std::vector<T> vector;
public:

	typedef T stat_val;


   /*
    * @mean:calculating the mean of all the values
    */
	T mean();

    /*
     * @median: to calculate the median of given values
     */
	T median();

	/*
	 * @mode: calculating the mode of values
	 */
	set<T> mode();

    /*
     * @variance: calulating the variance of given values
     */
	T variance();

    /*
     * @standardDeviation: calculating standard deviation for
     *  a given values
     */
	T standardDeviation();

private:
	//@mean_Value : for storing the mean value
	//@std_deviation : for storing the standard deviation value
	T mean_Value;
	T std_deviation;
};


template<typename T>
T Statistics<T>::mean()
{
	mean_Value = 0;
	typename Statistics<T>::iterator elements;
    int size = this->size();

    if(size==0)
	{
        throw std::underflow_error(" Not enough data");
    }
	else
	{
        for(elements=this->begin();elements!=this->end();elements++)
            mean_Value = mean_Value + *elements;
        mean_Value = mean_Value/size;
    }
    return mean_Value;
}

template<typename T>
T Statistics<T>::median()
{
    T median_Value;
    int Index_1;
    int Index_2;
    int size = this->size();
    typename Statistics<T>::iterator elements;

    std::sort (this->begin(),this->end());

    if(size==0)
        throw std::underflow_error(" Not enough data");

        if(size%2==0)
		{
            Index_1 = size/2;
            Index_2 = (size/2)+1;
            median_Value = (this->at(Index_1-1)+this->at(Index_2-1))/2;
        }
		else
		{
            Index_2 = (size/2)+1;
            median_Value = this->at(Index_2-1);
		}
    return median_Value;
}

template<typename T>
set<T> Statistics<T>::mode()
{
    int count1=0;
    int count2=0;
    int Index1=0;
    set<T> mode_val;
    int size = this->size();

    if(size==0)
        throw std::underflow_error(" Not enough data");

	std::sort (this->begin(), this->end());

    for(int i=0;i<size;i++){
        count1=0;
        for (int j = i + 1; j < size; j++)
        {
            if (this->at(i) == this->at(j))
            {
                count1++; i++;
            }
			else
			    break;
            }

            if(count1 ==0)
                continue;
            else if (count1 > count2)
            {
                count2 = count1;
                mode_val.erase(mode_val.begin(),mode_val.end());
                mode_val.insert(this->at(i));
            }
            else if(count1 == count2)
            {
                mode_val.insert(this->at(i));
            }
        }
    return mode_val;
}

template<typename T>
T Statistics<T>::variance()
{
    T variance = 0;
    int size = this->size();

    if(size<=1)
        throw std::underflow_error(" Not enough data");
    else
    {
    	for(int i = 0; i < size; i++)
        {
            variance = variance + pow((this->at(i)-mean_Value),2);
        }
        variance = variance/(size-1);
        std_deviation = variance;
	}

    return variance;
}

template<typename T>
T Statistics<T>::standardDeviation()
{
    int size = this->size();
    if(size<=1)
        throw std::underflow_error(" Not enough data");
    return sqrt(std_deviation);
}

#endif /* STATISTICS_H_ */
