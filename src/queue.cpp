#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    ~Queue() {
        clear();
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (rearNode == NULL) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    bool deleteValue(int& removedValue) {
        if (frontNode == NULL) return false;

        Node* temp = frontNode;
        removedValue = temp->data;
        frontNode = frontNode->next;

        if (frontNode == NULL)
            rearNode = NULL;

        delete temp;
        return true;
    }

    bool search(int value) const {
        Node* current = frontNode;

        while (current != NULL) {
            if (current->data == value) return true;
            current = current->next;
        }

        return false;
    }

    void display() const {
        Node* current = frontNode;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        int removed;
        while (deleteValue(removed)) {
        }
    }
};

int main() {
    Queue queue;

    queue.insert(10);
    queue.insert(20);
    queue.insert(30);

    cout << "Queue traversal: ";
    queue.display();

    cout << "Search 20: "
         << (queue.search(20) ? "Found" : "Not Found") << endl;

    int removed;
    if (queue.deleteValue(removed))
        cout << "Deleted from queue: " << removed << endl;

    cout << "After deletion: ";
    queue.display();

    return 0;
}
