#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
    cout<<Message<<endl;
    cin>>Number;
    } while (Number <= 0);
    return Number;
}
int ReverseNumbers(int Number)
{
   int Reminder = 0 , Number2 = 0;
   while (Number > 0)
   {
       Reminder = Number % 10;//1234 % 10 =4  
       Number = Number / 10 ;//1234 / 10 =123
       Number2 = Number2 * 10 + Reminder ;
    }
   return Number2;
}

int main()
{
    int Reverse ;
    Reverse =  ReadPositiveNumber("please enter a ReadPositiveNumber: ");
    cout<<"Reverse is : \n"<<ReverseNumbers(Reverse);
    //هنا في ملحوظة هنا بيطلع الرقم كامل مش رقم رقم  يعني لو عملت 1234 هيطلع 4321 كامل مش كل رقم لوحده
    //cout<<"Reverse is : \n"<<ReverseNumbers(Reverse)<<endl;
   // هنا هيطلع الرقم كامل مش كل رقم لوحده
}
