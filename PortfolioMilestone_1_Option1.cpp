#include <thread>
#include <iostream>
#include "Counter.h"

using namespace std;

/**
 * Increment counter to max value
 * 
 * @param counter Counter pointer   reference to counter
 * @param max int                   count ceiling
 */
void incrementTask(Counter *counter, int max)
{
  // while count is less than ceiling value
  do
  {
    // increment counter
    counter->increment();
    // print count value
    counter->printCount();
  } while (counter->getCount() < max);
  
  // print final count value
  counter->printCount();
}

/**
 * Decrement counter to min value
 * 
 * @param counter Counter pointer   reference to counter
 * @param max int                   count floor
 */
void decrementTask(Counter *counter, int min)
{
  do
  {
    counter->decrement();
    counter->printCount();
  } while (counter->getCount() > min);
}

int main()
{
  const int MAX = 20; // set const for max count number
  const int MIN = 0; // set const for min count number
  Counter counter; // initializes counter at 0

  // initialize first thread with increment callback fn
  // and dereference counter
  thread incrementThread(incrementTask, &counter, MAX);

  // initialize first thread with decrement callback fn
  // and dereference counter
  thread decrementThread(decrementTask, &counter, MIN);
  
  // terminate threads
  incrementThread.join();
  decrementThread.join();

  // exit program
  return 0;
}