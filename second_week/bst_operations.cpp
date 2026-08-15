
#include<bits/stdc++.h>
using namespace std;
class tree{
public:
    int val;
    tree* left;
    tree* right;

    tree(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

tree* root=NULL;

int min(tree* root){
    if(root->left==NULL)
        return root->val;
    else{
        min(root->left);
    }
}
void insert(int num){
    if(root==NULL)
          root=new tree(num);
    else{
        tree* current=root;
        tree* parent=NULL;
        while(1){
            if(current->val<num){
                parent=current;
                current=current->right;
                if(current==NULL){
                    parent->right=new tree(num);
                    break;
                }
            }
            else{
               parent=current;
                current=current->left;
                if(current==NULL){
                    parent->left=new tree(num);
                    break;
                } 
            }
        }
    }
}

void inorder(tree* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

int min_bst(tree* root){
    if(root->left==NULL)
        return root->val;
    return min_bst(root->left);
}
tree* deletion(tree* root,int key){
    if(root==NULL)
         return NULL;
    else if(key<root->val){
        root->left=deletion(root->left,key);
    }
    else if(key>root->val){
        root->right=deletion(root->right,key);
    }
    else{
        if(root->left==NULL){
            tree* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            tree* temp=root->left;
            free(root);
            return temp;
        }
        else{
                 int temp=min(root->right);
                 root->val=temp;
                 return deletion(root->right,temp);
        }
    }
}
int main(){
    insert(45);
    insert(18);
    insert(7);
    insert(10);
    insert(17);
    insert(96);
    insert(93);
    insert(3);

    inorder(root);

    deletion(root,93);
    cout<<"\nafter deletion"<<93<<endl;
    inorder(root);
    deletion(root,17);
    cout<<"\nafter deletion"<<17<<endl;
    inorder(root);
}