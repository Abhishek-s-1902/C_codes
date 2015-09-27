/*
 * main.cpp
 *
 *  Created on: 13-Dec-2013
 *      Author: ABHISHEK SHARMA
 */

#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ofstream
#include <map>			//std::map
#include <iterator>		//std::iterator
#include <string>
#include <iomanip>
using namespace std;

/*
 * @checkFormat: checking the format of string
 * for all cases
 */
string checkFormat(string str)
{
	/*
	 * @var: pos,pos2,pos3: stores the position of special characters
	 */
	unsigned int pos2=str.find_first_of("'");	    //for first position of '
	unsigned int pos3=str.find_last_of("'");		//for last position of '
	unsigned int pos=str.find_first_of("!.,?;:-|"); //for rest of special characters

	if(pos2==0 && pos3==(str.size()-1))				//if quote is present at both end : 'X'
	{
		if(pos!=-1)
			str=str.substr(1,pos-1);
		else
			str =str.substr(1,pos3-1);
	}
	else if(pos!=-1)								//if quote is not present and special characters
	{												//   is present
		if(pos==0)
			return "";
		else
			str=str.substr(0,pos);
	}

	return str;
}


using namespace std;
int main(int argsc, char* argsv[])
{
	string stringChar;					//@var:stringChar: for reading input from the file
	string tempChar;					//@var:tempChar: for reading input from the temporary file
	map<string,int> couuntVal;			//@var: map : for storing each string and its count
	string copyFile(argsv[0]);			//@var: copyFile: copying the file from argsv
	ifstream input;
	ofstream output;

	if(argsc!=2)						//if number of input is not = 2
	{
		cerr<< "Usage:" << endl<<endl<<"   "<<copyFile.substr(copyFile.find_first_of("/")+1)<<" filename"<<endl;
		return 2;
	}

	input.open(argsv[1]);
	if(!input.is_open())						//if the File provided can't be open
	{
		cerr<<copyFile.substr(copyFile.find_first_of("/")+1)<<": nofile: No such file"<<endl;
		return 2;
	}

	output.open("temp.txt");					//opening temporary file to store all the strings

	while(input>>stringChar)					//taking each string one by one
	{
	if(input.eof())
		break;

	stringChar = checkFormat(stringChar);		//calling the checkFormat function for each input

	output <<stringChar<<" ";					//storing into temp.txt each string
	}

	input.close();								//closing both the streams
	output.close();
	input.open("temp.txt");

	while(input>>tempChar)						//storing each word from temp.txt into the map
	{
		if(couuntVal.count(tempChar)>0)
		{
			 couuntVal[tempChar]+= 1;
		}else
		{
			 couuntVal.insert(pair<string,int>(tempChar,1));
		}
	}

	for(map<string,int>::iterator it = couuntVal.begin(); it != couuntVal.end(); ++it)
	{
	    cout << it->first <<": "<< it->second <<endl;	//printing out each word and its count
	}
return 0;
}
