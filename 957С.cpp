#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {

 int n,u;
 cin >> n >> u;
 double ans = -1;
 vector<int> a(n,0);
 for(int i = 0; i < n; i++) cin >> a[i];
 for(int i = 0; i < n-2; i++) {
    int l = i+2, r = n;
    while(r-l>1) {
        int mid=(r+l)/2;
        if(a[mid]-a[i] <= u) l = mid;
        else r = mid;
    }
    if(a[l]-a[i] <= u)
        ans = max(ans, (double) (a[l]-a[i+1])/(a[l]-a[i]));
 }
 cout << fixed;
 cout << setprecision(9) << ans;

}
