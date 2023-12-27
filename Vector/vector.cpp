#include <iostream>
#include <initializer_list>

template <typename T>
class MyVector {
private:
    T* arr;
    int capacity;
    int current_size;

public:
    MyVector() {
        arr = new T[1];
        capacity = 1;
        current_size = 0;
    }

    MyVector(std::initializer_list<T> values) : MyVector() {
        for (const auto& value : values) {
            add_back(value);
        }
    }

    MyVector(int amount, int value) : current_size(amount), capacity(amount) {
        arr = new T[amount];
        for(int i = 0; i < amount; i++) {
            *(arr+i) = value;
        }
    }

    void add_back(T data) {
        // If the vector size is equal to the capacity, double the capacity
        // to store new elements
        if (current_size == capacity) {
            T* temp = new T[2 * capacity];

            // Copy the content of old vector to new vector
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[current_size] = data;
        current_size++;
    }

    T get(int index) {
        if (index < current_size) {
            return arr[index];
        }
    }

    int size() {
        return current_size;
    }

    T* begin() { return arr; }

    T* end() { return arr + current_size; }

    T operator[] (int index) {
        return *(arr + index);
    }

};

int main() {
    MyVector<int> d = {2, 5, 10};
    MyVector<int> d1(10, 100);

    for (const auto& elem : d1) {
        std::cout << elem << std::endl;
    }
    return 0;
}