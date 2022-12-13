#pragma once

template <typename T>
class ListIterator;

template<typename T>
class SLL
{
public:
	struct Node
	{
		T data;
		Node* next;
	};

private:

	Node* first;

	void copy(const SLL<T>& other)
	{
		if (other->first == nullptr)
			return;

		first = new Node{ other.first->data, nullptr };

		Node* current = other.first->next;
		Node* save = first;

		while (current != nullptr)
		{
			first->next = new Node{ current->data, nullptr };
			first = first->next;
			current = current->next;
		}

		first = save;
	}
	void erase()
	{
		while (first != nullptr)
		{
			Node* temp = first->next;
			delete first;
			first = temp;
		}
	}
public:
	using value_type = T;
	using iterator = ListIterator<T>;

	SLL() : first(nullptr)
	{
	}
	SLL(const SLL<T>& other)
	{
		copy(other);
	}
	SLL& operator=(const SLL<T>& other)
	{
		if (this != &other)
		{
			erase();
			copy(other);
		}
		return *this;
	}
	~SLL()
	{
		erase();
	}

	void push(const T& elem)
	{
		first = new Node{ elem, first };
	}

	ListIterator<T> begin() const
	{
		return ListIterator<T>(first);
	}
	ListIterator<T> end() const
	{
		return ListIterator<T>(nullptr);
	}


	T& operator[](size_t index)
	{
		Node* curr = first;
		for (size_t count = 0; count < index; count++)
		{
			if (curr == nullptr)
				throw "Out of bounds.";
			curr = curr->next;
		}
		return curr->data;
	}
	T operator[](size_t index) const
	{
		Node* curr = first;
		for (size_t count = 0; count < index; count++)
		{
			if (curr == nullptr)
				throw "Out of bounds.";
			curr = curr->next;
		}
		return curr->data;
	}
};


template <typename T>
class ListIterator
{

public:

	ListIterator(typename SLL<T>::Node* first)
	{
		current = first;
	}

	T operator*()
	{
		if (current == nullptr)
		{
			throw "Iterator out of range.";
		}
		return current->data;
	}
	ListIterator<T>& operator++()
	{
		if (current == nullptr)
		{
			throw std::out_of_range("Iterator out of range.");
		}
		current = current->next;
		return *this;
	}
	bool operator!=(const ListIterator<T>& other) const
	{
		return current != other.current;
	}

private:
	typename SLL<T>::Node* current;
};