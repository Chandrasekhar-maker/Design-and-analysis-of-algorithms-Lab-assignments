
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int value;
    Node* next;
  
    Node(int val){
        value=val;
        next=NULL;
    }
    Node(){
        value=0;
        next=NULL;
    }
};


class Bucket{

   Node * bucket[10];

   void insert(int val){
     
        int index=val/1000;
    
        Node* current=bucket[index];

        while(current->next!=NULL && current->next->value<val){
               current=current->next;
        
        }
        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
}

  public:
    void bucket_sort(int a[],int n){

       for(int i=0;i<=9;i++){
               bucket[i]=new Node();
               bucket[i]->value=i;
               bucket[i]->next=NULL;
       }

       for(int i=0;i<n;i++){
                insert(a[i]);
       }

       int index=0;
       for(int i=0;i<=9;i++){
            Node*current=bucket[i]->next;

            while(current!=NULL){
                 a[index]=current->value;
                 current=current->next;
                 index++;
            }
        }
    }
};

int main(){
    
    int n;
    cout<<"enter size of the array ";
    cin>>n;
    int a[n];
    cout<<"enter elemetns into the array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    Bucket SortB;
    SortB.bucket_sort(a,n);
    
    cout<<"sort order of the elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}