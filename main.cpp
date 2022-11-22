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
              main()
            {
            //    ios_base::sync_with_stdio(false);
            //    cin.tie(NULL);
                int a,b,c,d;
                cin >> a >> b >> c >> d;
                int a1 = a*c,b1=b*c,c1=c*a,d1=d*a;
                int a2=a*d,b2=b*d,c2=c*b,d2=d*b;

                if((b1-d1)*a2 > (a2-c2)*b1) {
                    cout << (b1-d1)/gcd(b1-d1,b1) << "/" << b1/gcd(b1-d1,b1);
                    return 0;
                }
                cout << (a2-c2)/gcd(a2-c2,a2) << "/" << a2/gcd(a2-c2,a2);


            }
