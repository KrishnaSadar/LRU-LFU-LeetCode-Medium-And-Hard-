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