#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }

        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }

        void partitionList(int x) {
    Node* beforeStart = nullptr;
    Node* beforeEnd = nullptr;
    Node* afterStart = nullptr;
    Node* afterEnd = nullptr;

    Node* currentNode = head;
    while (currentNode != nullptr) {
        Node* next = currentNode->next;
        currentNode->next = nullptr;
        if (currentNode->value < x) {
            if (beforeStart == nullptr) {
                beforeStart = currentNode;
                beforeEnd = beforeStart;
            } else {
                beforeEnd->next = currentNode;
                beforeEnd = currentNode;
            }
        } else {
            if (afterStart == nullptr) {
                afterStart = currentNode;
                afterEnd = afterStart;
            } else {
                afterEnd->next = currentNode;
                afterEnd = currentNode;
            }
        }
        currentNode = next;
    }

    if (beforeStart == nullptr) {
        head = afterStart;
    } else {
        beforeEnd->next = afterStart;
        head = beforeStart;
    }
}
};