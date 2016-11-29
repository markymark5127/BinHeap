//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
//template <class T>
//BinHeap<T>::BinHeap()
//{
    // TODO: Allocate initial heap array and store sentinel value
//}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
//template <class T>
//BinHeap<T>::~BinHeap()
//{
    // TODO: Deallocate heap array
//}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty() method
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
// TODO: makeEmpty() method
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
// TODO: resizeArray() method
#endif

/* **************************************************************** */

#if LEFTINDEX || ALL
// TODO: leftIndex() method
#endif

/* **************************************************************** */

#if RIGHTINDEX || ALL
// TODO: rightIndex() method
#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
// TODO: parentIndex() method
#endif

/* **************************************************************** */

#if MINCHILD || ALL
// TODO: minChild() method
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL
// TODO: removeMin() method
#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
// TODO: percolateUp() method
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
// TODO: percolateDown() method
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
// TODO: buildHeap() method
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
