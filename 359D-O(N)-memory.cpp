#include <bits/stdc++.h>
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
//Solution + function GCD
int Maxpow(int n, vector<int>&pow2) {
    for(int i = 0; i < pow2.size(); i++) {
        if(pow2[i] > n) return i-1;
    }
    return pow2.size()-1;
}
bool check(int len, vector<int>& a, vector<vector<int> >&minx,vector<vector<int> >&g,vector<int>&pow2) {
    for(int i = 0; i < a.size(); i++) {
        if(i+len-1>=a.size())return 0;
        int mxpow = Maxpow(len,pow2);
        int Min = min(minx[i][mxpow],minx[i+len-pow2[mxpow]][mxpow]);
        int Gcd = gcd(g[i][mxpow],g[i+len-pow2[mxpow]][mxpow]);
        if(Min==Gcd) return 1;
    }
    return 0;
}
int main()
{
    int n; cin >> n;
    vector<int> a(n,0);
    vector<int> l(n,0);
    vector<int> r(n,0);
    vector<int> used(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    l[0]=-1;
    r[n-1]=n;
    for(int i = 1; i < n; i++) {
        if(a[i-1]%a[i]!=0) l[i]=i-1;
        else {
            l[i] = l[i-1];
            while(l[i] != -1 && a[l[i]]%a[i]==0) {
                l[i]=l[l[i]];
            }
        }
    }
    for(int i = n-2; i>=0;i--) {
        if(a[i+1]%a[i]!=0) r[i]=i+1;
        else{
            r[i] = r[i+1];
            while(r[i] != n && a[r[i]]%a[i]==0) {
                r[i]=r[r[i]];
            }
        }
    }
    int len = 0,cur=0;
    for(int i = 0; i < n; i++) {
        len=max(len,r[i]-l[i]-1);
    }
    for(int i = 0; i < n; i++) {
        if(r[i]-l[i]-1 == len&&!used[l[i]+1]){
            used[l[i]+1]=1;
            cur++;
        }
    }
    used.assign(n,0);
    cout << cur << " " << len-1<<'\n';




}
