// classworkIterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Llist.h"

using namespace std;



template<typename T>
struct ComplexNumber
{
	using value_type = T;

	T x, y;
};

template<typename T>
struct NormalNumber
{
	using value_type = T;

	T x;
};

template<typename T>
typename T::value_type sumOfWhatever(const T& num1, const T& num2)
{
	return num1.x + num2.x;
}

template<typename Container>
typename Container::value_type sum(const Container& container)
{
	typename Container::value_type returnSum = 0;
	for (typename Container::iterator i = container.begin(); i != container.end(); ++i)
	{
		returnSum += *i;
	}
	return returnSum;
}

int main()
{
	ComplexNumber<int> num1 = { 1, 2 };
	ComplexNumber<int> num2 = { 2, 2 };
	cout << sumOfWhatever(num1, num2);


	NormalNumber<int> num3 = { 1 };
	NormalNumber<int> num4 = { 2 };
	cout << sumOfWhatever(num3, num4);

	SLL<int> list;
	list.push(5);
	list.push(4);
	list.push(3);
	list.push(2);
	list.push(1);

	cout << endl;
	for (int x : list)
	{
		cout << x << endl;
	}

	cout << sum(list);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
