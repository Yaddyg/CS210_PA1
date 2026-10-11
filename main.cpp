#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    //Table 1
    std::unique_ptr<List<Player>> table1 = makeList<Player>();

    table1->addFront(new Player(1,"Billy Bob"));

    table1->addFront(new Player(2,"Filbert"));

    table1->addFront(new Player(3,"Swazzy"));

    table1->addFront(new Player(4,"Aziz Wasy"));

    table1->print();

    table1->addAnywhere(3, new Player (67, "joe"));

    table1->print();

    //Reverse
    table1->reverse();
    table1->print();

    //Double reverse
    table1->reverse();
    table1->print();

    std::cout <<"Joe has won the game" << std::endl;

    table1->deleteAnywhere(3);
    table1->print();


    //Table 2
    std::unique_ptr<List<Player>> table2 = makeList<Player>();

    table2->addFront(new Player(5,"Billy Bobs cousing frank "));

    table2->addFront(new Player(6,"Filberts mom janice "));

    table2->addFront(new Player(7,"Swazzys uncle albert "));

    table2->addFront(new Player(8,"Aziz Wasys brother fakir"));
//before merge
    table1->print();
    table2->print();


    table1->concat(table2.get());
//after merge
    table1->print();
    table2->print();

//concat incompatible test

    ArrayList<int> array;
    LinkedList<int> linked;

    array.addFront(new int(10));
    linked.addFront(new int(20));

    array.print();
    linked.print();


    array.concat(&linked);

    array.print();
    linked.print();

    return 0;
}
