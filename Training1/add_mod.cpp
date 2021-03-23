#include <bits/stdc++.h>
using namespace std;

unsigned long long int a, b, res;

void inline input()
{
    cin >> a >> b;
}

void solve()
{
    unsigned long long int c = 1e9 + 7;
    res += a%c;
    res += b%c;
    res = res%c;
    cout << res;
}

int main()
{
    input();
    solve();
    return 0;
}
