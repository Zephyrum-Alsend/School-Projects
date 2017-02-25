#pragma once
#include <iostream>


class Problem1
{
public:
	Problem1(){
		head = NULL;
	}
	~Problem1(){
		MakeEmpty();
	}
	struct Node{
		int value;
		Node *next;
	};
	void push(int x){
		Node *tmp = new Node;
		tmp->value = x;
		tmp->next = head;
		head = tmp;
		return;
	}

	int pop(){
		if (isEmpty()){
			return -9999999;
		}
		int temp = head->value;
		Node *tmp = head->next;
		delete head;
		head = tmp;
		return temp;
	}

	bool isEmpty(){
		return head == NULL;
	}

	void MakeEmpty(){
		Node *cnode = head;
		Node *nnode = NULL;
		
		for (; cnode != NULL; cnode = nnode) {
			nnode = cnode->next;
			delete cnode;
		}
		head = NULL;
	}

private:
	Node *head;
	Node *tail;
};

