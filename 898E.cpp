a#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n,ans=0;
    cin >> n;
    vector<int> a(n,0);
    vector<pair<int,int> > d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int x = sqrt(a[i]);
        d.push_back({min(abs(a[i]-x*x), abs(a[i]-(x+1)*(x+1))),a[i]});
    }
  
    sort(d.begin(),d.end());
    for(int i = 0; i < n/2; i++) {
        ans += d[i].first;
    }
    for(int i = n/2; i < n; i++) {
        if(!d[i].first) ans++;
        if(!d[i].second) ans++;
    }
    cout <<ans;
}
main()
{
   solve();
}
