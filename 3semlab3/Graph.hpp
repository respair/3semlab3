#pragma once
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include <iostream>
using namespace std;

template <class T>
class Graph {
private:
    Sequence<T>* graph; // graph - matrix
    int size_ = 0;
public:
    Graph(T* arr, int size) {
        this->graph = new ArraySequence<T>(size * size); //matrix
        this->size_ = size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this->graph->Set(j + i * size, arr[j + i * size]); //for string
            }
        }
    }

    Sequence<int>* Dijkstra(int start_, int end_) {
        if (start_ < 0 || start_ >= this->size_ || end_ < 0 || end_ >= this->size_)
            return nullptr;
        Sequence<T>* short_path = new ArraySequence<T>(this->size_);
        Sequence<bool>* visited = new ArraySequence<bool>(this->size_);
        Sequence<int>* ex_path = new ArraySequence<int>(this->size_);

        for (int i = 0; i < this->size_; i++) { // initial conditions
            short_path->Set(i, INT_MAX);
            visited->Set(i, false);
        }
        short_path->Set(start_, 0); // initial vertex
        ex_path->Set(0, start_); // just fill
        
        for (int i = 0; i < this->size_ - 1; i++) { // start

            int min = INT_MAX;
            T min_ = INT_MAX;
            for (int i = 0; i < this->size_; i++)  // along string
                if (visited->Get(i) == 0 && (short_path->Get(i) <= min_)) {
                    min_ = short_path->Get(i); // from unvisited take minimum for this v (string)
                    min = i;
                }

            visited->Set(min, true); // wiki

            for (int j = 0; j < this->size_; j++) {
                if (!visited->Get(j) && (this->graph->Get(j + min * this->size_)) && (short_path->Get(min) != INT_MAX) &&
                    (short_path->Get(min) + this->graph->Get(j + min * this->size_) < short_path->Get(j))) {
                    ex_path->Set(j, min);
                    short_path->Set(j, short_path->Get(min) + this->graph->Get(j + min * this->size_));
                }
            }
        } //finish
        Sequence<int>* path = result_path(ex_path, short_path, start_, end_);
        return path;
    }
    Sequence<int>* result_path(Sequence<int>* ex_path, Sequence<T>* short_path, int start_, int end_) {
        Sequence<T>* path = new ArraySequence<T>;
        int item = end_;
        while (item != start_) {
            if (short_path->Get(item) == INT_MAX) { //no path
                return new ArraySequence<T>;        // empty: size = 0
            }
            item = ex_path->Get(item);
            path->Prepend(item);
        }
        path->Append(end_);
        return path;
    }

    T Length(Sequence<int>* path) {
        if (path->GetSize() == 0)
            return INT_MAX;                     //infinity  
        else if (path->GetSize() == 1)
            return 0;
        else {
            T length = 0;
            for (int i = 0; i < path->GetSize() - 1; i++)
                length += this->graph->Get(path->Get(i + 1) + path->Get(i) * this->size_);
            return length;
        }
    }
    void PrintPath(Sequence<int>* path) {
        int i = 0;
        if (path->GetSize() > 1) {
            for (i = 0; i < path->GetSize() - 1; i++)
                cout << path->Get(i) << "->";
            cout << path->Get(i) << endl;
        }
        else if (path->GetSize() == 1)  cout << path->Get(0) << endl;
        else cout << "-" << endl;
    }
    void PrintMatrix() {
        for (int i = 0; i < this->size_; i++) {
            for (int j = 0; j < this->size_; j++)
                cout << this->graph->Get(j + i * this->size_) << " ";
            cout << endl;
        }
    }
    ~Graph() {
        delete graph;
    }
};
