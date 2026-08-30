
#include<bits/stdc++.h>
using namespace std;
class place{
    public:
    int val;
    place* pre;
    place(int n,place* p){
        val=n;
        pre=p;
    }
};

class Stack{
    private:
    place* top=NULL;

    public:
     void push(int n){
        top=new place(n,top);

     }
     void pop(){
        if(top==NULL){
            cout<<"stack is empty";
        }
        else{
            cout<<"top most element is deleted"<<endl;
           place* del=top;
           top=top->pre;
           delete del;
        }
     }
     void peek(){
        cout<<"top most element is "<<top->val<<endl;
     }
     void display(){
        for(place* i=top;i!=NULL;i=i->pre){
            cout<<i->val<<" ";
        }
        cout<<"\n";
     }
};

int main(){
    Stack s;
    s.push(38);
    s.push(28);
    s.push(18);
    s.push(48);
    s.push(8);
    s.display();
    s.peek();
    s.pop();
    s.display();

}
