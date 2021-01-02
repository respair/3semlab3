#include "test_sequence.hpp"
#include "test.hpp"
#include "Graph.hpp"
#include <cassert>
#include <string>
#include <chrono>
#include <iostream>
using namespace std;

string answ = "yes";

int main() {
    cout << "Hello!" << endl;
    string answer = "";
    int answ2 = 0;
    while (answ == "yes") {
        cout << "What would you like to do: find the shortest path from one point of the graph to another" << endl;
        cout << "(write the number 1) or look at the ready-made tests of the graph and sequence (write number 2)?" << endl;
        cin >> answ2;
        if (answ2 == 2) {
            TestSequence();
            TestGraph();
        }
        else if (answ2 == 1) {
            cout << "Please enter the number of vertices in the graph: " << endl;
            int numbers = 0;
            cin >> numbers;
            if (numbers == 0) cout << "Invalid number of vertices! Try again." << endl;
            cout << "Generate edges and their weights automatically?" << endl;
            cin >> answer;
            int* array = new int[numbers * numbers];
            if (answer == "no") {
                cout << "Enter the vertex adjacency matrix line by line:" << endl;
                for (int i = 0; i < numbers * numbers; i++)
                    cin >> array[i];
            }
            else {
                for (int i = 0; i < numbers * numbers; i++)
                    array[i] = rand() % 100;
            }
            Graph<int> graph(array, numbers);
            cout << "Want to see the resulting matrix?" << endl;
            cin >> answer;
            if (answer == "yes") graph.PrintMatrix();
            cout << endl;
            cout << "Enter the numbers of the vertices : starting and ending (keep in mind that the very first vertex has a zero number)." << endl;
            int start = 0, finish = 0;
            cin >> start >> finish;
            auto begin = std::chrono::steady_clock::now();
            Sequence<int>* path = graph.Dijkstra(start, finish);
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms_ = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            int n = graph.Length(path);
            if (n != INT_MAX) cout << "Path length: " << n << endl;
            else cout << "Path length: " << "no path" << endl;
            cout << "Vertices to go through: ";
            graph.PrintPath(path);
            cout << "Want to know how many seconds it took to find the shortest path?" << endl;
            cin >> answer;
            if (answer == "yes") cout << "Time: " << elapsed_ms_.count() << "ms." << endl;
        }
        else
            cout << "Sorry, there is no such command. Read the readings more carefully and try again." << endl;
        cout << "Thanks for using this program! Do you want to continue?" << endl;
        cin >> answ;
        if (answ != "yes") cout << "Good luck then! Have a nice day!!" << endl;
    }
}