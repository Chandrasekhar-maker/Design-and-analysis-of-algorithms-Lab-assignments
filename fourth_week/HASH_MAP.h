

#ifndef Hash_Map_h
#define Hash_Map_h 

#include<bits/stdc++.h>
using namespace std;

struct HashNode{
    int key;
    int value;
    bool isOccupied;

    HashNode(int k,int val){
        key=k;
        value=val;
        isOccupied=true;
    }

    HashNode(){
        key=0;
        value=0;
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
        totalSize=nextPrime(n);
        table = new HashNode[totalSize];
    }

    void insert(int k,int val){

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
            index=((originalIndex+prob*prob)%totalSize);

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
			     return table[index].value;
		    }
			prob++;
			index=(originalIndex+prob*prob)%totalSize;
		    
		}
		
		return -1;
	}

    void displayFrequencies(HashTable& ht) {
    cout << "\n=== Frequencies ===" << endl;
    cout << "Element\tFrequency" << endl;
    
    for(int i = 0; i < ht.totalSize; i++) {
        if(ht.table[i].isOccupied) {
            cout << ht.table[i].key << "\t" << ht.table[i].value << endl;
        }
    }
}
};

#endif 
