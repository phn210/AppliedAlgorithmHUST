#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tests;

void input()
{
    int s, tmp;
    vector<int> l;
    while(1)
    {
        cin >> s;
        if(s == 0) break;
        l.push_back(s);
        for (int i = 0; i < s; ++i)
        {
            cin >> tmp;
            l.push_back(tmp);
        }
        tests.push_back(l);
        l.clear();
    }

}

long long int find_max(vector<int> test)
{
    stack<int> s;
    int i = 0;
    long long int s_tmp = 0, s_max = 0;
    while(i < test.at(0))
    {
        if(s.empty())
        {
            s.push(i++);
        }
        else {
            int top = s.top();
            if (test.at(i+1) >= test.at(top+1)) s.push(i++);
            else
            {
                s.pop();
                s_tmp = (long long int) test.at(top+1)*(s.empty() ? i : i - s.top() - 1);
                if (s_tmp > s_max) s_max = s_tmp;
            }
        }
    }

    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        s_tmp = (long long int) test.at(top + 1)*(s.empty() ? i: i - s.top() - 1);
        if (s_tmp > s_max) s_max = s_tmp;
    }

    return s_max;
}

void solve()
{
    for (int i = 0; i < tests.size(); ++i)
    {
        cout << find_max(tests.at(i)) << endl;
    }
}

int main()
{
    input();
    solve();
    return 0;
}
