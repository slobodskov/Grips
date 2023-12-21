#include <iostream>
#include "Graph.h"
#include "Human.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru - RU.UTF - 8"); //

    Human h1("Павел");
    Human h2("Юрий");
    Human h3("Елена");
    Human h4("Георгий");
    Human h5("Анна");
    Human h6("Дмитрий");
    Human h7("Василий");
    Human h8("Ангелина");
    Human h9("Александр");

    Graph socialRelationship;

    socialRelationship.newHuman(h1);
    socialRelationship.newHuman(h2);
    socialRelationship.newHuman(h3);
    socialRelationship.newHuman(h4);
    socialRelationship.newHuman(h5);
    socialRelationship.newHuman(h6);
    socialRelationship.newHuman(h7);
    socialRelationship.newHuman(h8);
    socialRelationship.newHuman(h9);

    socialRelationship.becomeFriends(h1, h2);
    socialRelationship.becomeFriends(h2, h3);
    socialRelationship.becomeFriends(h3, h4);
    socialRelationship.becomeFriends(h4, h5);
    socialRelationship.becomeFriends(h5, h6);
    socialRelationship.becomeFriends(h5, h7);
    socialRelationship.becomeFriends(h6, h8);
    socialRelationship.becomeFriends(h8, h9);
    socialRelationship.becomeFriends(h9, h1);

    socialRelationship.allGrips(3);

    return 0;
}