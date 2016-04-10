#ifndef HUFFTREE_H
#define HUFFTREE_H
#include "HuffNode.h"
#include <string>
#include <map>
#include <queue>
#include <iostream>
class HuffTree
{
private:
	//data from the txt file
	string data;
	//asciiCodedData represents the ascii code to be written to text file
	string asciiCodeData;
	//
	string readAscii;

	HuffNode* rootOfNode = NULL;
	//2 maps created below
	//One to store the frequency of characters called freqTable
	map<char, int> freqTable;
	//Second to store the code (asciiCode) called huffTable
	map<char, string> huffTable;

	//This map will be used to iterate through the freqTable when displaying
	map<char, int>::iterator iterator1;
	//This map will be used to iterate through the huffTable when displaying
	map<char, string>::iterator iterator2;

	/***************************************************************************************
	*	 BASED ON
	*    Title: STL priority queue and overloading with pointers
	*    Author: Eric Smith
	*    Date: 26/03/2013
	*    Code version:
	*    Availability: 	http://stackoverflow.com/questions/15646451/stl-priority-queue-and-overloading-with-pointers
	*
	***************************************************************************************/
	priority_queue<HuffNode, vector<HuffNode*>, CompareNodes> ptQueue;
	//Get the encoding
	//PROVIDE URL HERE TO THE WEBSITE
	void getHuffmanEncoding(HuffNode*, string);


public:
	HuffTree();
	~HuffTree();
	//Takes in file name and returns the contents of the text file
	string readFromTextFile(string fileNameIN);
	void writeAciiCodeToFile();
	void buildFreqTable();
	void displayFreqTable();
	void buildHeapTable();
	void displayHuffTable();
	void decodeAsciiFile();
	void compressFile();
	void decompressFile();

	


};
#endif
