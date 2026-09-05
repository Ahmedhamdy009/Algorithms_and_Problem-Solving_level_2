#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enCharType{SmallLetters=1,CapitalLetter=2,SpecialCharacter=3,Digit=4};
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
char GetRandomCharacter(enCharType CharType){switch(CharType){case SmallLetters:return char(RandomNumbers(97,122));case CapitalLetter:return char(RandomNumbers(65,90));case SpecialCharacter:return char(RandomNumbers(33,47));case Digit:return char(RandomNumbers(48,57));}return '\0';}
int ReadPositiveNumber(string Message){int Number=0;do{cout<<Message<<endl;cin>>Number;}while(Number<=0);return Number;}
string GenerateWord(enCharType CharType,short length){string word="";for(int i=0;i<length;i++)word+=GetRandomCharacter(CapitalLetter);return word;}
string GenerateKey(){return GenerateWord(CapitalLetter,4)+"-"+GenerateWord(CapitalLetter,4)+"-"+GenerateWord(CapitalLetter,4)+"-"+GenerateWord(CapitalLetter,4);}
void FillArrayWithKeys(string arr[100],int &arrlength){for(int i=0;i<arrlength;i++)arr[i]=GenerateKey();}
void PrintStringKeys(string arr[100],int arrlength){cout<<"Array elements : \n";for(int i=0;i<arrlength;i++)cout<<"Array["<<i<<"] : "<<arr[i]<<endl;}
int main(){srand((unsigned)time(NULL));string arr[100];int arrlength=ReadPositiveNumber("How many keys do you want to generate ? ");FillArrayWithKeys(arr,arrlength);PrintStringKeys(arr,arrlength);}
