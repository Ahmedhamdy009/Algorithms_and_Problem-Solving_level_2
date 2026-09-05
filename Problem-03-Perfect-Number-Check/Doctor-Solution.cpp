#Prof Solution :
#include <iostream>
#include <cmath>
using namespace std;
int ReadPositiveNumber(string Message)
{
   int Number = 0;
   do
   {
      cout<<Message<<endl;
      cin>>Number;
     
   } while (Number <=0);
   return Number;
}
// الارقام المثالية بالتفصيل هيا الارقام الي بنقسمها علي اي رقم بدون باقي
//28 = 1 +2 +4 +7 +14     لغاية لما نوصل ل 28
 bool CheckPerfect (int Number)
{
   int Sum = 0;
   for(int i = 1 ; i < Number; i++)
   {
      if(Number % i == 0)
      Sum +=i;
   }
   return Sum == Number ;
}
void PrintResult(int Number)
   {
      if(CheckPerfect(Number))
      cout<<"\n" << Number <<" Is Perfect Number \n";
      else 
      cout<<"\n" << Number <<" Is  Not Perfect Number \n";

   }
int main() 
{
 PrintResult(ReadPositiveNumber("Please enter a Positive Number "));
}
