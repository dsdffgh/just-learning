#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//内存泄漏
#if 0
//Simple Betting game
/*
    J K Q   computer shuffles cards
    player has to guess the position of queen
    if he wins ,he takes 3*bet
    if he losses ,he losses the bet amount
    player has $100 intaially
*/

int cash = 100;

void Play(int bet)
{
    char C[3] = {'J','K','Q'};

    printf("shuffling...\n");
    srand(time(NULL));//seeding random number generator


    int i;

    for ( i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }

    int playersGuess;

    printf("what's the position of queen - 1 , 2 , 3\n");
    scanf("%d",&playersGuess);
    if(C[playersGuess - 1] == 'Q'){
        cash += 3 * bet;
        printf("you win ! Result = %c%c%c \nTotal Cash = %d\n",C[0],C[1],C[2],cash);
    }
    else{
        cash -= bet;
        printf("you loose ! Result = %c%c%c \nTotal Cash = %d\n",C[0],C[1],C[2],cash);
    }
    
}

int main()
{
    int bet;

    printf("welcome to the Virtual Casino\n");
    printf("Total Cash = %d",cash);
    while(cash > 0){
        printf("你下注是？ $");
        scanf("%d",&bet);
        if(bet == 0 || bet > cash) break;;
        Play(bet);
    }
}
#endif

#if 1
int cash = 100;

void Play(int bet)
{
    char *C = (char *)malloc(1024 * 1024 * 1024 * sizeof(char)); //变成在堆上创建而不是栈
    C[0] = 'J';
    C[1] = 'K';
    C[2] = 'Q';

    printf("shuffling...\n");
    srand(time(NULL)); // seeding random number generator

    int i;

    for (i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }

    int playersGuess;

    printf("what's the position of queen - 1 , 2 , 3\n");
    scanf("%d", &playersGuess);
    if (C[playersGuess - 1] == 'Q')
    {
        cash += 3 * bet;
        printf("you win ! Result = %c%c%c \nTotal Cash = %d\n", C[0], C[1], C[2], cash);
    }
    else
    {
        cash -= bet;
        printf("you loose ! Result = %c%c%c \nTotal Cash = %d\n", C[0], C[1], C[2], cash);
    }
}

int main()
{
    int bet;

    printf("welcome to the Virtual Casino\n");
    printf("Total Cash = %d", cash);
    while (cash > 0)
    {
        printf("你下注是？ $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
            break;
        ;
        Play(bet);
    }
    // free(C);
}
#endif
/***********玩的时候查看内存更好理解************************************/