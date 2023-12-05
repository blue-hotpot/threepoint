#include"three-point.h"
//三子棋游戏

void interface()
{
    printf("####################\n");
    printf("###0-exit 1-began###\n");
    printf("####################\n");
}

int game()
{
    //数组存放数据
    char board[ROW][COL]={0};
    char ret;
    // Initboard(board,ROW,COL);
    Initboard(board,ROW,COL);
    //初始化棋盘
    Displayboard(board,ROW,COL);
    while(1)
    {
        //玩家下棋
        playermove(board,ROW,COL);
        Displayboard(board,ROW,COL);
        ret=judge(board,ROW,COL);
        if(ret!='C')
        {
            break;
        }
        //电脑下棋
        computermove(board,ROW,COL);
        Displayboard(board,ROW,COL);
        ret=judge(board,ROW,COL);
        if(ret!='C')
        {
            break;
        }
        
    }
    if(ret=='*')
    {
        printf("you win\n");
    }
    if(ret=='#')
    {
        printf("you fail\n");
    }
    if(ret=='D')
    {
        printf("draw\n");
    }
}

void test()
{
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        interface();
        printf("please input:");
        scanf("%d",&input);
        switch (input)
        {
        case 0:
            printf("exit the game\n");
            break;
        case 1:
            printf("begane the game\n");
            game();
            break;
        default:
            printf("please input again\n");
            break;
        }
    } while (input);
    
}

int main()
{
    test();
    return 0;
}