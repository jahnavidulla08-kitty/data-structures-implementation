#include <iostream>
#include <cassert>
using namespace std;

class SimpleList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(NULL) {}
    };

    Node* head;

public:
    SimpleList() : head(NULL) {}
    ~SimpleList() { clear(); }

    void insert(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    bool search(int value) const {
        Node* t = head;
        while (t) {
            if (t->data == value) return true;
            t = t->next;
        }
        return false;
    }

    bool remove(int value) {
        if (!head) return false;
        if (head->data == value) {
            Node* t = head;
            head = head->next;
            delete t;
            return true;
        }

        Node* t = head;
        while (t->next && t->next->data != value) t = t->next;
        if (!t->next) return false;

        Node* removed = t->next;
        t->next = removed->next;
        delete removed;
        return true;
    }

    void clear() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }
};

void testInsertAndSearch() {
    SimpleList list;
    list.insert(10);
    list.insert(20);

    assert(list.search(10));
    assert(list.search(20));
    assert(!list.search(99));
}

void testDelete() {
    SimpleList list;
    list.insert(10);
    list.insert(20);

    assert(list.remove(10));
    assert(!list.search(10));
    assert(!list.remove(99));
}

void testEmptyDelete() {
    SimpleList list;
    assert(!list.remove(100));
}

int main() {
    testInsertAndSearch();
    testDelete();
    testEmptyDelete();

    cout << "All unit tests passed successfully!" << endl;
    return 0;
}
