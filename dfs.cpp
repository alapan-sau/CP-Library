#include <bits/stdc++.h>
using namespace std;


void dfs_Util(int node, vector<int> &ans, vector<int> g[], int N, int vis[]){
    vis[node] = 1;
    ans.push_back(node);
    
    int len = g[node].size();
    
    for(int i=0;i<len;i++){
        if(vis[g[node][i]]!=1){
            dfs_Util(g[node][i],ans,g,N,vis);
        }
    }
    
    return;
}

vector <int> dfs(vector<int> g[], int N)
{
    int vis[N];
    
    for(int i=0;i<N;i++) vis[i]=0;
    vector <int> ans;
    
    dfs_Util(0,ans,g,N,vis);
    return ans;
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
            g[v].push_back(u);
        }

        vector <int> ans = dfs(g,n);

        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}