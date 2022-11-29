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
//Solution
int check(int n, int m, int x) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += min(x/i,m);
    }
    return cnt;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n,0);
    vector<vector<int> > b(n);
    vector<vector<int> > g(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx,x);
        a[x]++;
        b[x].push_back(i);
    }
   
    if(b[0].size() != 1) {
        cout << -1;
        return 0;
    }
    int s = b[0][0];
    int ans = 0;
    for(int d = 1; d <= mx; d++) {
        if(!a[d]) {
            cout << -1;
            return 0;
        }
        for(int i = 0; i < a[d]; i++) {
            bool f=(s==b[0][0]);
           
            if(g[s].size()+2-f >k) {
                b[d-1].pop_back();
                if(!b[d-1].size()){
                    cout << -1;
                    return 0;
                }
                s = b[d-1][b[d-1].size()-1];
            }
            g[s].push_back(b[d][i]);
            ans++;

        }
        s = b[d][b[d].size()-1];
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        for(int j =0; j < g[i].size(); j++) cout << i+1 << " " << g[i][j]+1 << '\n';
    }


}
