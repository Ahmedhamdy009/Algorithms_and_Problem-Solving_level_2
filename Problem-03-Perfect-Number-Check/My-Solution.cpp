#include <iostream>
#include <cmath>
using namespace std;
enum enPerfectOrNotPerfect { Perfect = 1, NotPerfect = 0};
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
enPerfectOrNotPerfect checkPerfect(int Number)
{
   int Sum = 0;
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
void PrintResult(int Number)
   {
      if(checkPerfect(Number) == enPerfectOrNotPerfect::Perfect)
      cout<<"\n" << Number <<" Is Perfect Number \n";
      else 
      cout<<"\n" << Number <<" Is  Not Perfect Number \n";

   }
int main() 
{
 PrintResult(ReadPositiveNumber("Please enter a Positive Number "));
}
