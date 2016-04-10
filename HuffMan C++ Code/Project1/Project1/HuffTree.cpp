#include "HuffTree.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <bitset>
#include <Windows.h>
using namespace std;



HuffTree::HuffTree()
{
}


HuffTree::~HuffTree()
{
}

string HuffTree::readFromTextFile(string fileNameIN)
{
	//filenameIN represents the name of the file in which to read from
	ifstream infile(fileNameIN);
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
	//return the data back
	return data;

}

//This method will be used to write the asciii code from the huffTable to a txt file
void HuffTree::writeAciiCodeToFile()
{
	for (int i = 0; i < data.length(); i++)
	{
		//add the ascii code to the asciiCodeData
		asciiCodeData += huffTable.find(data[i])->second;
	}
	//After the asciiCodeData has the the code then add it to the text file
	ofstream asciiCodeFile("AsciiCode.txt");
	if (asciiCodeFile.is_open())
	{
		//Change color of cmd output
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << "\nWriting ASCII code to text file\n";
		//Add the code to the text file
		asciiCodeFile << asciiCodeData;
		cout << "Finished writing to AsciiCode.txt\n";
	}
	else
	{
		cout << "\n*** COULD NOT OPEN FILE TO WRITE ASCII CODE --- FILE NOT FOUND ***\n";
	}
	//close the txt file used for writing the code
	asciiCodeFile.close();
	

}

void HuffTree::buildFreqTable()
{
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
}

//Display the freqTable created above
void HuffTree::displayFreqTable()
{
	//Changes color of the output
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	//*stars have been used, just to make the output look better
	cout << "\n*****************************\n";
	cout << "*\tFrequency Table\t    *\n";
	cout << "*****************************\n";
	cout << "* \tChar \t Freq\t    *\n";

	for (iterator1 = freqTable.begin(); iterator1 != freqTable.end(); iterator1++)
	{
		cout << "* \t " <<iterator1->first << "\t  " << iterator1->second << "\t    *" << endl;
	}
	
	cout << "*****************************\n";

}

void HuffTree::buildHeapTable()
{
	//Add items into the ptQueue
	for (iterator1 = freqTable.begin(); iterator1 != freqTable.end(); iterator1++)
	{
		//Addina a new node to the ptQueue
		ptQueue.push(new HuffNode(iterator1->first, iterator1->second));
	}

	while (ptQueue.size() != 1)
	{
		//This creates a new HuffNode which contains the top element of the ptQueue
		HuffNode* left = new HuffNode(ptQueue.top());
		//Remove the top element from the ptQueue
		ptQueue.pop();

		//This creates a new HuffNode which contains the top element of the ptQueue
		HuffNode* right = new HuffNode(ptQueue.top());
		//Remove the top element from the ptQueue
		ptQueue.pop();

		//Add the left and right nodes to nodeToAdd
		HuffNode* nodeToAdd = new HuffNode(left, right);
		//Add the nodeToAdd back into the ptQueue
		ptQueue.push(nodeToAdd);
	}
	//rootOfNode is set as the root of the ptQueue(TREE)
	rootOfNode = ptQueue.top();
	//Remove the top element of the ptQueue
	ptQueue.pop();

	getHuffmanEncoding(rootOfNode, "");
	displayHuffTable();
}

/***************************************************************************************
*	 BASED ON
*    Title: An In-Depth Look At Huffman Encoding
*    Author: KYA
*    Date: 19/01/2011
*    Code version: 
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/
void HuffTree::getHuffmanEncoding(HuffNode *rootIN, string codeIN)
{
	//If the root of the tree is empty
	if (rootIN == NULL)
	{
		cout << "\n*** THE TREE IS EMPTY ***\n";
	}
	else if (rootIN->getLeft() == NULL) 
	{
		//rootIN->setHuffmanCode(codeIN);
		huffTable.insert(pair<char, string>(rootIN->getLetter(), codeIN));
		
	}
	else
	{

		getHuffmanEncoding(rootIN->getLeft(), codeIN + "0");
		getHuffmanEncoding(rootIN->getRight(), codeIN + "1");
	}
}


void HuffTree::displayHuffTable()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	//*stars have been used, just to make the output look better
	cout << "\n\n\n*****************************\n";
	cout << "*\tHuffman Table\t    *\n";
	cout << "*****************************\n";
	cout << "* \tChar \t Code\t    *\n";

	//loop through the hufftable and print out the character and the asciii code
	for (iterator2 = huffTable.begin(); iterator2 != huffTable.end(); iterator2++)
	{
		cout << "* \t " << iterator2->first <<"\t "  << iterator2->second << "\t    *" << endl;

	}

	cout << "*****************************\n";
}

/***************************************************************************************
*	 BASED ON
*    Title: An In-Depth Look At Huffman Encoding
*    Author: KYA
*    Date: 19/01/2011
*    Code version:
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/
void HuffTree::decodeAsciiFile()
{
	readAscii = readFromTextFile("AsciiCode.txt");

	HuffNode* node = rootOfNode;

	string decodedAscii = "";

	for (int i = 0; i < readAscii.length(); i++)
	{

		if (readAscii[i] == '1')
		{
			//cout << "\nGOING RIGHT";
			node = node->getRight();
		}
		else
		{
			//cout << "\nGOING LEFT";
			node = node->getLeft();
		}

		if (node->getLeft() == NULL && node->getRight() == NULL)
		{
			//decodedAscii.append(node->getLetter());
			decodedAscii += node->getLetter();
			node = rootOfNode;
		}
	}

	cout << "\nDecoded Ascii characters:\n" << decodedAscii << endl;

}


/***************************************************************************************
*	 BASED ON
*    Title: Convert a string of binary into an ASCII string (C++)
*    Author: Craig
*    Date: 28/04/14
*    Code version:
*    Availability: 	http://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
*
***************************************************************************************/
void HuffTree::compressFile()
{
	cout << "\nCompressing Ascii code\n";

	readAscii = readFromTextFile("AsciiCode.txt");

	stringstream stream(readAscii);
	string output;
	while (stream.good())
	{
		bitset<8> bits;
		stream >> bits;
		char c = char(bits.to_ulong());
		output += c;

	}


	cout << "Compressed Ascii Code: " << output << endl;

	ofstream compressedFile("CompressedFile.txt");
	if (compressedFile.is_open())
	{
		compressedFile << output;
		cout << "Finished writing to CompressedFile.txt\n";
	}
	else
	{
		cout << "\n*** COULD NOT OPEN FILE TO WRITE COMPRESSED ASCII CODE --- FILE NOT FOUND ***\n";
	}
	//close the txt file used for writing the code
	compressedFile.close();


}

void HuffTree::decompressFile()
{
	cout << "\n\nDecompressing the file........." << endl;
	string compressedTxt = readFromTextFile("CompressedFile.txt");
	string decompressedTxt;

	bitset<8> bits;

	for (int i = 0; i < compressedTxt.length(); i++)
	{
		bits = compressedTxt[i];
		decompressedTxt += bits.to_string();
	}

	cout << "Decompressed text:\n" <<decompressedTxt << endl;

}
