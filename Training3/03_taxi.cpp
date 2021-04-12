#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int N;
int c[2*MAX+1][2*MAX+1];
int x[MAX+1], mark[MAX+1];
int best = numeric_limits<int>::max();
int cmin = best;
int cur;

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

void input()
{
    cin >> N;
    for(int i = 0; i < 2*N+1; ++i)
        for(int j = 0; j < 2*N+1; ++j)
        {
            cin >> c[i][j];
            if(i != j) cmin = min(cmin, c[i][j]);
        }
}

void TRY(int k)
{
    for(int i = 1; i <= N; ++i)
    {
        if(!mark[i])
        {
            mark[i] = 1;
            x[k] = i;
            x[k+1] = i + N;
            cur += c[x[k-1]][i] + c[i][i+N];

            if(k == 2*N-1)
            {
                cur += c[i+N][0];
                best = min(cur, best);
                cur -= c[i+N][0];
            }
            else
            {
                if(cur + cmin*(2*N-k) < best) TRY(k+2);
            }

            mark[i] = 0;
            cur -= c[x[k-1]][i] + c[i][i+N];
        }
    }
}

void solve()
{
    TRY(1);
    cout << best;
}

int main()
{
    input();
    solve();
    return 0;
}

