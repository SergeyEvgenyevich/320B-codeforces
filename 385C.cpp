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
vector<int> mindiv;
vector<int> mp;
void factor(int x) {
    int last = -1;
    while(x>1){
        int p = mindiv[x];
        x /= p;
        if(last!=p){
          last = p;
          mp[p]++;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pref(mx+1,0);
    mindiv.resize(mx+1,1);
    mp.resize(mx+1,0);
    for(int i = 2; i < mx; i++) {
        for(int j = i; j < mx; j+= i)
            if(mindiv[j]==1)mindiv[j]=i;
    }


    int n,q;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        factor(a[i]);
    }
    for(int i = 2; i <= mx; i++) pref[i] = pref[i-1] + mp[i];
    cin >> q;
    for(int _ = 0; _< q; _++) {
        int l,r;
        cin >> l >> r;
        r = min(r,mx-1);
        cout << sum(l,r,pref)<< '\n';
    }



}
