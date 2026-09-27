#include "SkipList.h"

int skipList::randomLevel() {
    int lvl = 1;
    uniform_real_distribution<double> dist(0.0, 1.0);
    
    while (dist(rng)<p&& lvl< maxLevel) {
        lvl++;
    }
    return lvl;

}
void skipList::print(){
    for(int i=level-1;i>=0;i--){
        cout<<"Level "<<i<<": Header ->";
        Node* current = header->forward[i];
        while (current != nullptr) {
            cout <<current->key << " -> ";
            current = current->forward[i];
        }
        cout << "NIL" << endl;
    }
    cout<<endl;
}
bool skipList::search(int key,int& value){
    Node* current = header;
    for (int i = level - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && 
               current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current != nullptr && current->key == key) {
        value = current->value;
        return true;
    }
    return false;
}   
void skipList::insert(int key, int value) {

    vector<Node*> update(maxLevel + 1);
    Node* current = header;
    for (int i = level - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && 
               current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    
    if (current != nullptr && current->key == key) {
        current->value = value;
        return;
    }
    int lvl = randomLevel();

    if (lvl > level) {
        for (int i = level; i < lvl; i++) {
            update[i] = header;
        }
        level = lvl;
    }
    Node* newNode = new Node(key, value, lvl);
    
    for (int i = 0; i < lvl; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
    currentSize++;
}
void skipList::remove(int key) {

    vector<Node*> update(maxLevel + 1);
    Node* current = header;

    for (int i = level - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && 
               current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current->forward[0];
    if (current == nullptr || current->key != key) {
        return;
    }
    
    for (int i = 0; i < level; i++) {
        if (update[i]->forward[i] == current) {
            update[i]->forward[i] = current->forward[i];
        }
    }
    delete current;

    while (level>1 && header->forward[level-1] == nullptr) {
        level--;
    }
    currentSize--;
}
bool skipList::empty() const {
    return currentSize==0;
}
int skipList::size()const {
    return currentSize;
}