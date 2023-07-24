#include <bits/stdc++.h>
using namespace std;
int main() {
 int v,e;
cout<<"Enter number of vertices and edges";
cin>>v>>e;
vector<pair<int,int>>adj[v];
for(int i=0;i<e;i++){
int u,v,dist;
cout<<"Enter edge between u and v and distance between u and v";
cin>>u>>v>>dist;
adj[u].push_back({v,dist});
adj[v].push_back({u,dist});
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
cout<<"Enter the source";
int src;
cin>>src;
pq.push({0,src});
vector<int>dist(v,1e9);
dist[src]=0;
while(!pq.empty()){
    int curr=pq.top().second;
    int currWt=pq.top().first;
    pq.pop();
    for(auto x:adj[curr]){
        int currNode=x.first;
        int togoDist=x.second;
 if(dist[currNode]>togoDist+currWt){
            dist[currNode]=togoDist+currWt;
            pq.push({dist[currNode],currNode});
        }
    }
}
for(int i=0;i<v;i++){
    cout<<"Dist from"<<src<<" To"<<i<<" is "<<dist[i];
    cout<<endl;
}

return 0;
}
