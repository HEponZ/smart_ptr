#pragma once
#include "Header.h"

template<class T>
class my_unique_ptr
{
private:
	T* ptr;
public:
	my_unique_ptr() noexcept : my_unique_ptr(nullptr) {}
	my_unique_ptr(T* ptr_S) noexcept : ptr{ ptr_S } {}
	//”дален конструктор копировани€, что бы нельз€ было создать 2 указател€ на одно место
	my_unique_ptr(const my_unique_ptr& unique_ptr) = delete; 
	my_unique_ptr(my_unique_ptr&& my_unique_ptr) noexcept : ptr{ my_unique_ptr.ptr } { my_unique_ptr.ptr = nullptr; }
	//”далена перегрузка =, что бы нельз€ было создать 2 указател€ на одно место
	my_unique_ptr& operator=(const my_unique_ptr& unique_ptr) = delete;

	//Ёто оператор разыменовани€, чтобы получить данные по адресу
	T& operator*()const noexcept { return *ptr; }
	T& operator->()const noexcept  { return ptr; }

	//ћетод дл€ получени€ обьекта из указател€
	T& get_obj()const noexcept { return *ptr; }
	//ћетод дл€ обнулени€ указател€
	T& del_obj()noexcept;
	//ћетод который замен€ет обькт на который указывает указатель
	void replace(T* new_ptr)noexcept;

	~my_unique_ptr() { delete ptr; }
};