#pragma once
#include "TreeInterface.h"
#include "Node.h"

class Tree : public TreeInterface {
public:
	Tree(Node* rootNode) : rootNode(rootNode) {};
	~Tree() {};

	NodeInterface* getRootNode() const;
	Node* cheaterGetRootNode();

private:
	Node* rootNode;
};