#include <iostream>

#include "Heap.h"

int main()
{
    std::cout << "MAX heap " << "!!!!!!!" << std::endl;
    Heap<int> h(Max);
    h.insert(7);
    h.insert(5);
    h.insert(10);
    h.insert(14);
    h.insert(3);
    h.insert(25);
    
    std::cout << "heap is" << " ";
    h.print();
    
    std::cout << "heap size " << h.get_size() << std::endl;
    
    std::cout << "heapsort" << " ";
    int d = h.get_size();
    for(int i = 0; i < d; ++i)
    {
        std::cout << h.get_root() << " ";
        h.remove_root();
    }
    std::cout << std::endl;
    
    std::cout << "Heap size after heapsort " <<  h.get_size() << std::endl;
    
    std::cout << "MIN heap " << "!!!!!!!" << std::endl;
    Heap<int> h1(Min);
    h1.insert(7);
    h1.insert(5);
    h1.insert(10);
    h1.insert(14);
    h1.insert(3);
    h1.insert(25);
    
    std::cout << "heap is" << " ";
    h1.print();
    
    std::cout << "heap size " << h1.get_size() << std::endl;
    
    std::cout << "heapsort" << " ";
    int d1 = h1.get_size();
    for(int i = 0; i < d1; ++i)
    {
        std::cout << h1.get_root() << " ";
        h1.remove_root();
    }
    std::cout << std::endl;
    
    std::cout << "Heap size after heapsort " <<  h1.get_size() << std::endl;
    
    return 0;
}
