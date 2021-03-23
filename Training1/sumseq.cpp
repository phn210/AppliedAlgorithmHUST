#include <bits/stdc++.h>
using namespace std;

int N;
unsigned long long S = 0, c = 1e9+7, tmp;


int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        S += (tmp % c);
        S = S % c;
    }
    cout << S;

    return 0;
}
