#include <bits/stdc++.h>
using namespace std;

#define MAX 12+1

int N, W, H;
int h[MAX], w[MAX], x[MAX];
int box[MAX][MAX];
int res = 0;

bool check(int vw, int vh, int w, int h)
{
    for(int i = 0; i < w; ++i)
        for(int j = 0; j < h; ++j)
            if(box[i][j] == 1) return false;
}

void mark(int vw, int vh, int w, int h, int state)
{
    for(int i = 0; i < w; ++i)
        for(int j = 0; j < h; ++j)
            box[i][j] = state;
}

void input()
{
    int tmp1, tmp2;
    cin >> H >> W >> N;
    for(int i = 0; i < N; ++i)
        cin >> h[i] >> w[i];
}

void TRY(int k)
{
    if (res == 1) return;
    for(int i = 0; i < N; ++i)
    {
        if(x[i] == 1) continue;
        for(int vx = 0; vx <= W-w[i]; ++vx)
            for(int vy = 0; vy <= H-h[i]; ++vy)
            {
                if(check(vx, vy, w[i], h[i]))
                {
                    mark(vx, vy, w[i], h[i], 1);
                    x[i] = 1;
                    if (k == N-1) res = 1;
                    TRY(k+1);
                    x[i] = 0;
                    mark(vx, vy, w[i], h[i], 0);
                }
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
