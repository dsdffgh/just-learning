#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
 *	二叉搜索树，左孩小于父节点，右孩大于父节点
 */
struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

/*
 *	申请内存空间
 */
BSTNode *GetNewNode(int data)
{
	BSTNode *Node = new BSTNode;
	Node->data = data;
	Node->left = Node->right = nullptr;
	return Node;
}

/*
 * 	插入节点
 */
BSTNode *Insert(BSTNode *current, int data)
{
	if (!current)
	{
		current = GetNewNode(data);
	};
	if (data < current->data)
		current->left = Insert(current->left, data);
	if (data > current->data)
		current->right = Insert(current->right, data);
	return current;
}

/*
 *	查找结点，返回节点指针
 */
BSTNode *Find(BSTNode *current, int data)
{
	if (!current)
	{
		cout << "NONE!" << endl;
		return nullptr;
	}
	if (data == current->data)
	{
		return current;
	}
	if (data < current->data)
		return Find(current->left, data);
	if (data > current->data)
		return Find(current->right, data);
}

BSTNode *FindMax(BSTNode *current)
{
	if (!current)
	{
		return nullptr;
	}
	while (current->right)
	{
		current = current->right;
	}
	return current;
}

BSTNode *FindMin(BSTNode *current)
{
	if (!current)
	{
		return nullptr;
	}
	while (current->left)
	{
		current = current->left;
	}
	return current;
}

/*
 *	删除节点
 */
BSTNode *Delete(BSTNode *current, int data)
{
	if (!current)
	{
		return nullptr;
	}
	if (data > current->data)
		current->right = Delete(current->right, data);
	else if (data < current->data)
		current->left = Delete(current->left, data);
	else // I found you , TO Delete
	{
		// no child
		if (!current->left && !current->right)
		{
			delete current;
			current = nullptr;
		}
		// one child
		else if (!current->left || !current->right)
		{
			if (current->left)
			{
				BSTNode *temp = current;
				current = current->left;
				delete temp;
				temp = nullptr;
			}
			else
			{
				BSTNode *temp = current;
				current = current->right;
				delete temp;
				temp = nullptr;
			}
		}
		// two child
		else
		{
			BSTNode *temp = FindMin(current->right); // max for leftsubtree Or min for rightsubtree
			current->data = temp->data;
			temp = Delete(temp, data);
		}
	}
	return current;
}

/*
 *	广度优先——层次遍历
 *
 */
void LevelOrderTraversal(BSTNode *current)
{
	queue<BSTNode *> bucket;
	if (!current)
		return;
	bucket.push(current);
	while (!bucket.empty())
	{
		int size = bucket.size();
		cout << "[ ";
		for (int i = 0; i < size; i++)
		{
			current = bucket.front();
			cout << current->data << ' ';
			bucket.pop();
			if (current->left)
				bucket.push(current->left);
			if (current->right)
				bucket.push(current->right);
		}
		cout << "]";
	}
}

/*
 *	深度优先——递归遍历
 */
void preorderTraversal_recursion(BSTNode *current)
{
	if (!current)
		return;
	cout << current->data << ' ';
	if (current->left)
		preorderTraversal_recursion(current->left);
	if (current->right)
		preorderTraversal_recursion(current->right);
}
/*
 *	深度优先——迭代遍历
 */
void preorderTraversal_Iterate(BSTNode *current)
{
	stack<BSTNode *> bucket;
	if (!current)
		return;
	bucket.push(current);
	while (!bucket.empty())
	{
		current = bucket.top();
		cout << current->data << ' ';
		bucket.pop();
		if (current->right)
			bucket.push(current->right);
		if (current->left)
			bucket.push(current->left);
	}
}
// 中序和前序的迭代法是有点不一样的
// 因为前序遍历的顺序是中左右，先访问的元素是中间节点，要处理的元素也是中间节点，所以刚刚才能写出相对简洁的代码，因为要访问的元素和要处理的元素顺序是一致的，都是中间节点。
// 中序遍历是左中右，先访问的是二叉树顶部的节点，然后一层一层向下访问，直到到达树左面的最底部，再开始处理节点（也就是在把节点的数值放进result数组中），这就造成了处理顺序和访问顺序是不一致的。
void InorderTraverrsal(BSTNode *current)
{
	stack<BSTNode *> bucket;
	if (!current)
		return;
	while (current || !bucket.empty())
	{
		if (current)
		{
			bucket.push(current);
			current = current->left;
		}
		else
		{
			current = bucket.top();
			cout << current->data << ' '; // left
			bucket.pop();				  // middle
			current = current->right;
		}
	}
}
// 后序遍历是左右中，反转中右左就可以了

/*
 *	深度优先——迭代遍历——统一格式
 */
