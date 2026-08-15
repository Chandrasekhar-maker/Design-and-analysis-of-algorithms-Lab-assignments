
#include<bits/stdc++.h>
using namespace std;



class minHeap{
	vector<int> arr=vector<int>(100);
    int p=0;
    
    void restoreup(){
	   int i=p;
	   int k=arr[p];
	   int parent=p/2;
	   while(arr[parent]>k && i>1){
	    	arr[i]=arr[parent];
		    i=parent;
		    parent=i/2;
	   }
	   arr[i]=k;
   }
void heapfiy(){
	int i=1;
	int k=arr[1];
	int left=2*i,right=2*i+1;
	while(left<=p){
		int j=left;
		if(right<=p && arr[right]<arr[left]){
			j=right;
		}
		if(arr[j]>k)
		    break;
		arr[i]=arr[j];
		i=j;
		left=2*i,right=2*i+1;
	}
	arr[i]=k;
}
   
   
public:
	
	void insert(int num){
	   arr[++p]=num;
	   restoreup();
	
   }

   void deletion(){
    	arr[1]=arr[p--];
     	heapfiy();
   } 
   
   int getMin() const {
        return arr[1];
    }
};


void mearge(int a[],int s,int e,int mid){
    int i=s,j=mid+1,k=0;
    int b[e-s+1];
    while(i<=mid && j<=e){
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
    while(j<=e){
         b[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i]=b[i-s];
    }
}

void sort_a(int a[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        sort_a(a,s,mid);
        sort_a(a,mid+1,e);
        mearge(a,s,e,mid);
    }
}

int main(){
    int n;
    cout<<"enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"enter elements into the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort_a(arr,0,n-1);

    int k;
    cout<<"enter k value to found kth-smallest number";
    cin>>k;
    


    minHeap heap;
    for(int i=0;i<n;i++){
        heap.insert(arr[i]);
    }
    
    for(int i=1;i<k;i++){
        heap.deletion();
    }

    cout<<"kth-smallest element in the array is: "<<arr[k-1]<<" through sorting method"<<endl;
    cout<<"kth-smallest element in the array is: "<<heap.getMin()<<" through min heap method"<<endl;

}
