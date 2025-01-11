#pragma once
#include "Header.h"

template<class T>
class my_shared_ptr
{
private:
	T* ptr;
	int count;
public:
	my_shared_ptr()noexcept : my_shared_ptr(nullptr) {}
	my_shared_ptr(T* ptr_S)noexcept : ptr{ ptr_S }, count{ 1 } {}
	my_shared_ptr(const my_shared_ptr& shared_ptr) noexcept : ptr{ shared_ptr.ptr }, count{ shared_ptr.count } { count++; }
	
	T& operator*()const noexcept  { return *ptr; }
	T& operator->()const noexcept  { return ptr; }

	int get_count()const noexcept  { return count; }
	T& get_obj()const noexcept  { return *ptr; }
	T& del_obj()noexcept;
	void replace(T* new_ptr)noexcept;

	~my_shared_ptr();
};

