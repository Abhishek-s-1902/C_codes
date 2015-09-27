#include "SAE.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{

   cin.exceptions( std::istream::eofbit );

   while ( true )
   {
      float a, b, c, d;

      try
      {
         cin >> a >> b >> c >> d;
      }
      catch ( std::istream::failure &e ) // EOF
      {
         break;
      }

      SAE v1( a, b );
      SAE v2( c, d );
      cout << "        v1: " << v1<< endl;
      cout << "        v2: " << v2 <<endl;
      SAE add = v1 + v2;
      SAE sub = v1 - v2;
      SAE mul = v1 * v2;
      SAE mul2 = mul * v2;
      SAE div = mul/v2;
      SAE sac_mul = v1*c;
      SAE sac_div = v1/c;

      cout<<"div: "<<div<<endl;
      cout<<"mul: "<<mul<<endl;
      cout<<"add: "<<add<<endl;
      cout<<"sub: "<<sub<<endl;
      cout<<"mul2: "<<mul2<<endl;

      cout<<"sca_mul: "<<sac_mul<<endl;
      cout<<"sca_div: "<<sac_div<<endl;

      SAE temp_add = v1;
      	       temp_add += v2;
 cout<<"inline_add: "<<temp_add<<endl;
      	  SAE temp_sub = v1;
      	      temp_sub -= v2;
cout<<"inline_sub: "<<temp_sub<<endl;
      	  SAE temp_mul = v1;
      	  	  temp_mul *= v2;
cout<<"inline_mul: "<<temp_mul<<endl;
      	  SAE temp_div = v1;
      	  temp_div /= v2;
cout<<"inline_div: "<<temp_div<<endl;



	}

	 // return 0;
}


