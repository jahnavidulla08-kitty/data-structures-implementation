#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    ~SinglyLinkedList() {
        clear();
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool deleteValue(int value) {
        if (head == NULL) return false;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next != NULL &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == NULL) return false;

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    bool search(int value) const {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == value) return true;
            temp = temp->next;
        }

        return false;
    }

    void display() const {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Singly Linked List: ";
    list.display();

    cout << "Search 20: "
         << (list.search(20) ? "Found" : "Not Found") << endl;

    cout << "Delete 20: "
         << (list.deleteValue(20) ? "Deleted" : "Not Found") << endl;

    cout << "After deletion: ";
    list.display();

    return 0;
}
