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
	my_unique_ptr(const my_unique_ptr& unique_ptr) = delete;
	my_unique_ptr(my_unique_ptr&& my_unique_ptr) noexcept : ptr{ my_unique_ptr.ptr } { my_unique_ptr.ptr = nullptr; }
	my_unique_ptr& operator=(const my_unique_ptr& unique_ptr) = delete;

	T& operator*()const noexcept { return *ptr; }
	T& operator->()const noexcept  { return ptr; }

	T& get_obj()const noexcept { return *ptr; }
	T& del_obj()noexcept;
	void replace(T* new_ptr)noexcept;

	~my_unique_ptr() { delete ptr; }
};