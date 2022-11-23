#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{

    int n;
    cin >> n;
    vector<int>b(n/2,0);
    vector<int>a(n+1,0);
    for(int i = 0; i < n/2; i++){
        cin >> b[i];
    }
    for(int i =0; i < n/2; i++){
        if(a[b[i]]){
            cout << -1;
            return;
        }
        a[b[i]]=1;
    }
    set<int> s;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {

        if(!a[i])s.insert(-1*i);
    }
    for(int i = n/2 - 1; i >=0; i--)
    {
        ans.push_back(b[i]);
        auto x = s.upper_bound(-1*b[i]);
        if(x==s.end())
        {
            cout << -1;
            return;
        }
        ans.push_back(*x);
        s.erase(x);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++) cout << abs(ans[i])<< " ";


}
main()
{

    int t;
    cin >> t;
    while(t--)
    {
        solve();
        cout << '\n';
    }
}
