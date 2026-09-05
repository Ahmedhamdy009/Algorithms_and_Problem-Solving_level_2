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
 bool isPerfectNumber (int Number)
{
   int Sum = 0;
   for(int i = 1 ; i < Number; i++)
   {
      if(Number % i == 0)
      Sum +=i;
   }
   return Sum == Number ;
}
void PrintPerfectNumberFrom1ToN(int Number)
   {
      for(int i = 1 ; i <= Number ; i++)
      {
         if(isPerfectNumber(i))
         cout<< i <<"\t";
      }
   }
int main() 
{
 PrintPerfectNumberFrom1ToN(ReadPositiveNumber("Please enter a Positive Number "));
}
/*
💥 الخلاصة البسيطة جدًا

الرقم المثالي =
"رقم القواسم بتاعته ترجعله تاني"

🎯 ليه هم قليلين؟

لأن الشرط ده صعب يتحقق جدًا

يعني لازم:

القواسم تكون مظبوطة جدًا
لا تزيد ولا تقل
///
يعني من 1 ل500
مفيش ارقام بترجع نفس الناتج غير  
ال 6   28  496

*/
