#ifndef VECTOR_MY
#define VECTOR_MY

#include <cstddef>
#include <stdexcept>

template <class T>
class Vector
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    Vector():_capacity(0), _size(0) {
        _data = 0;
    }

    explicit Vector(size_type count):_capacity(count), _size(count) {
        _data = new value_type[count];
        for (unsigned int i = 0; i < count; i++) {
            _data[i] = 0;
        }
    }

    Vector(size_type count, const value_type& value):_capacity(count), _size(count) {
        _data = new value_type[count];
        for (unsigned int i = 0; i < count; i++) {
            _data[i] = value;
        }
    }

    Vector(const Vector& other):_capacity(other._size), _size(other._capacity) {
        _data = new value_type[_capacity];
        for (unsigned int i = 0; i < _size; i++){
            _data[i] = other._data[i];
        }
    }

    Vector(Vector &&other) noexcept :_size(other._size), _capacity( other._capacity), _data(other._data) {
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }

    ~Vector() {
        delete[] _data;
    }

    Vector<T>& operator=(const Vector& other) { 
        Vector a(other);
        this->swap(a);
        return *this;
    }

    Vector<T>& operator=(Vector&& other) noexcept {
        if (&other != this) {
                delete[] _data;
        }
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }

    reference operator[](size_type pos) noexcept {
        return _data[pos];
    }

    const_reference operator[](size_type pos) const noexcept {
        return _data[pos];
    }

    reference at(size_type pos) {
        if (pos >= _size) {
            throw std::out_of_range("positon >= size of vector");
        }
        return _data[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= _size) {
            throw std::out_of_range("positon >= size of vector");
        }
        return _data[pos];
    }

    reference front() noexcept {
        return _data[0];
    }

    const_reference front() const noexcept {
        return _data[0];
    }

    reference back() noexcept {
        return _data[_size - 1];
    }

    const_reference back() const noexcept {
        return _data[_size - 1];
    }

    pointer data() noexcept {
        return _data;
    }

    const_pointer data() const noexcept {
        return _data;
    }

    bool empty() const noexcept {
        if (_size == 0) {
            return true;
        }
        return false;
    }

    std::size_t size() const noexcept {
        return _size;
    }

    std::size_t capacity() const noexcept {
        return _capacity;
    }

    void clear() {
        _size = 0;
    }

    void push_back(const value_type& value){
        if (_capacity > _size) {
            _data[_size] = value;
            _size++;
        }
        else if (_size == 0) {
            Vector <T> b(1, value); 
            this->swap(b);
        }
        else {
            size_type n = _size;
            Vector <T> b(n * 2); 
            for (unsigned int i = 0; i < n; i++){
                b._data[i] = _data[i];
            }
            b [n] = value;
            this->swap(b);
            _size = n + 1;
        }
    }

    void swap(Vector& other) {
        std::swap(_data, other._data);
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
    }

private:
    value_type* _data;
    size_type _size;
    size_type _capacity;
};
#endif //VECTOR_MY	