#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);

    return Number;
}

int ReverseNumbers(int Number)
{
    int Reminder = 0;
    int M = 0;

    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        M = M * 10 + Reminder;
    }

    return M;
}

bool IsPalindrome(int Number, int M)
{
    return Number == M;
}

int main()
{
    int Num = ReadPositiveNumber("Please Enter The Number:");
    int Rev = ReverseNumbers(Num);

    if (IsPalindrome(Num, Rev))
        cout << "Yes, it is a Palindrome number\n";
    else
        cout << "No, it is NOT a Palindrome number\n";
}
