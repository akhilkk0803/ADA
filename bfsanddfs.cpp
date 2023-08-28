/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],int curr,vector<int>&visited){
    visited[curr]=1;
    cout<<curr<<" ";
    for(auto x:adj[curr]){
        if(!visited[x]){
            dfs(adj,x,visited);
        }
    }
}
void bfs(vector<int>adj[],int v,int e){
    vector<int>visited(v,0);
    queue<int>q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto x:adj[curr]){
            if(!visited[x]){
                visited[x]=1;
                q.push(x);
            }
        }
    }
    cout<<endl;
}
int main()
{  int v,e;
   cout<<"enter v,e";
   cin>>v>>e;
    vector<int>adj[v];
    for(int i=0;i<e;i++){
        cout<<"enter edge";
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(v,0);
    bfs(adj,v,e);
    dfs(adj,0,visited);
    return 0;
}
