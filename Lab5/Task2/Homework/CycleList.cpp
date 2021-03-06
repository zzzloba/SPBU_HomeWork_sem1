#include "CycleList.hpp"
#include "stdafx.hpp"

void printCycleList(const CycleList &list)
{
	if (list.length == 0)
	{
		printf("������ ������!\n");
	}
	else
	{
		ListElement *currentElement = list.head;
		for (int i = 0; i < list.length; ++i)
		{
			printf("%d", currentElement->data);
			currentElement = currentElement->next;
		}
		printf("\n");
	}
}

void addElement(int data, CycleList &list)
{
	if (list.length == 0)
	{
		list.head = newElement(data, nullptr);
		list.head->next = list.head;
		list.tail = list.head;
		++list.length;
		return;
	}
	else
	{
		list.tail->next = newElement(data, list.tail->next);
		list.tail = list.tail->next;
		++list.length;
	}
}

void kill(int pos, CycleList &list)
{
	ListElement* listElement = list.tail;
	while (listElement->next != listElement)
	{
		for (int i = 1; i < pos; ++i)
		{
			listElement = listElement->next;
		}
		ListElement* tmpListElement = listElement->next;
		listElement->next = tmpListElement->next;
		--list.length;
		delete tmpListElement;
	}
	list.head = listElement;
	list.tail = listElement;
}

ListElement *newElement(int data, ListElement *next)
{
	ListElement *result = new ListElement;
	result->data = data;
	result->next = next;
	return result;
}

void deleteList(CycleList &list)
{
	list.tail->next = nullptr;
	while (list.head != nullptr)
	{
		ListElement *element = list.head;
		list.head = list.head->next;
		delete element;
	}
	list.tail = nullptr;
	list.head = nullptr;
}
