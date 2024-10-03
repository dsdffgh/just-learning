#ifndef __AVL_H__
#define __AVL_H_

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <cstdint>
using namespace std;

/*
 *	AVL树，也是二叉搜索树，左孩小于父节点，右孩大于父节点
 */
struct AVLNode
{
	int data;
	AVLNode *left;
	AVLNode *right;
};

AVLNode *GetNewNode(int data);
AVLNode *LeftRotate(AVLNode *current);
AVLNode *RightRotate(AVLNode *current);
AVLNode *Rotate(AVLNode *current);
AVLNode *Insert(AVLNode *current, int data);
AVLNode *Find(AVLNode *current, int data);
AVLNode *FindMax(AVLNode *current);
AVLNode *FindMin(AVLNode *current);
AVLNode *Delete(AVLNode *current, int data);
void LevelOrderTraversal(AVLNode *current);
void preorderTraversal_recursion(AVLNode *current);
void preorderTraversal_Iterate(AVLNode *current);
void InorderTraverrsal(AVLNode *current);
void InorderTraverrsal_universal(AVLNode *current);
bool IsBST(AVLNode *current, int MinVal = INT32_MIN, int MaxVal = INT32_MAX);
bool isAVL(AVLNode* root);
AVLNode *Getsuccessor(AVLNode *root, int data);
ostream &operator<<(ostream &os, const AVLNode &Node);
int GetHeightOfNode(AVLNode *current);
int GetBalancingFactor(AVLNode *current);

#endif
