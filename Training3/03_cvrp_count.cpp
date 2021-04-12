#include <bits/stdc++.h>
using namespace std;

int n, K, Q, avai;
int d[20], x[20], mark[20];
unsigned int R;


void input()
{
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; ++i)
        cin >> d[i];
    avai = Q;
}

void TRY(int k)
{
    for(int i = 1; i <= n; ++i)
    {
        if (!mark[i])
        {
            if(d[i] <= avai)
            {
                avai -= d[i];
            }
            else avai = Q;

            x[k] = i;
            mark[i] = 1;

            if(k==n)
            {
                for(int j = 1; j <= n; ++j) cout << x[j] << " ";
                cout << endl;
                R++;
            }
            else TRY(k+1);

            mark[i] = 0;
        }


    }
}

void solve()
{
    TRY(1);
    cout << R % (unsigned int)(1e9 + 7);
}

int main()
{
    input();
    solve();
    return 0;
}
