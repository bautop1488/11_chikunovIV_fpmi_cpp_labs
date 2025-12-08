#include "vector_impl.h"

Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {}

Vector::Vector(size_t size) : data_(new int[size]()), size_(size), capacity_(size) {}

Vector::Vector(std::initializer_list<int> list)
    : data_(new int[list.size()]), size_(list.size()), capacity_(list.size()) {
    size_t i = 0;
    for (int val : list) {
        data_[i++] = val;
    }
}

Vector::Vector(const Vector& other)
    : data_(new int[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
    for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;

    int* new_data = new int[other.capacity_];
    for (size_t i = 0; i < other.size_; ++i) new_data[i] = other.data_[i];

    delete[] data_;

    data_ = new_data;
    size_ = other.size_;
    capacity_ = other.capacity_;

    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::Swap(Vector& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

int& Vector::operator[](size_t index) {
    return data_[index];
}

const int& Vector::operator[](size_t index) const {
    return data_[index];
}

int& Vector::At(size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return data_[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return data_[index];
}

size_t Vector::Size() const { return size_; }
size_t Vector::Capacity() const { return capacity_; }

void Vector::PushBack(int value) {
    if (size_ == capacity_) {
        size_t new_cap = capacity_ == 0 ? 1 : capacity_ * 2;
        Reserve(new_cap);
    }
    data_[size_++] = value;
}

void Vector::PopBack() {
    if (size_ > 0) --size_;
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity) {
    if (new_capacity <= capacity_) return;

    int* new_data = new int[new_capacity];
    for (size_t i = 0; i < size_; ++i) new_data[i] = data_[i];

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.size_; ++i) {
        os << v.data_[i];
        if (i + 1 < v.size_) os << ", ";
    }
    os << "]";
    return os;
}
