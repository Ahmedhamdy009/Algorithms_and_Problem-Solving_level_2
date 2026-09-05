#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
    cout<<Message<<endl;
    cin>>Number;//1234
    } while (Number < 0);
    return Number;
}
int ReverseNumbers (int Number )
{
    int Reminder = 0;
    int Number2 = 0;
    while (Number > 0)
    {
        Reminder = Number % 10 ;// 4 | 3 | 2 | 1
        Number = Number /10;//123 |12 | 1 
        Number2 = Number2 * 10 + Reminder; //0*10 + 4 =4 |3|2|1 
    }
    return Number2;//4321
}
bool IsPalindrome(int Number)
{
return Number == ReverseNumbers(Number);
//1234 == 4321 ? false
}
int main()
{
if
(
// IsPalindrome(ReverseNumbers(ReadPositiveNumber("Please Enter The Number ?")))  دي غلط عشان هنا ممكن يعكس مرتين
IsPalindrome((ReadPositiveNumber("Please Enter The Number ?")))
)
cout<<"Yes, it is a Palindrome number\n";
else 
cout<<"No, it is Not a Palindrome number\n";

}
