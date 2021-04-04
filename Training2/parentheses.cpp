#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> p;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i)
    {
        string tmp;
        getline(cin, tmp);
        p.push_back(tmp);
    }

    for(int i = 0; i < n ;++i)
    {
        string test = p.at(i);
        stack<char> s;
        for(int j = 0; j < test.size(); ++j)
        {
            if(s.empty() || !((s.top() == '{' && test.at(j) == '}') || (s.top() == '[' && test.at(j) == ']') || (s.top() == '(' && test.at(j) == ')')))
                s.push(test.at(j));
            else s.pop();
        }
        if (s.empty()) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
