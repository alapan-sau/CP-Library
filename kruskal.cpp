#include <bits/stdc++.h>
using namespace std;

struct edge{
    int s;
    int d;
    int w;
};


int parent[1000];
int siz[1000];

void make_set(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        siz[i]=1;
    }
}

int find_root(int node){
    if(parent[node]==node) return node;
    else return find_root(parent[node]);
}

int do_union(int a, int b){
    int root_a = find_root(a);
    int root_b = find_root(b);

    if(root_a == root_b) return -1;

    if(siz[root_a] > siz[root_b]){
        parent[root_b]=root_a;
        siz[root_a]+=siz[root_b];
        return root_a;
    }
    else{
        parent[root_a]=root_b;
        siz[root_b]+=siz[root_a];
        return root_b;
    }
}

int myComp(edge a, edge b)
{
    // choose a over b if a.w < b.w
    return a.w < b.w;
}

int kruskal(vector <edge> e, int n){

    make_set(n);

    int ans = 0;
    int count = 0;

    int len = e.size();

    sort(e.begin(),e.end(), myComp);


    for(int i=0;i<len;i++){
        if(count == n-1) break;

        int a = e[i].s;
        int b = e[i].d;
        int w = e[i].w;
        if(do_union(a,b)>=0){
            count ++;
            ans+= w;
        }
    }
    if(count == n-1) return ans;
    return -1;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector <edge> e;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            e.push_back({u,v,w});
        }

        cout << kruskal(e,n) << endl;
    }
}