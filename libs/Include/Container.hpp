#pragma once

#include <memory>
#include <assert.h>

template<class T> class Container
{
public:
	/**
	*	@brief Pure virtual blueprints for a custom container with common elements.
	*/
	Container() = default;

#pragma region Overrided Functions
	/**
	*	@brief Push element to back of container.
	*/
	virtual void PushBack(T a_item) = 0;

	/**
	*	@brief Remove element from back of container.
	*/
	virtual void PopBack() = 0;

#pragma endregion

	/**
	*	@brief Get number of elements in container.
	*	@param Returns an integer to avoid type mismatch.
	*/
	int		GetSize() { return (int)m_size; }

	/**
	*	@brief Are there any elements in the container?
	*/
	bool	IsEmpty() { return m_size == 0; }

	/**
	*	@brief	Return alias of element at the top of the container (relative).
	*/
	T& Top() { return m_data[m_top]; }

	/**
	*	@brief	Holds a pointer to a value and can point to the next value contiguously.
	*/
	struct Iterator {
		Iterator(T* a_ptr) : m_ptr(a_ptr) {}

		T*		m_ptr;

		void operator++() {
			m_ptr += sizeof(T);
		}
	};

protected:
	size_t		m_size = 0;		/* Amount of elements in container, always none by default*/
	size_t		m_top = 0;		/* Index of the top of the container (relative), 0 by default*/
};
