// عايز اراجع دا تاني مش عشان الحل عشان ال enum في الint main كنت بكتبها بطريقة تانية بدل لما اكتب الشرط كامل زي كدا
// cout<<GetRandomCharacter(enCharTayp::SmallLetter)<<endl;
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enCharType {SmallLetter = 1, CaptionLetter = 2, SpecialCharacter = 3, Digit = 4};
int RandomNumber(int From, int To)
{
 int randomNumber = From + rand() % (To - From + 1);
 return randomNumber;
}
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
       return char(RandomNumber(97,122));
    case enCharType::CaptionLetter:
       return char(RandomNumber(65,90));
    case enCharType::SpecialCharacter:
       return char(RandomNumber(33,47));
    case enCharType::Digit:
       return char(RandomNumber(48,57));
    }
    return '\0';
}
int main()
{
 srand((unsigned)time(NULL));
 cout<<GetRandomCharacter(enCharType::SmallLetter)<<endl;
 cout<<GetRandomCharacter(enCharType::CaptionLetter)<<endl;
 cout<<GetRandomCharacter(enCharType::CaptionLetter)<<endl;
 cout<<GetRandomCharacter(enCharType::Digit)<<endl;
}
