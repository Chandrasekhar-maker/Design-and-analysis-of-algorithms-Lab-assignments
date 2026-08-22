
#include<bits/stdc++.h>
using namespace std;
class place{
    public:
    int val;
    place* next;
   
    place(int n,place *p){
        val=n;
        next=p;
    }
};
class Queue{
    private:
    place *front=NULL,*rear=NULL;

    public:
    void enqueue(int n){
        place* temp=new place(n,NULL);
        if(front==NULL)
            front=rear=temp;
        else{
            rear->next=temp;
            rear=temp;
        }
    }
    void dequeue(){
        if(front==NULL){
            cout<<"no elements are avaliable to delete"<<endl;
        }
        else{
            cout<<"element is deleted "<<endl;
            place* temp=front;
            front=front->next;
            delete temp;
        }
    }
    void peeks(){
         cout<<"rear element is "<<rear->val<<endl;
         cout<<"front element is "<<front->val<<endl;
    }
    void display(){
        for( place * i=front;i!=NULL;i=i->next){
            cout<<i->val<<" ";
        }
        cout<<"\n";
    }
    
};

int main(){
    Queue q;
    q.enqueue(28);
    q.enqueue(27);
    q.enqueue(29);
    q.enqueue(18);
    q.display();
    q.peeks();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

}
