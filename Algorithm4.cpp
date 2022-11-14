#include <bits/stdc++.h>
using namespace std;

int NO_PARENT = -1;

void printPath(int currentVertex, vector<int> parents)
{

    if (currentVertex == NO_PARENT) {
        return;
    }
    printPath(parents[currentVertex], parents);
    cout << currentVertex << " ";
}
void printSolution(int startVertex, vector<int> distances,
                vector<int> parents)
{
    int nVertices = distances.size();
    cout << "Vertex\t Distance\tPath";

    for (int vertexIndex = 0; vertexIndex < nVertices;
        vertexIndex++) {
        if (vertexIndex != startVertex) {
            cout << "\n" << startVertex << " -> ";
            cout << vertexIndex << " \t\t ";
            cout << distances[vertexIndex] << "\t\t";
            printPath(vertexIndex, parents);
        }
    }
}
void dijkstra(vector<vector<int> > adjacencyMatrix,
            int startVertex)
{
    int nVertices = adjacencyMatrix[0].size();
    vector<int> shortestDistances(nVertices);
    vector<bool> added(nVertices);
    for (int vertexIndex = 0; vertexIndex < nVertices;
        vertexIndex++) {
        shortestDistances[vertexIndex] = INT_MAX;
        added[vertexIndex] = false;
    }
    shortestDistances[startVertex] = 0;
    vector<int> parents(nVertices);
    parents[startVertex] = NO_PARENT;
    for (int i = 1; i < nVertices; i++) {

        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices;
            vertexIndex++) {
            if (!added[vertexIndex]
                && shortestDistances[vertexIndex]
                    < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance
                    = shortestDistances[vertexIndex];
            }
        }

        added[nearestVertex] = true;
        for (int vertexIndex = 0; vertexIndex < nVertices;
            vertexIndex++) {
            int edgeDistance
                = adjacencyMatrix[nearestVertex]
                                [vertexIndex];

            if (edgeDistance > 0
                && ((shortestDistance + edgeDistance)
                    < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex]
                    = shortestDistance + edgeDistance;
            }
        }
    }

    printSolution(startVertex, shortestDistances, parents);
}

int main()
{
int originnode=0;

    vector<vector<int> > adjacencyMatrix
      = { 
        {0, 10, 0, 0, 3},
        {10, 0, 2, 0, 4},
        {0, 2, 0, 9, 8},
        {0, 0, 7, 0, 2},
        {3, 1, 8, 2, 0}};
     std::cout << "Enter origin node: ";
     std::cin >> originnode;
    dijkstra(adjacencyMatrix, originnode);
    return 0;
}
