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
int n,m,k;
vector<vector<int > > a;
vector<pair<int,int> > dx = {{-1,0},{1,0},{0,-1},{0,1}};
int check(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    return a[i][j];
}

void dfs(int i, int j)
{
    a[i][j]=2;
    k--;
    for(auto l : dx)
    {
        if(k > 0 && check(i+l.first,j+l.second)==1) dfs(i+l.first,j+l.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    a.resize(n,vector<int>(m,0));
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <m; j++)
        {
            char x;
            cin >> x;
            a[i][j]=(x=='.');
            s += a[i][j];
        }
    }

    k = s - k;
    for(int i = 0; i < n; i++)
    {   bool f = 0;
        for(int j = 0; j < m; j++)
        {
            if(check(i,j)==1 && k >0) {
                dfs(i,j);
                f=1;
                break;
            }
        }
        if(f)break;
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(a[i][j]==1) cout <<'X';
            else !a[i][j] ? cout << '#' : cout << '.';
        }
        cout << '\n';
    }

}


