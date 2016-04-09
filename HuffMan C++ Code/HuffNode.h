#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <string>
#include <iostream>
using namespace std;
class HuffNode
{
	friend class CompareNodes;
	friend class HuffTree;
private:
	//holds the frequency of the letters
	int freq;
	// letter represents the characters in the text
	char letter;
	//Pointer to the left of the node
	HuffNode* left;
	//Pointer to the right of the node
	HuffNode* right;
	//pointer to the root of the node
	HuffNode* root;
	string asciiCode;// maybe not needed

public:
	HuffNode();

	HuffNode(char letterIN, int freqIN);
	HuffNode(HuffNode* nodeIN);
	HuffNode(HuffNode* leftIN, HuffNode* rightIN);
	~HuffNode();

	//Returns the frequency of each character
	int getFrequency();
	//Returns the letter
	char getLetter();
	//Returns the left node
	HuffNode* getLeft();
	//Returns the right node
	HuffNode* getRight();
	//Returns the root node
	HuffNode* getRoot();
	//Returns the asciiCode (MAYBE NOT NEEDED)
	string getAsciiCode(); //maybe not needed

};

class CompareNodes
{
	friend class HuffTree;

public:
	bool operator()(HuffNode* node1IN, HuffNode* node2IN);

};

#endif