
#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int start,int mid,int end){
    int i=start,j=mid+1,k=0;
    int b[end-start+1];
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }

    while(i<=mid){
         b[k++]=a[i++];
    }

    while(j<=end){
         b[k++]=a[j++];
    }

    for(int i=start;i<=end;i++){
        a[i]=b[i-start];
    }
}

void merge_sort(int a[],int start,int end){
    if(start<end){
        int mid=start+(end-start)/2;

        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}


int main(){
    int n;
    cout<<"enter size of the array ";
    cin>>n;
    int a[n];
    cout<<"enter elemetns into the array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    merge_sort(a,0,n-1);
    cout<<"sort order of the elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}