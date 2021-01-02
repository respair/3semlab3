#pragma once
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "Graph.hpp"
#include <cassert>
#include <iostream>
using namespace std;

void TestGraph() {
	cout << "TEST GRAPH: START:" << endl;
	{
		int a[25] = { 0,0,12,0,0,
					 34,0,0,0,0,
					 0,20,30,12,3,
					 28,0,0,0,0,
					 0,0,32,0,0 };
		Graph<int> g(a, 5);
		Sequence<int>* test_ = g.Dijkstra(3, 2);
		//g.PrintMatrix();
	//	cout << g.Length(test_) << " " << test_->GetSize() << endl;

		assert(test_->GetSize() == 3);
		assert(test_->Get(0) == 3);
		assert(test_->Get(1) == 0);
		assert(test_->Get(2) == 2);
		assert(g.Length(test_) == 40);
		cout << "TEST GRAPH 1: GOOD!" << endl;
	}
	{
		int a[25] = { 0,0,12,0,0,
					 34,0,0,0,0,
					 0,20,30,12,3,
					 28,0,0,0,0,
					 0,0,32,0,0 };
		Graph<int> g(a, 5);
		Sequence<int>* test_ = g.Dijkstra(0, 4);

		assert(g.Length(test_) == 15);
		assert(test_->GetSize() == 3);
		assert(test_->Get(0) == 0);
		assert(test_->Get(1) == 2);
		assert(test_->Get(2) == 4);
		cout << "TEST GRAPH 2: GOOD!" << endl;
	}
	{
		int a[25] = { 0,0,0,0,0,
					 0,0,0,0,0,
					 0,0,0,0,0,
					 0,0,0,0,0,
					 0,0,0,0,0 };
		Graph<int> g(a, 5);
		Sequence<int>* test_ = g.Dijkstra(0, 0);

		assert(g.Length(test_) == 0);
		assert(test_->GetSize() == 1);
		assert(test_->Get(0) == 0);
		cout << "TEST GRAPH 3: GOOD!" << endl;
	}
	{
		int a[25] = { 0,0,0,0,0,
					 0,0,0,0,0,
					 0,0,0,0,0,
					 0,0,0,0,0,
					 0,0,0,0,0 };
		Graph<int> g(a, 5);
		Sequence<int>* test_ = g.Dijkstra(0, 2);

		assert(g.Length(test_) == INT_MAX);
		assert(test_->GetSize() == 0);
		cout << "TEST GRAPH 4: GOOD!" << endl;
	}
	{
		int a[25] = { 0,0,12,200,0,
					 38,0,0,0,0,
					 0,20,0,0,3,
					 28,0,0,0,0,
					 0,0,32,15,0 };
		Graph<int> g(a, 5);
		Sequence<int>* test_ = g.Dijkstra(1, 3);
		//g.PrintMatrix();

		assert(test_->GetSize() == 5);
		assert(test_->Get(0) == 1);
		assert(test_->Get(1) == 0);
		assert(test_->Get(2) == 2);
		assert(test_->Get(3) == 4);
		assert(test_->Get(4) == 3);
		assert(g.Length(test_) == 68);
		cout << "TEST GRAPH 5: GOOD!" << endl;
	}
	cout << "TEST GRAPH: THE END." << endl;
	cout << endl;
}
