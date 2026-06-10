#include <iostream>
#include "BST.h"



BST::~BST()
{
	DestroyTree(Root);
}

void BST::Insert(int InKey)
{
	Root = InsertNode(Root, InKey);
}

void BST::Delete(int InKey)
{
	Root = DeleteNode(Root, InKey);
}

TreeNode* BST::Search(int InKey)
{
	return SearchNode(Root, InKey);
}

void BST::PrintPreOrder() const
{
	printf("PreOrder : ");
	PreOrderTraversal(Root);
	printf("\n");
}

void BST::PrintInOrder() const 
{
	printf("InOrder : ");
	InOrderTraversal(Root);
	printf("\n");
}

void BST::PrintPostOrder() const
{
	printf("PostOrder : ");
	PostOrderTraversal(Root);
	printf("\n");
}

TreeNode* BST::InsertNode(TreeNode* InNode, int InKey)
{
	if (InNode == nullptr)
	{
		return new TreeNode(InKey);
	}

	if (InKey < InNode->Key)
	{
		InNode->Left = InsertNode(InNode->Left, InKey);
	}
	else if (InKey > InNode->Key)
	{
		InNode->Right = InsertNode(InNode->Right, InKey);
	}
	else
	{
		//이진탐색 트리에서는 키가 중복되면 안됨
	}
	return InNode;
}

TreeNode* BST::DeleteNode(TreeNode* InNode, int InKey)
{
	if (InNode == nullptr)
	{
		return InNode;
	}

	if (InKey < InNode->Key)
	{
		InNode->Left = DeleteNode(InNode->Left, InKey);
	}
	else if (InKey > InNode->Key)
	{
		InNode->Right = DeleteNode(InNode->Right, InKey);
	}
	else
	{
		if (InNode->Left == nullptr)
		{
			TreeNode* Temp = InNode->Right;
			delete InNode;
			return Temp;
		}
		else if (InNode->Right == nullptr)
		{
			TreeNode* Temp = InNode->Left;
			delete InNode;
			return Temp;
		}
		
		TreeNode* Temp = FindMinNode(InNode->Right);
		InNode->Key = Temp->Key;
		InNode->Right = DeleteNode(InNode->Right, Temp->Key);

	}
	return InNode;
}

TreeNode* BST::SearchNode(TreeNode* InNode, int InKey)
{
	if (InNode == nullptr) return nullptr;

	if (InKey < InNode->Key)
	{
		return SearchNode(InNode->Left, InKey);
	}
	else if (InKey > InNode->Key)
	{
		return SearchNode(InNode->Right, InKey);
	}
	else
	{
		return InNode;
	}
}

TreeNode* BST::FindMinNode(TreeNode* InNode)
{
	while (InNode != nullptr && InNode->Left != nullptr)
	{
		InNode = InNode->Left;
	}
	return InNode;
}

TreeNode* BST::FindMaxNode(TreeNode* InNode)
{
	return nullptr;
}


void BST::PreOrderTraversal(const TreeNode* InNode) const 
{
	if (InNode == nullptr) return;
	printf("%d ", InNode->Key);
	PreOrderTraversal(InNode->Left);
	PreOrderTraversal(InNode->Right);
}

void BST::InOrderTraversal(const TreeNode* InNode) const
{
	if (InNode == nullptr) return;
	InOrderTraversal(InNode->Left);
	printf("%d ", InNode->Key);
	InOrderTraversal(InNode->Right);
}

void BST::PostOrderTraversal(const TreeNode* InNode) const
{
	if (InNode == nullptr) return;
	PostOrderTraversal(InNode->Left);
	PostOrderTraversal(InNode->Right);
	printf("%d ", InNode->Key);

}

void BST::DestroyTree(TreeNode* InNode)
{
	if (InNode != nullptr)
	{
		DestroyTree(InNode->Left);
		DestroyTree(InNode->Right);
		delete InNode;
		InNode = nullptr;
	}
}