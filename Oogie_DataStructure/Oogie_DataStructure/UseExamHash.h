#pragma once
#include "HashTable.h"

class Key
{
public:
	Key(float key1, float key2)
		: key1_(key1)
		, key2_(key2)
	{
	}

	~Key()
	{
	}

	float key1_;
	float key2_;
};


void UseExamHash()
{
	// Test HashTable
	int* value1 = new int(10);
	int* value2 = new int(20);
	int* value3 = new int(30);
	int* value4 = new int(40);
	int* value5 = new int(50);

	Key* key1 = new Key(10, 10);
	Key* key2 = new Key(20, 20);
	Key* key3 = new Key(30, 30);
	Key* key4 = new Key(40, 40);
	Key* key5 = new Key(50, 50);

	HashTable table(16, 16);
	void* hashHandle1 = table.Insert(value1, key1, sizeof(Key));
	void* hashHandle11 = table.Insert(value2, key1, sizeof(Key));
	void* hashHandle2 = table.Insert(value2, key2, sizeof(Key));
	void* hashHandle3 = table.Insert(value3, key3, sizeof(Key));
	void* hashHandle4 = table.Insert(value4, key4, sizeof(Key));
	void* hashHandle5 = table.Insert(value5, key5, sizeof(Key));

	// Print()
	table.DebugPrint();
	std::cout << '\n' << '\n';

	// Search()
	/*int* searchList[8];
	int searchedCount;
	if (false == table.Search((void**)&searchList, &searchedCount, 8, key1, sizeof(Key)))
	{
		__debugbreak();
	}
	for (int i = 0; i < searchedCount; ++i)
	{
		std::cout << *searchList[i] << '\n';
	}
	std::cout << '\n' << '\n';*/


	// Delete()
	table.Delete(key1, sizeof(Key));
	table.Delete(key2, sizeof(Key));
	table.Delete(key3, sizeof(Key));
	table.Delete(key4, sizeof(Key));
	table.Delete(key5, sizeof(Key));
	table.DebugPrint();

	/*table.Delete(&hashHandle1);
	table.Delete(&hashHandle11);
	table.Delete(&hashHandle2);
	table.Delete(&hashHandle3);
	table.Delete(&hashHandle4);
	table.Delete(&hashHandle5);
	table.DebugPrint();*/

	// Clear()
	//table.Clear();
	//table.DebugPrint();


	delete value1;
	value1 = nullptr;
	delete value2;
	value2 = nullptr;
	delete value3;
	value3 = nullptr;
	delete value4;
	value4 = nullptr;
	delete value5;
	value5 = nullptr;

	delete key1;
	key1 = nullptr;
	delete key2;
	key2 = nullptr;
	delete key3;
	key3 = nullptr;
	delete key4;
	key4 = nullptr;
	delete key5;
	key5 = nullptr;
}
