#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
vector<int> ans;
int m;
bool rec(int s1, int s2, int len, int last) {
    if(len==m) return 1;
    for(int i = 0; i < a.size(); i++) {
        if(len%2==0) {
            if(s1+a[i] > s2 && a[i] != last) {
                ans.push_back(a[i]);
                if(rec(s1+a[i],s2,len+1,a[i])) return 1;
                ans.pop_back();

            }
        }
        else{
             if(s2+a[i] > s1 && a[i] != last) {
                ans.push_back(a[i]);
                if(rec(s1,s2+a[i],len+1,a[i])) return 1;
                ans.pop_back();

            }
        }
    }
    return 0;
}
main()
{
    string s;
    cin >> s >> m;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='1') a.push_back(i+1);
    }
    rec(0,0,0,-1)==1 ? cout << "YES"<< '\n' : cout << "NO";
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";


}
