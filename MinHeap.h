//
// Created by zedio on 21/01/2022.
//

#ifndef PROJETO2_MINHEAP_H
#define PROJETO2_MINHEAP_H


#include <vector>
#include <unordered_map>

#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

using namespace std;

/**
 * @brief Binary min-heap to represent integer keys of type K with values (priorities) of type V
 *
 */
template <class K, class V>
class MinHeap {
    /**
     * @brief An element of the heap: a pair (key, value)
     *
     */
    struct Node {
        K key;   /*!< A key  */
        V value; /*!< The value attached to a key  */
    };

    int size;                  /*!< Number of elements in the heap  */
    int maxSize;               /*!< Maximum number of elements that can be in the heap  */
    vector<Node> a;            /*!< The heap array as a std::vector  */
    unordered_map<K, int> pos; /*!< Maps a key into its position in the array  */
    const K KEY_NOT_FOUND;     /*!< A default value for when a key doesn't exist  */

    /**
     * @brief Make a value go "up the tree" until it reaches its position
     *
     * @param i Value to move up in priority
     */
    void upHeap(int i);

    /**
    * @brief Make a value go "down the tree" until it reaches its position
    *
    * @param i Value to move down in priority
    */
    void downHeap(int i);

    /**
     * @brief Swap two positions in the heap
     *
     * @param i1 First position to swap
     * @param i2 Second position to swap
     */
    void swap(int i1, int i2);

public:
    /**
     * @brief Create a min-heap for a max of n pairs (K,V) with notFound returned when empty
     *
     * @param n Number of pairs in the heap
     * @param notFound Value to return when empty
     */
    MinHeap(int n, const K& notFound);

    /**
     * @brief Return number of elements in the heap
     *
     * @return int Size of the heap's array
     */
    int getSize();

    /**
     * @brief Check if the heap contains the provided key
     *
     * @param key Key to check if exists in the heap
     *
     * @return boolean True if it exists, false otherwise
     */
    bool hasKey(const K& key);

    /**
     * @brief // Insert (key, value) on the heap
     *
     * @param key A key
     * @param value A value associated to the key
     */
    void insert(const K& key, const V& value);

    /**
     * @brief Decrease value of key
     *
     * @param key Key to decrease
     * @param value Target value
     */
    void decreaseKey(const K& key, const V& value);

    /**
     * @brief Remove and return key with smaller value
     *
     * @return K Key with the smallest associated value
     */
    K removeMin();
};

// ----------------------------------------------

template <class K, class V>
void MinHeap<K,V>::upHeap(int i) {
    while (i>1 && a[i].value < a[PARENT(i)].value) { // while pos smaller than parent, keep swapping to upper position
        swap(i, PARENT(i));
        i = PARENT(i);
    }
}

// Make a value go "down the tree" until it reaches its position
template <class K, class V>
void MinHeap<K,V>::downHeap(int i) {
    while (LEFT(i) <= size) { // while within heap limits
        int j = LEFT(i);
        if (RIGHT(i)<=size && a[RIGHT(i)].value < a[j].value) j = RIGHT(i); // choose smaller child
        if (a[i].value < a[j].value) break;   // node already smaller than children, stop
        swap(i, j);                    // otherwise, swap with smaller child
        i = j;
    }
}

// Swap two positions of the heap (update their positions)
template <class K, class V>
void MinHeap<K,V>::swap(int i1, int i2) {
    Node tmp = a[i1]; a[i1] = a[i2]; a[i2] = tmp;
    pos[a[i1].key] = i1;
    pos[a[i2].key] = i2;
}

// ----------------------------------------------

// Create a min-heap for a max of n pairs (K,V) with notFound returned when empty
template <class K, class V>
MinHeap<K,V>::MinHeap(int n, const K& notFound) : KEY_NOT_FOUND(notFound), size(0), maxSize(n), a(n+1) {
}

// Return number of elements in the heap
template <class K, class V>
int MinHeap<K,V>::getSize() {
    return size;
}

// Heap has key?
template <class K, class V>
bool MinHeap<K, V>::hasKey(const K& key) {
    return pos.find(key) != pos.end();
}

// Insert (key, value) on the heap
template <class K, class V>
void MinHeap<K,V>::insert(const K& key, const V& value) {
    if (size == maxSize) return; // heap is full, do nothing
    if (hasKey(key)) return;     // key already exists, do nothing
    a[++size] = {key, value};
    pos[key] = size;
    upHeap(size);
}

// Decrease value of key to the indicated value
template <class K, class V>
void MinHeap<K,V>::decreaseKey(const K& key, const V& value) {
    if (!hasKey(key)) return; // key does not exist, do nothing
    int i = pos[key];
    if (value > a[i].value) return; // value would increase, do nothing
    a[i].value = value;
    upHeap(i);
}

// remove and return key with smaller value
template <class K, class V>
K MinHeap<K,V>::removeMin() {
    if (size == 0) return KEY_NOT_FOUND;
    K min = a[1].key;
    pos.erase(min);
    a[1] = a[size--];
    downHeap(1);
    return min;
}


#endif //PROJETO2_MINHEAP_H