void InorderTraverrsal_universal(BSTNode *current)
{
	stack<BSTNode *> bucket;
	if (!current)
		return;
	bucket.push(current);
	while (!bucket.empty())
	{

		current = bucket.top();
		if (current)
		{
			bucket.pop(); // Prevent duplication
			if (current->right)
				bucket.push(current->right);
			bucket.push(current);
			bucket.push(nullptr);
			if (current->left)
				bucket.push(current->left);
		}
		else
		{
			bucket.pop();
			current = bucket.top();
			bucket.pop();
			cout << current->data << ' ';
		}
	}
}
/*
 *	检查是否为二叉搜索树
 */
bool IsBST(BSTNode *current, int MinVal = INT32_MIN, int MaxVal = INT32_MAX)
{
	if (!current)
		return true;
	if (current->data > MinVal && current->data < MaxVal && IsBST(current->left, MinVal, current->data) && IsBST(current->right, current->data, MaxVal))
		return true;
	else
		return false;
}

/*
 * Find the inorder successor node.
 * If the right subtree exists, it is the minimum value of the right subtree.
 * If it doesn't exist, it is an ancestor that hasn't been accessed.
 */
BSTNode *Getsuccessor(BSTNode *root, int data)
{
	// Seach the Node - O(h)
	BSTNode *current = Find(root, data);
	if (!current)
		return nullptr;
	// Node has right subtree
	if ((current->right) != nullptr)
		return FindMin(current->right);
	// No right subtree
	else
	{
		BSTNode *successor = nullptr;
		BSTNode *ancestor = root;
		while (ancestor != current) // travsersal
		{
			if (ancestor->data > data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}

/*
 *重载 << 运算符
 */
ostream &operator<<(ostream &os, const BSTNode &Node)
{
	os << Node.data;
	return os;
}

/*
 *	主函数测试集
 */
int main()
{
	// 创建一个新的二叉搜索树
	BSTNode *root = nullptr;

	// 插入节点
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	// 打印二叉搜索树
	cout << "Level order traversal: ";
	LevelOrderTraversal(root);
	cout << endl;

	cout << "recursion for Preorder traversal: ";
	preorderTraversal_recursion(root);
	cout << endl;

	cout << "Inorder traversal: ";
	InorderTraverrsal(root);
	cout << endl;

	// 查找节点
	BSTNode *found = Find(root, 10);
	if (found != nullptr)
	{
		cout << "Found the node with value 10" << endl;
	}
	else
	{
		cout << "Did not find the node with value 10" << endl;
	}

	// 删除节点
	root = Delete(root, 20);

	// 再次打印二叉搜索树
	cout << "Iterate for Preorder traversal after deleting node with value 20:";
	preorderTraversal_Iterate(root);
	cout << endl;

	// 检查是否为二叉搜索树
	if (IsBST(root))
	{
		cout << "The tree is a binary search tree." << endl;
	}
	else
	{
		cout << "The tree is not a binary search tree." << endl;
	}

	// 找到中序后继节点
	BSTNode *theNode = nullptr;
	theNode = Getsuccessor(root, 6);
	if (theNode != nullptr)
	{
		cout << "the inorder successor node of " << 6 << " is " << theNode->data << endl;
	}
	else
	{
		cout << "Node not found in the tree." << endl;
	}

	theNode = Getsuccessor(root, 8);
	if (theNode != nullptr)
	{
		cout << "the inorder successor node of " << 8 << " is " << theNode->data << endl;
	}
	else
	{
		cout << "Node not found in the tree." << endl;
	}

	theNode = Getsuccessor(root, 12);
	if (theNode != nullptr)
	{
		cout << "the inorder successor node of " << 12 << " is " << theNode->data << endl;
	}
	else
	{
		cout << "Node not found in the tree." << endl;
	}

	theNode = Getsuccessor(root, 20);
	if (theNode != nullptr)
	{
		cout << "the inorder successor node of " << 20 << " is " << theNode->data << endl;
	}
	else
	{
		cout << "Node not found in the tree." << endl;
	}

	return 0;
}
/*
for
	theNode = Getsuccessor(root, 8);// 找到中序后继节点
	BSTNode *theNode = nullptr;
	theNode = Getsuccessor(root, 6);
	cout << "the inorder successor node of " << 6 << " is " << theNode->data << endl;
	theNode = Getsuccessor(root, 8);
	cout << "the inorder successor node of " << 8 << " is " << theNode->data << endl;
	theNode = Getsuccessor(root, 12);
	cout << "the inorder successor node of " << 12 << " is " << theNode->data << endl;
	theNode = Getsuccessor(root, 20);
	cout << "the inorder successor node of " << 20 << " is " << theNode->data << endl;

The issue with the unexpected program termination after the Getsuccessor function calls is likely related to the fact that the function is not guarded against the case where the target node to find a successor(root, 8);
If the Getsuccessor function is called with a value that doesn't exist in the tree (e.g., 6, 8, 12, 20 in your code), it may not return a valid node, leading to undefined behavior when you try to access the data member of the returned node. This can cause a segmentation fault or other runtime errors, which can result in program termination.
*/
