#include <bits/stdc++.h>
using namespace std;

int a, b, c, res = -1;
int visited[901][901];

void bfs()
{
    queue<pair<pair<int, int>, int>> Q;
    pair<pair<int, int>, int> node;
    Q.push(make_pair(make_pair(0, 0), 0));
    while(!Q.empty())
    {
        node = Q.front();
        pair<int, int> state = make_pair(node.first.first, node.first.second);
        Q.pop();
        if (visited[state.first][state.second] == 1)
            continue;
        else visited[state.first][state.second] = 1;

        if (state.first == c || state.second == c)
        {
            res = node.second;
            break;
        }
        else
        {
            int x = state.first, y = state.second, new_x, new_y;
            if(x*x + y*y > 0)
            {
                if((x + y) > a)
                {
                    new_x = a;
                    new_y = y - (a - x);
                }
                else
                {
                    new_x = x + y;
                    new_y = 0;
                }
                if(!(new_x == a && new_y == 0)) Q.push(make_pair(make_pair(new_x, new_y), node.second+1));

                if((x + y) > b)
                {
                    new_x = x - (b - y);
                    new_y = b;
                }
                else
                {
                    new_x = 0;
                    new_y = x + y;
                }
                if(!(new_x == 0 && new_y == b)) Q.push(make_pair(make_pair(new_x, new_y), node.second+1));
                Q.push(make_pair(make_pair(x, 0), node.second+1));
                Q.push(make_pair(make_pair(0, y), node.second+1));
            }
            if(x < a) Q.push(make_pair(make_pair(a, y), node.second+1));
            if(y < b) Q.push(make_pair(make_pair(x, b), node.second+1));
        }
    }
    cout << res;
}

int main()
{
    cin >> a >> b >> c;

    bfs();

    return 0;
}
