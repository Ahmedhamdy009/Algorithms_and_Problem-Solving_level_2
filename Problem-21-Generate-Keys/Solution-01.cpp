#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int ReadPositiveNumber(string Message){int Number=0;do{cout<<Message<<endl;cin>>Number;}while(Number<0);return Number;}
string GenerateKeys(int From,int To){string word="";for(int i=0;i<4;i++){int RandomCharacter=From+rand()%(To-From+1);word+=char(RandomCharacter);}return word;}
void PrintKeys(int Key){for(int i=1;i<=Key;i++){cout<<"Key["<<i<<"] : "<<GenerateKeys(65,90)<<"-"<<GenerateKeys(65,90)<<"-"<<GenerateKeys(65,90)<<"-"<<GenerateKeys(65,90)<<endl;}}
int main(){srand((unsigned)time(NULL));PrintKeys(ReadPositiveNumber("Please Enter the number of Key : "));}
