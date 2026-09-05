#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int ReadPositiveNumber(string Message) {
int Number;
do {
cout << Message;
cin >> Number;
} while (Number < 0);
return Number;
}
int ReversedNumber(int Number) {
int Remainder = 0;
int Number2 = 0;
while (Number > 0) {
Remainder = Number % 10;
Number = Number / 10;
Number2 = Number2 * 10 + Remainder;
};
return Number2;
}
void PrintDigits(int Number) {
int Remainder = 0;
int ReversedN = ReversedNumber(Number);
while (ReversedN > 0) {
Remainder = ReversedN % 10;
ReversedN = ReversedN / 10;
cout << Remainder << endl;
}
}
int main() {
int Number = ReadPositiveNumber("please enter a positive number : ");
PrintDigits(Number);
return 0;
}
