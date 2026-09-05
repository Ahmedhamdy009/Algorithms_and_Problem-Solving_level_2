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
int CountDigitFrequency(int Number, int DigitToCheck) {
int Feqcounter = 0;
int Remainder = 0;
while (Number > 0) {
Remainder = Number % 10;
Number = Number / 10;
if (Remainder == DigitToCheck) Feqcounter++;
}
return Feqcounter;
}
void PrintAllDigitFrequency(int Number) {
for (int digit = 0; digit < 10; digit++) {
short DigitFrequency = CountDigitFrequency(Number, digit);
if (DigitFrequency > 0) {
cout << "\nDigit " << digit << " Frequency is " << DigitFrequency << " Time(S)\n";
}
}
}
int main() {
int Number = ReadPositiveNumber("please enter the main number: ");
PrintAllDigitFrequency(Number);
return 0;
}
