#include "Huffman.h"

//Almost complete
//Minor ordering issue, otherwise functional
bool Huffman::createTree(string filename) {
	//read in a filename and cancel out if it's no good
	ifstream myfile(filename);

	if (myfile.fail()) {
		myfile.clear();
		return false;
	}

	//string parceMe = "";
	//string line;

	//this should put the whole file into the parce me string I hope?
	//outfile 1 is doubling the string here I think...
	//ifstream infile{ "file.txt" };
	string parceMe{ istreambuf_iterator<char>(myfile), istreambuf_iterator<char>() };
	
	//while (myfile) {
	//	getline(myfile, line);
	//	parceMe = parceMe + line;
	//}

	istringstream iss(parceMe);

	//create a map to cout up frequencies
	map<char, int> tally;
	char c;
	//loop here to give every character a node and frequency
	while (iss.get(c)) {
		//first check if there is already a node for that character:
		if (tally.find(c) == tally.end()) {
			tally[c] = 1;
		}
		else {
			tally[c]++;
		}
	}

	//give everything in map a Node and add it to a vector
	//take *(tally.begin()), make it into a node, put that into a vector, and delete *(tally.begin()) from map
	vector<Node*> allNodes;
	while (!tally.empty()) {
		Node* temp = new Node(tally.begin()->first, tally.begin()->second, nullptr, nullptr);
		allNodes.push_back(temp);
		//delete temp?
		tally.erase(tally.begin());
	}

	//sort(allNodes.begin(), allNodes.end(), sorter);

	//combine nodes here until there is only a root node
	while (allNodes.size() > 1) {
		Node* temp = new Node(NULL, allNodes[0]->getFrequency() + allNodes[1]->getFrequency(), allNodes[0], allNodes[1]);
		
		int i = 0;
		bool checker = true;
		while (checker) {
			if (i == allNodes.size()) {
				allNodes.insert(allNodes.end(), temp);
				checker = false;
			}
			//first check if the frequency is less than where we are at
			//if it is, then insert the node here
			if (temp->getFrequency() < allNodes[i]->getFrequency()) {
				allNodes.insert(allNodes.begin() + i, temp);
				checker = false;
			}
			//if the nodes have the same frequency, then we check the next one?
			//leaves come first and older nodes come first so...
			else if (temp->getFrequency() == allNodes[i]->getFrequency()) {
				i++;
			}
			//if the frequency is greater then we just loop to the next item
			else {
				i++;
			}
		}
		
		allNodes.erase(allNodes.begin());
		allNodes.erase(allNodes.begin());
		//allNodes.push_back(temp);
		//sorter might not work with combined Nodes?
		//sort(allNodes.begin(), allNodes.end(), sorter);
	}


	//making a blank tree here just so the code will run
	myTree = new Tree(allNodes[0]);

	return true;
}

string Huffman::encodeMessage(string toEncode) {
	return "";
}

string Huffman::decodeMessage(string toDecode) {
	return "";
}

//Done #EZPZ
TreeInterface* Huffman::getTree() {
	return myTree;
}

map<char, string> Huffman::getEncodings() {
	map<char, string> mapping;
	myTree->cheaterGetRootNode()->getCharPath(mapping, "");

	return mapping;
}