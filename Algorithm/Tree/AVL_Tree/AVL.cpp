#include "AVL.h"

/*
 *	申请内存空间
 */
AVLNode *GetNewNode(int data)
{
	AVLNode *Node = new AVLNode;
	Node->data = data;
	Node->left = Node->right = nullptr;
	return Node;
}

/*
 *  左旋,冲突的左孩变右孩
 */
AVLNode* LeftRotate(AVLNode *root)
{
    AVLNode *current = root;
	if (!current)
	{
		return nullptr;
	}
    AVLNode *tmpForConflict = nullptr;
    if ( current->right ) {
        if ( current->right->left )
            tmpForConflict = current->right->left;
        current->right->left = current;
        root = current->right;
        current->right = tmpForConflict;
    }
    return root;
}

/*
 *  右旋，冲突的右孩变左孩
 */
AVLNode* RightRotate(AVLNode *root)
{
    AVLNode *current = root;
	if (!current)
	{
		return nullptr;
	}
    AVLNode *tmpForConflict = nullptr;
    if ( current->left ) {
        if ( current->left->right )
            tmpForConflict = current->left->right;
        current->left->right = current;
        root = current->left;
        current->left = tmpForConflict;
    }
    return root;
}

/*
 *  检查并旋转
 */
AVLNode* Rotate(AVLNode *current)
{
    if (!current)
        return nullptr;
    int currentBalancingFactor = GetBalancingFactor(current); 
    if ( currentBalancingFactor < -1 )     // current Node失衡，R_ 型，进一步判断
    {
        int current_RightBalancingFactor = GetBalancingFactor(current->right);
        if( current_RightBalancingFactor == -1 )  // RR型
            current = LeftRotate(current);
        else if ( current_RightBalancingFactor == 1 )    // RL
        {
            //AVLNode *tmpCurrentRoot = current;
            current->right = RightRotate(current->right);
            current = LeftRotate(current);
        }
    }
    else if ( currentBalancingFactor > 1 )  // current Node失衡，L_ 型，进一步判断
    {
        int current_LeftBalancingFactor = GetBalancingFactor(current->left);
        if( current_LeftBalancingFactor == 1 )   // LL 型
            current = RightRotate(current);
        else if ( current_LeftBalancingFactor == -1 )    // LR
        {
            //AVLNode *tmpCurrentRoot = current;
            current->left = LeftRotate(current->left);
            current = RightRotate(current);
        }
    }
    else
    {
        // do nothing
    }
    return current;
}

/*
 * 	插入节点
 */
AVLNode *Insert(AVLNode *current, int data)
{

	if (!current)
	{
		current = GetNewNode(data);
	}
	if (data < current->data)
		current->left = Insert(current->left, data);
	if (data > current->data)
		current->right = Insert(current->right, data);
    AVLNode *tmp = Rotate(current);
    if (current == tmp)
	    return current;
    else
        return tmp;
}

/*
 *	查找结点，返回节点指针
 */
AVLNode *Find(AVLNode *current, int data)
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
	return nullptr;
}

AVLNode *FindMax(AVLNode *current)
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

AVLNode *FindMin(AVLNode *current)
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
 *	after 删除节点, 对每个祖先检查并调整
 */
AVLNode *Delete(AVLNode *current, int data)
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
				AVLNode *temp = current;
				current = current->left;
				delete temp;
				temp = nullptr;
			}
			else
			{
				AVLNode *temp = current;
				current = current->right;
				delete temp;
				temp = nullptr;
			}
		}
		// two child
		else
		{
			AVLNode *temp = FindMin(current->right); // max for leftsubtree Or min for rightsubtree
			current->data = temp->data;
			temp = Delete(temp, data);
		}
        
	}
    current = Rotate(current);
	return current;
}

/*
 *	广度优先——层次遍历
 *
 */
