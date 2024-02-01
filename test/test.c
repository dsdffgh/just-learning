/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/23 22:02:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<math.h>
int main(){
    long long int t;
    scanf("%lld",&t);
    while(t--){
        //a[]  imply the relationship of the reflection 
        //store separate x(every number in x) in b[]
        //c[] are the value of the reflection
        long long int a[10],b[10],i,k,c[10],y=0,cnt=0;
        long long int x;
        /*input the corresponding sequence*/
        for(i=0;i<10;i++){
            scanf("%lld",&a[i]);
        }
        long long int median,median2;
        scanf("%lld%lld",&x,&k);
        /*store x in other variable(x will change next)*/
        median2=median=x;
        /*measure the length of x*/
        while(median){
            median=median/10;
            cnt++;
        }
        //get every  number of x and store every number in array
        while(k--) {
            for(i=0;i<cnt;i++){
                b[i]=x%10;
                x=x/10;
            }
            //follow every number in array get the corresponding number and store every number in another array
            for(i=0;i<cnt;i++) {
                c[i]=a[b[i]];}
            // turn every number into a integer
            for(i=0;i<cnt;i++){
                y+=c[i]*pow(10,i);
            }
            //get new median (x)
            median2+=y;
        }
        printf("%lld\n",median2);
    }

}
