
#include<bits/stdc++.h>
using namespace std;

int partision(int a[],int l,int h){
    int i=l,j=l;
    int pivot=a[h];

    for( i=l;i<h;i++){
        if(a[i]<=pivot){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;

            j++;
        }
    }

     int temp=a[i];
     a[i]=a[j];
     a[j]=temp;


    return j;
}

void Quick_sort(int a[],int start,int end){

    if(start<end){
        int p=partision(a,start,end);
        Quick_sort(a,start,p-1);
        Quick_sort(a,p+1,end);
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
    Quick_sort(a,0,n-1);
    cout<<"sort order of the elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}