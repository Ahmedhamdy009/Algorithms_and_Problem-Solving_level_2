#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message<<endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int CountDigitFrequency(int Number, short DigitToCheck)
{
    int Reminder = 0;
    int counter = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        if (Reminder == DigitToCheck)
        {
            counter++;
        }
    }
    return counter;
}
int main()
{
    int Number = ReadPositiveNumber("Please enter the main Number : ");
    short DigitToCheck = ReadPositiveNumber("Please enter one Digit To Check : ");
    //Short عشان احجز مكان اصغر في الزاكرة عشان انا هدخل رقم واحد
    cout << "Digit " << DigitToCheck << " Frequency is " << CountDigitFrequency(Number, DigitToCheck) << " Time(s) \n";
}
