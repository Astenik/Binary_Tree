#pragma once

#include <iostream>

#include <vector>

enum MaxMin
{
    Max,
    Min 
};

template <typename T>
class Heap
{
public:
    Heap(MaxMin);
    ~Heap();

public:
    void insert(const T&);
    void remove_root();
    
    T get_root() const;
    bool empty() const;
    int get_size() const;
    void print() const;
    int leftChildeIndex(int) const;
    int rightCildeIndex(int) const;
    int parentIndex(int) const;
    

private:
    void heapifyUp(int);
    void heapifyDown(int);

private:
    MaxMin m_state;
    std::vector<T> m_data;
};

template <typename T>
Heap<T>::Heap(MaxMin state)
    : m_state(state)
{}

template <typename T>
Heap<T>::~Heap()
{
    std::cout << "dtor" << std::endl;
}

template <typename T>
void Heap<T>::insert(const T& d)
{
    m_data.push_back(d);
    heapifyUp(m_data.size() - 1);
}

template <typename T>
void Heap<T>::remove_root() 
{
    if(empty())
    {
        throw "the Heap is empty.";
    }
    
    m_data[0] = m_data[m_data.back()];
    m_data.pop_back();
    heapifyDown(0);
    
}

template <typename T>
T Heap<T>::get_root() const
{
    if(empty())
    {
        throw "the Heap is empty.";
    }
    
    return m_data[0];
}

template <typename T>
bool Heap<T>::empty() const
{
    return m_data.empty();
}

template <typename T>
int Heap<T>::get_size() const 
{
    return m_data.size();
}

template <typename T>
void Heap<T>::print() const
{ 
    for(int i = 0; i < m_data.size(); ++i)
    {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int Heap<T>::leftChildeIndex(int i) const
{
    return 2*i + 1 < m_data.size() ? 2*i + 1 : -1;
}

template <typename T>
int Heap<T>::rightCildeIndex(int i) const
{
    return 2*i + 2 < m_data.size() ? 2*i + 2 : -1;
}

template <typename T>
int Heap<T>::parentIndex(int i) const
{
    return i == 0 ? -1 : (i - 1) / 2;
}

template <typename T>
void Heap<T>::heapifyUp(int i)
{
    int current = i;
    int parent = parentIndex(current);
    if(m_state == Max)
    {
        while(parent >= 0 && m_data[current] > m_data[parent])
        {
            std::swap(m_data[current], m_data[parent]);
            current = parent;
            parent = (current - 1) / 2;
        }
    }
    else if(m_state == Min)
    {
        while(parent >= 0 && m_data[current] < m_data[parent])
        {
            std::swap(m_data[current], m_data[parent]);
            current = parent;
            parent = parentIndex(current);
        }
    }
}

template <typename T>
void Heap<T>::heapifyDown(int i)
{
    int current = i;
    int maxchild = leftChildeIndex(current);
    if(maxchild == -1)
        return;
    if(m_state == Max)
    {
        if(rightCildeIndex(current) != -1 && m_data[maxchild] < m_data[rightCildeIndex(current)])
        {
            maxchild = rightCildeIndex(current);
        }
        while(maxchild != - 1 && m_data[current] < m_data[maxchild])
        {
            std::swap(m_data[current], m_data[maxchild]);
            current = maxchild;
            maxchild = leftChildeIndex(current);
            if(maxchild == -1)
                return;
            if(rightCildeIndex(current) != -1 && m_data[maxchild] < m_data[rightCildeIndex(current)])
            {
                maxchild = rightCildeIndex(current);
            }   
        }
    }
    else if(m_state == Min)
    {
        if(rightCildeIndex(current) != -1 && m_data[maxchild] > m_data[rightCildeIndex(current)])
        {
            maxchild = rightCildeIndex(current);
        }
        while(maxchild != - 1 && m_data[current] > m_data[maxchild])
        {
            std::swap(m_data[current], m_data[maxchild]);
            current = maxchild;
            maxchild = leftChildeIndex(current);
            if(maxchild == -1)
                return;
            if(m_data[maxchild] > m_data[rightCildeIndex(current)])
            {
                maxchild = rightCildeIndex(current);
            }   
        }
    }
}
