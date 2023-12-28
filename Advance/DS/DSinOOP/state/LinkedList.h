#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool IsEmpty() const {
        return head == nullptr;
    }

    void Insert(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    bool Find(const T& data) const {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == data) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    int Count() const {
        int count = 0;
        Node<T>* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    const T& operator[](int index) const {
        Node<T>* current = head;
        int currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) {
                return current->data;
            }

            current = current->next;
            currentIndex++;
        }

        // Handle out-of-bounds index
        throw std::out_of_range("Index out of bounds");
    }
};
