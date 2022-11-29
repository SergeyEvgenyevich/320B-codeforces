#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18+7;
const int mx = 1e7+2;
const int INF = 1e18;
int fact[mx];
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
//Solution
int check(int n, int m, int x) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += min(x/i,m);
    }
    return cnt;
}

main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int l = 0;
    int r = n*m+1;
    while(r-l>1) {
        int x = (l+r)/2;
        if(check(n,m,x) >= k){
            r = x;
        }
        else l = x;
    }
    cout << r;



}
