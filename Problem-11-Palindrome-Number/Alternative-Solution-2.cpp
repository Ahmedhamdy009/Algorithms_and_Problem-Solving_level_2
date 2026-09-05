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
int ReverseNumber(int Number)
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
 bool IsPalindrome(int Number)
 {
  return Number == ReverseNumber(Number);
 }
int main()
{
  int Num = ReadPositiveNumber("please enter the positive Number ?");

  //طريقة اطبع الرقم قبل الناتج
//    if(IsPalindrome(Num))
//   cout<<Num<<" Yes , it is a Palindrome Number ";
//   else
//   cout<<Num<<" No , it is Not a Palindrome Number ";
  
//طريقة لطباعة الرقم الاصلي قبل الناتج زي الي فوق

//   cout << "Number = " << Num << endl;

// if (IsPalindrome(Num))
//     cout << "Yes, it is a Palindrome Number";
// else
//     cout << "No, it is Not a Palindrome Number";
  
  //طريقة طباعة الرقم الاصلي والمعكوس قبل الناتج

cout << "Number          : " << Num << endl;
cout << "Reversed Number : " << ReverseNumber(Num) << endl;

if (IsPalindrome(Num))
    cout << "Yes, it is a Palindrome Number";
else
    cout << "No, it is Not a Palindrome Number";
}
// استخدمنا هنا bool لسهولة الحل الافضل اما لو استخدمنا int او غيره لازم اعمل كدا
/*
int IsPalindrome(int Number)
{
    if (Number == ReverseNumber(Number))
        return 1;
    else
        return 0;
}
*/
