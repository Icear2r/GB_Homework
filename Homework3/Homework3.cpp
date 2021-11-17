//  Author Sharypov Artur
// 16.11.2021

#include <iostream>
#include <clocale>

using namespace std;

/* Задание 2
Дано целое число. Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21. 
Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. 
При выполнении задания следует использовать тернарный оператор (?:).
*/

int number = 73;

int difference;

/* Задание 3
Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива 
и при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1].
*/

const int SIZE = 3;


int Array[SIZE][SIZE][SIZE];
int* pArr = nullptr;

/* Задание 4
 Написать программу, вычисляющую выражение из первого задания, а переменные для неё объявлены и инициализировать в другом cpp файле. 
 Используйте extern.
*/

extern int a1, b1, c1, d1;
extern float e;

int main()
{
    setlocale(LC_ALL, "Russian");

    //2

    difference = (number <= 21) ? (number - 21) : (2 * (number - 21));

    std::cout << "Задание 2" << std::endl;
    std::cout << "difference = " << difference << std::endl;

    //3

    pArr = &Array[0][0][0];

    for (a1 = 0; a1 < SIZE* SIZE*SIZE; a1++) {

       pArr[a1] = a1 + 5;
    }
          
    std::cout << "Задание 3" << std::endl;
    std::cout << "Array[1][1][1] =" << *(pArr + 13) << std::endl;

    //4

    e = a1 * (b1 + (static_cast<float> (c1) / d1));

    std::cout << "Задание 4" << std::endl;
    std::cout << "e = " << e << std::endl;

    return 0;

}
