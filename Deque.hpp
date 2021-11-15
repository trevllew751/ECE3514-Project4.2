#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "abstract_deque.hpp"

#define INITIAL_CAPACITY 64

template <typename T>
class Deque: public AbstractDeque<T>
{
private:
    std::size_t frontIndex;
    std::size_t rearIndex;
    std::size_t size;
    std::size_t capacity;
    T* items;

    /**
     * Resizes the items array to capacity * 2 + 1
     */
    void resize();

    /**
     * Swaps the items of each Deque
     * @param lhs left Deque
     * @param rhs right Deque
     */
    void swap(Deque &lhs, Deque&rhs);
 
public:
  /** Deque constructor */
  Deque();

  /** Copy Constructor */ 
  Deque(const Deque& other );
  
  /** Copy assignment operator */
  Deque& operator=(Deque rhs);
  
  /** Stack destructor. Must delete any allocated memory. */
  virtual ~Deque();

  /** Returns true if the deque is empty, else false
   */
  bool isEmpty() const noexcept;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  void pushFront(const T & item);

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popFront();

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  T front() const;

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  void pushBack(const T & item);

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popBack();

  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  T back() const;

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Deque<U>& d);
};

#include "Deque.txx"

#endif
