/*
 * =====================================================================================
 *
 *       Filename:  test-1227.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/28/23 21:52:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include<stdio.h>
struct nickname{
    char a[20];
    int cnt;
};
int main() {
    int t,i,j,temp,median[100];
    scanf("%d",&t);
    while(t--){
       int n;
       scanf("%d",&n);
    struct nickname name[n];
    for(i=0;i<n;i++){
       scanf("%s%d",name[i].a,&name[i].cnt);
    }
    for(i=0;i<n;i++){
       median[i]=name[i].cnt;
    }
    for(i=0;i<n-1;i++){
       for(j=0;j<n-1-i;j++){
          if(median[j]<median[j+1]){
             temp=median[j];
             median[j]=median[j+1];
             median[j+1]=temp;
          }
       }
    }
    int b=0;
    while(b<n){
    for(i=0;i<n;i++){
       if(median[b]==name[i].cnt)
        {printf("%s\n",name[i].a);
       b++;
        break;}
    }
    }
    }
}
