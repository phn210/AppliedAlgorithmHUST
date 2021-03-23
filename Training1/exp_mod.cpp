#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull pow_mod(ull a, ull b, ull mod)
{
    if (b == 0) return 1;
    else if (b == 1) return a % mod;
    else
    {
        ull res = pow_mod(a, b/2, mod);
        if(b % 2 == 0)
        {
            return ((res % mod)*(res % mod))% mod;
        }
        else
        {
            return ((((res % mod)*(res % mod))% mod)*(a % mod))% mod;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);

    ull a, b, res;
    ull c = 1e9+7;
    cin >> a >> b;
    res = pow_mod(a, b, c);
    cout << res;

    return 0;
}
