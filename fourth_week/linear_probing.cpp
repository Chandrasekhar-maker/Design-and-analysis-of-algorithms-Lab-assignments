#include<bits/stdc++.h>
using namespace std;

struct HashNode{
	int key;
	string value;
	bool isOccupied;
	
	HashNode(){
		key=0;
		value="";
		isOccupied=false;
	}
	HashNode(int k,string v){
		key=k;
		value=v;
		isOccupied=true;
	}
	
};

class HashTable{
	 
	 HashNode* table;
	 int currentSize=0;
	 int totalSize=0;
	 
	 const double Load_Factor=0.6;
	 
	 int hashFunction(int k){
	 	return k%totalSize;
	 }
	 
	 void rehash(){
	 	int oldSize=totalSize;
	 	HashNode* oldTable=table;
	 	
	 	totalSize=totalSize*2;
	 	currentSize=0;
	 	table=new HashNode[totalSize];
	 	
	 	for(int i=0;i<oldSize;i++){
	 		if(oldTable[i].isOccupied){
	 			insert(oldTable[i].key,oldTable[i].value);
			 }
		}
		
		delete[] oldTable;
	 }
	 
  public:
  	
  	HashTable(int size){
  		totalSize=size;
  		currentSize=0;
  		table= new HashNode[totalSize];
	}
	
	void insert(int k,string val){
		
		if((double) currentSize >=totalSize*Load_Factor){
			rehash();
		}
		
		int index=hashFunction(k);
		int originalIndex=index;
		int prob=0;
		
		while(table[index].isOccupied){
			
			if(table[index].key==k){
				table[index].value=val;
				return ;
			}
			
			prob++;
			index=(originalIndex+prob)%totalSize;
			
			if(prob>=totalSize){
				rehash();
				insert(k,val);
				return;
			}
		}
		table[index]=HashNode(k,val);
		currentSize++;
	}
	
	int search(int k){
		int index=hashFunction(k);
		int originalIndex=index;
		int prob=0;
		while(table[index].isOccupied){
			if(table[index].key==k){
			     return index;
		    }
			prob++;
			index=(originalIndex+prob)%totalSize;
		    
		}
		
		return -1;
	}
};

int main(){

	HashTable linear(10);
	linear.insert(4,"four");
	linear.insert(24,"twentyfour");
	linear.insert(84,"Eightyfour");
	
	int sea;
	cout<<"enter element to search";
	cin>>sea;
	(linear.search(sea)!=-1)?cout<<"element is present at the index "<<linear.search(sea):cout<<"element is not present";
}
