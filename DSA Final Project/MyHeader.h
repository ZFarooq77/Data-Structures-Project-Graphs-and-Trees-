#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <climits>
using namespace std;


const int X = 25;
int adjMatrix[X * X][X * X]; 
const int ROWS = 25, COLS = 25;
char graph11[ROWS][COLS] =
{
        "CCCCC@#CCCCCC#CCC#",
        "CCCCC##C@C#CC#C#JC",
        "CC#P&C#C&C&CCCC##J",
        "C%CJK%$C##C%WCCC%C",
        "#CJCJCC#CCCCCC%CC",
        "C#C@#CP%CATWC@@@@",
        "CJ#C@CCCC%J$C%#CC",
        "CCCCCCCCCCCCCC#C*",
        "CCCCCCCCCCCCCCCCC",
        "CJCJCCCCCCCCCCCCC",
        "C$C#C#CP#CJC%CC#C",
        "#$C#$C#CC%#CPCJCC",
        "JJC#C#CCCC#%CP#W#",
        "CCCCCCCCC#C#CJ%C%",
        "#&CPCJCCCJCC#$&CC",
        "CC#CCCCCCCCCCCCCC",
        "#CCCCCCCCC&CPCPC@",
        "@CCCJCCCC%CC$###@",
        "C%C#CCCCCC#CCCCCC",
        "CCCCCCCCC$#CCCCCC"
    };

int returnIdx(int i, int j, int m)
{ 
    int idx = i * m + j;
    return idx;
}

void createAdjMatrix(int n, int m)
{

    memset(adjMatrix, 0, sizeof(adjMatrix)); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = returnIdx(i, j, m); 


            if (j > 0 && graph11[i][j - 1] != '#')
            { // left
                int v = returnIdx(i, j - 1, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 1; 
            }
            else if (j > 0 && graph11[i][j - 1] == '#')
            {
                int v = returnIdx(i, j - 1, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 100; 

            }
            if (j < m - 1 && graph11[i][j + 1] != '#')
            { // right
                int v = returnIdx(i, j + 1, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 1;
            }
            else if (j < m - 1 && graph11[i][j + 1] == '#')
            {
                int v = returnIdx(i, j + 1, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 100;

            }
            if (i > 0 && graph11[i - 1][j] != '#')
            { // up
                int v = returnIdx(i - 1, j, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 1;
            }
            else if (i > 0 && graph11[i - 1][j] == '#')
            {
                int v = returnIdx(i - 1, j, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 100;

            }
            if (i < n - 1 && graph11[i + 1][j] != '#')
            { // down
                int v = returnIdx(i + 1, j, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 1;
            }
            else if (i < n - 1 && graph11[i + 1][j] == '#')
            {
                int v = returnIdx(i + 1, j, m);
                adjMatrix[u][v] = adjMatrix[v][u] = 100;

            }
        }
    }

}


void DisplayAdjMatrix()
{
    int size = ROWS * COLS;
    createAdjMatrix(ROWS, COLS);

    // print adjacency matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }


}


int Infinity = 999999;
int V = 625;
int dist[625];
bool IfVis[625] = { 0 };
int p[625];

void func(int s11)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = Infinity;
        dist[s11] = 0;
    }
}
int getNearestNode()
{
    int minV = Infinity;
    int minN = 0;
    for (int i = 0; i < V; i++)
    {
        if (!IfVis[i] && dist[i] < minV)
        {
            minV = dist[i];
            minN = i;
        }
    }
    return minN;
}

void dijkstraAlgo()
{
    for (int i = 0; i < V; i++)
    {
        int nearest = getNearestNode();
        IfVis[nearest] = true;

        for (int adj = 0; adj < V; adj++)
        {
            if (adjMatrix[nearest][adj] != 0 && adjMatrix[nearest][adj] != 100 && dist[adj] > dist[nearest] + adjMatrix[nearest][adj])
            {
                dist[adj] = dist[nearest] + adjMatrix[nearest][adj];
                p[adj] = nearest;
            }
        }
    }
}

int createAdjMatrix1(int r77, int c77)
{

    int v1 = 0;

    for (int i = 0; i < r77; i++)
    {
        for (int j = 0; j < c77; j++)
        {
            int u = returnIdx(i, j, c77); 

            if (graph11[i][j] == '*')
            {
                v1 = u;
            }
            if (j > 0 && graph11[i][j - 1] == '*')
            { // left
                v1 = returnIdx(i, j - 1, c77);

            }

            if (j < c77 - 1 && graph11[i][j + 1] == '*')
            { // right
                v1 = returnIdx(i, j + 1, c77);

            }

            if (i > 0 && graph11[i - 1][j] == '*')
            { // up
                v1 = returnIdx(i - 1, j, c77);

            }

            if (i < r77 - 1 && graph11[i + 1][j] == '*')
            { // down
                v1 = returnIdx(i + 1, j, c77);

            }

        }
    }
    return v1;
}
int createAdjMatrix2(int r77, int c77, int t23)
{

    int v11 = -1;
    for (int i = 0; i < r77; i++)
    {
        for (int j = 0; j < c77; j++)
        {
            int u = returnIdx(i, j, c77); 
            if (u == t23)
            {
                v11 = u;
                return v11;
            }

        }
    }
    return v11;
}

void printMinDist(int q1)
{   
    cout << "minimum distance = " << dist[q1] << endl;
}
int mink(int k[], bool ms[])
{
    int min = Infinity, minIdx = 0;

    for (int v = 0; v < V; v++)
        if (ms[v] == false && k[v] < min)
            min = k[v], minIdx = v;

    return minIdx;
}


void printPrims(int arr[625])
{
    cout << "Edge \t Weight"<< endl;
    for (int i = 1; i < 625; i++)
    {
        cout << arr[i] << endl;
    }
}
void primsAlgo()
{
    int p[625];
    int k[625];
    bool ms[625];

    for (int i = 0; i < V; i++)
        k[i] = Infinity, ms[i] = false;

    k[0] = 0;

    p[0] = -1;

    for (int c = 0; c < V - 1; c++)
    {

        int u = mink(k, ms);

        ms[u] = true;

       
        for (int a = 0; a < V; a++)
        {

            if (adjMatrix[u][a] != 0 && adjMatrix[u][a] != 100 && ms[a] == false && adjMatrix[u][a] < k[a])
            {
                p[a] = u, k[a] = adjMatrix[u][a];
            }
        }
    }

    printPrims(k);
}