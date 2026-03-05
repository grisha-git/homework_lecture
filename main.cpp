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

template< class T >
BiList< T >* deleteHead(BiList< T >* head) noexcept
{
  BiList< T >* temp = head->next;
  head->prev->next = head->next;
  head->next->prev = head->prev;
  delete head;
  return temp;
}

template< class T >
BiList< T >* deleteAfter(BiList< T >* head) noexcept
{
  BiList< T >* temp = head->next;
  head->next = temp->next;
  temp->next->prev = head;
  delete temp;
  return head;
}

template< class T >
BiList< T >* clear(BiList< T >* h, BiList< T >* e) noexcept
{
  BiList< T >* temp = nullptr;
  do
  {
    temp = h->next;
    h->prev->next = temp;
    temp->prev = h->prev;
    delete h;
    h = temp;
  } while (h != e)
  return h;
}

template< class T, class F >
F traverse(F f, BiList< T >* h, BiList< T >* e)
{
  do
  {
    f(h->val);
    h = h->next;
  } while(h != e)
  return f;
}

template< class T, class F >
F reverseTraverse(F f, BiList< T >* h, BiList< T >* e)
{
  do
  {
    f(h->val);
    h = h->prev;
  } while(h != e)
  return f;
}