#include<bits/stdc++.h>
using namespace std;

int helper(int w,int profit[],int weight[],int i){

if(i<0)return 0;
int nontake=helper(w,profit,weight,i-1);
int take=INT_MIN;
if(weight[i]<=w)take=helper(w-weight[i],profit,weight,i-1)+profit[i];
return max(take,nontake);
}
int memo(int w,int profit[],int weight[],int i,vector<vector<int>>&dp){

if(i==0)return 0;
if(dp[i][w]!=-1)return dp[i][w];
int nontake=memo(w,profit,weight,i-1,dp);
int take=INT_MIN;
if(weight[i-1]<=w)take=memo(w-weight[i-1],profit,weight,i-1,dp)+profit[i-1];
return dp[i][w]=max(take,nontake);
}
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
//cout<< helper(w,profit,weight,n-1);
//vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
//cout<<memo(w,profit,weight,n,dp);
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
