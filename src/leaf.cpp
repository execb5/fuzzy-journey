#include "leaf.h"
#include "bdata.h"
#include "branch.h"
#include <iostream>
#include <stdexcept>

Node* Leaf::insert(uint32_t index, RowID rowID)
{
	for(size_t i = 0; i < block.size(); i++)
	{
		if (index == block[i].getIndex())
			throw std::runtime_error( "Index already exists" );

		if (index < block[i].getIndex())
		{
			block.insert(block.begin() + i, LData(index, rowID));
			if (block.size() > max_size)
			{
				return split();
			}
			return this;
		}
	}
	block.push_back(LData(index, rowID));
	if (block.size() > max_size)
	{
		return split();
	}
	return this;
}

RowID Leaf::select(uint32_t index)
{
	for(size_t i = 0; i < block.size(); i++)
	{
		if (index == block[i].getIndex()) {
			return block[i].getRowID();
		}
	}
	throw std::runtime_error( "Index not found" );
}

Node* Leaf::split()
{
	size_t const half_size = block.size() / 2;
	std::vector<LData> left_block(block.begin(), block.begin() + half_size);
	std::vector<LData> right_block(block.begin() + half_size, block.end());

	setBlock(left_block);

	Leaf* newLeaf = new Leaf();
	newLeaf->setBlock(right_block);
	newLeaf->setParent(parent);

	uint32_t index = right_block.front().getIndex();
	BData bData(index, this, newLeaf);

	Branch* parentBranch;
	if (!parent)
	{
		parent = new Branch();
		newLeaf->setParent(parent);
		parentBranch = (Branch*) parent;
		parentBranch->addToBlock(bData);

		return parent;
	}

	parentBranch = (Branch*) parent;
	parentBranch->addToBlock(bData);
	return this;
}

int Leaf::myClass()
{
	return 2;
}

void Leaf::setBlock(std::vector<LData> block)
{
	this->block = block;
}

void Leaf::print(std::string level) {
	std::cout << level << "Leaf" << std::endl;
	level += "  ";
	for (auto &ld : block)
		std::cout << level << ld.getIndex() << std::endl;
}

void Leaf::setParent(Node* parent)
{
	this->parent = parent;
}

Node* Leaf::getParent()
{
	return parent;
}
