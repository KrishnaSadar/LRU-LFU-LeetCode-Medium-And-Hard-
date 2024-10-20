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

int main() {
    // Create an LFUCache with a capacity of 2
    LFUCache cache(2);

    // Add key-value pairs to the cache
    cache.put(1, 10);  // Cache = {1=10}
    cache.put(2, 20);  // Cache = {1=10, 2=20}

    // Retrieve values using get() method
    cout << "Value for key 1: " << cache.get(1) << endl;  // Should return 10 and increase its frequency
    cache.put(3, 30);  // Since capacity is 2, key 2 (least freq) will be evicted, Cache = {1=10, 3=30}

    // Key 2 should have been evicted, so get(2) should return -1
    cout << "Value for key 2 after eviction: " << cache.get(2) << endl;  // Should return -1

    // Key 1 should still be present
    cout << "Value for key 1: " << cache.get(1) << endl;  // Should return 10

    // Key 3 should also be present
    cout << "Value for key 3: " << cache.get(3) << endl;  // Should return 30

    // Add another key-value pair
    cache.put(4, 40);  // Key 1 will be evicted because both key 1 and key 3 have the same frequency, but key 1 was used least recently, Cache = {3=30, 4=40}

    // Now, key 1 should be evicted, so get(1) should return -1
    cout << "Value for key 1 after eviction: " << cache.get(1) << endl;  // Should return -1

    // Key 3 and key 4 should be present
    cout << "Value for key 3: " << cache.get(3) << endl;  // Should return 30
    cout << "Value for key 4: " << cache.get(4) << endl;  // Should return 40

    return 0;
}
