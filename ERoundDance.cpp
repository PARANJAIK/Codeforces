Q) E. Round Dance -> https://codeforces.com/contest/1833/problem/E
  
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj(n,vector<int> ());
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            bool present = false;
            for(auto el : adj[i]){
                if(el == x-1) present = true;
            }
            if(present == false) adj[i].push_back(x-1);
            if(present == false) adj[x-1].push_back(i);
        }
        queue<int> q;
        vector<int> vis(n,0);
        int maxx = 0;
        int minn = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 1) continue;
            maxx++;
            q.push(i);
            vis[i] = 1;
            bool loop = true;
            while(!q.empty()){
            int person = q.front();
            q.pop();
            if(adj[person].size() == 1) loop = false;
            for(auto child : adj[person]){
                if(vis[child] == 1) continue;
                vis[child] = 1;
                q.push(child);
            }
            }
            if(loop == false) minn++;
        }
        if(minn == 0){
            cout<<maxx<<" "<<maxx<<endl;
        }
        else{
            cout<<(maxx-minn+1)<<" "<<maxx<<endl;
        }
    }
    return 0;
}
