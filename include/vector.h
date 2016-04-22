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
        _inform = 0;
    }

    explicit Vector(size_type count):_capacity(count),_size(count) {
        _inform = new value_type[count];
        for (unsigned int i = 0; i < count; i++) {
            _inform[i] = 0;
        }
    }

    Vector(size_type count, const value_type& value):_capacity(count),_size(count) {
        _inform = new value_type[count];
        for (unsigned int i = 0; i < count; i++) {
            _inform[i] = value;
        }
    }

    Vector(const Vector& other):_capacity(other._size),_size(other._capacity) {
        _inform = new value_type[_capacity];
        for (unsigned int i = 0; i < _size; i++){
            _inform[i] = other._inform[i];
        }
    }

    Vector(Vector &&other) noexcept :_size(other._size), _capacity( other._capacity), _inform(other._inform) {
        other._size = 0;
        other._capacity = 0;
        other._inform = nullptr;
    }

    ~Vector() {
        delete[] _inform;
    }

    Vector<T>& operator=(const Vector& other) { 
        Vector  a(other);
        this->swap(a);
        return *this;
    }

    Vector<T>& operator=(Vector&& other) noexcept {
        if (&other != this) {
                delete[] _inform;
        }
        _size = other._size;
        _capacity = other._capacity;
        _inform = other._inform;
        other._size = 0;
        other._capacity = 0;
        other._inform = nullptr;
    }

    reference operator[](size_type pos) noexcept {
        return _inform[pos];
    }

    const_reference operator[](size_type pos) const noexcept {
        return _inform[pos];
    }

    reference at(size_type pos) {
        if (pos >= _size) {
            throw std::out_of_range("positon >= size of vector");
        }
        return _inform[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= _size) {
            throw std::out_of_range("positon >= size of vector");
        }
        return _inform[pos];
    }

    reference front() noexcept {
        return _inform[0];
    }

    const_reference front() const noexcept {
        return _inform[0];
    }

    reference back() noexcept {
        return _inform[_size - 1];
    }

    const_reference back() const noexcept {
        return _inform[_size - 1];
    }

    pointer data() noexcept {
        return _inform;
    }

    const_pointer data() const noexcept {
        return _inform;
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
        size_type n;
        if (_capacity > _size) {
            _inform[_size] = value;
            _size++;
        }
        else {
            if (_size == 0) {
                Vector b(1, value); 
            }  
            else {
                n = _size;    
                Vector b(n * 2); 
                for (unsigned int i = 0; i < n; i++) {
                    b._inform[i] = _inform[i];
                }
                b[n] = value;
                _size= n + 1;
            }
            this->swap(b);    
        }
    }

    void swap(Vector& other) {
        std::swap(_inform, other._inform);
        std::swap(_capacity,other._capacity);
        std::swap(_size, other._size);
    }

private:
    value_type* _inform;
    size_type _size;
    size_type _capacity;
};
#endif //VECTOR_MY	