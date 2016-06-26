#ifndef LEAF_H
#define LEAF_H

#include "node.h"
#include "rowid.h"
#include "ldata.h"
#include <cstdint>
#include <vector>

class Leaf : public Node
{
	public:
		virtual Node* insert(uint32_t index, RowID rowID);
		virtual RowID select(uint32_t index);
		virtual bool hasIndex(uint32_t index);
		virtual int myClass();
		Node* split();
		void setBlock(std::vector<LData> block);
		virtual void setParent(Node *parent);
		virtual Node* getParent();
		virtual void print(std::string level);


	private:
		std::vector<LData> block;
};

#endif /* LEAF_H */
