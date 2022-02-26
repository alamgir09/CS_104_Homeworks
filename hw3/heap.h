#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator c;

};

// Add implementation of member functions here
template<typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  this->m = m;
  this->c = c;
}

template<typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{


}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(data.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(data.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }
  // TO BE COMPLETED - Referenced from my own Lab 6
  std::swap(data[0], data[data.size()-1]);
  data.pop_back();
  unsigned int i = 0;
  unsigned int important = 0; //Value that takes precedence over others
  while (((this->m)*i)+1 < data.size())
  {
    important = ((this->m)*i)+1;
    //Checks and assigns most important child's index to important
    for (int children = 1; children < (this->m); children++)
    {
      if ((((this->m)*i)+1+children) < data.size())
      {
        if ((!this->c(data[important], data[(((this->m)*i)+1+children)])))
        {
          important = (((this->m)*i)+1+children);
        }
      }
    }
    if (!this->c(data[i], data[important]))
    {
      std::swap(data[i], data[important]);
    }
    i = important;
  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  // TO BE COMPLETED - Referenced from my Lab 6
  data.push_back(item);
  std::size_t index = data.size()-1;
  while (index != 0)
  {
    std::size_t parent_index = (index - 1) / this->m;
    T& current = data[index];
    T& parent = data[parent_index];
    if (!(this->c(current, parent)))
    {
      break;
    }
    std::swap(current, parent);
    index = parent_index;
  }


}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data.size() == 0;
}



#endif

