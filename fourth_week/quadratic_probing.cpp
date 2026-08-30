
#include<bits/stdc++.h>
using namespace std;

struct HashNode{
    int key;
    string value;
    bool isOccupied;

    HashNode(int k,string val){
        key=k;
        value=val;
        isOccupied=true;
    }

    HashNode(){
        key=0;
        value="";
        isOccupied=false;
    }
};

class HashTable{
      HashNode* table;
      int totalSize;
      int currentSize=0;

      const double Load_factor=0.6;

      int hashFunction(int k){
        return k%totalSize;
      }

     int nextPrime(int n){
        while (true) {
            bool isPrime = true;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                  return n;

            n++;
        }
    }

    void rehash(){
        int oldSize=totalSize;
        HashNode* oldTable=table;

        totalSize=nextPrime(oldSize*2);
        table=new HashNode[totalSize];
        for(int i=0;i<oldSize;i++){
            if(oldTable[i].isOccupied){
                insert(oldTable[i].key,oldTable[i].value);
            }
        }

        delete[] oldTable;
    }

  public:
    
    HashTable(int n){
        totalSize=n;
        table = new HashNode[n];
    }

    void insert(int k,string val){

        if((double) currentSize > totalSize*Load_factor){
            rehash();
        }

        int index=hashFunction(k);
        int originalIndex=index;
        int prob=0;
        while(table[index].isOccupied){
            if(table[index].key==k){
                table[index].value=val;
                return;
            }
            prob++;
            index=((originalIndex+prob*prob%totalSize));

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
			index=(originalIndex+prob*prob)%totalSize;
		    
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
	cout<<"enter element to search ";
	cin>>sea;
	(linear.search(sea)!=-1)?cout<<"element is present at the index "<<linear.search(sea):cout<<"element is not present";
}