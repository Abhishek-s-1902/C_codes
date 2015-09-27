#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    
    vector<int> v;
 v.assign( 10, 42 );
 for( int i = 0; i < v.size(); i++ ) {
   cout << v[i] << " ";
 }
 cout << endl; 
vector<int> v1; // what’s in the vector? what’s the type of an element?
vector<int> v2(5); // what’s the number of elements in the vector?
vector<int> v3(5,1); // size of the vector? values of elements?

std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;
cout <<myvector[0]<<myvector[1]<<myvector[2]<<endl;

  it = myvector.begin();
   myvector.insert( it, 2 , 200 );
cout <<myvector[0]<<myvector[1]<<myvector[2]<<endl;
  myvector.insert (++it,2,300);
  cout<<myvector[0]<<myvector[1]<<myvector[2]<<endl;
 
 cout<<*(++it)<<endl;
 
  /*for (it=myvector.begin(); it<myvector.end(); it++){
    std::cout << ' ' << *it<<;
}
//v2[0] = 2; // what happens?
//v3[5] = 10; // what happens?
//vector<char> v;

//cout<<v1[0]<<v2[0]<<v3[5];
/*for (int i = 0; i < 5; i++)
v.push_back(65 + i); // what happens?
vector<char> v4(5,'A');
v4.push_back('B'); // what happens?*/
    system("PAUSE");
   
}
