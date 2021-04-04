#include <bits/stdc++.h>
using namespace std;

int N, b;
int a[200001];

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

void input()
{
    cin >> N >> b;
    for (int i = 0; i < N; ++i) cin >> a[i];
}

void solve()
{
    int preMax[N-2];
    int postMax[N-2];
    preMax[0] = a[0];
    postMax[N-3] = a[N-1];

    for (int i = 1; i < N-2; ++i)
    {
        preMax[i] = max(preMax[i-1], a[i]);
        postMax[N-3-i] = max(postMax[N-2-i], a[N-1-i]);
    }

    int res = -1;
    for(int i = 0; i < N-2; ++i)
    {
        if(preMax[i] - a[i+1] >= b && postMax[i] - a[i+1] >= b) res = max(res, preMax[i] - a[i+1] + postMax[i] - a[i+1]);
    }
    cout << res;
}

int main()
{
    input();
    solve();
    return 0;
}
