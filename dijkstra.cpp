#include <bits/stdc++.h>
using namespace std;

// Using priority_queue
vector <int> dijkstra(int n, vector <pair <int, int>> g[], int src){
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

    vector <int> dist(n,INT_MAX);
    vector <int> parent(n, -1);

    pq.push(make_pair(0,src));
    dist[src]=0;

    while(!pq.empty()){
        int node  = pq.top().second;
        int minDist = pq.top().first;
        pq.pop();

        // ignore the redundant ones:
        if(minDist > dist[node]) continue;

        int len = g[node].size();
        for(int i=0;i<len;i++){
            // neighbour
            int newNode = g[node][i].second;
            int newWeight = g[node][i].first;

            // relax the neighbours
            if(dist[node] != INT_MAX && dist[node] + newWeight < dist[newNode]){
                dist[newNode] = dist[node] + newWeight;
                parent[newNode] = node;
                pq.push(make_pair(dist[newNode],newNode));
            }
        }
    }

    return dist;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> n >> m;

        vector < pair <int, int> > g[n];

        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;

            g[u].push_back(make_pair(w,v));
            g[v].push_back(make_pair(w,u));
        }

        vector <int> ans = dijkstra(n,g,0);
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
