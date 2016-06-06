#include "datafile.h"
#include "table.h"
#include "table_entry.h"
#include "datablock.h"
#include <fstream>
#include <iostream>
#include <string>

void print_arruda()
{
	std::string line;
	std::ifstream myfile("data/arruda.txt");
	if (myfile)
	{
		while (getline( myfile, line ))
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
	TableEntry te(1, "Oi td bem com vc");
	TableEntry te2(2, "Sim e com vc");
	DataBlock db(123);
	db.addEntry(te);
	db.addEntry(te2);
	TableEntry te3 = db.getEntry(1);
	TableEntry te4 = db.getEntry(0);

	std::cout << te3.getCode() << std::endl;
	std::cout << te3.getDescription() << std::endl;
	std::cout << te4.getCode() << std::endl;
	std::cout << te4.getDescription() << std::endl;
	return 0;
}
