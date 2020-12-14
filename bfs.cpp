#include <bits/stdc++.h>
using namespace std;

vector <int> bfs(vector<int> g[], int N){
    queue <int> q;
    int vis[N];
    vector <int> ans;
    for(int i=0;i<N;i++) vis[i]=0;

    vis[0] = 1;
    q.push(0);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node]= 2;
        ans.push_back(node);

        int len = g[node].size();
        for(int i=0;i<len;i++){
            if(vis[g[node][i]] == 0){
                vis[g[node][i]]=1;
                q.push(g[node][i]);
            }
        }
    }

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

        vector <int> ans = bfs(g,n);

        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}