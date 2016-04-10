#include "EncryptionRot13.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


EncryptionRot13::EncryptionRot13()
{
}

void EncryptionRot13::encryptFile()
{
	cout << "\nEncrypting the poem txt file.........................\n";
	cout << "Encrypted Poem:\n\n";

	//File in which to write the encrypted text
	ofstream out;
	//Clear the data in the output text file to store new encrypted data
	out.open("EncryptedPoem.txt", std::ofstream::out | std::ofstream::trunc);
	out.close();

	//Read in the poem file
	ifstream myfile("poem.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//get the length of the text
			length = line.length();
			//This same method can be used to decode a text file that has been used to encode it
			for (count = 0; count < length; count++)
			{
				//Check to see if the text is an alphabet
				if (isalpha(line[count]))
				{
					//This loop is going to run 13 times
					for (int i = 0; i < 13; i++)
					{
						//change the aplhabet to lower case
						line[count] = tolower(line[count]);
						if (line[count] == 'z')
						{
							line[count] = 'a';
						}
						else
						{
							line[count]++;
						}
					}
				}

			}
			cout << line << '\n';
			//std::ios:app will append to the end of the file
			out.open("EncryptedPoem.txt", ios::app);
			out << line << "\n";
			out.close();



		}
	}
	else cout << "Unable to open file";

	myfile.close();

	cout << "\nWritten to EncryptedPoem.txt.........................\n" << endl;
	cout << "*******************************************************\n";



}

void EncryptionRot13::decryptFile()
{
	cout << "\n\nDecrypting the Encrypted poem.........................\n\n";

	//File in which to write the encrypted text
	ofstream out;
	//Clear the data in the output text file to store new encrypted data
	out.open("DecryptedPoem.txt", std::ofstream::out | std::ofstream::trunc);
	out.close();

	//Read in the poem file
	ifstream myfile("EncryptedPoem.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//get the length of the text
			length = line.length();
			//This same method can be used to decode a text file that has been used to encode it
			for (count = 0; count < length; count++)
			{
				//Check to see if the text is an alphabet
				if (isalpha(line[count]))
				{
					//This loop is going to run 13 times
					for (int i = 0; i < 13; i++)
					{
						//change the aplhabet to lower case
						line[count] = tolower(line[count]);
						if (line[count] == 'z')
						{
							line[count] = 'a';
						}
						else
						{
							line[count]++;
						}
					}
				}

			}
			cout << line << '\n';
			//std::ios:app will append to the end of the file
			out.open("DecryptedPoem.txt", ios::app);
			out << line << "\n";
			out.close();



		}
	}
	else cout << "Unable to open file";

	myfile.close();

	cout << "\nDecrypted poem written to DecryptedPoem.txt..............\n\n";

}


EncryptionRot13::~EncryptionRot13()
{
}
