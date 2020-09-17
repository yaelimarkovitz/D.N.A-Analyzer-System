//
// Created by mby on 07/07/2020.
//

#ifndef SMART_POINTER_SHAREDPOINTER_H
#define SMART_POINTER_SHAREDPOINTER_H

#include <cstddef>
template <typename T>
class SharedPointer {

public:
    explicit SharedPointer(T* ptr = NULL);
    ~SharedPointer();

    T*	operator*();
    T*  operator->();

    T* 			    getPtr() const;
    const size_t * 	getCount() const;
    template <typename U>
    SharedPointer&	operator=(const SharedPointer<U> &other);
    template <typename U>
    SharedPointer	(const SharedPointer<U> &other);
    
    operator 		bool() const;
    bool    		operator==(const SharedPointer& other)const ;
    bool    		operator!=(const SharedPointer& other)const ;

private:
    T* 		m_ptr;
    size_t* 	m_count;
    bool 	isMoreThanOnePinter() const ;
};
template <typename T>
inline SharedPointer<T>::SharedPointer(T *ptr):m_ptr(ptr),m_count(new size_t(1)) 
{
}
template <typename T>
template <typename U>
inline SharedPointer<T>::SharedPointer(const SharedPointer<U> &other):m_ptr(other.getPtr())
								     ,m_count(other.getCount()) 
{
    (*m_count)++;
}

template <typename T>
template <typename U>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<U> &other) 
{
    delete m_ptr;
    m_ptr = other.getPtr();
    (*m_count)--;
    m_count=other.getCount();
    (*m_count)++;
    return *this;
}
template <typename T>
SharedPointer<T>::~SharedPointer<T>() 
{
    if(!isMoreThanOnePinter())
    {
        delete m_ptr;
        delete m_count;
    }
    else{
        (*m_count)--;
    }
}
template <typename T>
bool SharedPointer<T>::isMoreThanOnePinter() const
{
    return ((*m_count)>1);
}
template <typename T>
T* SharedPointer<T>::operator*()
{
    return m_ptr;
}
template <typename T>
bool SharedPointer<T>::operator==(const SharedPointer &other)const 
{
    return m_ptr==other.m_ptr;
}
template <typename T>
bool SharedPointer<T>::operator!=(const SharedPointer &other) const {
    return !(*this==other);
}
template <typename T>
SharedPointer<T>::operator bool() const {
    return m_ptr;
}
template <typename T>
T* SharedPointer<T>::getPtr() const {
    return m_ptr;
}
template <typename T>
const size_t* SharedPointer<T>::getCount() const {
    return m_count;
}
template <typename T>
T* SharedPointer<T>::operator->() {
    return m_ptr;
}
#endif //SMART_POINTER_SHAREDPOINTER_H
