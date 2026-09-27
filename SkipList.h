#include <iostream>
#include <vector>
#include <random>
#include <climits>
using namespace std;

class Node {
    public:
    int key;
    int value;
    vector<Node*>forward;
    Node(int k, int v, int level):
    key(k), value(v), forward(level+1, nullptr){}
};

class skipList{

    private:
    Node* header;
    int level;
    int maxLevel;
    float p;
    mt19937 rng;
    int currentSize;
    int randomLevel();

    public:
    skipList(int maxLevel= 16, float p=0.5)
    : maxLevel(maxLevel),p(p),rng(random_device{}()), level(1),currentSize(0){
        header = new Node(0, 0, maxLevel);
    }

    ~skipList() {
    Node* current = header;
    while (current != nullptr) {
        Node* next = current->forward[0];
        delete current;
        current = next;
    }
    }

    void print(); 
    void insert(int key, int value);
    void remove(int key);
    int size() const;
    bool empty() const;
    bool search(int key,int& value);

};