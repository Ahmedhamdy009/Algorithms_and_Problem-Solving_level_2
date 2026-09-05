//احسب عدد الأرقام في العدد
//يعني حصل كام عملية في المسئلة دي
/*
أشيل 4 → يبقى 123 (عد = 1)
أشيل 3 → يبقى 12 (عد = 2)
أشيل 2 → يبقى 1 (عد = 3)
أشيل 1 → يبقى 0 (عد = 4)

💥 إذن:

كل مرة بشيل رقم → أزود العداد
*/
#include <iostream>
#include <cmath>
using namespace std;
int CountDigits(int Number)
{
    int count = 0;

    while (Number > 0)
    {
        Number = Number / 10;
        count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;   // ✅ مهم جدًا
    cout << CountDigits(n);
}