void LevelOrderTraversal(AVLNode *current)
{
	queue<AVLNode *> bucket;
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
void preorderTraversal_recursion(AVLNode *current)
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
void preorderTraversal_Iterate(AVLNode *current)
{
	stack<AVLNode *> bucket;
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
void InorderTraverrsal(AVLNode *current)
{
	stack<AVLNode *> bucket;
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
void InorderTraverrsal_universal(AVLNode *current)
{
	stack<AVLNode *> bucket;
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
bool IsBST(AVLNode *current, int MinVal, int MaxVal)
{
	if (!current)
		return true;
	if (current->data > MinVal && current->data < MaxVal && IsBST(current->left, MinVal, current->data) && IsBST(current->right, current->data, MaxVal))
		return true;
	else
		return false;
}

bool IsAVL(AVLNode* root) {
    // An empty tree is an AVL tree
    if (root == nullptr) 
        return true;
    
    // Get the height of the left child
    int leftHeight = (root->left == nullptr) ? 0 : GetHeightOfNode(root->left);
    
    // Get the height of the right child
    int rightHeight = (root->right == nullptr) ? 0 : GetHeightOfNode(root->right);
    
    // Check if this node is balanced and if its subtrees are balanced
    return abs(leftHeight - rightHeight) <= 1 && IsAVL(root->left) && IsAVL(root->right);
}

/*
 * Find the inorder successor node.
 * If the right subtree exists, it is the minimum value of the right subtree.
 * If it doesn't exist, it is an ancestor that hasn't been accessed.
 */
AVLNode *Getsuccessor(AVLNode *root, int data)
{
	// Seach the Node - O(h)
	AVLNode *current = Find(root, data);
	if (!current)
		return nullptr;
	// Node has right subtree
	if ((current->right) != nullptr)
		return FindMin(current->right);
	// No right subtree
	else
	{
		AVLNode *successor = nullptr;
		AVLNode *ancestor = root;
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
ostream &operator<<(ostream &os, const AVLNode &Node)
{
	os << Node.data;
	return os;
}

/*
 *  获取节点高度
 */
int GetHeightOfNode(AVLNode *current)
{
    int height = 0;
    if(!current)
        return height;
    queue<AVLNode *> bucket;
    bucket.push(current);
    while(!bucket.empty())
    {
        int size = bucket.size();
        for(int i = 0; i < size ; i++)
        {
            current = bucket.front();
            bucket.pop();
            if( i == size-1 ) height++;
            if(current->left)
				bucket.push(current->left);
			if (current->right)
				bucket.push(current->right);
        }
    }
    return height;
}

/*
 *  获取平衡因子
 */
int GetBalancingFactor(AVLNode *current)
{
    if ( current )
        return ( GetHeightOfNode(current->left) - GetHeightOfNode(current->right) );
    else
        return (int) EOF;
}

/*
 *	主函数测试集
 */
int main()
{
    AVLNode *root = nullptr;             // 创建一个新的二叉搜索树
    int inputData[] = {14, 9, 5, 17, 11, 12, 7, 19, 16, 27, 8, 18, 23};  // 创建输入数据
    
    cout << "Inserting data into AVL tree...\n";
    for(int i = 0; i < 13; ++i) {  // 插入数据
        root = Insert(root, inputData[i]);
        cout << "Tree after inserting " << inputData[i] << ":\n";
        LevelOrderTraversal(root);  // 层次遍历输出 AVL 树
        cout << "\n";
        cout << "Balancing Factor of root after inserting " << inputData[i] << ": " << GetBalancingFactor(root) << "\n\n";
    }
    if( IsBST(root) && IsAVL(root)) {  // 检查AVL树是否平衡
        cout << "This tree is a valid AVL Tree!";
    } else {
        cout << "This tree is not a valid AVL Tree!";
    }
    
    cout << "Inorder traversal of the constructed AVL tree is: ";
    InorderTraverrsal(root);  // 中序遍历
    cout << endl;

    cout << "\nIs our constructed tree BSTree ? (1:Yes; 0:No) => " << IsBST(root) << "\n";  // 检查是否是 BST 树
    
    int deleteNode = 5;
    cout << "\nDeleting node " << deleteNode << " from the constructed AVL tree...\n";
    root = Delete(root, deleteNode);  // 删除节点
    cout << "After deleting, updated AVL Tree is: ";
    LevelOrderTraversal(root);  // 层次遍历输出 AVL 树
    cout << endl;

    if( IsBST(root) && IsAVL(root)) {  // 检查AVL树是否平衡
        cout << "This tree is a valid AVL Tree!";
    } else {
        cout << "This tree is not a valid AVL Tree!";
    }


    return 0;
}
