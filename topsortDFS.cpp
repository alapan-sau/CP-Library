#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack <int> &s, vector <int> adj[], int vis[]){

        vis[node]=1;

        int len = adj[node].size();
        for(int i=0;i<len;i++){
            if(!vis[adj[node][i]]){
                dfs(adj[node][i],s,adj,vis);
            }
        }
        s.push(node);
        return ;
}

vector<int> topoSort(int V, vector<int> adj[]){

    int vis[V];
    for(int i=0;i<V;i++) vis[i]=0;
    
    stack <int> s;

    for(int i=0;i<V;i++)if(!vis[i]) dfs(i,s,adj, vis);
    
    vector <int> ans;
    while(!s.empty()){
        int a = s.top();
        s.pop();
        ans.push_back(a);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector <int> adj[n];

        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> sorted = topoSort(n,adj);
        for(int i=0;i<n;i++) cout << sorted[i] << " ";
        cout << endl;
    }
    return 0;
}

