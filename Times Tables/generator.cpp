#include "generator.h"

#include <random>
#include <exception>

int rand_int(int min, int max)
{
	if (min > max)
		throw std::invalid_argument{"rand_int(): min > max"};

	static std::default_random_engine generator;
	generator.seed(std::random_device()());
	return std::uniform_int_distribution<>{min, max}(generator);
}

template<typename T>
T rand_element(std::vector<T> v)
{
	int i = rand_int(0, v.size());
	return v.at(i);
}

bool rand_bool()
{
	return rand_int(0,1);
}

Operation rand_op()
{
	return rand_bool()?Operation::multiplication:Operation::division;
}

std::ostream& operator<<(std::ostream& os, const Operation& op)
{
	switch (op) {
		case Operation::multiplication:
			return os << " × ";
			break;
		case Operation::division:
			return os << " ÷ ";
			break;
		default:
			return os << " invalid ";
			break;
	}
}

std::ostream& operator<<(std::ostream& os, const Question& q)
{
	return os << q.num1 << q.op << q.num2;
}

Question multiplication(std::vector<int> tables)
{
	Question q;
	q.num1 = rand_element(tables);
	q.op = Operation::multiplication;
	q.num2 = rand_element(tables);

	return q;
}

Question multiplication()
{
	return multiplication(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
}

Question division(std::vector<int> tables)
{
	int quotient = rand_element(tables);
	int divisor = rand_element(tables);

	Question q;
	q.num1 = quotient * divisor;
	q.op = Operation::division;
	q.num2 = divisor;

	return q;
}

Question division()
{
	return division(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
}

std::vector<Question> questions(Operation op, int n)
{
	std::vector<Question> qs;

	for (size_t i = 0; i < n; i++)
		switch (op) {
			case Operation::multiplication:
				qs.push_back(multiplication());
				break;
			case Operation::division:
				qs.push_back(division());
				break;
			default:
				break;
		}

	return qs;
}

std::vector<Question> questions(int n)
{
	std::vector<Question> qs;

	for (size_t i = 0; i < n; i++) {
		Operation op = rand_op();
		switch (op) {
			case Operation::multiplication:
				qs.push_back(multiplication());
				break;
			case Operation::division:
				qs.push_back(division());
				break;
			default:
				break;
		}
	}

	return qs;
}

