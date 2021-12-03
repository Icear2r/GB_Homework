
#include <iostream>
#include <string>
#include "mylib.h"
#include <fstream>

using namespace std;

#define INSIDE_IN_INTERVAL(a, b) bool c = ((a > 0) && (a < b))? true :  false;\
if (c > 0) std::cout << "true" << endl;\
else std::cout << "false" << endl;

#define SET_SIZE_OF_INT_ARRAY(d) size_t SIZE_ARRAY = d; int Array[d];

#define SwapINT(a,b) int temp;\
temp = a; a = b; b = temp

const size_t CONST_CHAR_ARRAY = 30;

const size_t CONST_SIZE_ARRAY = 10;

#pragma pack(push, 1)
struct Employee 
{ 
    unsigned int ID;

    char FirstName[CONST_CHAR_ARRAY];

    char SecondName[CONST_CHAR_ARRAY];

    int age;

    int salary;
};
#pragma pop

void InitArray(int* array, const size_t n)
{
    std::cout << "Set array" << std::endl;

    for (int i = 0; i < n; i++)
    {
        int j{ 0 };

        std::cin >> j;

        *(array + i) = j;
    }
}

void OrderedArray(int* array, size_t n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - 1; j++) 
        {
            if (*(array + j) > *(array + (j + 1))) 
            {
                SwapINT(*(array + j), *(array + (j + 1)));
            }
        }
    }
}

void PrintArray(int* array, const size_t n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << *(array + i) << " ";
    }

    std::cout << std::endl;
}

int main()
{ 
    //Task 5

    cout << "Task 5" << endl;

    float MyArray[CONST_SIZE_ARRAY];

    MyLib::InitArray(MyArray, CONST_SIZE_ARRAY);

    MyLib::PrintArray(MyArray, CONST_SIZE_ARRAY);

    MyLib::SpecialFunc(MyArray, CONST_SIZE_ARRAY);

    //Task 2

    cout << "Task 2" << endl;

    INSIDE_IN_INTERVAL(3, 30);

    //Task 3

    cout << "Task 3" << endl;

    SET_SIZE_OF_INT_ARRAY(5);

    InitArray(Array, SIZE_ARRAY);

    PrintArray(Array, SIZE_ARRAY);

    OrderedArray(Array, SIZE_ARRAY);

    PrintArray(Array, SIZE_ARRAY);

    //Task 4

    cout << "Task 4" << endl;

    Employee* employee = new Employee;

    employee->ID = 1;

    for (int i = 0; i < CONST_CHAR_ARRAY; i++)
    {
        char name[CONST_CHAR_ARRAY] = "Artur";

        employee->FirstName[i] = name[i];
    }

    for (int i = 0; i < CONST_CHAR_ARRAY; i++)
    {
        char name[CONST_CHAR_ARRAY] = "Sharypov";

        employee->SecondName[i] = name[i];
    }

    employee->age = 26;

    employee->salary = 50000;

    cout << "Size employee " << sizeof(employee) << " byte" << endl;

    cout << "employee " << "ID " << employee->ID << ", First name " << employee->FirstName

        << ", Second name " << employee->SecondName << ", age " << employee->age << ", salary " << employee->salary << endl;

    ofstream fout("employee.txt");

    fout << "employee" << endl;

    fout << employee->ID << " " << employee->FirstName << " " << employee->SecondName << " "

        << employee->age << " " << employee->salary << endl;

    fout.close();

    return 0;
}


