// Oliver Andreae 11/1/2018
// Outputs random times tables as division
// and multiplication questions

/*
	Options
	- times tables to include
	- multiplication/divions questions
	- format
		- list
		- table (x by y)

	Task order
	- input options
	- generate times tables vector
	- randomly select amount of calculations requested
		from tt vector
	- output as requested (list or table)
*/

#include "format.h"
#include "generator.h"

#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>
#include <vector>

//struct Table {
//	int columns;
//	int rows;
//};
//
//struct Options {
//	std::vector<int> times_tables;
//	std::vector<Operation> operations;
//};
//
//
//
//int main()
//try {
//	std::vector<char> chs{
//		'a',
//		'b',
//		'c',
//		'd',
//		'e',
//		'f',
//		'g',
//		'h'
//	};
//
//	print_tbl(chs, 2);
//
//	pause();
//
//} catch (const std::exception& e) {
//	std::cerr << "error: " << e.what() << '\n';
//	pause();
//}

void pause()
{
	std::cout << "Please enter a character to continue...";

	// wait for input
	char c;
	std::cin.clear();
	std::cin >> c;
}

template <typename T>
void print_table(const std::vector<T>& v, int columns, char del, std::ostream& os)
{
	double d = v.size() / static_cast<double>(columns);
	int rows = std::ceil(d); // find maximum no. of rows

	for (int i = 0; i<rows; ++i) {
		for (int j = 0; j<columns; ++j) {
			int item = (i * columns) + j;

			// prevent invalid references
			if (item==v.size())
				return;

			os << v.at(item) << " = ";
			
			// avoid extra column
			if(j!=columns-1)
				os << del;
		}
		os << "\n";
	}
}

std::vector<Question> times_tables(int start, int end, bool repeats, bool div)
{
	std::vector<Question> tts;

	// each times table from start to end
	for (int i = start; i < end+1; ++i) {
		// multiples up to 12
		// should include repeats? e.g. 7*1 and 1*7
		for (int j=repeats?1:i; j<13; ++j) {
			Question q;
			q.num1 = i;
			q.op = Operation::multiplication;
			q.num2 = j;

			tts.push_back(q);
		}
	}

	if (div) {
		// each times table from start to end
		for (int i = start; i < end+1; ++i) {
			// multiples up to 12
			// should include repeats? e.g. 7*1 and 1*7
			for (int j = repeats?1:i; j<13; ++j) {
				Question q;
				// multiply 'answer'
				q.num1 = i * j;
				q.op = Operation::division;
				q.num2 = j;
				
				// quotient = i

				tts.push_back(q);
			}
		}
	}

	return tts;
}

template <typename T>
std::vector<T> random_elements(int n, const std::vector<T>& v)
{
	std::vector<T> v2;
	v2.reserve(n);

	// copy elements
	for (auto& i : v2)
		i = v.at(rand_int(0, v.size()-1));

	return v2;
}

int main()
try {
	std::vector<Question> t_tbls = times_tables(1, 12, true, true);
	
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(t_tbls.begin(), t_tbls.end(), g);
	
	//std::cout << "amount of questions: ";
	//int n;
	//std::cin >> n;

	t_tbls.resize(52);


	std::ofstream osf{"times_tables.txt"};

	//std::cout << "amount of columns: ";
	//int c;
	//std::cin >> c;

	print_table(t_tbls, 4, '\t', osf);

	//std::cout << "Times tables output to times_tables.txt\n";

	//pause();

} catch (const std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	pause();
}
