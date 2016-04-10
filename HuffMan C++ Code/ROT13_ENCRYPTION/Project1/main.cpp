/*
	This C++ Program uses Rot-13 cipher.
	Rot-13 cipher changes each of the alphabet 13 characters forward in the english alphabet
	BY: Shajun Dominic - X00109340
*/
#include "EncryptionRot13.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string line;
	int length;
	int count = 0;
	//ifstream myfile("Test.txt");

	//File which contains the poem
	ifstream myfile("poem.txt");

	//File in which to write the encrypted text
	ofstream out;
	//Clear the data in the output text file to store new encrypted data
	out.open("out.txt", std::ofstream::out | std::ofstream::trunc);
	out.close();

	//if (myfile.is_open())
	//{
	//	while (getline(myfile, line))
	//	{
	//		//get the length of the text
	//		length = line.length();
	//		//This same method can be used to decode a text file that has been used to encode it
	//		for (count = 0; count < length; count++)
	//		{
	//			//Check to see if the text is an alphabet
	//			if (isalpha(line[count]))
	//			{
	//				//This loop is going to run 13 times
	//				for (int i = 0; i < 13; i++)
	//				{
	//					//change the aplhabet to lower case
	//					line[count] = tolower(line[count]);
	//					if (line[count] == 'z')
	//					{
	//						line[count] = 'a';
	//					}
	//					else
	//					{
	//						line[count]++;
	//					}
	//				}
	//			}

	//		}	
	//		cout << line << '\n';
	//		//std::ios:app will append to the end of the file
	//		out.open("out.txt", ios::app);
	//		out << line << "\n";
	//		out.close();



	//	}
	//}	
	//else cout << "Unable to open file";

	//myfile.close();

	EncryptionRot13 e13;
	e13.encryptFile();

	e13.decryptFile();



	system("pause");
	return 0;
}





