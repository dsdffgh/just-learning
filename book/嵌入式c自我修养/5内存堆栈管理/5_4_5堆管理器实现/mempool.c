/*
 * =====================================================================================
 *
 *       Filename:  mempool.c
 *
 *    Description:  嵌入式裸机环境下的堆管理器
 *
 *        Version:  1.0
 *        Created:  01/03/24 19:03:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include    <stdio.h>
#include	<stdlib.h>

#define POOL_SIZE 1088            /*  */
#define CHUNK_NUM 16            /*  */

struct chunk
{
    unsigned char *addr;
    char          used;
    unsigned char size;
};

char mempool[POOL_SIZE];
struct chunk bitmap[CHUNK_NUM];


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pool_init
 *  Description:  
 * =====================================================================================
 */
void pool_init ( <+argument_list+> )
{
    int i;
    char *p = &mempool[0];

    for ( int i = 0;i < CHUNK_NUM {+CONDITION+}; i++{+INCREMENT+} ) {
        p = p + i*8;
        bitmap[i].addr = p;
        bitmap[i].size = 8 * (i + 1);
        bitmap[i].used = 0;
    }
    return <+return_value+>;
}		/* -----  end of function pool_init  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bitmap_index
 *  Description:  
 * =====================================================================================
 */
int bitmap_index ( int nbytes )
{
    if(nbytes %8 = 0)
        return nbytes / 8 - 1;
    else
        return nbytes/8;
}		/* -----  end of function bitmap_index  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pool_initpool_malloc
 *  Description:  
 * =====================================================================================
 */
void* pool_malloc ( int nbytes<+argument_list+> )
{
    int i;
    int index;
    index = bitmap_index(nbytes);
    return <+return_value+>;
}		/* -----  end of function pool_initpool_malloc  ----- */
int main ( int argc, char *argv[] )
{
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
