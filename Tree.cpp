#include "Tree.h"

NodeInterface* Tree::getRootNode() const {
	if (rootNode == nullptr) {
		return NULL;
	}
	return rootNode;
}

Node* Tree::cheaterGetRootNode() {
	return rootNode;
}