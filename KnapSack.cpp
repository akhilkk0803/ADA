#include<bits/stdc++.h>
using namespace std;

int main(){
int n,w;
cout<<"Enter no of items and the maxWeight of the bag";
cin>>n>>w;
int profit[n];
int weight[n];
cout<<"Enter the profits";
for(int i=0;i<n;i++){
cin>>profit[i];
}
cout<<"Enter the weights";
for(int i=0;i<n;i++){
cin>>weight[i];
}
// tabulation O(n*w) SC:-O(n*w)
vector<vector<int>>dp(n+1,vector<int>(w+1,0));
for(int i=1;i<=n;i++){

for(int j=0;j<=w;j++){

int nontake=dp[i-1][j];
int take=INT_MIN;
if(j>=weight[i-1])take=dp[i-1][w-weight[i-1]]+profit[i-1];
dp[i][j]=max(take,nontake);
}
}
cout<<dp[n][w];
}
