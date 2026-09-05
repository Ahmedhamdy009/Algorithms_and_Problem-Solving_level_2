#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int ReadPositiveNumber(string Message) {
int number = 0;
do {
cout << Message;
cin >> number;
} while (number <= 0);
return number;
}
int SumDigits(int Number) {
int Remainder = 0, Sum = 0;
while (Number > 0) {
Remainder = Number % 10;
Number = Number / 10;
Sum = Sum + Remainder;
}
return Sum;
}
int main() {
cout << "\nSum of digits is " << SumDigits(ReadPositiveNumber("please enter a postive number : ")) << "\n";
}
