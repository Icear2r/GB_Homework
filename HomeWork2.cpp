#include <iostream>

using namespace std;

//Задание 1

int i = 2;
double b = 2.89;
float c = 4.7544f;
long long e = 78'912'355'555'523;
short int g = 255;
char o = 'C';
bool d = true;

//Задание 2 

enum GameSymbol { Empty, Cross, Zero };

//Задание 3

const int SIZE = 3;

int GameTable[SIZE][SIZE] = { Empty, Cross, Empty,
                                   Empty, Empty, Zero,
                                   Zero, Empty, Cross, };

//Задание 4

struct FieldForGame {

    unsigned int GameIsOver : 1;
    unsigned int Gamer1Won : 1;
    unsigned int Gamer2Won : 1;
    unsigned int Draw : 1;
    unsigned int Gamer1Symbol : 1;
    unsigned int Gamer2Symbol : 1;
    
    unsigned int NumberOfParties;
    unsigned int NumbOfPartGamer1Won;
    unsigned int NumbOfPartGamer2Won;
    unsigned int NumbOfPartDraw;
};

//Задание 5

union MyUnion
{
    int i;
    float f;
    char ch;
};

struct MyVariant {

    MyUnion myunion;
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
};

int main()
{
    MyVariant variant;
    
    variant.myunion.i = 3;
    variant.isInt = 1;
    variant.isFloat = 0;
    variant.isChar = 0;

    return 0;
}
