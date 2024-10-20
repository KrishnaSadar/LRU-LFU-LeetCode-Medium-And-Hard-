#include<map>

#include "bits/stdc++.h"
using namespace std;
class LRUCache{
    public:
    class node{
        public:
        int val;
        int key;
        node* next;
        node* prev;

        node(int k,int v){
            key=k;
            val=v;
            next=nullptr;
            prev=nullptr;
        }
    };
    int cap;
    unordered_map<int,node*>mpp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
LRUCache(int cap1){
    cap=cap1;
    head->next=tail;
    tail->prev=head;
}
    void deleteNode(node* temp){
        node* deleprev=temp->prev;
        node* delnext=temp->next;
        deleprev->next=delnext;
         delnext->prev=deleprev;
         delete temp;
    }
    void addNode(node* add){
        node* temp=head->next;
              head->next=add;
              add->prev=head;
              add->next=temp;
              temp->prev=add;
    }
    

     int get(int key){
        if(mpp.find(key)!=mpp.end()){
            node* resnode=mpp[key];
            int res=resnode->val;
            mpp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mpp[key]=head->next;
            return res;
        }
        return -1;
     }
     void put(int key,int val){
        if(mpp.find(key)!=mpp.end()){
            node* resnode=mpp[key];
            mpp.erase(key);
            deleteNode(resnode);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,val));
        mpp[key]=head->next;
     }

};
int main() {
    // Create an LRUCache with a capacity of 2
    LRUCache cache(2);

    // Add key-value pairs to the cache
    cache.put(1, 10);
    cache.put(2, 20);
    
    // Retrieve values using get() method
    cout << "Value for key 1: " << cache.get(1) << endl;  // Should return 10
    cout << "Value for key 2: " << cache.get(2) << endl;  // Should return 20

    // Add another key-value pair, which will cause the least recently used (key 1) to be evicted
    cache.put(3, 30);
    
    // Now, key 1 should be evicted, so get(1) should return -1
    cout << "Value for key 1 after eviction: " << cache.get(1) << endl;  // Should return -1

    // Key 2 should still be in the cache
    cout << "Value for key 2: " << cache.get(2) << endl;  // Should return 20
    
    // Key 3 should also be in the cache
    cout << "Value for key 3: " << cache.get(3) << endl;  // Should return 30

    // Add another key-value pair, which will cause key 2 (least recently used) to be evicted
    cache.put(4, 40);
    
    // Now, key 2 should be evicted, so get(2) should return -1
    cout << "Value for key 2 after eviction: " << cache.get(2) << endl;  // Should return -1

    // Key 3 and key 4 should still be in the cache
    cout << "Value for key 3: " << cache.get(3) << endl;  // Should return 30
    cout << "Value for key 4: " << cache.get(4) << endl;  // Should return 40

    return 0;
}
