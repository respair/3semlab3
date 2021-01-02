#pragma once
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include <cassert>
#include <iostream>

void TestSequence() {
    std::cout << "TEST SEQUENCE: START:" << std::endl;

    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        assert(5 == seq->GetSize());
        std::cout << "GET SIZE: 1 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        assert(10 == seq->GetSize());
        std::cout << "GET SIZE: 2 TEST: DONE!" << std::endl;
    }
    /* {
         int arr[5] = { 1,0,2,3,-1 };
         ListSequence<int> test(arr, 5);
         Sequence<int>* seq = &test;
         //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
         assert(5 == seq->GetSize());
         std::cout << "GET SIZE: 3 TEST: DONE!" << std::endl;
     }
     {
         int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
         ListSequence<int> test(arr, 10);
         Sequence<int>* seq = &test;
         //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
         assert(10 == seq->GetSize());
         std::cout << "GET SIZE: 4 TEST: DONE!" << std::endl;
     }*/
    {
        ArraySequence<int> test(50);
        Sequence<int>* seq = &test;
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(50 == seq->GetSize());
        std::cout << "GET SIZE: 3 TEST: DONE!" << std::endl;
    }
    {
        ArraySequence<int> test(150);
        Sequence<int>* seq = &test;
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(150 == seq->GetSize());
        std::cout << "GET SIZE: 4 TEST: DONE!" << std::endl;
    }
    std::cout << std::endl;
    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq = &testing;
        //Sequence<int>* seq1 = new ListSequence<int>(arr, 5);
        assert(0 == seq->Get(1));
        assert(1 == seq->Get(0));
        assert(2 == seq->Get(2));
        std::cout << "GET: 1 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq2 = &testing;
        //Sequence<int>* seq3 = new ListSequence<int>(arr, 5);
        assert(998 == seq2->Get(3));
        assert(-345 == seq2->Get(4));
        assert(-97665 == seq2->Get(1));
        std::cout << "GET: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 0,1,0,998,-345 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq2 = &testing;
        //Sequence<int>* seq3 = new ListSequence<int>(arr, 5);
        assert(998 == seq2->Get(3));
        assert(0 == seq2->Get(2));
        assert(1 == seq2->Get(1));
        std::cout << "GET: 3 TEST: DONE!" << std::endl;
    }
    /* {
         int arr[5] = { 1,0,2,3,-1 };
         ListSequence<int> testing(arr, 5);
         Sequence<int>* seq4 = &testing;
         //Sequence<int>* seq5 = new ListSequence<int>(arr, 5);
         assert(0 == seq4->Get(1));
         assert(1 == seq4->Get(0));
         assert(2 == seq4->Get(2));
         std::cout << "GET: 3 TEST: DONE!" << std::endl;
     }
     {
         int arr[5] = { 8899,-97665,0,998,-345 };
         ListSequence<int> testing(arr, 5);
         Sequence<int>* seq6 = &testing;
         //Sequence<int>* seq3 = new ListSequence<int>(arr, 5);
         assert(998 == seq6->Get(3));
         assert(-345 == seq6->Get(4));
         assert(-97665 == seq6->Get(1));
         std::cout << "GET: 4 TEST: DONE!" << std::endl;
     }*/
    std::cout << std::endl;
    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq = &testing;
        seq->Set(1, 2);
        assert(2 == seq->Get(1));
        seq->Set(0, -2);
        assert(-2 == seq->Get(0));
        std::cout << "SET: 1 TEST: DONE!" << std::endl;
        std::cout << "SET: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq2 = &testing;
        seq2->Set(4, 0);
        assert(0 == seq2->Get(4));
        std::cout << "SET: 3 TEST: DONE!" << std::endl;
    }
    {
        int arr[5] = { 8899,-97665,0,998,-345 };
        ArraySequence<int> testing(arr, 5);
        Sequence<int>* seq2 = &testing;
        seq2->Set(1, 0);
        assert(0 == seq2->Get(1));
        std::cout << "SET: 4 TEST: DONE!" << std::endl;
    }
    /* {
         int arr[5] = { 1,0,2,3,-1 };
         ListSequence<int> testing(arr, 5);
         Sequence<int>* seq4 = &testing;
         seq4->Set(1, 2);
         assert(2 == seq4->Get(1));
         seq4->Set(0, -2);
         assert(-2 == seq4->Get(0));
         std::cout << "SET: 4 TEST: DONE!" << std::endl;
         std::cout << "SET: 5 TEST: DONE!" << std::endl;
     }
     {
         int arr[5] = { 8899,-97665,0,998,-345 };
         ListSequence<int> testing(arr, 5);
         Sequence<int>* seq6 = &testing;
         seq6->Set(4, 0);
         assert(0 == seq6->Get(4));
         std::cout << "SET: 6 TEST: DONE!" << std::endl;
     }*/
    std::cout << std::endl;
    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        seq->Append(3);
        assert(3 == seq->Get(5));
        std::cout << "APPEND: 1 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        seq->Append(0);
        assert(0 == seq->Get(10));
        std::cout << "APPEND: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        seq->Append(3);
        seq->Append(15);
        assert(3 == seq->Get(10));
        assert(15 == seq->Get(11));
        std::cout << "APPEND: 3 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        seq->Append(12);
        assert(12 == seq->Get(10));
        std::cout << "APPEND: 4 TEST: DONE!" << std::endl;
    }
    std::cout << std::endl;
    {
        int arr[5] = { 1,0,2,3,-1 };
        ArraySequence<int> test(arr, 5);
        Sequence<int>* seq = &test;
        seq->Prepend(3);
        assert(3 == seq->Get(0));
        std::cout << "PREPEND: 1 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        seq->Prepend(0);
        assert(0 == seq->Get(0));
        std::cout << "PREPEND: 2 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        seq->Prepend(3);
        seq->Prepend(15);
        assert(3 == seq->Get(1));
        assert(15 == seq->Get(0));
        std::cout << "PREPEND: 3 TEST: DONE!" << std::endl;
    }
    {
        int arr[10] = { 1,0,2,3,-1,1,44,6,32,1 };
        ArraySequence<int> test(arr, 10);
        Sequence<int>* seq = &test;
        seq->Prepend(12);
        assert(12 == seq->Get(0));
        std::cout << "PREPEND: 4 TEST: DONE!" << std::endl;
    }
    std::cout << "TEST SEQUENCE: THE END." << std::endl;
    std::cout << std::endl;
}