#include "Test.h"
#include <limits>
#include <iostream>
#include <stdexcept>
using namespace std;

//based on https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
int* getShortestPath(int** graph, int size, int origin)
{
  int* predecessor = new int[size];
  int* distance = new int[size];
  int maxDist = std::numeric_limits<int>::max();
  for (int i = 0; i < size; ++i)
  {
    predecessor[i] = -1;
    distance[i] = maxDist;
  }
  predecessor[origin] = 0;
  distance[origin] = 0;
  // int i = 0;
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if(graph[i][j]!=-1 && (distance[i] + graph[i][j] < distance[j]))
      {
        distance[j] = distance[i] + graph[i][j];
        predecessor[j] = i;
      }
    }
  }

  return predecessor;
}

int main ()
{
    test();
    return 0;
}
