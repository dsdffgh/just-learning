/*
 * =====================================================================================
 *
 *       Filename:  Huffman_Tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  3/2/2024 3:27:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <vector>

#define EXIT_SUCCESS 0

using namespace std;

typedef struct HuffmanNode
{
    int weight;             /* the weight of node */
    HuffmanNode *left;      /* left child */
    HuffmanNode *right;     /* right child */
    //HuffmanNode *parent;
} *HuffmanNodePtr;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreatHuffmanTree
 *  Description:  
 * =====================================================================================
 */
    HuffmanNodePtr
CreatHuffmanTree ( int WeightArr[], int length )
{
    vector< HuffmanNodePtr > forest;
    HuffmanNodePtr Root = nullptr;

    for ( int i = 0; i < length; i++ ) {
        HuffmanNodePtr tmp;
        tmp = new HuffmanNode ;
        tmp->weight = WeightArr[i];
        tmp->left = tmp->right = nullptr;

        forest.push_back( tmp );
    }

    for ( int j = 1; j < static_cast<int> (forest.size()); j++ )
    {
        //  intinalize Min_Second, Min_First
        int Min_First = -1, Min_Second = -1;
        for ( int i = 0; i < static_cast<int> (forest.size()) ;i++)
        {
            if (forest[i] != nullptr)
            {
                if( Min_First == -1 )
                {
                    Min_First = i;continue;
                }
                Min_Second = i;
                break;
            }
        }
        //  find the two nodes with the smallest weights
        for ( int i = Min_Second;  i < static_cast<int> (forest.size()) ; i++ )
        {
            if (forest[i] != nullptr)
            {

                if ( forest[i]->weight < forest[Min_First]->weight )
                {
                    Min_Second = Min_First;
                    Min_First = i;
                }
                else if ( forest[i]->weight < forest[Min_Second]->weight )
                {
                    Min_Second = i;
                }

            }
        }
        //  creat a new subtree
        Root = new HuffmanNode ;
        Root->weight = forest[Min_First]->weight + forest[Min_Second]->weight;
        Root->left = forest[Min_First];
        Root->right = forest[Min_Second];
        //  delete the two old nodes and add the new subtree
        forest[Min_First] = Root;
        forest[Min_Second] = nullptr;
    }
        return Root;
}		/* -----  end of function CreatHuffmanTree  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CalculateWPL
 *  Description:  BST
 * =====================================================================================
 */
    int
CalculateWPL ( HuffmanNodePtr current )
{
    if( current == nullptr )   return 0;
    queue< HuffmanNodePtr > bucket;
    int Deepth = -1;    //  the level of root is 0
    int WPL = 0;
    bucket.push( current );
    while ( !bucket.empty() )
    {
        int size = bucket.size();
        Deepth++;
        while ( size-- )
        {
            current = bucket.front();
            if ( !(current->left) && !(current->right) )    // find a leaf node,calculate
                WPL += ( current->weight * Deepth );
            bucket.pop();
            if( current->left )     bucket.push( current->left );
            if( current->right )     bucket.push( current->right );
        }
    }
    return WPL;
}		/* -----  end of function CalculateWPL  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    int TestNode1[] = { 2,3,4,7 };       // WPL = 2*2 + 3*2 + 4*2 + 7*2 = 37
    int TestNode3[] = { 2,7,4,5 };       // WPL = 7*1 + 5*2 + 2*3 + 4*3 = 35
    int TestNode2[] = { 1,2,2,5,9 };     // WPL = (1+2)*4 + 3*2 + 5*2 + 9 = 3+5+10+19 = 37

    int length;
    length = sizeof( TestNode1 ) / sizeof( *TestNode1 );
    HuffmanNodePtr Tree1 = CreatHuffmanTree( TestNode1, length );
    length = sizeof( TestNode2 ) / sizeof( *TestNode2 );
    HuffmanNodePtr Tree2 = CreatHuffmanTree( TestNode2, length );
    length = sizeof( TestNode3 ) / sizeof( *TestNode3 );
    HuffmanNodePtr Tree3 = CreatHuffmanTree( TestNode3, length );

    int WPL4Tree1 = CalculateWPL( Tree1 );
    int WPL4Tree2 = CalculateWPL( Tree2 );
    int WPL4Tree3 = CalculateWPL( Tree3 );

    cout << "Tree1's WPL is: " << WPL4Tree1 << endl;
    cout << "Tree2's WPL is: " << WPL4Tree2 << endl;
    cout << "Tree3's WPL is: " << WPL4Tree3 << endl;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
