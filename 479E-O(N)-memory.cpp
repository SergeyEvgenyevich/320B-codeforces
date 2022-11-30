#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
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

    return (a[r]-a[l-1]+mod)%mod;

}
int main()
{
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vector<int> pref(n+1,0);
    vector<int> new_pref(n+1,0);
    for(int i = a; i <= n; i++) pref[i] = 1;
    for(int i = 1; i <= k; i++) {
        new_pref.clear();
        for(int j = 1; j <= n; j++) {
            new_pref[j]=new_pref[j-1];
            if(j==b) continue;
            if(j < b)
                new_pref[j]=(new_pref[j]+(sum(1,j-1,pref)+sum(j+1,(b+j - 1)/2 ,pref))%mod)%mod;
            else{
                new_pref[j]=(new_pref[j]+(sum(j+1,n,pref)+sum((b+j+2)/2 , j-1,pref))%mod)%mod;
            }
        }
        swap(pref,new_pref);

    }
    cout << pref[n];

}
