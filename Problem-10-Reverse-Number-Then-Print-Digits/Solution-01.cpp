#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
    cout<<Message;
    cin>>Number;
        
    } while (Number <0);
    return Number;
}
int ReverseNumber(int Number )
{
    int Reminder = 0;
    int Number2 = 0;
   while (Number > 0)//1234
   {
   Reminder = Number % 10;//4 | 3 | 2 | 1
   Number /= 10;//123 | 12 | 1 
   Number2 = Number2 * 10 + Reminder;
   // 0 * 10 + 4 = 4 | 4 * 10 + 3 = 43  ....
   }
   return Number2;//4321
}
void PrintDigits(int Number)
{
    int reminder = 0;
    while (Number > 0)
    {
      reminder =Number % 10 ;
      Number /=10;
      cout<<reminder<<endl;//1234
    }
    
}
int main()
{
PrintDigits(ReverseNumber(ReadPositiveNumber("please enter the positive Number ?")));
}
