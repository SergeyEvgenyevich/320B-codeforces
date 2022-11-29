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
    int maxpow = 20,n;
    cin >> n;
    vector<int> a(n,0);
    vector<vector<int> > minx(n,vector<int>(maxpow,1e9));
    vector<vector<int> > g(n,vector<int>(maxpow,0));
    vector<int> pow2(maxpow,1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < maxpow; i++) pow2[i] = pow2[i-1]*2;
    for(int i=n-1;i >= 0; i--) {
        minx[i][0]=a[i];
        g[i][0]=a[i];
        for(int k = 1; k < maxpow; k++) {
            if(i+pow2[k]-1 >= n){
                minx[i][k]=minx[i][k-1];
                g[i][k]=g[i][k-1];
                continue;
            }
            minx[i][k]=min(minx[i][k-1],minx[i+pow2[k-1]][k-1]);
            g[i][k]=gcd(g[i][k-1],g[i+pow2[k-1]][k-1]);
        }
    }
    int l = 0;
    int r = n+1;
    while(r-l>1) {

        int m=(r+l)/2;
        if(check(m,a,minx,g,pow2)) {
            l = m;
        }
        else r = m;
    }
    int len = l,cur=0;
    vector<int> ans;
    for(int i = 0; i < a.size(); i++) {
        if(i+len-1>=a.size())break;
        int mxpow = Maxpow(len,pow2);
        int Min = min(minx[i][mxpow],minx[i+len-pow2[mxpow]][mxpow]);
        int Gcd = gcd(g[i][mxpow],g[i+len-pow2[mxpow]][mxpow]);
        if(Min==Gcd){
            cur++;
            ans.push_back(i+1);
        }
    }
    cout << cur << " " << len-1 << '\n';
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


}
