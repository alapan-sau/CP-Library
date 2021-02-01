#include <bits/stdc++.h>
using namespace std;


vector<int> topoSortKahn(int V, vector<int> adj[]){

    int vis[V];
    int indegree[V];
    for(int i=0;i<V;i++){
        vis[i]=0;
        indegree[i]=0;
    }

    for(int i=0;i<V;i++){
        int len = adj[i].size();
        for(int j=0;j<len;j++){
            indegree[adj[i][j]]++;
        }
    }
    queue <int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector <int> ans ;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node]=1;
        ans.push_back(node);
        int len = adj[node].size();

        for(int i=0;i<len;i++){
            if(!vis[adj[node][i]]){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
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

        vector <int> sorted = topoSortKahn(n,adj);
        for(int i=0;i<n;i++) cout << sorted[i] << " ";
        cout << endl;
    }
    return 0;
}