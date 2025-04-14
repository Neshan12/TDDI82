#include <memory>

template <typename T>
counted_ptr()
    :   data{ new std::shared_ptr<nullptr>{} }, counter{ new int{0} }
{}

template <typename T>
counted_ptr(T* ptr)
    :   data{ new std::shared_ptr<T>{*T} }, counter{ std::use_count(data) }
{}
