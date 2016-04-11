#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	char nextChar;

	string data;
	map<char, int> freqTable;



	ifstream infile("secret24.txt");
	if (infile.is_open())
	{
		//While there is txt in the file --- LOOP
		while (infile)
		{
			//add the contents to the data variable
			getline(infile, data);
		}
	}
	else
	{
		cout << "\n*** COULD NOT OPEN FILE --- FILE NOT FOUND ***\n";
	}
	//close the txt file used for reading in the txt
	infile.close();

	////***************************************************************************************************

	//Loop goes through each of the charaters of the txt file
	for (int i = 0; i < data.length(); i++)
	{
		char c = data.at(i);

		//If the character is not found ass it with a value of 1
		if (freqTable.find(data.at(i)) == freqTable.end())
		{
			freqTable.insert(pair<char, int>(data[i], 1));
		}
		else
		{

			freqTable[c]++;
		}
	}

	//*****************************************************************************************
	//PRINT THE FREQUENCY TABLE
	//*stars have been used, just to make the output look better
	cout << "\n*****************************\n";
	cout << "*\tFrequency Table\t    *\n";
	cout << "*****************************\n";
	cout << "* \tChar \t Freq\t    *\n";

	for (map<char, int>::iterator it = freqTable.begin(); it != freqTable.end(); it++)
	{
		cout << "* \t " << it->first << "\t  " << it->second << "\t    *" << endl;
	}

	cout << "*****************************\n";




	system("pause");
	return 0;
}

