#include "unique_ptr.h"
#include "shared_ptr.h"
#include "shared_ptr.cpp"
#include "unique_ptr.cpp"

int main()
{
	setlocale(LC_ALL, "rus");
	int mas[3]{ 1,2,3 };
	my_unique_ptr<int> ptr_test{ new int(mas[0]) };
	my_shared_ptr<int> ptr_test2{ new int(mas[2]) };
	my_shared_ptr<int> ptr_test3(ptr_test2);

	cout << "”мный указатель: " << *ptr_test << "\n”казатель, со счетчиком: " << *ptr_test2 << "\n—четчик: " << ptr_test3.get_count();

	return 0;
}