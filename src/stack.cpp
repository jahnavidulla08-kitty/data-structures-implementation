#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    ~Stack() {
        clear();
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    bool deleteValue(int& removedValue) {
        if (topNode == NULL) return false;

        Node* temp = topNode;
        removedValue = temp->data;
        topNode = topNode->next;
        delete temp;
        return true;
    }

    bool search(int value) const {
        Node* current = topNode;

        while (current != NULL) {
            if (current->data == value) return true;
            current = current->next;
        }

        return false;
    }

    void display() const {
        Node* current = topNode;

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
    Stack stack;

    stack.insert(10);
    stack.insert(20);
    stack.insert(30);

    cout << "Stack traversal: ";
    stack.display();

    cout << "Search 20: "
         << (stack.search(20) ? "Found" : "Not Found") << endl;

    int removed;
    if (stack.deleteValue(removed))
        cout << "Deleted from stack: " << removed << endl;

    cout << "After deletion: ";
    stack.display();

    return 0;
}
