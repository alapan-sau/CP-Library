#include <bits/stdc++.h>
using namespace std;


bool isCyclicUtil(int node, vector<int> adj[], int vis[], int recst[]){
    
    vis[node] = 1;
    recst[node] = 1;
    
    int len = adj[node].size();
    for(int i=0;i<len;i++){
        if(vis[adj[node][i]]==0 && isCyclicUtil(adj[node][i],adj,vis,recst)) return true;
        else if(recst[adj[node][i]]==1) return true;
    }
    
    recst[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    int vis[V];
    int recst[V];
    
    for(int i=0;i<V;i++){
        vis[i]=0;
        recst[i]=0;
    }
    
    for(int i=0;i<V;i++){
        if(vis[i]==0 && isCyclicUtil(i,adj,vis,recst)){
            return true;
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> n >> m;
        vector <int> g[n];

        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
        }

        cout << isCyclic(n,g) << endl;
    }
    return 0;
}