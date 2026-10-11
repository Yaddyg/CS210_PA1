#pragma once
#include <iostream>
#include "List.h"
#include <utility>

using namespace std;

template<typename T>

class ArrayList : public List<T> {
public:
    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Position invalid" << std::endl;
            return;
        }
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }
        data_[position] = value;
        ++size_;
    }


    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Position invalid" << std::endl;
            return;
        }
        delete data_[position];
        for (int i = position; i < size_ -1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }


    void reverse() override {
        int left = 0, right = size_ - 1;
        while (left < right) {
            std::swap(data_[left], data_[right]);
            ++left;
            --right;

        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* otherArray = dynamic_cast<ArrayList<T>*>(other);
        if (otherArray == nullptr) {
            std::cout << "Invalid list type" << std::endl;
            return;
        }

        if (size_ + otherArray->size_ > CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
         for (int i = 0; i < otherArray->size_; ++i) {
             data_[size_ + i] = otherArray->data_[i];

         }
        size_ += otherArray->size_;
        otherArray->size_ = 0;


    }


    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_ = 0;
};