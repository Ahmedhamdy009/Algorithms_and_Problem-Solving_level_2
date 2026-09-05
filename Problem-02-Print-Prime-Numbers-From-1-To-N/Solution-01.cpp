#include <iostream>
#include <cmath>
using namespace std;
enum enPrimeOrNotPrime { Prime = 1, NotPrime = 2};
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
enPrimeOrNotPrime checkPrime(int Number)
{
   int M =round(Number / 2);//10/2 = 5
   for(int Counter = 2 ; Counter<=M;Counter++)
   {
      if(Number % Counter == 0)
      return enPrimeOrNotPrime::NotPrime;
   }
   return enPrimeOrNotPrime::Prime;
}
void PrintPrimeNumbersFrom1ToNumber(int Number)
   {
      cout<<"Prime Number From "<<1<<" To "<<Number<<" are : \n";
      for(int i = 1;i<=Number;i++)
      {
         //هنا اطلع من بين الرقم الي انا دخلتو الارقام الاولية
         if(checkPrime(i) ==enPrimeOrNotPrime::Prime )
         {
            cout<< i <<endl;
         }
      }
   }
   /*
   دي لو عايزه يقولي الرقم الي انا دخلته دا اولي ولا لا فقط
    void PrintPrimeNumbersFrom1ToNumber(int Number)
 {
    cout<<"Prime Number From "<<1<<" To "<<Number<<" are : \n";

        if(CheckPrime(Number) == enPrimeOrNotPrime::Prime)
        
            cout<<"the Number is Prime";
            else
            cout<<"the Number is  Not Prime";
        

 }
 */
 2
 /*
 دي او عايزها كمان يطبعلي الارقام كلها ويقولي هيا اولية ولا لا
  void PrintPrimeNumbersFrom1ToNumber(int Number)
 {
    cout<<"Prime Number From "<<1<<" To "<<Number<<" are : \n";
    for(int i = 1; i <= Number; i++)
    {

        cout<<i<<" -> ";
        if(CheckPrime(i) == enPrimeOrNotPrime::Prime)
        
            cout<< "Prime";
            else
            cout<< "Not Prime";
            cout<<endl;
    }
 }
 */
int main() 
{
 PrintPrimeNumbersFrom1ToNumber(ReadPositiveNumber("Please enter a Positive Number "));
}
