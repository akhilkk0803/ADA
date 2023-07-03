#include<bits/stdc++.h>

using namespace std;


int main(){

int n,edges,u,v;
cout<<"Enter the number of nodes and number of edges";
cin>>n>>edges;
vector<bool>visited(n,false);
vector<int>adj[n],indegree(n,0),ans;
for(int i=0;i<edges;i++){
cout<<"Enter u and v";
cin>>u>>v;
adj[u].push_back(v);
indegree[v]++;
}
queue<int>q;
for(int i=0;i<n;i++){
if(indegree[i]==0){
q.push(i);
}
}
int noofNodes=0;
while(!q.empty()){

int curr=q.front();
q.pop();
ans.push_back(curr);
noofNodes++;
if(noofNodes==n)break;
for(auto x:adj[curr]){
indegree[x]--;
if(indegree[x]==0){
q.push(x);
}
}
}
if(noofNodes==n){
for(auto x:ans){
cout<<x<<" ";
}
}
else cout<<"Sorting Not possible";
}