        #include <bits/stdc++.h>
        using namespace std;
        const int mod = 1e18+7;
        vector<int> fact;

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


        vector<int> c;
        int f(int x)
        {
            int s = 0;
            while(x)
            {
                s+=c[x%10];
                x/=10;
            }
            return s;
        }
        int gcd(int a, int b)
        {
            if(!b)return a;
            return gcd(b,a%b);
        }

        vector<vector<int> > g;
        vector<int> used;
        bool dfs(int v,int u) {
            if(v==u) return 1;
            used[v] = 1;
            for(int i = 0; i < g[v].size(); i++) {
                int to =g[v][i];
                if(!used[to]) {
                    if(dfs(to,u)) return 1;
                }
            }

            return 0;

        }
         int main()
        {
        //    ios_base::sync_with_stdio(false);
        //    cin.tie(NULL);
        int q;
        cin >> q;
        vector<pair<int,int > > a;
        g.resize(q+1);
        for(int _ = 0; _ < q; _++) {

            int t, x,y;
            cin >> t >> x>> y;
            if(t==1) {
                a.push_back({x,y});
                for(int i = 0; i < a.size()-1; i++){
                    if((a[i].first < x &&  x < a[i].second)||(a[i].first < y &&  y < a[i].second))
                    {
                        g[a.size()-1].push_back(i);
                    }

                    if((x < a[i].first  &&  a[i].first < y)||(x < a[i].second && a[i].second < y)){
                        g[i].push_back(a.size()-1);
                    }
                }
            }
            else{
                used.assign(a.size(),0);
                if(dfs(x-1,y-1))cout<<"YES" << '\n';
                else cout << "NO" << '\n';
            }
        }

        }
