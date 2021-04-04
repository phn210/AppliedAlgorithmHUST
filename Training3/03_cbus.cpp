#include <bits/stdc++.h>
using namespace std;
#define MAX 11

int N, K;
int c[2*MAX+1][2*MAX+1];
int x[MAX+1], mark[MAX+1];
int best = numeric_limits<int>::max(), cmin = numeric_limits<int>::max();
int space, cur;

int min(int a, int b)
{
    if(a < b) return a;
    else return b;
}

void input()
{
    cin >> N >> K;
    for(int i = 0; i < 2*N+1; ++i)
        for(int j = 0; j < 2*N+1; ++j)
        {
            cin >> c[i][j];
            if(i != j)cmin = min(c[i][j], cmin);
        }
}

bool check(int i, int j)
{
    if(i == j) return false;
    if(mark[j] == 1) return false;
    if(j <= N && space == K) return false;
    if(j > N && (mark[j-N] == 0 || i == 0)) return false;
    return true;
}

void TRY(int k)
{
    for(int i = 1; i <= 2*N; ++i)
    {
        if(check(x[k-1], i))
        {
            if(i <= N) space++;
            else space--;
            x[k] = i;
            mark[i] = 1;
            cur += c[x[k-1]][i];

            if(k == 2*N)
            {
                cur += c[i][0];
                if(cur < best) best = cur;
                cur -= c[i][0];
            }
            else if((cur + cmin*(2*N+1-k)) < best) TRY(k+1);

            if(i <= N) space--;
            else space++;
            mark[i] = 0;
            cur -= c[x[k-1]][i];
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
    ios_base::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
