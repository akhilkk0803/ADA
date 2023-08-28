#include<bits/stdc++.h>
using namespace std;

void dfs(vector<bool>&visited,vector<int>adj[],int curr,stack<int>&st){

visited[curr]=true;
for(auto x:adj[curr]){
if(!visited[x]){
dfs(visited,adj,x,st);
}
}
st.push(curr);
}

int main(){
int n,edges,u,v;
cout<<"Enter the number of nodes and number of edges";
cin>>n>>edges;
vector<bool>visited(n,false);
vector<int>adj[n];
for(int i=0;i<edges;i++){
cout<<"Enter u and v";
cin>>u>>v;
adj[u].push_back(v);
}
stack<int>st;
dfs(visited,adj,0,st);
while(!st.empty()){
cout<<st.top();
st.pop();
}
}
