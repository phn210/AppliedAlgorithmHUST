#include <bits/stdc++.h>
using namespace std;

int N, M;
int c[16];
int A[16][16];
int x[16];
int load[5];
int best = numeric_limits<int>::max();

void input()
{
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        cin >> c[i];
    for(int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
}

bool check(int k, int i) //course k and period i
{
    for(int j = 0; j < k; ++j)
    {
        if(A[j][k] == 1 && x[j] >= i) return false;
        if(A[k][j] == 1 && x[j] <= i) return false;
    }
    return true;
}

void solution()
{
    int res = 0;
    for(int i = 0; i < M; ++i)
        if(load[i] > res) res = load[i];
    if(res < best) best = res;
}

void TRY(int k)
{
    if(k == N)
    {
        solution();
        return;
    }
    for(int i = 0; i < M; ++i)
    {
        if(check(k, i))
        {
            x[k] = i;
            load[i] += c[k];

            TRY(k+1);

            load[i] -= c[k];
        }
    }
}

void solve()
{
    TRY(0);
    cout << best;
}

int main()
{
    input();
    solve();
    return 0;
}

