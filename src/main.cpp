#include "datafile.h"
#include "table.h"
#include "table_entry.h"
#include "datablock.h"
#include "rowid.h"
#include "leaf.h"
#include "branch.h"
#include "btree.h"
#include <fstream>
#include <iostream>
#include <string>

void print_arruda()
{
	std::string line;
	std::ifstream myfile("data/arruda.txt");
	if (myfile)
	{
		while (getline(myfile, line))
		{
			std::cout << line << std::endl;
		}
		myfile.close();
	}
	else
		std::cout << "fooey\n" << std::endl;
}

int main()
{

	std::ifstream ifile("datafile.part");
	if (!ifile)
		Datafile::init();

	Table table;

	RowID rowid1 = table.newEntry("matthias gay");

	table.saveData();

	Branch b;
	Leaf l;
	b.insert(32, rowid1);
	l.insert(32, rowid1);

	BTree btree(new Leaf());
	std::cout << btree.insert(32, rowid1) << std::endl;
	RowID id = btree.select(32);
	std::cout << id.getBlockNumber() << " " << id.getPosition() << std::endl;

	return 0;
}
