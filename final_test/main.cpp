/*
 * main.cpp
 *
 *  Created on: 09-May-2014
 *      Author: ABHI
 */

#include <iostream>

using namespace std;
int main(){

	string *str_ptr1 = new string("hello");
	string *str_ptr2 = new string("world");
	str_ptr2 = str_ptr1;
	delete str_ptr1;
	cout<<str_ptr2;

}

