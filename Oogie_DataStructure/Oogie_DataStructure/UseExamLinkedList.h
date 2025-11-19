#pragma once
#include "LinkedList.h"

void UseExamLinkedList()
{
	//LinkedList Test
	LinkedList list;

	LINK_NODE* pNode1 = new LINK_NODE;
	pNode1->pItem_ = new int(10);
	pNode1->next_ = nullptr;
	pNode1->prev_ = nullptr;

	LINK_NODE* pNode2 = new LINK_NODE;
	pNode2->pItem_ = new int(20);
	pNode2->next_ = nullptr;
	pNode2->prev_ = nullptr;

	LINK_NODE* pNode3 = new LINK_NODE;
	pNode3->pItem_ = new int(30);
	pNode3->next_ = nullptr;
	pNode3->prev_ = nullptr;

	LINK_NODE* pNode4 = new LINK_NODE;
	pNode4->pItem_ = new int(40);
	pNode4->next_ = nullptr;
	pNode4->prev_ = nullptr;

	list.PushFront(pNode1);
	list.PushBack(pNode2);
	list.PushFront(pNode3);
	list.PushBack(pNode4);
	list.Print();
	std::cout << '\n' << '\n';
	
	list.Clean();
	//list.Remove(pNode1);
	//list.Remove(pNode2);
	list.Print();

	
	delete pNode4->pItem_; 
	delete pNode3->pItem_;
	delete pNode2->pItem_;
	delete pNode1->pItem_;

	delete pNode4;
	delete pNode3;
	delete pNode2;
	delete pNode1;
}
