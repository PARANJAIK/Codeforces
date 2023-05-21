Q) F. Ira and Flamenco -> https://codeforces.com/contest/1833/problem/F

#include <bits/stdc++.h>
using namespace std;
#define int long long

int binexp(int a,int b,int M){
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = (ans*1LL*a)%M;
        }
        a = (a*1LL*a)%M;
        b >>=1;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        int M = 1e9 + 7;
        vector<int> a(n);
        map<int,int> mapp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mapp[a[i]]++;
        }
        vector<int> v;
        for(auto level : mapp){
            v.push_back(level.first);
        }
        if(v.size() < m){
            cout<<"0\n";
        }
        else{
            int start = 0,end = m-1;
            int ans = 0;
            int size = v.size();
            int temp = 1;
            for(int i=0;i<m-1;i++){
                temp = (temp*mapp[v[i]])%M;
            }
            while(end < size){
                temp = (temp*mapp[v[end]])%M;
                if(v[end]-v[start] < m){
                    ans = (ans + temp)%M;
                }
                int mmi = binexp(mapp[v[start]],M-2,M);
                temp = ((temp%M)*(mmi))%M;
                start++;
                end++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
