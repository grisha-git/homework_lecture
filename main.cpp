#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

//Task 2
template< class T >
BiList< T >* newHead(BiList< T >* head, const T& target);

template< class T >
BiList< T >* addAfter(BiList< T >* head, const T& target);

template< class T >
BiList< T >* deleteHead(BiList< T >* head) noexcept;

template< class T >
BiList< T >* deleteAfter(BiList< T >* head) noexcept;

template< class T >
BiList< T >* clear(BiList< T >* h, BiList< T >* e) noexcept;

template< class T, class F >
F traverse(F f, BiList< T >* h, BiList< T >* e);

template< class T, class F >
F reverseTraverse(F f, BiList< T >* h, BiList< T >* e);

template< class T >
BiList< T >* create(const T* array, size_t s);

//Task 3

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

template< class T >
BiList< T >* create(const T* array, size_t s)
{
  if (s == 0)
  {
    return nullptr;
  }
  BiList< T >* head = new BiList< T >{array[0], nullptr, nullptr};
  head->next = head;
  head->prev = head;
  BiList< T >* it = head;
  for (size_t i = 1; i < s; ++i)
  {
    BiList< T >* temp = new BiList< T >{array[i], head, it};
    it->next = temp;
    it = temp;
  }
  return head;
}

//Task 4
template< class T >
T* convert(BiList< T >* list, size_t& size)
{
  BiList< T >* saveList = list;
  T* array - new T [size];
  size_t i = 0;
  do
  {
    array[i++] = list->val;
    list = list->next;
  } while(list != saveList)
  return array;
}

int main()
{
  int* arr = new int[5]{1, 2, 3, 4, 5};
  size_t size = 5;
  BiList< int >* list = create(arr, size);
  size_t converted = 0;
  int* convertList = nullptr;
  try{
    convertList = convert(list, size);
  }
  catch(...)
  {
    delete [] convertList;
  }
  delete [] convertList;
}

//Task 1
//Конструктор по умолчанию
//Деструктор
//ККонструктор копирующего присваивания