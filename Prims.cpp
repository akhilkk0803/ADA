// // list
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
// int v,e;
// cout<<"Enter number of vertices and edges";
// cin>>v>>e;
// vector<pair<int,int>>adj[v];
// for(int i=0;i<e;i++){
// int u,v,cost;
// cout<<"Enter edge between u and v and cost between u and v";
// cin>>u>>v>>cost;
// adj[u].push_back({v,cost});
// adj[v].push_back({u,cost});
// }
// vector<int>visited(v,0);
// q.push({0,0});
// int sum=0;
// while(!q.empty()){
// int currNode=q.top().second;
// int currWeight=q.top().first;
// q.pop();
// if(!visited[currNode]){
// sum+=currWeight;
// }
// else continue;
// visited[currNode]=1;
// for(auto x:adj[currNode]){
// int node=x.first;
// int wt=x.second;
// if(!visited[node]){
// q.push({wt,node});
// }
// }
// }
// cout<<"The sum is "<<sum;
// }
//matrix
#include<bits/stdc++.h>
using namespace std;
int main(){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int v,e;
cout<<"Enter number of vertices and edges";
cin>>v>>e;
int adj[v][v]={0};
for(int i=0;i<e;i++){
int u,v,cost;
cout<<"Enter edge between u and v and cost between u and v";
cin>>u>>v>>cost;
adj[u][v]=cost;
adj[v][u]=cost;
}
vector<int>visited(v,0);
q.push({0,0});
int sum=0;
while(!q.empty()){
int currNode=q.top().second;
int currWeight=q.top().first;
q.pop();
if(!visited[currNode]){
sum+=currWeight;
}
else continue;
visited[currNode]=1;
for(int i=0;i<v;i++){
int wt=adj[currNode][i];
if(wt!=0){
    if(!visited[i]){
q.push({wt,i});
}
}
}
}
cout<<"The sum is "<<sum;
}
