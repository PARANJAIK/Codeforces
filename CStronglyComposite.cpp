// https://codeforces.com/contest/1823/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

// bool check(int k, int a, int b, int c){

// }

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int,int> m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int j=2;j*j <= x;j++){
                while(x%j == 0){
                    x /= j;
                    m[j]++;
                }
            }
            if(x != 1){
                m[x]++;
            }
        }
        int ans = 0;
        int r = 0;
        for(auto it : m){
            int num = it.first;
            int cnt = it.second;
            ans += cnt/2;
            r += cnt%2;
        }
        ans += r/3;
        cout<<ans<<endl;
    }
    return 0;
}
