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
int FrequencyNumber(int Number , short DigitToCheck)
{
    int Reminder = 0;
    int frequency = 0;
   while (Number > 0)
   {
   Reminder = Number % 10;//1223222 %10=2
   Number = Number / 10;//1223222 /10=122322
    if (Reminder == DigitToCheck) // 2=2 ?
    {
      frequency++;//0 + 1 =1 | 1 + 1 = 2 
    }
   }
   return frequency;
}
void PrintAllDigitsFrequency(int Number)
{
   short DigitFrequency = 0;
    for(int i =0 ;i< 10 ;i++)
    {
        DigitFrequency = FrequencyNumber(Number,i);//frequency++ بتزيد هنا
        //(1223222,0) | (1223222,1)
        if(DigitFrequency > 0)// 0 > 0 ?| 1 > 0 ?
        {
     cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s) \n";

        }
    }
}
int main()
{
    int Number = ReadPositiveNumber("Please enter the main Number : ");
    PrintAllDigitsFrequency(Number);
}
