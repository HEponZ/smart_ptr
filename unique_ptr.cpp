#include "unique_ptr.h"

template<class T>
T& my_unique_ptr<T>::del_obj()noexcept
{
	T& obj = *ptr;
	ptr = nullptr;
	return obj;
}

template<class T>
void my_unique_ptr<T>::replace(T* new_ptr)noexcept
{
	if (ptr)
	{
		delete ptr;
	}
	ptr = new_ptr;
}