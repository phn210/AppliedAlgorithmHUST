#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int n, b, curW = 0, curV = 0, res = 0;
int a[31], c[31], x[31], mark[31];

void input()
{
    cin >> n >> b;
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> c[i];
}

void TRY(int k)
{
    if(k >= n) return;
    for(int i = (k == 0) ? 0 : x[k-1]+1; i < n; ++i)
    {
        if(curW + a[i] <= b)
        {
            //mark[i] = true;
            x[k] = i;
            curW += a[i];
            curV += c[i];
            if (curV > res) res = curV;

            TRY(k+1);

            //mark[i] = false;
            curW -= a[i];
            curV -= c[i];
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    input();
    TRY(0);
    cout << res;
    return 0;
}
