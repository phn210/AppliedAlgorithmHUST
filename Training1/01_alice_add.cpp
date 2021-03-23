#include <iostream>
using namespace std;

int main()
{
    unsigned long long int a, b;
    cin >> a >> b;

    unsigned long long int a0 = a % 10;
    unsigned long long int b0 = b % 10;
    unsigned long long int a1 = (a - a0)/10;
    unsigned long long int b1 = (b - b0)/10;
    unsigned long long int c0 = (a0+b0)%10;
    unsigned long long int c1 = (a0+b0)/10;

    c1 = a1 + b1 + c1;
    if (c1 > 0) cout << c1;
    cout << c0;

    return 0;
}
