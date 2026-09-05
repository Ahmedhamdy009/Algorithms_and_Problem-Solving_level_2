#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enCharType {SmallLetters=1,CapitalLetter=2,SpecialCharacter=3,Digit=4};
int ReadPositiveNumber(string Message){int Number=0;do{cout<<Message<<endl;cin>>Number;}while(Number<0);return Number;}
int RandomNumber(int From,int To){return From+rand()%(To-From+1);}
char RandomCharacter(enCharType CharType){switch(CharType){case SmallLetters:return char(RandomNumber(97,122));case CapitalLetter:return char(RandomNumber(65,90));case SpecialCharacter:return char(RandomNumber(33,47));case Digit:return char(RandomNumber(48,57));}return '\0';}
string GenerateWord(enCharType CharType,short length){string word="";for(int i=0;i<length;i++)word+=RandomCharacter(CapitalLetter);return word;}
string GenerateKey(){string key=GenerateWord(CapitalLetter,4)+"-";key+=GenerateWord(CapitalLetter,4)+"-";key+=GenerateWord(CapitalLetter,4)+"-";key+=GenerateWord(CapitalLetter,4);return key;}
void PrintKeys(int NumberOfKeys){for(int i=1;i<=NumberOfKeys;i++)cout<<"Key["<<i<<"] : "<<GenerateKey()<<endl;}
int main(){srand((unsigned)time(NULL));PrintKeys(ReadPositiveNumber("Please Enter the number of Key : "));}
