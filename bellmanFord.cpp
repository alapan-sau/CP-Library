#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a;
    int b;
    int w;
};

vector <int> bellmanFord(int n, int m, vector <edge> e, int src){

    vector <int> dist(n,INT_MAX);
    vector <int> parent(n, -1);

    dist[src]=0;


    // relax all the edges n-1 times and blah. One more iteration for cycle detection!!
    int x = -1;
    for(int i=0;i<n;i++){
        x = -1;

        // here total number of edges are 2m. As it is undirected.
        for(int j=0;j<2*m;j++){
            int node1 = e[j].a;
            int node2 = e[j].b;
            int weight = e[j].w;

            if(dist[node1] == INT_MAX)continue;

            if(dist[node1] + weight < dist[node2]){
                dist[node2] = dist[node1]+weight;
                parent[node2] = node1;
                x=1;
            }
        }
    }
    if(x==-1) cout << "No Negative Cycles :)" << endl;
    else cout << "Negative Cycle Present! :(" << endl;

    return dist;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> n >> m;

        vector < edge > e;

        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            e.push_back({u,v,w});
            e.push_back({v,u,w});
        }

        vector <int> ans = bellmanFord(n,m,e,0);
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
