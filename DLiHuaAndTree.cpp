Q) D. Li Hua and Tree -> https://codeforces.com/contest/1797/problem/D

i) initial approach : (gives TLE)

#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int vertex,vector<int>& size,vector<int>& imp,vector<vector<int>>& adj,vector<int>& a,vector<int>& parent){
    if(adj[vertex].size() == 0){
        size[vertex] = 1;
        imp[vertex] = a[vertex];
        return;
    }
    size[vertex] = 1;
    imp[vertex] = a[vertex];
    for(auto node : adj[vertex]){
        if(node == parent[vertex]) continue;
        parent[node] = vertex;
        dfs(node,size,imp,adj,a,parent);
        imp[vertex] += imp[node];
        size[vertex] += size[node];
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> size(n+1,0);
    vector<long long> imp(n+1,0);
    vector<int> parent(n+1,-1);
    parent[1] = -1;
    dfs(1,size,imp,adj,a,parent);
    while(m--){
        int j,x;
        cin>>j>>x;
        if(j == 1){
            cout<<imp[x]<<"\n";
        }
        else{
            int hson = -1;
            int hsonsize = 0;
            for(int i=0;i<adj[x].size();i++){
               if(adj[x][i] == parent[x]) continue;
               if(size[adj[x][i]] > hsonsize){
                  hsonsize = size[adj[x][i]];
                  hson = i;
               }
               else if(size[adj[x][i]] == hsonsize){
                  if(adj[x][i] < adj[x][hson]) hson = i;
               }
            }
            if(hson == -1) continue;
            int hsonnode = adj[x][hson];
            int par = parent[x];
            for(auto it=adj[par].begin();it!=adj[par].end();it++){
                if(*it == x){
                    adj[par].erase(it);
                    break;
                }
            }
            for(auto it = adj[x].begin();it!=adj[x].end();it++){
                if(*it == par){
                    adj[x].erase(it);
                    break;
                }
            }
            size[x] -= size[hsonnode];
            imp[x] -= imp[hsonnode];
            parent[x] = hsonnode;
            size[hsonnode] += size[x];
            imp[hsonnode] += imp[x];
            parent[hsonnode] = par;
            adj[par].push_back(hsonnode);
            adj[hsonnode].push_back(par);
        }
    }
    return 0;
}

ii) Proper approach : 

#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int vertex,vector<int>& size,vector<int>& imp,vector<vector<int>>& adj,vector<int>& a,vector<int>& parent,vector<int>& son,set<pair<int,int>> sons[]){
    if(adj[vertex].size() == 0){
        size[vertex] = 1;
        imp[vertex] = a[vertex];
        return;
    }
    size[vertex] = 1;
    imp[vertex] = a[vertex];
    for(auto node : adj[vertex]){
        if(node == parent[vertex]) continue;
        parent[node] = vertex;
        dfs(node,size,imp,adj,a,parent,son,sons);
        imp[vertex] += imp[node];
        size[vertex] += size[node];
        sons[vertex].insert({-size[node],node});
        son[vertex] = (size[node] > size[son[vertex]] || (size[node] == size[son[vertex]] && node < son[vertex])) ? node : son[vertex];
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> size(n+1,0);
    vector<long long> imp(n+1,0);
    vector<int> parent(n+1,-1);
    set<pair<int,int>> sons[n+1];
    vector<int> son(n+1,0);
    parent[1] = -1;
    dfs(1,size,imp,adj,a,parent,son,sons);
    while(m--){
        int j,x;
        cin>>j>>x;
        if(j == 1){
            cout<<imp[x]<<"\n";
        }
        else{
            int hsonnode = son[x];
            int par = parent[x];
            if(hsonnode == 0) continue;
            sons[par].erase({-size[x],x});
            sons[x].erase({-size[hsonnode],hsonnode});
            son[x] = (sons[x].empty()) ? 0 : (*sons[x].begin()).second;
            size[x] -= size[hsonnode];
            imp[x] -= imp[hsonnode];
            parent[x] = hsonnode;
            size[hsonnode] += size[x];
            imp[hsonnode] += imp[x];
            parent[hsonnode] = par;
            sons[hsonnode].insert({-size[x],x});
            son[hsonnode] = (*sons[hsonnode].begin()).second;
            sons[par].insert({-size[hsonnode],hsonnode});
            son[par] = (*sons[par].begin()).second;
        }
    }
    return 0;
}
