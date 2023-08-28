/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[mini]>arr[j]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}
void merge(vector<int>&arr,int lb,int mid,int ub){
    int i=lb,j=mid+1;
    vector<int>temp;
    while(i<=mid and j<=ub){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else temp.push_back(arr[j++]);
    }
    while(i<=mid)temp.push_back(arr[i++]);
    while(j<=ub)temp.push_back(arr[j++]);
    int k=0;
    for(int i=lb;i<=ub;i++){
        arr[i]=temp[k++];
    }
}
void mergeSort(int lb,int ub,vector<int>&arr){
    if(lb>=ub)return;
    int mid=(lb+ub)/2;
    mergeSort(lb,mid,arr);
    mergeSort(mid+1,ub,arr);
    merge(arr,lb,mid,ub);
}
void input(){
    for(int i=100;i<=1000;i+=100){
        vector<int>arr(i);
        for(int j=0;j<i;j++){
            arr[j]=rand()%i;
        }
        clock_t start_ss=clock();
        selectionSort(arr);
        clock_t end_ss=clock();
        clock_t start_ms=clock();
        mergeSort(0,i-1,arr);
        clock_t end_ms=clock();
        double time_ss=(double)((end_ss-start_ss))/1000;
        double time_ms=(double)((end_ms-start_ms))/1000;
        cout<<"time for "<<i<<" inputs selectionSort: "<<time_ss<<endl;
        cout<<"time for "<<i<<" inputs mergeSort: "<<time_ms<<endl;
    }
}
int main()
{
    input();

    return 0;
}
