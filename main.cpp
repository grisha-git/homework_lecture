#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
BiList< T >* newHead(BiList< T >* head, const T& target)
{
  BiList< T >* newNode = new BiList< T >{target, head->next, head->prev};
  head->next->prev = newNode;
  head->prev->next = newNode;
  delete head;
  return newNode;
}

template< class T >
BiList< T >* addAfter(BiList< T >* head, const T& target)
{
  BiList< T >* newNode = new BiList< T >{target, head->next, head};
  head->next = newNode;
  newNode->next->prev = newNode;
  return newNode;
}