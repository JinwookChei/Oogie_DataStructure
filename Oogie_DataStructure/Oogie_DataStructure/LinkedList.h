#pragma once
#include <iostream>

class LinkedList;
class HashTable;

struct LINK_NODE
{
	LINK_NODE* prev_  = nullptr;
	LINK_NODE* next_ = nullptr;
	void* pItem_ = nullptr;

private:
	friend class HashTable;
	friend class LinkedList;
	
	LinkedList* pOwner_ = nullptr;
};


class LinkedList
{
public:
	friend class HashTableIterator;
	friend class HashTable;
	LinkedList()
		: count_(0)
		, pHead_(nullptr)
		, pTail_(nullptr)
	{

	}
	~LinkedList()
	{
		//Clean();
	}

	void PushFront(LINK_NODE* pNode)
	{
		if (nullptr == pNode)
		{
			return;
		}

		if (nullptr != pNode->pOwner_)
		{
			__debugbreak();
			return;
		}

		if (nullptr == pHead_)
		{
			pHead_ = pTail_ = pNode;
		}
		else
		{
			pNode->next_ = pHead_;
			pHead_->prev_ = pNode;
			pHead_ = pNode;
			pHead_->prev_ = nullptr;
		}

		pNode->pOwner_ = this;
		++count_;
	}

	void PushBack(LINK_NODE* pNode)
	{
		if (nullptr == pNode)
		{
			return;
		}

		if (nullptr != pNode->pOwner_)
		{
			__debugbreak();
			return;
		}

		if (nullptr == pTail_)
		{
			pHead_ = pTail_ = pNode;
		}
		else
		{
			pNode->prev_ = pTail_;
			pTail_->next_ = pNode;
			pTail_ = pNode;
			pTail_->next_ = nullptr;
		}

		pNode->pOwner_ = this;
		++count_;
	}

	bool Search(void** ppOutItem, void* pItem)
	{
		LINK_NODE* pIter = pHead_;
		while (pIter)
		{
			if (pIter->pItem_ == pItem)
			{
				*ppOutItem = pIter->pItem_;
				return true;
			}
			pIter = pIter->next_;
		}

		return false;
	}

	void Remove(LINK_NODE* pNode)
	{
		if (nullptr == pNode)
		{
			__debugbreak();
			return;
		}
		if (pNode->pOwner_ != this)
		{
			__debugbreak();
			return;
		}

		if (pHead_ == pNode && pTail_ == pNode)
		{
			pNode->next_ = nullptr;
			pNode->prev_ = nullptr;
			pHead_ = nullptr;
			pTail_ = nullptr;
		}
		else if (pNode == pHead_)
		{
			pHead_ = pNode->next_;
			pNode->next_ = nullptr;
			pHead_->prev_ = nullptr;			
		}
		else if (pNode == pTail_)
		{
			pTail_ = pNode->prev_;
			pNode->prev_ = nullptr;
			pTail_->next_ = nullptr;
		}
		else
		{
			pNode->prev_->next_ = pNode->next_;
			pNode->next_->prev_ = pNode->prev_;
			pNode->prev_ = nullptr;
			pNode->next_ = nullptr;
		}

		pNode->pOwner_ = nullptr;
		--count_;
	}

	void Clean()
	{
		while (pHead_)
		{
			Remove(pHead_);
		}
	}

	void Print()
	{
		LINK_NODE* pCurNode = pHead_;
		while (pCurNode)
		{
			std::cout << *(int*)pCurNode->pItem_ << '\n';
			pCurNode = pCurNode->next_;
		}
	}

private:
	unsigned int count_;

	LINK_NODE* pHead_;

	LINK_NODE* pTail_;
};


