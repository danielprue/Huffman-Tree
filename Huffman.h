#pragma once
#include "HuffmanInterface.h"
#include "Tree.h"
#include "Node.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

class Huffman : public HuffmanInterface {
public:
	Huffman() : myTree(nullptr) {};
	~Huffman() {};

	bool createTree(string filename);
	string encodeMessage(string toEncode);
	string decodeMessage(string toDecode);
	TreeInterface* getTree();
	map<char, string> getEncodings();

private:
	Tree* myTree;
};