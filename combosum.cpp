#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void combination(int n,int sum,int a[],int i,vector<int>&temp){
    if(i==n){
        if(sum==0){
            ans.push_back(temp);
        }
        return;
    }
    combination(n,sum,a,i+1,temp);
    if(sum>=a[i]){
    temp.push_back(a[i]);
    combination(n,sum-a[i],a,i+1,temp);
    temp.pop_back();
    }
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k;
    cout<<"Enter Target";
    cin>>k;
    vector<int>temp;
    combination(n,k,a,0,temp);
    for(auto x:ans){
for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
