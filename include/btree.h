#ifndef BTREE_H
#define BTREE_H

#include "node.h"
#include "rowid.h"

class BTree
{
	public:
		BTree(Node* root);
		~BTree();
		bool insert(uint32_t index, RowID rowID);
		RowID select(uint32_t index);
	private:
		Node* root;
};

#endif /* BTREE_H */
