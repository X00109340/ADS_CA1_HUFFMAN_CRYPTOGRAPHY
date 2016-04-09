#include "HuffTree.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

/*
	HuffTree - Shajun Dominic - X00109340
*/

int main()
{
	//Create an instace of the HuffTree
	HuffTree tree;
	//Print the contents of the Original txt file
	cout << "This is the message in the txt file:\n";
	cout << tree.readFromTextFile("Original.txt") << endl;
	//Build the frquency table with the map<char, int>
	tree.buildFreqTable();
	//Display the freqTable
	tree.displayFreqTable();
	//Build and display the huffTable map<char, string>
	tree.buildHeapTable();
	//Write ascii characters to txt file
	tree.writeAciiCodeToFile();
	//Decode ascii characters from text file
	tree.decodeAsciiFile();

	system("pause");
	return 0;
}