#include<bits/stdc++.h>
using namespace std;
class Dsu{
private:vector<int>parent,size;
public:Dsu(int n){
size.resize(n,1);
parent.resize(n);
for(int i=0;i<n;i++){
parent[i]=i;
}
}
int find(int u){

if(parent[u]==u)return u;
return parent[u]=find(parent[u]);
}
void Union(int u,int v){
int u_par=find(u);
int v_par=find(v);
if(u_par==v_par)return;
if(size[u_par]>size[v_par]){
parent[v_par]=parent[u_par];
size[u_par]+=size[v_par];
}
else {
parent[u_par]=parent[v_par];
size[v_par]+=size[u_par];
}
}
};

int main(){
int v,e;
cout<<"Enter number of vertices and edges";
cin>>v>>e;
Dsu d(v);
vector<vector<int>>adj;
for(int i=0;i<e;i++){
int u,v,cost;
cout<<"Enter edge between u and v and cost between u and v";
cin>>u>>v>>cost;
adj.push_back({cost,u,v});
}
sort(adj.begin(),adj.end());
int sum=0;
for(int i=0;i<e;i++){
if(d.find(adj[i][1])!=d.find(adj[i][2])){
sum+=adj[i][0];
d.Union(adj[i][1],adj[i][2]);
}
cout<<"The sum is"<<sum;
}
}
