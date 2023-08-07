#include <bits/stdc++.h>
using namespace std;
int main() {
 int v,e;
cout<<"Enter number of vertices and edges";
cin>>v>>e;
vector<pair<int,int>>adj[v]={{{2,3}},{{0,2}},{{1,7},{3,1}},{{0,6}}};
// for(int i=0;i<e;i++){
// int u,v,dist;
// cout<<"Enter edge between u and v and distance between u and v";
// cin>>u>>v>>dist;
// adj[u].push_back({v,dist});
// }

 vector<vector<int>>distance(v,vector<int>(v,1e9));
 for(int i=0;i<v;i++){
     for(auto x:adj[i]){
         distance[i][x.first]=x.second;
     }
 }
 for(int i=0;i<v;i++){
     distance[i][i]=0;
 }
for(int via=0;via<v;via++){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            distance[i][j]=min(distance[i][via]+distance[via][j],distance[i][j]);
        }
    }
}
for(int i=0;i<v;i++){
    cout<<i<<" Src"<<endl;
    for(int j=0;j<v;j++){
        cout<<i<<" to"<<" "<<j<<":"<<distance[i][j]<<endl;
    }
    cout<<endl;
}

}
