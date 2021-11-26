//Sharypov Artur 11.25.2021

#include <iostream>
#include <cstdlib>

using namespace std;

//
/*
1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. 
Вызвать эту функцию из main.

2.Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.

3. Задать пустой целочисленный массив размером 8. 
Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран. 

4. Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), 
при этом метод должен циклически сместить все элементы массива на n позиций.

5. Написать функцию, которой передается не пустой одномерный целочисленный массив, 
она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. 
Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, 
checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
*/

const size_t SIZE = 5;

const size_t SpecialSIZE = 8;

void PrintArray(double*, const size_t);

void PrintArray(int*, const size_t);

void ReplaceArray(int*, const size_t);

void DisplaceArray(int*, int);

void FillArray(int*, const size_t);

bool CheckArray(int*);

int main()
{
	//Task 1

	double Array[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{

		Array[i] = i + 1;
	}

	PrintArray(Array, SIZE);

	//Task 2

	int IntArray[SIZE * 2] = { 0 };

	FillArray(IntArray, SIZE * 2);

	PrintArray(IntArray, SIZE * 2);

	ReplaceArray(IntArray, SIZE * 2);

	PrintArray(IntArray, SIZE * 2);

	//Task 3

	int EmptyArray[SpecialSIZE] = { 0 };

	for (int i = 0; i < SpecialSIZE; i++)
	{

		EmptyArray[i] = i * 3 + 1;
	}

	PrintArray(EmptyArray, SpecialSIZE);

	//Task 4

	int n = 0;

	FillArray(IntArray, SIZE);

	PrintArray(IntArray, SIZE);

	cout << "Enter number of displace" << endl;

	cin >> n;

	DisplaceArray(IntArray, n);

	//Task 5 

	int NewArray[5] = {0, 1, 3, 4, 2};
	

	PrintArray(IntArray, 5);

	cout << CheckArray(IntArray) << endl;
}

	void PrintArray(double* array, const size_t size)
{

	for (int i = 0; i < size; i++) {
		
		cout << *(array + i) << " ";
	}

	cout << endl;
}

void PrintArray(int* array, const size_t size)
{

	for (int i = 0; i < size; i++) {

		cout << *(array + i) << " ";
	}

	cout << endl;
}

void ReplaceArray(int* array, const size_t size) 
{

	for (int i = 0; i < size; i++)
	{

		if (*(array + i) == 0) *(array + i) = 1;

		else *(array + i) = 0;
	}
}

void FillArray(int* array, const size_t size)
{

	srand(time(0));

	for(int i = 0; i < size; i++)
	{
	
		*(array + i) = rand() % 2;
	}
}

void DisplaceArray(int* array, int n)
{

	//const int size = sizeof(array) / sizeof(array[0]); vmesto rasmera massiva 5 vidayot 2

	int fArray[SIZE] = { 0 };

	int j;

	for(int i = 0; i < SIZE; i++)
	{
	
		if (n > 0) {

			if (n > SIZE) j = n % SIZE;

			else j = n;

			if ( i < j) *(fArray + i) = *(array + (SIZE - j + i));

			else *(fArray + i) = *(array + (i - j));
		}
			
		else 
		{

			if (n > SIZE) j = -n % SIZE;

			else j = -n;

			if (j - 1 - i >= 0) *(fArray + (SIZE - i -1)) = *(array + (j - 1 - i));

			else   *(fArray + (SIZE - i - 1)) = *(array + (SIZE -1 + j - i));
		}
	 
	}

	for (int i = 0; i < SIZE; i++)
	{
		*(array + i) = *(fArray + i);

	}
}

bool CheckArray(int* array)
{
	int result = 0;

	bool flag = false;

 for (int i = 0; i <SIZE; i++)
 {
	 result += *(array + i);
 }

 for (int i = 0; i < SIZE; i++)
 {
	 int res = 0;

	 res += *(array + i);

	 if (result - res == res)  flag = true;
	
	 return flag;
 }
}