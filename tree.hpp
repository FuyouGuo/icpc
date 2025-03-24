#ifndef ICPC_BUILTIN_TREE_H
#define ICPC_BUILTIN_TREE_H
namespace icpc {
	typedef struct BinaryTreeNode<T> {
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		T         		val;
		BinaryTreeNode(T val, BinaryTreeNode* left, BinaryTreeNode* right){
			this->val=val;
			this->left=left;
			this->right=right;
		}
	}BinaryTreeNodeType;

	typedef struct RBTreeNode<T> {
		
	}RBTreeNodeType;
}
#endif