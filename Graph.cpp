#include "Graph.h"
#include <map>
#include <limits>

using namespace std;

#define VERYBIGINT numeric_limits<int>::max()

Graph::Graph()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            Matrix[i][j] = 0;
    vertexCount = 0;
}
  
void Graph::newHuman(Human& newHuman)
{
    vertexes.push_back(newHuman);
    vertexCount++;
}

void Graph::becomeFriends(Human& human1, Human& human2)
{
    Matrix[human1.getData()][human2.getData()] = true;
    Matrix[human2.getData()][human1.getData()] = true;
}

bool Graph::areFriends(Human& human1, Human& human2)
{
    return Matrix[human1.getData()][human2.getData()];
}

bool Graph::humanExists(Human& human)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == human)
            return true;
    return false;
}

void Graph::allGrips(int humanQuantity)
{
    for (int i = 0; i < vertexCount; i++)
    {
        cout << "Человек с именем " << vertexes[i].getName() << " знаком(-а) с данными людьми через (количество рукопожатий): " << endl;
        findGrips(vertexes[i], humanQuantity);
    }
}

void Graph::findGrips(Human& human, int humanQuantity)
{
    map<Human, int> distances;
    for (int i = 0; i < vertexCount; ++i)
    {
        distances[vertexes[i]] = VERYBIGINT;
    }
    distances[human] = 0;

    bool* check = new bool[vertexCount];
    for (int i = 0; i < vertexCount; ++i)
    {
        check[i] = false;
    }
    int currentVertex = human.getData();
    int min_dist = 0;
    while (min_dist != VERYBIGINT)
    {
        check[currentVertex] = true;
        for (int i = 0; i < vertexCount; ++i)
        {
            if (areFriends(vertexes[currentVertex], vertexes[i])
                && distances[vertexes[currentVertex]] + Matrix[currentVertex][i] < distances[vertexes[i]])
            {
                distances[vertexes[i]] = distances[vertexes[currentVertex]] + Matrix[currentVertex][i];
            }
        }

        min_dist = VERYBIGINT;
        for (int i = 0; i < vertexCount; ++i)
        {
            if (humanExists(vertexes[i]) && !check[i] && distances[vertexes[i]] < min_dist)
            {
                min_dist = distances[vertexes[i]];
                currentVertex = i;
            }
        }
    }

    for (int i = 0; i < vertexCount; ++i)
    {
        if (distances[vertexes[i]] > 0 && distances[vertexes[i]] <= humanQuantity)
        {
            cout << vertexes[i].getName() << " - " << distances[vertexes[i]] << endl;
        }
    }

    delete[] check;
}
