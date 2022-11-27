#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18+7;
const int max_size = 1e5+1;
int fact[max_size];
int binpow(int a,int n)
{

    if(!n) return 1;
    if(n==1) return a;
    if(n%2==1) return a*binpow(a,n-1);
    else
    {
        int t = binpow(a,n/2);
        return t*t;
    }
}
int inverse(int x)
{
    return binpow(x,mod-2);
}
int div_mod(int a, int b)
{
    return a*inverse(b)%mod;
}
int cnk(int n, int k)
{
    if(n<k) return 0;
    return div_mod(fact[n],fact[k]*fact[n-k]%mod);
}

int gcd(int a, int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int sum(int l, int r,vector<int>&a)
{
    if(l > r) return 0;
    if(!l) return a[r];
    return a[r]-a[l-1];

}

main()
{
    int n,m,w;
    cin >> n >> m >> w;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++)cin>>a[i];
    int l = 1, r = 1e10;
    while(r-l > 1) {
        int mid = (r+l)/2,cur=0,t=0;
        vector<int> pref(2*n,0);
        for(int i = 0; i<n; i++) {
            cur += pref[i];
            int diff=mid-(a[i]+cur);
            if(diff <= 0) continue;
            cur += diff;
            t += diff;
            pref[i+w] += -1*diff;

        }
        if(t <= m) l = mid;
        else r = mid;
    }
    cout << l;
}
