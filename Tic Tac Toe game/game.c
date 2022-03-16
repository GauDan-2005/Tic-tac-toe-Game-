#include<stdio.h>
#include<stdlib.h>

int check();
void mark(char);
void draw();
char pos[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int main()
{
    int gamestatus;
    char marking;
    player=1;

    do
    {
        draw();

        player=(player%2)?1:2;

        printf("Enter your position Player %d: ", player);
        scanf("%d", &choice);

        marking=(player==1)?'X':'O';

        mark(marking);

        gamestatus=check();

        player++;

    }while(gamestatus==-1);

    if(gamestatus==1)
        printf("==>\aPlayer %d win", --player);
    else
        printf("==>\aGame draw");

    return 0;
}
// CHECK: it checks if the player wins, draws or continues.
//        returns 1 if wins;        returns 0 if draws;         returns -1 if continues;
int check()
{
    int result=0;

    if(pos[1]==pos[2] && pos[1]==pos[3])
    {
        result=1;
    }
    else if(pos[3]==pos[6] && pos[9]==pos[3])
    {
        result=1;
    }
    else if(pos[7]==pos[8] && pos[8]==pos[9])
    {
        result=1;
    }
    else if(pos[1]==pos[4] && pos[1]==pos[7])
    {
        result=1;
    }
    else if(pos[1]==pos[5] && pos[1]==pos[9])
    {
        result=1;
    }
    else if(pos[3]==pos[5] && pos[7]==pos[3])
    {
        result=1;
    }
    else if(pos[5]==pos[2] && pos[5]==pos[8])
    {
        result=1;
    }
    else if(pos[4]==pos[5] && pos[4]==pos[6])
    {
        result=1;
    }
    else if(pos[1]!='1' && pos[2]!='2' && pos[3]!='3' && pos[4]!='4' && pos[5]!='5' && pos[6]!='6' && pos[7]!='7' && pos[8]!='8' && pos[9]!='9')
    {
        result=0;
    }
    else
    {
        result=-1;
    }
    return result;
}

// MARK:  it marks the box where player 1 or 2 places X or O;
void mark(char marking)
{
    if(pos[1]=='1' && choice==1)
    {
        pos[1]=marking;
    }
    else if(pos[2]=='2' && choice==2)
    {
        pos[2]=marking;
    }
    else if(pos[3]=='3' && choice==3)
    {
        pos[3]=marking;
    }
    else if(pos[4]=='4' && choice==4)
    {
        pos[4]=marking;
    }
    else if(pos[5]=='5' && choice==5)
    {
        pos[5]=marking;
    }
    else if(pos[6]=='6' && choice==6)
    {
        pos[6]=marking;
    }
    else if(pos[7]=='7' && choice==7)
    {
        pos[7]=marking;
    }
    else if(pos[8]=='8' && choice==8)
    {
        pos[8]=marking;
    }
    else if(pos[9]=='9' && choice==9)
    {
        pos[9]=marking;
    }
    else
    {
        printf("Invalid move");

        player--;
        int getch();
    }
}

// DRAW: it draws the checker board after the player enters the data;
void draw()
{
    system("cls");

    printf("\n\n\t\t\t\t\t\t\t\t\t --TIC TAC TOE--\n\n");
    printf("\t\t\t\t\t\t\t\t    Player 1(X)    VS    Player 2(O)\n\n\n");

    printf("   |   |   \n");
    printf(" %c | %c | %c \n", pos[1], pos[2], pos[3]);
    
    printf("___|___|___\n");
    printf("   |   |   \n");
    
    printf(" %c | %c | %c \n", pos[4], pos[5], pos[6]);
    
    printf("___|___|___\n");
    printf("   |   |   \n");
    
    printf(" %c | %c | %c \n", pos[7], pos[8], pos[9]);
    printf("   |   |   \n");
}