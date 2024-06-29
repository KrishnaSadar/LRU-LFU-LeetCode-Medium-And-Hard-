#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

class LFUCache {
public:
    class Node {
    public:
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1; 
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> cache;
    map<int, Node*> freqMap;
    int minFreq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void increaseFrequency(Node* node) {
        int freq = node->freq;
        freqMap.erase(freq);
        node->freq++;
        freqMap[node->freq] = node;
        if (freqMap[minFreq] == nullptr) {
            minFreq++;
        }
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            increaseFrequency(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            increaseFrequency(node);
        } else {
            if (cache.size() >= capacity) {
                auto leastFreqNode = freqMap[minFreq];
                cache.erase(leastFreqNode->key);
                freqMap.erase(minFreq);
                delete leastFreqNode;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            freqMap[1] = newNode;
            minFreq = 1;
        }
    }
};
