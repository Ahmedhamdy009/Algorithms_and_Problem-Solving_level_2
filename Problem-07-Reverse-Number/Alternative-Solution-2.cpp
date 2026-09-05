#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void ReverseNumber(int Number)
{
    int Remainder = 0;
    int  inverse = 0;
    int New = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        inverse = inverse * 10 + Remainder;
       
    }

    while (inverse > 0) {

        New = inverse % 10;
        inverse = inverse / 10;
        cout << New << endl;
    }
    
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a Number: ");
    ReverseNumber(Number);
    return 0;
}    // هذا هو حلي الخاص لكن حل الاستاذ اسهل
