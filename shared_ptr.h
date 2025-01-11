#pragma once
#include "Header.h"

template<class T>
class my_shared_ptr
{
private:
	T* ptr;
	int count; //Счетчик указателей
public:
	my_shared_ptr()noexcept : my_shared_ptr(nullptr) {}
	my_shared_ptr(T* ptr_S)noexcept : ptr{ ptr_S }, count{ 1 } {}
	//Если инициализируем один указатель другим, то счетчик увеличивается
	my_shared_ptr(const my_shared_ptr& shared_ptr) noexcept : ptr{ shared_ptr.ptr }, count{ shared_ptr.count } { count++; }
	
	//Это оператор разыменования, чтобы получить данные по адресу
	T& operator*()const noexcept  { return *ptr; }
	T& operator->()const noexcept  { return ptr; }

	//Метод для получения счетчика
	int get_count()const noexcept  { return count; }
	//Метод для получения обьекта из указателя
	T& get_obj()const noexcept  { return *ptr; }
	//Метод для обнуления указателя
	T& del_obj()noexcept;
	//Метод который заменяет обькт на который указывает указатель
	void replace(T* new_ptr)noexcept;

	~my_shared_ptr();
};

