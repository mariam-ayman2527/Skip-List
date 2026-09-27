

#include "SkipList.h"
#include "test.h"


void testPrint() {
    cout << "=== Test: Print ===" << endl;
    skipList sl;
    
    sl.insert(3, 30);
    sl.insert(6, 60);
    sl.insert(7, 70);
    sl.insert(9, 90);
    sl.insert(12, 120);
    sl.insert(21, 210);
    sl.insert(25, 250);
    
    sl.print();
    cout << "size: " << sl.size() << endl << endl;
}

void testRandomInsert() {
    cout << "=== Test: Random Insert ===" << endl;
    skipList sl;
    
    int arr[] = {25, 3, 12, 6, 21, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        sl.insert(arr[i], arr[i] * 10);
    }
    
    sl.print();
    cout << "size: " << sl.size() << endl << endl;
}

void testDeleteAndLevel() {
    cout << "=== Test: Delete and Level ===" << endl;
    skipList sl;
    
    sl.insert(3, 30);
    sl.insert(6, 60);
    sl.insert(7, 70);
    sl.insert(9, 90);
    sl.insert(21, 210);
    
    cout << "Before delete:" << endl;
    sl.print();
    
    sl.remove(21);
    sl.remove(9);
    
    cout << "After delete:" << endl;
    sl.print();
    cout << endl;
}

