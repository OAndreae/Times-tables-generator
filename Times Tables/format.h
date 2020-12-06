#pragma once
#include <iostream>
#include <fstream>
#include <vector>

namespace format {
	
	template<typename T> 	
	void print_tbl(const std::vector<T>& v, int columns, char del, std::ostream& os);

	//template<typename T> void print_tbl(const std::vector<T>& v, int columns, char del);
	//template<typename T> void print_tbl(const std::vector<T>& v, int columns);

	template<typename T>
	void print_table(std::vector<T> v, int columns);


}