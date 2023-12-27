#include <iostream>
#include <initializer_list>
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* arr;
    int capacity;
    int current_size;

public:
    // Default constructor if nothing is initialized from the vector
    MyVector() {
        arr = new T[1];
        capacity = 1;
        current_size = 0;
    }

    // Constructor to initialize the elements from given values
    MyVector(std::initializer_list<T> values) : MyVector() {
        for (const auto& value : values) {
            add_back(value);
        }
    }

    // Overload constructor to initialize values and amount of elements
    MyVector(int amount, int value) : current_size(amount), capacity(amount) {
        arr = new T[amount];
        for(int i = 0; i < amount; i++) {
            *(arr+i) = value;
        }
    }

    // Equivalent to push_back()
    void add_back(T data) {
        // If the vector size is equal to the capacity, double the capacity
        // to store new elements
        if (current_size == capacity) {
            capacity *= 2;
            T* new_array = new T[capacity];
            // Copy the content of old vector to new vector
            for (int i = 0; i < capacity; i++) {
                new_array[i] = arr[i];
            }
            delete[] arr;  // Delete the old vector to prevent memory leak
            arr = new_array; // Assign the new array back to the original one
            static int temp = 0;
            std::cout << "Reallocated " << ++temp << " times." << std::endl;
        }

        // Insert the new data into the vector then increase the current size by one
        arr[current_size] = data;
        current_size++;
    }

    // Get the value at given index
    T get_value(int index) {
        if (index < current_size) {
            return arr[index];
        }
    }

    int get_size() { return current_size; }

    int get_capacity() { return capacity; }

    T* begin() { return arr; }

    T* end() { return arr + current_size; }

    void sort() {
        std::sort(begin(), end());
    }

    T operator[] (int index) { return *(arr + index); }

};

int main() {
    MyVector<int> d = {20, 5, 10};

    d.add_back(50);
//    d.add_back(600);

    std::cout << "Before sort: " << std::endl;
    for (const auto& elem : d) {
        std::cout << elem << std::endl;
    }
    std::cout << "Current size: " << d.get_size() << std::endl;
    std::cout << "Max capacity: " << d.get_capacity() << std::endl;

    d.sort();
    std::cout << "After sort: " << std::endl;
    for (const auto& elem : d) {
        std::cout << elem << std::endl;
    }
    return 0;
}