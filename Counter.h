#include <mutex>
#include <atomic>

class Counter
{
  public:
    Counter();
    Counter(int _count);
    
    void increment();
    void decrement();

    int getCount();
    void setCount(int _count);

    void printCount();
  private:
    std::atomic<int> count;
    std::mutex mx;
};