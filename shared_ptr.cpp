#include "shared_ptr.h"

template <class T>
T& my_shared_ptr<T>::del_obj()noexcept
{
	T& obj = *ptr;
	ptr = nullptr;
	return obj;
}

template <class T>
void my_shared_ptr<T>::replace(T* new_ptr)noexcept
{
	if (ptr)
	{
		delete ptr;
	}
	ptr = new_ptr;
}

template <class T>
my_shared_ptr<T>::~my_shared_ptr()
{
	count--;
	if (count == 0)
	{
		delete ptr;
	}
}