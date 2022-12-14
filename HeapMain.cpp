#include <iostream>

#include "Heap.h"

int main()
{
    Heap<int> h(Max);
    h.insert(7);
    h.insert(5);
    h.insert(10);
    h.insert(14);
    h.insert(3);
    h.insert(25);
    
    std::cout << "heap is" << " ";
    h.print();
    
    std::cout << "heapsort" << " ";
    for(int i = 0; i < h.get_size(); ++i)
    {
        std::cout << h.get_root() << " ";
        h.remove_root();
    }
    std::cout << std::endl;
    
    h.remove_root();
    h.remove_root();
    
    std::cout << h.get_root() << std::endl;
    std::cout << h.get_size() << std::endl;
    
    return 0;
}
