#include<bits/stdc++.h>
using namespace std;


int parent[1000];
int siz[1000];

void make_set(){
    for(int i=0;i<1000;i++){
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


int main(){
    make_set();
    cout << do_union(1,2) << endl;
    cout << do_union(2,3) << endl;
    cout << do_union(4,5) << endl;
    cout << do_union(1,4) << endl;
    cout << do_union(2,5) << endl;
}