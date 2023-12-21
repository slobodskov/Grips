#pragma once
#ifndef __GRAPH__
#define __GRAPH__
#include <vector>
#include "Human.h"
#define SIZE 10



class Graph
{
    public:
        Graph();
        void newHuman(Human& newHuman);
        void becomeFriends(Human& human1, Human& human2);
        bool areFriends(Human& human1, Human& human2);
        bool humanExists(Human& human);
        void allGrips(int humanQuantity);
        void findGrips(Human& fromHuman, int humanQuantity);

    private:
        bool Matrix[SIZE][SIZE]; 
        vector<Human> vertexes;
        int vertexCount;
};


#endif