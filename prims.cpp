#include <bits/stdc++.h>
using namespace std;

// Using priority_queue
int prims(int n, vector <pair <int, int>> g[]){
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

    vector <int> cost(n,INT_MAX);
    vector <int> parent(n, -1);
    vector <int> inSet(n, 0);

    pq.push(make_pair(0,0));
    cost[0]=0;

    int totalCost = 0;
    while(!pq.empty()){
        int node  = pq.top().second;
        int minCost = pq.top().first;
        pq.pop();

        if(inSet[node]==1)continue;

        inSet[node]=1;
        totalCost+= minCost;

        int len = g[node].size();
        for(int i=0;i<len;i++){
            // neighbour
            int newNode = g[node][i].second;
            int newWeight = g[node][i].first;

            // relax the neighbours
            if(!inSet[newNode] && newWeight < cost[newNode]){
                cost[newNode] = newWeight;
                parent[newNode] = node;
                pq.push(make_pair(cost[newNode],newNode));
            }
        }
    }
    return totalCost;
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

        int ans = prims(n,g);
        cout << ans;
        cout << "\n";
    }
}
