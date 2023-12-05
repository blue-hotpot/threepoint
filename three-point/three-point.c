#include "three-point.h"

void Initboard(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// void Initboard(char board[ROW][COL])
// {
//     int i,j;
//     for(i=0;i<ROW;i++)
//     {
//         for(j=0;j<COL;j++)
//         {
//             board[i][j]=' ';
//         }
//     }
// }

void Displayboard(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        // 打印数据
        // 打印分割行
        //|-----------|
        //|   |   |   |
        //|---|---|---|
        //|   |   |   |
        //|---|---|---|
        //  printf("|---|---|---|\n");
        //  printf("| %c | %c | %c |\n",board[i][0],board[i][1],board[i][2]);
        for (j = 0; j < col; j++)
            printf("|---");
        printf("|\n");
        for (j = 0; j < col; j++)
            printf("| %c ", board[i][j]);
        printf("|\n");
    }
    // printf("|---|---|---|\n");
    for (j = 0; j < col; j++)
        printf("|---");
    printf("|\n");
}

void playermove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
    while (1) // 循环检测
    {
        printf("please input position(x,y):");
        scanf("%d%d", &x, &y);
        // judge the position suitful?
        if ((x <= 0 || x > row) || (y <= 0 || y > col))
        {
            printf("the position is fail\n");
        }
        else
        {
            if (board[x - 1][y - 1] != ' ')
            {
                printf("the position is placed\n");
            }
            else
            {
                board[x - 1][y - 1] = '*';
                break;
            }
        }
    }
}

//未完成，感觉有点不好弄
// char judge(char board[ROW][COL], int row, int col,int x,int y)
// {
//     int i,j;
//     for(i=-1;i<2;i++)
//     {
//         if((x+i<0)||x+i>=row)
//         {
//             continue;
//         }
//         for(j=-1;j<2;j++)
//         {
//             if(y+j<0||y+j>=col)
//             {
//                 continue;
//             }
//             if(x==0&&y==0)
//             {
//                 continue;
//             }
//             if(board[x+i][y+j]==board[x][y])
//             {
                
//             }
//         }
//     }
// }

char judge(char board[ROW][COL],int row,int col)
{
    //win
    //fail
    //draw
    int flag=0;
    for(int i=0;i<row;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
        {
            return board[i][0];
        }
    }
    for(int j=0;j<col;j++)
    {
        if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[0][j]!=' ')
        {
            return board[0][j];
        }
    }
    if(board[1][1]==board[0][0]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    if(board[1][1]==board[0][2]&&board[1][1]==board[2][0]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    //判断是否平局
    if(full(board,row,col)==1)
    {
        return 'D';
    }
    return 'C';
}

int full(char board[ROW][COL],int row,int col)
{
    for(int j,i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j]==' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void computermove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
again:
    x = rand() % row;
    y = rand() % col;
    if (board[x][y] == ' ')
    {
        board[x][y] = '#';
    }
    else
    {
        goto again;
    }
}
