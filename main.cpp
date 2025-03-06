#include "data.h"

int main()
{
    xx::LinkedList<int> llist;

    llist.AddToBack(1);
    llist.AddToBack(2);
    llist.AddToBack(3);
    llist.AddToBack(4);
    llist.AddToBack(5);

    llist.Insert(1, -1);

    llist.LoopList([](int&Node ) -> void {std::cout<<Node<<std::endl;});
}