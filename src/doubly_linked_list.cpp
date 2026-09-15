#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) {
            data = value;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~DoublyLinkedList() {
        clear();
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool deleteValue(int value) {
        Node* current = head;

        while (current != NULL && current->data != value) {
            current = current->next;
        }

        if (current == NULL) return false;

        if (current->prev != NULL)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
        return true;
    }

    bool search(int value) const {
        Node* current = head;

        while (current != NULL) {
            if (current->data == value) return true;
            current = current->next;
        }

        return false;
    }

    void displayForward() const {
        Node* current = head;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() const {
        Node* current = tail;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
    }
};

int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Forward traversal: ";
    list.displayForward();

    cout << "Backward traversal: ";
    list.displayBackward();

    cout << "Search 20: "
         << (list.search(20) ? "Found" : "Not Found") << endl;

    cout << "Delete 20: "
         << (list.deleteValue(20) ? "Deleted" : "Not Found") << endl;

    cout << "After deletion: ";
    list.displayForward();

    return 0;
}
