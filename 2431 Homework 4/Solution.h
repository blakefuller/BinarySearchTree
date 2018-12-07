#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

namespace SPU {
namespace CSC2431 {
namespace Homework4 {

template<class T>
class BinarySearchTree
{
public:
	void Add(T add)
	{
		root = Insert(root, add);
	};

	void PreorderDFS(void (*func) (T&))
	{
		PreOrderTraverse(root, func);
	};

	void PostorderDFS(void (*func) (T&))
	{
		PostOrderTraverse(root, func);
	};

	void InorderDFS(void (*func) (T&))
	{
		InOrderTraverse(root, func);
	};

	void BFS(void (*func) (T&))
	{
		BFSTraverse(root, func);
	};

private:
	template<class T>
	struct TreeNode
	{
		T item;
		TreeNode<T>* left;
		TreeNode<T>* right;
	};

	TreeNode<T>* root = NULL;

	TreeNode<T>* MakeNewNode(T data)
	{
		TreeNode<T>* newNode = new TreeNode<T>;
		newNode->item = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	};

	TreeNode<T>* Insert(TreeNode<T>* node, T data)
	{
		if (node == NULL)				//if tree is empty
			node = MakeNewNode(data);

		else if (data <= node->item)	//data is less or equal to
			node->left = Insert(node->left, data);

		else if (data > node->item)		//data is greater than
			node->right = Insert(node->right, data);

		return node;
	};

	void PreOrderTraverse(TreeNode<T>* node, void (*func) (T&) )
	{
		if (node != NULL)				//visit node
			func(node->item);
		if (node->left != NULL)			//if there is a node to the left
			PreOrderTraverse(node->left, func);
		if (node->right != NULL)		//if there is a node to the right
			PreOrderTraverse(node->right, func);
	};

	void PostOrderTraverse(TreeNode<T>* node, void (*func) (T&) )
	{
		if (node->left != NULL)			//if there is a node to the left
			PostOrderTraverse(node->left, func);
		if (node->right != NULL)		//if there is a node to the right
			PostOrderTraverse(node->right, func);
		if (node != NULL)				//visit node
			func(node->item);
	};

	void InOrderTraverse(TreeNode<T>* node, void(*func) (T&))
	{
		if (node->left != NULL)			//if there is a node to the left
			InOrderTraverse(node->left, func);
		if (node != NULL)				//visit node
			func(node->item);
		if (node->right != NULL)		//if there is a node to the right
			InOrderTraverse(node->right, func);
	};

	void BFSTraverse(TreeNode<T>* node, void(*func) (T&))
	{
		if (node == NULL)				//end if tree is empty
			return;
		queue<TreeNode<T>*> q;
		q.push(node);
		while (!q.empty())				//loop until tree is empty
		{
			TreeNode<T>* curNode = q.front();
			q.pop();
			func(curNode->item);
			if (curNode->left != NULL)
				q.push(curNode->left);
			if (curNode->right != NULL)
				q.push(curNode->right);
		}
	};
};

//AccumulatePrint - is a templated function that takes the templated type and keeps and prints a running accumulation
//				of all the visited nodes.For example, in intTree, it prints the running sum as each node is visited.
//				For stringTree, it prints the string concatenation as each node is visited.
template<class T>
void AccumulatePrint(T& t)
{
	static T total;
	total += t;
	cout << total << "\t";
};

//Capitalize - is a function that takes an std::string and capitalizes it.This will obviously fail to compile if
//				passed into a binary search tree of any type other than std::string.
void Capitalize(std::string& s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		s.at(i) = toupper(s.at(i));
};

}	//namespace Homework4
}	//namespace CSC2431
}	//namespace SPU