#include "HuffNode.h"
#include <string>
using namespace std;



HuffNode::HuffNode()
{
	freq = 0;
	letter = ' ';
	left = NULL;
	right = NULL;
	root = NULL;
	asciiCode = " ";//maybe not needed
}

HuffNode::HuffNode(char letterIN, int freqIN)
{
	letter = letterIN;
	freq = freqIN;
	left = NULL;
	right = NULL;
}

HuffNode::HuffNode(HuffNode * nodeIN)
{
	letter = nodeIN->letter;
	freq = nodeIN->freq;
	if (nodeIN->left != NULL)
	{
		left = nodeIN->left;
	}
	if (nodeIN->right != NULL)
	{
		right = nodeIN->right;
	}
}

HuffNode::HuffNode(HuffNode * leftIN, HuffNode * rightIN)
{
	left = leftIN;
	right = rightIN;
	//letter = ' ';
	letter = NULL;
	freq = left->getFrequency() + right->getFrequency();
}

//Delete the nodes
HuffNode::~HuffNode()
{
	if (left != NULL)
	{
		delete left;
	}
	if (right!= NULL)
	{
		delete right;
	}
	//if (root != NULL)
	//{
	//	delete root;
	//}
}

//Returns the frequency of a character in the node
int HuffNode::getFrequency()
{
	return freq;
}

//Returns the letter of a node
char HuffNode::getLetter()
{
	return letter;
}

//Returns the reference to the left child
HuffNode * HuffNode::getLeft()
{
	return left;
}

//Returns the reference to the right child
HuffNode * HuffNode::getRight()
{
	return right;
}

//Returns the reference to the root
HuffNode * HuffNode::getRoot()
{
	return root;
}

string HuffNode::getAsciiCode()
{
	return asciiCode;
}

//To compare frequency of the 2 nodes passed in as parameters
bool CompareNodes::operator()(HuffNode * node1IN, HuffNode * node2IN)
{
	if (node1IN->getFrequency() > node2IN->getFrequency())
	{
		return true;
	}
	else
	{
		return false;
	}
}
