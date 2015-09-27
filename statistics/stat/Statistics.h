#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include <vector>
#include <algorithm>
#include "Time.h"
template< class T >
class Statistics
{
public:
   /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */
   T mean(){
         
         T Tmean;  
       for(int i=0;i<mytime.size();i++)     
       Tmean = Tmean + mytime[i];
      int sec = Tmean.getSeconds()/mytime.size();
       
       Tmean.putSeconds(sec);
       return Tmean;
       }
  
   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
   T median(){

      Time Tmedian;
      int midle;

       sort(mytime.begin(), mytime.end());

         if(mytime.size()%2==0){
     int midle1 = mytime.size()/2;
      int midle2= midle1+1;
      midle = (mytime[midle1].getSeconds()+mytime[midle2].getSeconds())/2;
      
      Tmedian.putSeconds(midle);
      return Tmedian;
      }
      else{
          int midle1 =(mytime.size()/2)+1;
           return mytime[midle1];
        }
      }
   
  
 bool  mysort(T arr1, T arr2){
                                             
               return(arr1 < arr2); 
  }   
         
  

   /**
    * Calculate the mode (most common element). 
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */
 /*  std::set<T> mode(){
    int iterator;
    T tempTime;
    
    std::sort(mytime.begin(), mytime.end(), mysort);
    tempTime =  mytime[0];
    
    for(i=0;i<mytime.length();){
     if(mytime[i]== mytime[++i]){
     counter++;
     continue;
    }else{
         if(counter1<counter){
          counter1 = counter;
       iterator = tempiterator;
       tempiterator = i;
       counter = 0;  
       continue; 
    }
     
}
    std::set<int> modeTime(mytime.at(iterator), mytime.end(tempiterator));
    
    return modeTime;    
  }
*/
   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in 
    */
   //T min();

   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in 
    */
  // T max();

   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
    
     
 void push(T t ) {
      mytime.push_back(t); 
        }

   /**
    * Removes all elements from the data
    */
  //void clear();
 
      void put(){
           for(int i=0;i<mytime.size();i++){
      cout<<"stat"<<i<<endl;
      mytime[i].puttime();
      }}
   
private:
      vector<T> mytime; 
      
      T myT;
};
 

#endif // _STATISTICS_H_

