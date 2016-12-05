//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
BinHeap<T>::BinHeap()
{
    // TODO: Allocate initial heap array and store sentinel value
    heapArray = new T[2];
    maxSize =1;
    heapSize = 0;
    heapArray[0]=-1;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
BinHeap<T>::~BinHeap()
{
   delete [] heapArray;
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty() method
template <class T>
bool BinHeap<T>::isEmpty()
{
    return heapSize == 0;
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
// TODO: makeEmpty() method
template <class T>
void BinHeap<T>::makeEmpty()
{
    delete [] heapArray;
    heapArray = new T[2];
    maxSize =1;
    heapSize = 0;
    heapArray[0]=-1;
}
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
// TODO: resizeArray() method
template <class T>
void BinHeap<T>::resizeArray(int newSize)
{
    /*maxSize = newSize+1;
    T tempArray[maxSize+1];
    for (int i = 0; i < heapSize+1 ; i++)
    {
        tempArray[i] = heapArray[i];

    }
        delete [] heapArray;
        heapArray = tempArray;*/
    heapArray[2];
    heapArray[0]=-1;
    heapArray[0] = -1;
    for(int i =1; i<newSize; i++)
    {
        insert(heapArray[i]);
    }

}
#endif

/* **************************************************************** */

#if LEFTINDEX || ALL
// TODO: leftIndex() method
template <class T>
int BinHeap<T>::leftIndex(int idx)
{
    return 2*idx;
}

#endif

/* **************************************************************** */

#if RIGHTINDEX || ALL
// TODO: rightIndex() method
template <class T>
int BinHeap<T>::rightIndex(int idx)
{
    return 2*idx+1;
}

#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
// TODO: parentIndex() method
template <class T>
int BinHeap<T>::parentIndex(int idx)
{
    return idx/2;
}
#endif

/* **************************************************************** */

#if MINCHILD || ALL
// TODO: minChild() method
template <class T>
int BinHeap<T>::minChild(int idx)
{
    if(rightIndex(idx) > heapSize)
    {
        if(leftIndex(idx) > heapSize)
            return -1;
        return leftIndex(idx);
    }
    if(heapArray[leftIndex(idx)] < heapArray[rightIndex(idx)])
        return leftIndex(idx);
    return rightIndex(idx);
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void BinHeap<T>::insert(const T & x)
{
    if(heapSize >= maxSize)
    {
        resizeArray(heapSize * 2);
    }
    heapSize=heapSize+1;
    heapArray[heapSize]=x;
    percolateUp(heapSize);
}
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL
// TODO: removeMin() method
template <class T>
T BinHeap<T>::removeMin()
{
    if(heapSize<1)
    {
        return -1;
    }

    T tmp = heapArray[1];
    heapArray[1] = heapArray[heapSize];
    heapArray[heapSize] = NULL;
    heapSize--;
    percolateDown(1);
    if(heapSize < maxSize/3.0)
    {
        resizeArray(maxSize/2);
    }

    return tmp;

}
#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
// TODO: percolateUp() method
template <class T>
void BinHeap<T>::percolateUp(int idx)
{
    T tmp;
    while(heapArray[parentIndex(idx)] > heapArray[idx])
    {
        tmp = heapArray[parentIndex(idx)];
        heapArray[parentIndex(idx)] = heapArray[idx];
        heapArray[idx] = tmp;
        idx = parentIndex(idx);
    }
}
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
// TODO: percolateDown() method
template <class T>
void BinHeap<T>::percolateDown(int idx)
{
    while (idx <= heapSize && minChild(idx) != -1)
    {
        if (heapArray[idx] > heapArray[minChild(idx)])
        {
            T tmp = heapArray[idx];
            heapArray[idx] = heapArray[minChild(idx)];
            heapArray[minChild(idx)] = tmp;
        }
        idx = minChild(idx);
    }

/*
    while(heapArray[idx] > heapArray[minChild(idx)]) {
        T tmp;
        tmp = heapArray[minChild(idx)];
        heapArray[minChild(idx)] = heapArray[idx];
        heapArray[idx] = tmp;
        idx = minChild(idx);
    }*/
}
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
// TODO: buildHeap() method
template <class T>
void BinHeap<T>::buildHeap(const T* arr, int size)
{
    heapArray[size];
    maxSize =size;
    heapSize = 0;
    heapArray[0]=-1;
    heapArray[0] = -1;
    for(int i =0; i<size;i++)
    {
        insert(arr[i]);
    }
    int i = size;
    while (i > 0)
    {
        percolateDown(i);
        i = i - 1;
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
template <class T>
void BinHeap<T>::printHeap()
{
    std::stringstream ss;
    printHeapToStream(ss);
    std::cout << ss.str();
}


template <class T>
void BinHeap<T>::printHeapToStream(std::stringstream& ss)
{
    ss << "  Current array size: " << maxSize << std::endl;
    ss << "  Current heap size: " << heapSize << std::endl;
    
    if (!isEmpty()) {
        ss << "  Heap Elements: ";
        // Print heap array
        for (int i = 1; i <= heapSize; i++) {
            ss << heapArray[i] << " ";
        }
    }
    else {
        ss << "  Heap is empty";
    }
    ss << std::endl << std::endl;
}
#endif

template class BinHeap<int>;
