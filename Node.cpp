#include "Node.h"

char Node::getCharacter() const {
	return character;
}

int Node::getFrequency() const {
	return frequency;
}

NodeInterface* Node::getLeftChild() const {
	return leftChild;
}

NodeInterface* Node::getRightChild() const {
	return rightChild;
}

map<char, string> Node::getCharPath(map<char,string> soFar, string currentPath) {
	//if the current node is a leaf node, then add that character's path to the map
	if (character != NULL) {
		soFar[character] = currentPath;
	}
	//call function on the left child if it exists
	if (leftChild != nullptr) {
		currentPath += "0";
		getCharPath(soFar, currentPath);
	}
	//call function on the right child if it exists
	if (rightChild != nullptr) {
		currentPath += "1";
		getCharPath(soFar, currentPath);
	}

	return soFar;
}