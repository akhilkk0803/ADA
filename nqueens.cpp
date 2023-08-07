#include <bits/stdc++.h>
using namespace std;
bool isValid(int row,int col,int n,vector<string>&board){
        for(int i=col-1;i>=0;i--){
            if(board[row][i]=='Q')return false;
        }
        for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=row+1,j=col-1;i<n and j>=0;i++,j--){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve(int i,vector<string>&board,int n){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int k=0;k<n;k++){
            board[k][i]='Q';
            if(isValid(k,i,n,board)){
                solve(i+1,board,n);
            }
            board[k][i]='.';
        }
    }

int main()
{
    int n;
    cout<<"Enter the size of board";
    cin>>n;
    vector<string>board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i]+='.';
            }
        }
        solve(0,board,n);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<endl;
            }
            cout<<"----------------------"<<endl;
        }

    return 0;
}
