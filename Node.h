#pragma once
#include <map>
#include "NodeInterface.h"

//EDIT THIS LATER IN DEVELOPMENT
//return values will need to reflect nulls

class Node : public NodeInterface {
public:
	Node(char character, int frequency, Node* leftChild, Node* rightChild) : character(character), frequency(frequency), leftChild(leftChild), rightChild(rightChild) {};
	~Node() {};

	char getCharacter() const;
	int getFrequency() const;
	NodeInterface* getLeftChild() const;
	NodeInterface* getRightChild() const;
	map<char, string> getCharPath(map<char,string> soFar, string currentPath);

private:
	char character;
	int frequency;
	Node* leftChild;
	Node* rightChild;
};