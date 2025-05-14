

template <typename T>
counted_ptr<T>::counted_ptr()
    :   data{ nullptr }, count{ new int{0} }
{}

template <typename T>
counted_ptr<T>::counted_ptr(T* ptr)
    :   data{ ptr }, count{ new int{1}  }
{}

template <typename T>
counted_ptr<T>::counted_ptr(counted_ptr const& other)
    :   data{ other.data }, count{ other.count }
{
    (*count)++;
}

template <typename T>
counted_ptr<T>::counted_ptr(counted_ptr && other)
    :   data{other.data}, count{other.count}
{
    other.data = nullptr;
    other.count = nullptr;
}

template <typename T>
counted_ptr<T>::~counted_ptr()
{
    if (count) 
    {
        (*count)--;
        if (*count == 0)
        {
            delete data;
            delete count;
        }
    }
}

template <typename T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr const& rhs)
{   
    if (this != &rhs && count)  // skydda mot självtilldelning!
    {
        (*count)--;
        if (*count == 0)
        {
            delete data;
            delete count;
        }
        data = rhs.data;
        count = rhs.count;
        (*count)++; 
    }
    return *this;
}

template <typename T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr && rhs)
{
    if (count)
    {
        (*count)--;
        if (*count <= 0)
        {
            delete data;
            delete count;
        }
    }

    data = rhs.data;
    count = rhs.count;
    rhs.data = nullptr;
    rhs.count = nullptr;
    return *this;
}

template <typename T>
counted_ptr<T>& counted_ptr<T>::operator=(std::nullptr_t)
{
   // TODO: FiX!!!!
}


template <typename T>
T&   counted_ptr<T>::operator* () const
{
    return *data;
}

template <typename T>
T*   counted_ptr<T>::operator->() const
{
    return data;
}


template <typename T>
bool counted_ptr<T>::operator==(counted_ptr const& rhs) const
{
    return data == rhs.data;
}

template <typename T>
bool counted_ptr<T>::operator!=(counted_ptr const& rhs) const
{
    return data != rhs.data;
}

template <typename T>
bool counted_ptr<T>::operator==(T* const& rhs) const
{
    return data == rhs;
}

template <typename T>
bool counted_ptr<T>::operator!=(T* const& rhs) const
{
    return data != rhs;
}


template <typename T>
int counted_ptr<T>::use_count() const
{
    return *count;
}

template <typename T>
T* counted_ptr<T>::get() const
{
    return data;
}