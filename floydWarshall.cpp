#include <bits/stdc++.h>
using namespace std;

// not tested

int graph[500][500];

void floydWarshal(int n){

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) graph[i][j]=0;
                else graph[i][j] = INT_MAX;
            }
        }

        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            graph[u][v]=w;
            graph[v][u]=w;
        }

        floydWarshal(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cout << graph[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
