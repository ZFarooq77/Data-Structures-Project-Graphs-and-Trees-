
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <MMSystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include"header.h"




int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "!!!!!!!!!!!!!!!!!!!!! WELCOME TO "; SetConsoleTextAttribute(hConsole, 6); cout << "The Quest for the"; SetConsoleTextAttribute(hConsole, 1); cout << " Crystal Kingdom"; SetConsoleTextAttribute(hConsole, 15); cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl << endl;

    while (true)
    {
        char value;
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Select one of the following: " << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 12);
        cout << "1 - Draw adjaceny matrix of graph" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 7);
        cout << "2 - Find minimum distance of custom location using dijkstra" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 3);
        cout << "3 - Find minimum distance of starting location(0,0) using dijkstra" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 9);
        cout << "4 - Use Floyd's algorithm to calculate the shortest path between a custom location and the crystal" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 11);
        cout << "5 - Use Floyd's algorithm to calculate the shortest path between a custom location and the crystal" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "6 - Use Kruskal's algorithm to calculate the minimum spanning tree of the map" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 4);
        cout << "7 - Use Prim's algorithm to calculate the minimum spanning tree of the map" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 2);
        cout << "8 - Find total score of game" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 11);
        cout << "9 - EXIT" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        SetConsoleTextAttribute(hConsole, 3);
        cout << "Input: ";
        SetConsoleTextAttribute(hConsole, 15);
        cin >> value;


        while (value != '1' && value != '2' && value != '3' && value != '4' && value != '5' && value != '6' && value != '7' && value != '8' && value != '9')
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "*Please enter from the following list provided" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cout << "Input: ";
            cin >> value;

        }

                

        if (value == '1')
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << "\nCongratulations you can view your adjaceny matrix of the map!\n\n\n";
            DisplayAdjMatrix();
            SetConsoleTextAttribute(hConsole, 15);
            system("pause");
            system("cls");
        }
        if (value == '2')
        {
            createAdjMatrix(ROWS, COLS);
            int source1;
            SetConsoleTextAttribute(hConsole, 1);
            cout << "**Enter the custom location from which you want to start finding minimum distance using dijkstra = " << endl;
            SetConsoleTextAttribute(hConsole, 10);
            cin >> source1;
            int r134 = createAdjMatrix2(25, 25, source1);
            if (r134 == -1)
            {
                SetConsoleTextAttribute(hConsole, 9);
                cout << "***This custom location does not exits***" << endl;
                SetConsoleTextAttribute(hConsole, 14);
            }
            cout << " r134 = " << r134 << endl;

            func(r134);
            minDistByDijkjrtra();
            int r1 = createAdjMatrix1(25, 25);
            cout << " r1 = " << r1 << endl;
            printMinDist(r1);

            system("pause");
            system("cls");

        }
        if (value == '3')
        {
            createAdjMatrix(ROWS, COLS);
            int source1;
            SetConsoleTextAttribute(hConsole, 8);
            cout << "**Enter the starting location(0,0) from which you want to start finding minimum distance using dijkstra = " << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cin >> source1;
            int r134 = createAdjMatrix2(25, 25, source1);
            if (r134 == -1)
            {
                SetConsoleTextAttribute(hConsole, 5);
                cout << "***This starting location does not exits***" << endl;
                SetConsoleTextAttribute(hConsole, 13);
            }
            cout << " r134 = " << r134 << endl;

            func(r134);
            minDistByDijkjrtra();
            int r1 = createAdjMatrix1(25, 25);
            cout << " r1 = " << r1 << endl;
            printMinDist(r1);

            system("pause");
            system("cls");
        }
        if (value == '4')
        {
        }
        if (value == '5')
        {
        }
        if (value == '6')
        {
        }
        if (value == '7')
        {
            createAdjMatrix(ROWS, COLS);
            primsAlgo();

        }
        if (value == '8')
        {
        }
        if (value == '9')
        {
            return 0;
        }
      
        system("pause");
    }
}





