#pragma once

template <typename T>

class StackList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value, Node* nextNode)
            : data(value), next(nextNode) {}
    };

    Node* head_ = nullptr;
    int count_ = 0;

public:
    void push(const T& item){
        Node* newNode = new Node(item, head_);
        head_ = newNode;
        ++count_;
    };
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
};
