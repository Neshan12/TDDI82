#ifndef COUNTED_PTR_H
#define COUNTED_PTR_H

#include <memory>

template <typename T>
class counted_ptr
{
public:
    counted_ptr();
    counted_ptr(T* ptr);
    counted_ptr(counted_ptr const& other); // Kopieringskonstruktor
    counted_ptr(counted_ptr &&     other); // Flyttkonstruktor
    ~counted_ptr() = default;
    counted_ptr& operator=(counted_ptr const& rhs); // Kopieringsoperator
    counted_ptr& operator=(counted_ptr &&     rhs); // Flyttoperator
    
    T&   operator* ();
    T*   operator->();
    bool operator==(counted_ptr const& rhs);
    bool operator!=(counted_ptr const& rhs);

    int  use_count() const;
    T*   get() const;

private:
    std::shared_ptr<T> data{};
    int* counter{};
};

#include "counted_ptr.tcc"

#endif
