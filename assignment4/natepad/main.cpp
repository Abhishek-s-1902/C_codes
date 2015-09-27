/**
 * 4003-703-03 Homework 4 main.cpp.  Students should add a showStats()
 * function to this file.
 */
#include "Statistics.h"
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

/* showStats() function goes here */
using namespace std;
template< typename T >

int showStats(Statistics<T> data )
{
    cout<<"mean: " <<data.mean()<<endl;
    cout<<"median: "<<data.median()<<endl;

    typename set<T>::iterator it;
    set<T> mode_val = data.mode();
    cout<<"mode: ";
    for(it=mode_val.begin();it != mode_val.end();it++)
     cout << *it<<" ";
   cout<<endl; 
   cout<<"variance: "<< data.variance()<<endl;
   cout<<"stdDeviation: "<<data.standardDeviation()<<endl;

	return 0;
}



/* DO NOT MODIFY ANYTHING BELOW THIS LINE */
int main()
{
   Statistics< int > iStats;
   Statistics< float > fStats;

   cout << "Enter integers separated by whitespace. Press CTRL-D on an empty line to end." << endl;;

   /* Set up an input iterator and process the user input for integers */
   istream_iterator< int > i_in_it( cin );
   for( ; i_in_it != istream_iterator<int>(); i_in_it++ )
   {
      if ( !cin.fail() )
      {
         iStats.push_back(*i_in_it);
      }
   }

   showStats( iStats );
   
   /* Clear the EOF we recieved from integer inputs */
   cin.clear();

   cout << endl << endl;
   cout << "Enter floats separated by whitespace. Press CTRL-D on an empty line to end." << endl;;

   /* Set up an input iterator and process the user input for integers */
   istream_iterator< float > f_in_it( cin );
   for( ; f_in_it != istream_iterator<float>(); f_in_it++ )
   {
      if ( !cin.fail() )
      {
         fStats.push_back(*f_in_it);
      }
   }
   showStats( fStats );

}