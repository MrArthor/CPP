#include <iostream>
using namespace std;
 
// A generic smart pointer class
template <class T>
class SmartPtr {
    T* ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = NULL) { ptr = p; }
};
 
int main()
{
    SmartPtr<int> ptr(new int());
   
    return 0;
}
