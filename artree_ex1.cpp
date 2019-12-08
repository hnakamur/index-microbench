#include <iostream>
#include "ARTOLC/Tree.h"

void loadKey(TID tid, Key &key)
{
    switch (tid)
    {
    case 1:
        key.set("actor", 5);
        break;
    case 2:
        key.set("act", 3);
        break;
    }
}

int main(int argc, char *argv[])
{
    ART_OLC::Tree tree(loadKey);
    auto t = tree.getThreadInfo();
    Key key;

    key.set("actor", 5);
    tree.insert(key, 1, t);
    auto tid = tree.lookup(key, t);
    std::cout << "tid for actor = " << tid << "\n";

    key.set("act", 3);
    tree.insert(key, 2, t);
    tid = tree.lookup(key, t);
    std::cout << "tid for act = " << tid << "\n";

    return 0;
}
