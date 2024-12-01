#pragma once
#include <iostream>
#include <stdexcept>
#include <deque>

template <typename T>
class Stack
{
	std::deque<T> data;
public:
	Stack() 
	{
	}

	void push(const T& val)
	{
		data.push_back(val);
	}

	void pop()
	{
		if (empty()) throw "stack is empty";
		data.pop_back();
	}

    T peek() const
	{
		if (!empty()) return data.back();
		throw "stack is empty";
	}

	size_t get_size() const
	{
		return data.size();
	}

	bool empty() const
	{
		return data.empty();
	}

	void clear()
	{
		data.clear();
	}
};


