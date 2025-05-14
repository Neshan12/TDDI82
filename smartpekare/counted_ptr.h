#pragma once

#include <algorithm>
#include <iterator>

template <typename T>
class counted_ptr
{
public:
    counted_ptr();
    counted_ptr(T* ptr);
    counted_ptr(counted_ptr const& other); // Kopieringskonstruktor
    counted_ptr(counted_ptr &&     other); // Flyttkonstruktor
    ~counted_ptr();
    counted_ptr& operator=(counted_ptr const& rhs); // Kopieringsoperator
    counted_ptr& operator=(counted_ptr &&     rhs); // Flyttoperator
    counted_ptr& operator=(std::nullptr_t);
    
    T&   operator* () const;
    T*   operator->() const;
    bool operator==(counted_ptr const& rhs) const;
    bool operator!=(counted_ptr const& rhs) const;
    bool operator==(T* const& rhs) const;
    bool operator!=(T* const& rhs) const;


    int  use_count() const;
    T*   get() const;

private:
    T* data{};  
    int* count{};
};

#include "counted_ptr.tcc"
