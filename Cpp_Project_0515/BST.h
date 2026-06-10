#pragma once

struct TreeNode
{
	int Key = 0;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;

	TreeNode() = default;
	TreeNode(int InKey) : Key(InKey) {}
};
class BST
{

public:

private:
	TreeNode* Root = nullptr;


public:
	BST() = default;
	~BST();

	void				Insert(int InKey);
	void				Delete(int InKey);
	TreeNode*			Search(int InKey);

	void				PrintPreOrder() const;
	void				PrintInOrder() const;
	void				PrintPostOrder() const;

	inline bool			IsEmpty() const { return Root == nullptr; }

private:
	TreeNode*			InsertNode(TreeNode* InNode, int InKey);
	TreeNode*			DeleteNode(TreeNode* InNode, int InKey);
	TreeNode*			SearchNode(TreeNode* InNode, int InKey);
	TreeNode*			FindMinNode(TreeNode* InNode);
	TreeNode*			FindMaxNode(TreeNode* InNode);

	void				PreOrderTraversal(const TreeNode* InNode) const;
	void				InOrderTraversal(const TreeNode* InNode) const;
	void				PostOrderTraversal(const TreeNode* InNode) const;

	void				DestroyTree(TreeNode* InNode);

};

