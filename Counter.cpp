#include "Counter.h"
#include <iostream>

using namespace std;

/**
 * initialize count to zero
*/
Counter::Counter() {
  setCount(0);
}

/**
 * Initialize Counter with starting count number
 * 
 * @param _count int  starting count
*/
Counter::Counter(int _count)
{
  setCount(_count);
}

/**
 * Increment count by 1
*/
void Counter::increment()
{
  mx.lock();
  count++;
  mx.unlock();
};

/**
 * Decrement count by 1
 */
void Counter::decrement()
{
  mx.lock();
  count--;
  mx.unlock();
};

/**
 * gets count
 * 
 * @return int  value of count
*/
int Counter::getCount()
{
  return count;
}

/**
 * Initialize Counter with starting count number
 * 
 * @param _count int  count number
*/
void Counter::setCount(int _count)
{
  mx.lock();
  count = _count;
  mx.unlock();
}

/**
 * Print count to stdout
 */
void Counter::printCount()
{
  cout << "Count is: " << count << endl;
}
