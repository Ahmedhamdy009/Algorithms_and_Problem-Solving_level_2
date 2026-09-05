#include <iostream>
#include <cmath>
using namespace std;
 enum enPerfectOrNotPerfect {Perfect = 1 , NotPerfect = 0};
 int ReadPositiveNumber(string Message)
 {
    int Number = 0 ;
    do
    {
      cout<<Message<<endl;
      cin>>Number;
    } while (Number <= 0);
    return Number;
 }
 enPerfectOrNotPerfect CheckPerfect(int Number)
 {
  int Sum = 0 ;
  for(int i = 1 ; i < Number; i++)
  {
    if(Number % i == 0)
    Sum +=i;

  }
  if(Sum == Number)
 return enPerfectOrNotPerfect::Perfect;
 else
 return enPerfectOrNotPerfect::NotPerfect;
 }
void PrintPerfectNumberFrom1ToN(int Number)
   {
      for(int i = 1 ; i <= Number ; i++)
      {
         if(CheckPerfect(i) == enPerfectOrNotPerfect::Perfect)
         cout<< i <<"\t";
      }
   }
int main()
{
 PrintPerfectNumberFrom1ToN(ReadPositiveNumber("Please enter a positive Number :"));
}
