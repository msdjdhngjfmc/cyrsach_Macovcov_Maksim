#pragma once
#include "List.h"

template<class T>
class outer_list
{
	class Node
	{
	private:
		T data;
		Node* next, * prev;
	public:

		Node(T data) {
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}
		~Node() {
			next = nullptr;
			prev = nullptr;
		}

		Node() : next(nullptr), prev(nullptr) {};

		void set_data(T& data) {
			this->data = data;
		}

		T& get_data() {
			return data;
		}

		Node* get_next() {
			return next;
		}

		Node* get_prev() {
			return prev;
		}

		void set_next(Node* temp) {
			next = temp;
		}

		void set_prev(Node* temp) {
			prev = temp;
		}
	};

	Node* head, * tail;

	Node* get_node(size_t index)
	{
		if (index == get_size() - 1)
			return tail;
		else if (index == 0)
			return head;
		else
		{
			Node* temp = head;
			while ((temp) && (index--))
			{
				temp = temp->get_next();
			}
			return temp;
		}
	}
public:
	outer_list() : head(nullptr), tail(nullptr) {}
	outer_list(const outer_list<T>& list) {
		head = nullptr;
		tail = nullptr;
		Node* temp = list.head;
		while (temp) {
			push_back(temp->get_data());
			temp = temp->get_next();
		}
	}
	~outer_list()
	{
		while (head)
		{
			tail = head->get_next();
			delete head;
			head = tail;
		}
		head = nullptr;
	}

	void set(size_t index, T data)
	{
		Node* temp;
		temp = get_node(index);
		temp->set_data(data);
	}

	void push_back(T& data)
	{
		Node* temp = new Node;
		temp->set_data(data);

		if (head)
		{
			temp->set_prev(tail);
			tail->set_next(temp);
			tail = temp;
		}
		else
		{
			head = temp;
			tail = head;
		}
	}

	void push_front(T data)
	{
		Node* temp = new Node;
		temp->set_data(data);
		if (head)
		{
			temp->set_next(head);
			head->set_prev(temp);
			head = temp;
		}
		else
		{
			head = temp;
			tail = head;
		}
	}

	void push_back(outer_list<bool> scnd_list)
	{
		Node* temp = scnd_list.head;
		size_t size = scnd_list.get_size();
		while ((temp) && (size--))
		{
			push_back(temp->get_data());
			temp = temp->get_next();
		}
	}

	void push_front(outer_list& scnd_list)
	{
		Node* temp = scnd_list.tail;
		size_t n = scnd_list.get_size();
		while ((temp) && (n--))
		{
			push_front(temp->get_data());
			temp = temp->get_prev();
		}
	}

	void insert(size_t index, T data)
	{
		Node* temp;
		temp = get_node(index);
		if (temp == head)
			push_front(data);
		else
		{
			Node* newel = new Node;
			newel->set_data(data);
			temp->get_prev()->set_next(newel);
			newel->set_prev(temp->get_prev());
			newel->set_next(temp);
			temp->set_prev(newel);
		}
	}

	void pop_back()
	{
		if (head != tail)
		{
			Node* temp = tail;
			tail = tail->get_prev();
			tail->set_next(nullptr);
			delete temp;
		}

		else if (!isEmpty())
		{
			Node* temp = tail;
			tail = head = nullptr;
			delete temp;
		}
	}

	void pop_front()
	{
		if (head != tail)
		{
			Node* temp = head;
			head = head->get_next();
			head->set_prev(nullptr);
			delete temp;
		}
		else if (!isEmpty())
		{
			Node* temp = head;
			head = tail = nullptr;
			delete temp;
		}
	}

	void remove(T data) {
		Node* temp = head;
		while (temp && temp->get_data() != data)
			temp = temp->get_next();
		if (temp == head)
			pop_front();
		else if (temp == tail)
			pop_back();
		else
		{
			temp->get_prev()->set_next(temp->get_next());
			temp->get_next()->set_prev(temp->get_prev());
			delete temp;
		}
	}

	T& at(size_t index)
	{
		Node* temp;
		temp = get_node(index);
		return temp->get_data();
	}

	void remove(size_t index)
	{
		Node* temp;
		temp = get_node(index);
		if (temp == head)
			pop_front();
		else if (temp == tail)
			pop_back();
		else
		{
			temp->get_prev()->set_next(temp->get_next());
			temp->get_next()->set_prev(temp->get_prev());
			delete temp;
		}
	}

	size_t get_size()
	{
		Node* temp = head;
		size_t length = 0;
		while (temp)
		{
			length++;
			temp = temp->get_next();
		}
		return length;
	}

	void print_to_console()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->get_data();
			temp = temp->get_next();
		}
	}

	void clear()
	{
		while (head)
		{
			tail = head->get_next();
			delete head;
			head = tail;
		}
	}

	bool isEmpty()
	{
		if (!head)
			return true;
		else
			return false;
	}
	bool compare(List<T>& scnd_lst) {
		if (get_size() != scnd_lst.get_size())
			return false;
		for (int i = 0; i < get_size(); i++) {
			if (at(i) != scnd_lst.at(i))
				return false;
		}
		return true;
	}
	bool contains(List<char>& scnd_lst) {
		Node* temp = head;
		while (temp) {
			if (temp->get_data().compare(scnd_lst))
				return true;
			temp = temp->get_next();
		}
		return false;
	}
};
