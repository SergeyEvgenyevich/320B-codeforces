#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    int n;
    cin >> n;
    n=n*2;
    for(int k = 1; k <= 1e5; k++) {
        int c = n-k*(k+1);
        int l = 0;
        int r = 1e5+1;
        while(r-l>1) {
            int m = (l+r)/2;
            if(m*(m+1) < c) l = m;
            else r = m;
        }
        if(k*(k+1) + r*(r+1) == n){
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
}
