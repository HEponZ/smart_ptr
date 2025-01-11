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
	//Если в указателе что-то есть, то очищаем его
	if (ptr)
	{
		delete ptr;
	}
	//приравниваем к новому указателю
	ptr = new_ptr;
}

template <class T>
my_shared_ptr<T>::~my_shared_ptr()
{
	//Уменьшает счетчик
	count--;
	//Если счетчик равен 0, то очищаем указатель
	if (count == 0)
	{
		delete ptr;
	}
}