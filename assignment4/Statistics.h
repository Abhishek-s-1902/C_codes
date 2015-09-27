#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include <vector>
#include<stdexcept>
#include <algorithm>
#include <set>
#include "Time.h"
template< class T >
class Statistics
{
public:
	typedef T value_type;
   /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */
   T mean(){
         
	   if(mytime.size()==0){
		   throw underflow_error("Not enough data");
	   }else{
         T Tmean;  						//@var Tmean: temparory object of T
       for(int i=0;i<mytime.size();i++)     
       Tmean = Tmean + mytime[i];		//@Operator Overloading: + for summing Seconds

      int sec = Tmean.getSeconds()/mytime.size();
       
       Tmean.putSeconds(sec);  		//setting the mean Seconds in temporary T object
       return Tmean;
       }}
  
   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
   T median(){


      Time Tmedian;							////@var Tmedian: temparory object of T
      int midle;

       sort(mytime.begin(), mytime.end());  	//@std::sort:  sorting the vector mytime

         if(mytime.size()%2==0){				//checking for even or odd size of vector
     int midle1 = mytime.size()/2-1;
      int midle2= midle1+1;
      midle = (mytime[midle1].getSeconds()+mytime[midle2].getSeconds())/2;
      
      Tmedian.putSeconds(midle);			//setting the median Seconds in temporary T object
      return Tmedian;
      }
      else{
          int midle1 =(mytime.size()/2);	//if the size of vector is odd
           return mytime[midle1];
        }
      }

   /**
    * Calculate the mode (most common element). 
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */

  std::set<T> mode(){


	  int counter1=0,counter=0;		//@counter1: to keep track of frequency	of element
	  set<T>modeTime;				//@counter2: to keep track of frequency	of element
    
    sort(mytime.begin(),mytime.end());
if(mytime.size()==1){

	return modeTime;	            //if the size of vector is one only no element will be considered

}else{								//else block will check for mode element if size is > 1
   for(int i=0;i<mytime.size()-1;i++){
	   	   	   	   	   	   	   	   	   //@std::count: will count the frequency of each element in vector
	   counter = count(mytime.begin(), mytime.end(),mytime[i]);

	if(counter==1){					//if the frequency of element of size 1, won't get save
		counter = 0;
		continue;}
	    if(counter1<counter){		// this block will check for the element with highest frequency
          counter1 = counter;
          modeTime.clear();
          modeTime.insert(mytime[i]);
          counter = 0;
          continue;
    }else if(counter1==counter){		//if elements have same frequency then save all
        	  modeTime.insert(mytime[i]);
        	  continue;
          }
   }
}
   return modeTime;
  }


   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in 
    */
   T min(){

	   if(mytime.size()==0){
		   T Tmin;
		   Tmin.putSeconds(0);
	  		 return Tmin;
	  	   }else{							//@std::min_element: will give the min element in the vector

	  return *min_element(mytime.begin(), mytime.end());


   }}

   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in 
    */
   T max(){
	   if(mytime.size()==0){
	   		   T Tmin;
	   		   Tmin.putSeconds(0);
	   	  		 return Tmin;}
	   else{								//@std::max_element: will give the min element in the vector
	   return *max_element(mytime.begin(), mytime.end());

   }}

   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
    
     
 void push(T t ) {
      mytime.push_back(t); 		//@std::push_back: pushing the T object in the vector
        }

   /**
    * Removes all elements from the data
    */
  //void clear();
 
 void clear(){
	 mytime.clear();		//@std::clear: clear all the element in the vector
 }
   
private:
      vector<T> mytime; 
      
      T myT;
};
 

#endif // _STATISTICS_H_

