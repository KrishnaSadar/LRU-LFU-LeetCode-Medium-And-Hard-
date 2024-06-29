# Cache Management Project

## LFU Cache Implementation

### Overview

Experienced in designing and implementing advanced Data Structures and Algorithms, specializing in Cache Management:

**LFU Cache Implementation:**
Crafted a scalable LFU (Least Frequently Used) Cache using unordered maps and frequency-based linked lists. This solution efficiently manages key-value pairs, dynamically adjusting frequencies and removing less accessed entries based on minimal frequency occurrences.

#### Explanation

- **Data Structures Utilized:** Utilized `unordered_map` for fast key lookup and `map` for frequency tracking, ensuring quick access and frequency management.
- **Algorithm Approach:** On cache hits (get operations), increments the frequency of accessed items, reorganizing them in the frequency map. On cache misses (put operations), evicts the least frequently accessed item to maintain cache size limits.
- **Complexity Analysis:** Achieved average time complexities of O(1) for both get and put operations by leveraging efficient data structures.

## LRU Cache Implementation

### Overview

**LRU Cache Implementation:**
Developed an efficient LRU (Least Recently Used) Cache using doubly linked lists and hash maps. This solution optimizes cache performance by removing the least recently accessed items when the cache reaches capacity limits.

#### Explanation

- **Core Structures:** Implemented a doubly linked list for quick insertion and deletion operations, complemented by a hash map for fast key-value pair lookups.
- **Operating Principle:** Ensured that recently accessed items are moved to the front of the list, while eviction occurs from the end of the list when capacity is exceeded.
- **Performance Metrics:** Maintained average time complexities of O(1) for both get and put operations, emphasizing performance efficiency and responsiveness.

## Key Contributions

- Developed robust methods for adding, retrieving, and managing cache entries, optimizing operations for maximum efficiency.
- Thoroughly tested implementations across diverse test cases, validating correctness and efficiency under varying workload conditions.
- Documented comprehensive algorithmic approaches, including time and space complexity analyses, to demonstrate proficiency in problem-solving and optimization strategies.

## Skills Highlight

Data Structures | Algorithms | Cache Management | Problem-solving | C++ Programming
