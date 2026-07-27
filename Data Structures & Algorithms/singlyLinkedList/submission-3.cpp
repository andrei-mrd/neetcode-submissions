#include <vector>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int value)
            : value(value), next(nullptr) {
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList()
        : head(nullptr), tail(nullptr), size(0) {
    }

    ~LinkedList() {
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        if (size == 0) {
            tail = newNode;
        }

        size++;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        if (index == 0) {
            Node* nodeToDelete = head;

            head = head->next;
            delete nodeToDelete;

            size--;

            if (size == 0) {
                tail = nullptr;
            }

            return true;
        }

        Node* previous = head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->next;
        }

        Node* nodeToDelete = previous->next;

        previous->next = nodeToDelete->next;

        if (nodeToDelete == tail) {
            tail = previous;
        }

        delete nodeToDelete;
        size--;

        return true;
    }

    std::vector<int> getValues() {
        std::vector<int> values;
        values.reserve(size);

        Node* current = head;

        while (current != nullptr) {
            values.push_back(current->value);
            current = current->next;
        }

        return values;
    }
};