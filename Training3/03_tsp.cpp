#include <bits/stdc++.h>
using namespace std;

int N, M;
int c[20][20];
int best = numeric_limits<int>::max();
int cmin = best, cur = 0;
int x[20], visited[20];

int min(int x, int y)
{
    if(x < y) return x;
    else return y;
}

void input()
{
    cin >> N >> M;
    int tmp1, tmp2;
    for(int i = 0; i < M; ++i)
    {
        cin >> tmp1 >> tmp2;
        cin >> c[tmp1-1][tmp2-1];
        cmin = min(cmin, c[tmp1-1][tmp2-1]);
    }
}

void TRY(int k)
{
    //if(k >= N) return;
    if(k == N-1)
    {
        if(c[x[k]][0] != 0)
        {
            cur += c[x[k]][0];
            best = min(best, cur);
            cur -= c[x[k]][0];
        }
        return;
    }

    for(int i = 1; i < N; ++i)
    {
        if(!visited[i] && c[x[k]][i] != 0)
        {
            x[k+1] = i;
            visited[i] = 1;
            cur += c[x[k]][i];

            if(cur + (N - k)*cmin <= best) TRY(k+1);

            visited[i] = 0;
            cur -= c[x[k]][i];
        }
    }

}

void solve()
{
    TRY(0);
    cout << best << endl;
    /*
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << c[i][j] << " ";
        cout << endl;
    }
    */
}

int main()
{
    ios_base::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
