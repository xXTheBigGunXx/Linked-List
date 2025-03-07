#include "data.h"

int main()
{
    xx::LinkedList<int> llist;

    llist.AddToFront(1);
    llist.AddToFront(2);
    llist.AddToFront(3);
    llist.AddToFront(4);
    llist.AddToFront(5);

    llist.SelectionSort();

    llist.SwapNodes(0,1);

    llist.LoopList([](int&Node ) -> void {std::cout<<Node<<std::endl;});
}