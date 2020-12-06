#pragma once
#include <iostream>
#include <vector>

enum class Operation {
	multiplication,
	division
};

std::ostream& operator<<(std::ostream& os, const Operation& q);

struct Question {
	Question() :num1{1}, op{Operation::multiplication}, num2{1} {}
	Question(int n1, Operation o, int n2) :num1{n1}, op{o}, num2{n2} {}
	int num1;
	Operation op;
	int num2;
};

std::ostream& operator<<(std::ostream& os, const Question& q);


Question multiplication(std::vector<int> tables);
Question multiplication();
Question division(std::vector<int> tables);
Question division();

std::vector<Question> questions(Operation op, int n);
std::vector<Question> questions(int n);

int rand_int(int min, int max);