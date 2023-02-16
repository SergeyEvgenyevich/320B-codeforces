#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
 ios::sync_with_stdio(false);
 cin.tie(0);
 int n,len=0,sum=0;
 cin >> n;
 vector<int> v(n,0);
 vector<int> t(n,0);
 multiset<int> s;
 for(int i = 0; i < n; i++) cin >> v[i];
 for(int i = 0; i < n; i++) cin >> t[i];

 int cnt = t[0], last= max(v[0]-t[0],0ll);
 if(v[0]-t[0]>0) { 
    s.insert(v[0]); 
    len++; 
    sum += v[0];
 }
 cout << min(t[0],v[0]) << " ";
 for(int i = 1; i < n; i++) {
    s.insert(v[i]+cnt);
    sum += v[i]+cnt;
    cnt += t[i];
    len++;
    while(!s.empty() && *s.begin()<=cnt) {
        sum -=*s.begin();
        s.erase(s.begin());
        len--;
    }
    cout << last+v[i]-(sum-len*cnt) << " ";
    last = sum-len*cnt;

 }

}
