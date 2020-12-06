#include "format.h"
namespace format {

	/// <summary>
	/// BUG!!
	/// </summary>
	template<typename T>
	void print_tbl(const std::vector<T>& v, int columns, char del, std::ostream& os)
	{
		double d = v.size() / static_cast<double>(columns);
		int rows = std::ceil(d); // find maximum no. of rows

		for (int i = 0; i<rows; ++i) {
			for (int j = 0; j<columns; ++j) {
				int item = (i * columns) + j;

				// prevent invalid references
				if (item==v.size())
					return;

				os << v.at(item) << del;
			}
			os << "\n";
		}
	}

	//template<typename T>
	//void print_tbl(const std::vector<T>& v, int columns, char del)
	//{
	//	print_tbl(v, columns, del, std::cout);

	//}
	//template<typename T>
	//void print_tbl(const std::vector<T>& v, int columns)
	//{
	//	print_tbl(v, columns, '\t', std::cout);
	//}
	template<typename T>
	void print_table(std::vector<T> v, int columns)
	{
	}
}