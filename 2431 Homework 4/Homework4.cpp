// Homework4.cpp : Defines the entry point for the console application.
//

/*
Create a file called Solution.h to contain your solution. Look, it's already #included for you!

You should encapsulate your code within the namespace SPU::CSC2431::Homework4.

Create a templated BinarySearchTree class that implements the following functions, all of which return void:
Add - takes a single parameter of the templated type and adds it to the tree according to Binary Search Tree rules
PreorderDFS - see below
PostorderDFS - see below
InorderDFS - see below
BFS - see below

The DFS and BFS tree traversal functions all return void and take a function pointer as a parameter.
As the DFS/BFS function traverses the tree, it calls the function pointer on the tree node data as appropriate:
pre-order, post-order, or in-order for DFS or just in BFS.

Below you'll find all sorts of examples. A test program that creates two BinarySearchTrees, adds stuff,
and traverses the trees in all ways with my own test functions like Print, which works on string and int,
and Double, which works on int.

Additionally, create two functions of your own that can be passed into the tree traversal functions:
Capitalize - is a function that takes an std::string and capitalizes it. This will obviously fail to compile if
            passed into a binary search tree of any type other than std::string.
AccumulatePrint - is a templated function that takes the templated type and keeps and prints a running accumulation
            of all the visited nodes. For example, in intTree, it prints the running sum as each node is visited.
            For stringTree, it prints the string concatenation as each node is visited.
*/

#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#include <iostream>
#include <queue>
#include <cctype>

#include "Solution.h"

using namespace std;

namespace Test {
namespace MyFunctions {

template<class T>
void Print(T &t)
{
    cout << t << "\t";
}

void Double(int &n)
{
    n *= 2;
}

} // namespace MyFunctions
} // namespace Test

int main()
{
    {
        printf("Doing string stuff:\r\n");
        SPU::CSC2431::Homework4::BinarySearchTree<std::string> stringTree;

        stringTree.Add("foo");
        stringTree.Add("bar");
        stringTree.Add("baz");
        stringTree.Add("a");
        stringTree.Add("z");
        stringTree.Add("asdf");

        printf("PreorderDFS:\t");
        stringTree.PreorderDFS(Test::MyFunctions::Print);
		cout << endl;
		printf("PostorderDFS:\t");
		stringTree.PostorderDFS(Test::MyFunctions::Print);

        printf("\r\nPostorderDFS:\t");
        stringTree.PostorderDFS(Test::MyFunctions::Print);
        printf("\r\nPostorderDFS Accumulate:\t");
        stringTree.PostorderDFS(SPU::CSC2431::Homework4::AccumulatePrint);
        printf("\r\nPOSTORDERDFS capitalize:\t");
        stringTree.PostorderDFS(SPU::CSC2431::Homework4::Capitalize);
        stringTree.PostorderDFS(Test::MyFunctions::Print);
        printf("\r\nInorderDFS:\t");
        stringTree.InorderDFS(Test::MyFunctions::Print);
        printf("\r\nBFS:\t\t");
        stringTree.BFS(Test::MyFunctions::Print);
        printf("\r\n");
    }

    {
        printf("Doing int stuff\r\n");
        SPU::CSC2431::Homework4::BinarySearchTree<int> intTree;

        intTree.Add(5);
        intTree.Add(3);
        intTree.Add(7);
        intTree.Add(4);
        intTree.Add(8);
        intTree.Add(2);
        intTree.Add(6);
        intTree.Add(1);

        printf("PreorderDFS:\t");
        intTree.PreorderDFS(Test::MyFunctions::Print);
        printf("\r\nPostorderDFS:\t");
        intTree.PostorderDFS(Test::MyFunctions::Print);
        printf("\r\nInorderDFS:\t");
        intTree.InorderDFS(Test::MyFunctions::Print); 
        printf("\r\nInorderDFS Accumulate:\t");
        intTree.InorderDFS(SPU::CSC2431::Homework4::AccumulatePrint);
        printf("\r\nInorderDFSx2:\t");
        intTree.InorderDFS(Test::MyFunctions::Double);
        intTree.InorderDFS(Test::MyFunctions::Print);
        printf("\r\nBFS:\t\t");
        intTree.BFS(Test::MyFunctions::Print);
        printf("\r\n");
    }

    printf("\r\nPress any key to exit\r\n" \
           "Note: static or global variables can be falsely detected as a \"memory leak\".");
    getc(stdin);

    _CrtDumpMemoryLeaks();

    return 0;
}

