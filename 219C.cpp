#include <bits/stdc++.h>
using namespace std;
const int mod = 1e18+7;
const int max_size = 1e5+1;
const int INF = 1e9+7;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<vector<int> > dp(n,vector<int>(k,INF));
    vector<vector<int> > p(n,vector<int>(k,INF));
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        a[i] = x-'A';
    }

    for(int i = 0; i < k; i++)
    {
        if(a[0]==i) dp[0][i]= 0;
        else dp[0][i]=1;
    }
    for(int i = 1; i < n; i++)
    {

        for(int j = 0; j < k; j++)
        {
            if(a[i] != j){
                if(dp[i][a[i]] > dp[i-1][j]) p[i][a[i]]=j;
                dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]);
            }

        }
        for(int j = 0; j < k; j++)
        {
            for(int l = 0; l < k; l++)
            {
                if(j != l){
                    if(dp[i][j] > dp[i-1][l]+1) p[i][j]=l;
                    dp[i][j]=min(dp[i][j],dp[i-1][l]+1);
                }
            }

        }
    }
    int ans = INF;
    string s="";
    for(int i = 0; i < k; i++) ans = min(ans,dp[n-1][i]);
    for(int i = 0; i < k; i++) {
        if(dp[n-1][i] == ans) {
            int len = n-1, pos = i;
            while(len > -1) {
                char c = 'A' + pos;
                s += c;
                pos = p[len][pos];
                len--;


            }   
            break;
        }
    }
    cout << ans<< '\n';
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}


