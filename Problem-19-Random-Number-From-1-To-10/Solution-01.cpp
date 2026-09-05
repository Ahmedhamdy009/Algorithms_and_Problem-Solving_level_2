#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumberFrom1To10(int From, int To)
{
 int randomNumber = From + rand() % (To - From + 1);
 return randomNumber;
}
int main()
{
    srand((unsigned)time(NULL));
    cout<<RandomNumberFrom1To10(1,10)<<endl;
    cout<<RandomNumberFrom1To10(1,10)<<endl;
    cout<<RandomNumberFrom1To10(1,10)<<endl;
    return 0;
}
