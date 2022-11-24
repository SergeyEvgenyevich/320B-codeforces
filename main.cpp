#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5000;
const int INF = 1e9;
int sum(vector<int>&a, int l, int r){
    if(l > r) return 0;
    if(!l) return a[r];
    return a[r] - a[l-1];
}
main()
{

    ifstream fin("input.txt");
	ofstream fout("output.txt");
    int n,minx=INF;
    fin >> n;
    vector<int> a(N+1,0);
    vector<int> pref(N+1,0);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    pref[0] = a[0];
    for(int i = 1; i <= N; i++) pref[i]=pref[i-1]+a[i];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(j <= 2*i && j > i) {
                minx = min(minx,sum(pref,0,i-1)+sum(pref,j+1,N));

            }
        }
    }
    fout << minx;

}
