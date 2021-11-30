
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>


using namespace std;

//Task 1

int* CreateDynamicArray(int n)
{
    int* ptrArr = new int[n];

    return ptrArr;
}

void InitArray(int* ptr, int n)
{
    const int CONST_TWO = 2;

    for (int i = 0; i < n; i++)
    {
        ptr[i] = pow(CONST_TWO, i);
    }
}

void PrintArray(int* ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

//Task 2

const size_t CONST_LINE = 4;

const size_t CONST_COLUMN = 4;

int** CreateComplexArray(const size_t line, const size_t column)
{
   int** ptr = new int* [line];

    for (size_t i = 0; i < column; i++)
    {
        ptr[i] = new int[column];
    }

    return ptr;
}

void InitComplexArray(int** ptr)
{
    srand(time(0));

    for (size_t i = 0; i < CONST_LINE; i++)
    {
        for (size_t j = 0; j < CONST_COLUMN; j++)
        {
            ptr[i][j] = rand() % 100;
        }
    }
}

void PrintComplexArray(int**ptr)
{
    for (size_t i = 0; i < CONST_LINE; i++)
    {
        for (size_t j = 0; j < CONST_COLUMN; j++)
        {
            cout << ptr[i][j] << " ";

            if (j == 3) cout << endl;
        }
    }
}

//Task 3

void CreateTwoFile(string name1, string name2)
{
    ofstream fout1(name1);

    ofstream fout2(name2);

    for (unsigned int i = 65; i < 123; i++)
    {
        unsigned int j = i - 17;

        fout1 << static_cast<char>(i);

        if (i % 20 == 0) fout1 << endl;

        fout2 << static_cast<char>(j);

        if (i % 20 == 0) fout2 << endl;
    }

    fout1 << endl;

    fout2 << endl;

    fout1.close();

    fout2.close();
}

// Task 4

void MergeInThirdFile(string name1, string name2)
{
    const int MAX = 80;

    char buffer[MAX];

    ifstream fin1(name1);

    ifstream fin2(name2);

    ofstream fout3("merger.txt");

    while(!fin1.eof())
    {
        fin1.getline(buffer, MAX);

        fout3 << buffer << endl;
    }

    while(!fin2.eof())
    {
        fin2.getline(buffer, MAX);

        fout3 << buffer << endl;
    }

    fin1.close();

    fin2.close();

    fout3.close();
}

// Task 5

bool FindText(string findstring, string filename)
{
    bool Flag = false;

    const int MAX = 80;

    char buffer[MAX];

    int pos;

    string text;

    ifstream fin(filename);

    while(!fin.eof())
    {
          fin.getline(buffer, MAX);

          for (int i = 0; i < MAX; i++)
          {
              text += buffer[i];
          }

     pos = text.find(findstring);

     if (pos != -1) Flag = true;
}
    fin.close();

    return Flag;
}

int main()
{
    //Task 1

    int* ptrArray;

    int NumberOfUnitArray;

    cout << "Set number of unit array" << endl;

    cin >> NumberOfUnitArray;

    ptrArray = CreateDynamicArray(NumberOfUnitArray);

    InitArray(ptrArray, NumberOfUnitArray);

    PrintArray(ptrArray, NumberOfUnitArray);

    delete[] ptrArray;

    ptrArray = nullptr;

    //Task 2

    int** ptrComplexArray{};

    ptrComplexArray = CreateComplexArray(CONST_LINE, CONST_COLUMN);

    InitComplexArray(ptrComplexArray);

    PrintComplexArray(ptrComplexArray);

    for (int i = 0; i < CONST_COLUMN; i++)
    {
        delete[] ptrComplexArray [i];
    }

    delete[] ptrComplexArray;

    ptrComplexArray = nullptr;

    //Task 3

    string filename1, filename2;

    cout << "Set file name N1" << endl;

    filename1 = "file1";

    //getline(cin, filename1);

    //getch();

    cout << "Set file name N2" << endl;

    filename2 = "file2";

    //getline(cin, filename2);

    //getch();

    filename1 += ".txt";

    filename2 += ".txt";

    CreateTwoFile(filename1, filename2);

    //Task 4

    MergeInThirdFile(filename1, filename2);

    //Task 5

    string strABC = "?";

    cout << FindText(strABC, "merger.txt");

}


