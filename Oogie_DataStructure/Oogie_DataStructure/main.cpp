#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

class Key
{
public:
	Key()
	{

	}

	~Key()
	{

	}
	float key_;
};

int main()
{
	// LinkedList Test
	//LinkedList list;

	//LINK_NODE* pNode1 = new LINK_NODE;
	//pNode1->pItem_ = new int(10);
	//pNode1->next_ = nullptr;
	//pNode1->prev_ = nullptr;

	//LINK_NODE* pNode2 = new LINK_NODE;
	//pNode2->pItem_ = new int(20);
	//pNode2->next_ = nullptr;
	//pNode2->prev_ = nullptr;

	//LINK_NODE* pNode3 = new LINK_NODE;
	//pNode3->pItem_ = new int(30);
	//pNode3->next_ = nullptr;
	//pNode3->prev_ = nullptr;

	//LINK_NODE* pNode4 = new LINK_NODE;
	//pNode4->pItem_ = new int(40);
	//pNode4->next_ = nullptr;
	//pNode4->prev_ = nullptr;

	//list.PushFront(pNode1);
	//list.PushBack(pNode2);
	//list.PushFront(pNode3);
	//list.PushBack(pNode4);
	//list.Print();
	//std::cout << '\n' << '\n';
	//
	//list.Clean();
	////list.Remove(pNode1);
	////list.Remove(pNode2);
	//list.Print();

	//
	//delete pNode4->pItem_; 
	//delete pNode3->pItem_;
	//delete pNode2->pItem_;
	//delete pNode1->pItem_;

	//delete pNode4;
	//delete pNode3;
	//delete pNode2;
	//delete pNode1;

	int* value1 = new int(10);
	int* value2 = new int(20);
	int* value3 = new int(30);
	int* value4 = new int(40);
	int* value5 = new int(50);

	float key1 = 1;
	float key2 = 2;
	float key3 = 3;
	float key4 = 4;
	float key5 = 5;

	HashTable table(16, 16);
	table.Insert(value1, &key1, sizeof(float));
	table.Insert(value1, &key2, sizeof(float));
	table.Insert(value2, &key1, sizeof(float));
	table.Insert(value3, &key1, sizeof(float));
	table.Insert(value4, &key1, sizeof(float));
	table.Insert(value5, &key5, sizeof(float));

	table.DebugPrint();

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

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}