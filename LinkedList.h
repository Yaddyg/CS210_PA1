#pragma once
#include "Node.h"
#include "List.h"

using namespace std;

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        size_++;
    }

    void addAnywhere(int position, T* value) override {
        if (position == 0) {
            addFront(value);
            return;
        }
        if (position < 0 || position > size_) {
            std::cout << "Position invalid" << std::endl;
            return;
        }

        Node<T>* fresh = new Node<T>(value);

        Node<T>* current = head_;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;

        }
        fresh->next = current->next;
        current->next = fresh;

        ++size_;


    }




    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
        --size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Position invalid" << std::endl;
            return;
        }

        if (position == 0) {
            Node<T>* temp = head_;
            head_ = head_->next;
            delete temp->data;
            delete temp;
            --size_;
            return;
        }

        Node<T>* current = head_;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp->data;
        delete temp;
        --size_;
    }





    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head_;
        Node<T>* next = nullptr;


        while (current != nullptr) {
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;

        }

        head_ = previous;

    }

    void concat(List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>*>(other);

        if (otherList == nullptr) {
            std::cout << "Invalid list type" << std::endl;
            return;
        }
        if (otherList->head_ == nullptr) {
            std::cout << "Other list is empty." << std::endl;
            return;
        }
        if (head_ == nullptr) {
            head_ = otherList->head_;
            size_ = otherList->size_;
            otherList->head_ = nullptr;
            otherList->size_ = 0;
            return;
        }
        Node<T>* current = head_;

        while (current->next != nullptr) {
            current = current->next;
        }
            current->next = otherList->head_;
            size_ += otherList->size_;
            otherList->head_ = nullptr;
            otherList->size_ = 0;
    }


    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    int size_;

};