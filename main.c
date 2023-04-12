#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#define ROW 10 //satir
#define COLUMN 10 //sutun
#define SIZE 5 // for user input

int TakeLocationFromUser();
int ControlForStop(char board[ROW][COLUMN]); // board belongs to against one
void DrawBoard(char board[ROW][COLUMN]);
void PrintBoardForUser(char board[ROW][COLUMN]); //board belongs to user
void PrintBoardForComputer(char board[ROW][COLUMN]); //board belongs to computer
void PlaceShipForComputer(char board[ROW][COLUMN], int x); //board belongs to computer
void PlaceShipForUser(char board[ROW][COLUMN], int x, char ship[12]); //board belongs to user
void ShootingForComputerHard(char board[ROW][COLUMN]); //board belongs to user
void ShootingForUserHard(char board[ROW][COLUMN]); //board belongs to computer
void ShootingForComputerEasy(char board[ROW][COLUMN]); //board belongs to user
void ShootingForUserEasy (char board[ROW][COLUMN]); //board belongs to computer
void PlayTheGame(char boardC[ROW][COLUMN], char boardU[ROW][COLUMN]); // first one for computer board second one for user's
void Rules();

int main()
{
    char userBoard[ROW][COLUMN], computerBoard[ROW][COLUMN];
    Rules();
    DrawBoard(userBoard);
    DrawBoard(computerBoard);
    PlaceShipForComputer(computerBoard, 5);
    PlaceShipForComputer(computerBoard, 4);
    PlaceShipForComputer(computerBoard, 3);
    PlaceShipForComputer(computerBoard, 3);
    PlaceShipForComputer(computerBoard, 2);
    PrintBoardForUser(userBoard);
    printf("\n");
    PlaceShipForUser(userBoard, 5, "Carrier");
    PrintBoardForUser(userBoard);
    printf("\n");
    PlaceShipForUser(userBoard, 4, "Battleship");
    PrintBoardForUser(userBoard);
    printf("\n");
    PlaceShipForUser(userBoard, 3, "Cruiser");
    PrintBoardForUser(userBoard);
    printf("\n");
    PlaceShipForUser(userBoard, 3, "Submarine");
    PrintBoardForUser(userBoard);
    printf("\n");
    PlaceShipForUser(userBoard, 2, "Destroyer");
    PrintBoardForUser(userBoard);
    printf("\n");
    PlayTheGame(computerBoard,userBoard);

    return 0;
}

void DrawBoard(char board[ROW][COLUMN])
{
    int i, j;
    for(i=0; i<ROW; i++)
    for(j=0; j<COLUMN; j++)
    board[i][j]='~';
}
void PrintBoardForUser(char board[ROW][COLUMN])
{
    printf("\t\tUSER'S BOARD");
    int i, j;
    printf("\n   ");
    for(i=3; i<(COLUMN*4)+4; i++)
    printf("-");
    printf("\n   |");
    for(i=0; i<COLUMN; i++)
    {
        printf("%2d |",i+1);
    }
    printf("\n");
    for(i=0; i<(COLUMN*4)+4; i++)
    printf("-");
    printf("\n");
    for(i=0; i<ROW; i++)
    {
        printf("%2d |",i+1);
        for(j=0; j<COLUMN; j++)
        {
            printf("%2c  ",board[i][j]);
        }
    printf("\n----\n");
    }
}
void PlaceShipForComputer(char board[ROW][COLUMN], int x)
{
    srand(time(NULL));
    int i, j, v, h, v_, h_, va, vb, ha, hb, v_or_h;
    int pass = 0;
    do
    {
        pass = 0;
        v = rand()%10;
        h = rand()%10;
        v_or_h = rand()%2;
        if(v == 0)
        v_ = 1;
        else if(v == 9)
        v_ = 8;
        else
        v_ = v;
        if(h == 0)
        h_ = 1;
        else if(h == 9)
        h_ = 8;
        else
        h_ = h;
        if(v_or_h == 0)  // if v_or_h = 0 it will be vertical placement
        {
            if(v <= 10-x)
            {
                if(h == 9)
                {
                    ha = 8;
                    hb = h;
                }
                else if(h == 0)
                {
                    hb = 1;
                    ha = h;
                }
                else
                {
                    ha = h;
                    hb = h;
                }
                for(i=v_-1; i<=v+x; i++)
                {
                    for(j=hb-1; j<=ha+1; j++)
                    {
                        if(board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            break;
                        }
                    }
                }
                if (pass == 0)
                {
                    for(i=0; i<x; i++)
                    board[v+i][h] = '%';
                }
            }
            else
            {
                if(h == 9)
                {
                    ha = 8;
                    hb = h;
                }
                else if(h == 0)
                {
                    hb = 1;
                    ha = h;
                }
                else
                {
                    ha = h;
                    hb = h;
                }
                for(i=v-x; i<=v_+1; i++)
                {
                    for(j=hb-1; j<=ha+1; j++)
                    {
                        if (board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            break;
                        }
                    }
                }
                if(pass == 0)
                {
                    for (i=0; i<x; i++)
                    board[v-i][h] = '%';
                }
            }
        }
        else   // v_or_h = 1 will be horizontal placement
        {
            if(h <=10-x)
            {
                if(v == 9)
                {
                    va = 8;
                    vb = v;
                }
                else if(v == 0)
                {
                    vb = 1;
                    va = v;
                }
                else
                {
                    va = v;
                    vb = v;
                }
                for(i=vb-1; i<=va+1; i++)
                {
                    for(j=h_-1; j<=h+x; j++)
                    {
                        if(board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            break;
                        }
                    }
                }
                if(pass == 0)
                {
                    for(i=0; i<x; i++)
                    board[v][h+i] = '%';
                }
            }
            else
            {
                if(v == 9)
                {
                    va = 8;
                    vb = v;
                }
                else if(v == 0)
                {
                    vb = 1;
                    va = v;
                }
                else
                {
                    va = v;
                    vb = v;
                }
                for(i=vb-1; i<=va+1; i++)
                {
                    for(j=h-x; j<=h_+1; j++)
                    {
                        if (board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            break;
                        }
                    }
                }
                if(pass == 0)
                {
                    for (i=0; i<x; i++)
                    board[v][h-i] = '%';
                }
            }
        }
    }
    while(pass);
}
int TakeLocationFromUser()
{
    int pass = 0, i;
    do
    {
        pass = 0;
        char location[SIZE];
        fgets(location, SIZE, stdin);
        for(i = 0; location[i] != '\n'; i++)
        {
            if(isdigit(location[i]) == 0)
            {
                pass = 1;
                printf("Make sure you have entered a number value!\n");
                break;
            }
        }
        if (pass == 0)
        {
            int value = atoi(location);
            if(value>=1 && value<=10)
            return value;
            else
            {
                printf("Your number must be in range [1,10]\n");
                pass = 1;
            }
        }
    }
    while(pass);
}
void PlaceShipForUser(char board[ROW][COLUMN], int x, char ship[12])
{
    int i, j, v, v_, h, h_, ha, hb, va, vb, failureCounter = 0;
    int isVorH;
    char vorh[SIZE];
    char v_or_h;
    int pass = 0;
    do                             // Taking right values from user
    {
        pass = 0;
        failureCounter = 0;
        printf("\nChoose a coordinate which will be your %s's (%d unit) prow.\n", ship, x);
        printf("x axis : ");
        h = TakeLocationFromUser();
        printf("y axis : ");
        v = TakeLocationFromUser();
        printf("(%d,%d)\n",h--,v--);
        if(v == 0)
        v_ = 1;
        else if(v == 9)
        v_ = 8;
        else
        v_ = v;
        if(h == 0)
        h_ = 1;
        else if(h == 9)
        h_ = 8;
        else
        h_ = h;
        do
        {
            printf("How  will your ship placement be.\nVertical - press (V)\nHorizontal - press (H)\nWhat is your choice : ");
            isVorH = 0;
            fgets(vorh, SIZE, stdin);
            if (vorh[0]== 'V' || vorh[0] == 'v')
            {
                isVorH = 0;
                v_or_h = 'V';
            }
            else if (vorh[0] == 'H' || vorh[0] == 'h')
            {
                isVorH = 0;
                v_or_h = 'H';
            }
            else
            {
                printf("\n\nFailure input!!!! Please try again.\n\n");
                isVorH = 1;
            }
        }
        while(isVorH);


        if(v_or_h == 'V')  // if v_or_h = V it will be vertical placement
        {
            if(v <= 10-x)
            {
                if(h == 9)
                {
                    ha = 8;
                    hb = h;
                }
                else if(h == 0)
                {
                    hb = 1;
                    ha = h;
                }
                else
                {
                    ha = h;
                    hb = h;
                }
                for(i=v_-1; i<=v+x; i++)
                {
                    for(j=hb-1; j<=ha+1; j++)
                    {
                        if(board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            if(failureCounter == 0)
                            printf("\nThe ships cannot touch each other. Please check rules again.\n");
                            failureCounter++;
                            break;
                        }
                    }
                }
                if (pass == 0)
                {
                    for(i=0; i<x; i++)
                    board[v+i][h] = '%';
                }
            }
            else
            {
                if(h == 9)
                {
                    ha = 8;
                    hb = h;
                }
                else if(h == 0)
                {
                    hb = 1;
                    ha = h;
                }
                else
                {
                    ha = h;
                    hb = h;
                }
                for(i=v-x; i<=v_+1; i++)
                {
                    for(j=hb-1; j<=ha+1; j++)
                    {
                        if (board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            if(failureCounter == 0)
                            printf("\nThe ships cannot touch each other. Please check rules again.\n");
                            failureCounter++;
                            break;
                        }
                    }
                }
                if(pass == 0)
                {
                    for (i=0; i<x; i++)
                    board[v-i][h] = '%';
                }
            }
        }
        else  // v_or_h = H it will be horizontal placement
        {
            if(h<=10-x)
            {
                if(v == 9)
                {
                    va = 8;
                    vb = v;
                }
                else if(v == 0)
                {
                    vb = 1;
                    va = v;
                }
                else
                {
                    va = v;
                    vb = v;
                }
                for(i=vb-1; i<=va+1; i++)
                {
                    for(j=h_-1; j<=h+x; j++)
                    {
                        if(board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            if(failureCounter == 0)
                            printf("\n%c   %d %d\n", board[i][j],i,j);//printf("\nThe ships cannot touch each other. Please check rules again.\n");
                            failureCounter++;
                            break;
                        }
                    }
                }
                if(pass == 0)
                {
                    for(i=0; i<x; i++)
                    board[v][h+i] = '%';
                }
            }
            else
            {
                if(v == 9)
                {
                    va = 8;
                    vb = v;
                }
                else if(v == 0)
                {
                    vb = 1;
                    va = v;
                }
                else
                {
                    va = v;
                    vb = v;
                }
                for(i=vb-1; i<=va+1; i++)
                {
                    for(j=h-x; j<=h_+1; j++)
                    {
                        if (board[i][j] == '%')       //controlling if it is convenient
                        {
                            pass = 1;
                            if(failureCounter == 0)
                            printf("\nThe ships cannot touch each other. Please check rules again.\n");
                            failureCounter++;
                            break;
                        }
                    }
                }
                if(pass == 0)
                {
                    for (i=0; i<x; i++)
                    board[v][h-i] = '%';
                }
            }
        }
    }
    while(pass);
}
void PrintBoardForComputer(char board[ROW][COLUMN])
{
    printf("\t\tCOMPUTER'S BOARD");
    int i, j;
    printf("\n   ");
    for(i=3; i<(COLUMN*4)+4; i++)
    printf("-");
    printf("\n   |");
    for(i=0; i<COLUMN; i++)
    {
        printf("%2d |",i+1);
    }
    printf("\n");
    for(i=0; i<(COLUMN*4)+4; i++)
    printf("-");
    printf("\n");
    for(i=0; i<ROW; i++)
    {
        printf("%2d |",i+1);
        for(j=0; j<COLUMN; j++)
        {
            if(board[i][j] == '%')
            printf("%2c  ",'~');
            else
            printf("%2c  ",board[i][j]);
        }
    printf("\n----\n");
    }
}
void ShootingForComputerHard(char board[ROW][COLUMN])
{
    srand(time(NULL));
    int i, j, ia,ja, ib, jb, h, v, pass = 1, m_or_xpass = 0;
    int mindv, mindh;
    int mindRandom;
    int beRandom = 0;
    printf("Your opponent is preparing to shoot.\n\n");
    do
    {
        for(i = 0; i<ROW; i++)
        {
            for(j = 0; j< COLUMN; j++)
            {
                if (i == 0)
                ia = 1;
                else
                ia = i;
                if (j == 0)
                ja = 1;
                else
                ja = j;
                if (i == 9)
                ib = 8;
                else
                ib = i;
                if (j == 9)
                jb = 8;
                else
                jb = j;
                if(board[i][j] == 'X' && (board[ib+1][j] == '%' || board[ia-1][j] == '%' || board[i][jb+1] == '%' || board[i][ja-1] == '%'))
                {
                    mindv = i;
                    mindh = j;
                    beRandom = 1;
                }
            }
        }
        if(beRandom == 1 && (board[mindv+1][mindh] == '%' || board[mindv-1][mindh] == '%' || board[mindv][mindh+1] == '%' || board[mindv][mindh-1] == '%'))
        {
            do
            {
                if((board[mindv][mindh+1] == 'M' || board[mindv][mindh-1] == 'M') || (board[mindv+1][mindh] == '%' || board[mindv-1][mindh] == '%'))
                mindRandom = 0;
                else if ((board[mindv+1][mindh] == 'M' || board[mindv-1][mindh] == 'M') || (board[mindv][mindh+1] == '%' || board[mindv][mindh-1] == '%') )
                mindRandom = 1;
                else
                mindRandom = rand()%2; // 0 vertical  1 horizontal
                if(mindRandom == 0 )
                {
                    if(board[mindv+1][mindh] == '%' && mindv+1 != 10)
                    {
                        v = mindv+1;
                        h = mindh;
                        break;
                    }
                    else if(board[mindv-1][mindh] == '%' && mindv-1 != -1)
                    {
                        v = mindv-1;
                        h = mindh;
                        break;
                    }
                    else
                    {
                        if (mindv-1 == -1)
                        v = mindv+1;
                        else
                        v = mindv-1;
                        h = mindh;
                        break;
                    }
                }
                else if(mindRandom == 1)
                {
                    if(board[mindv][mindh+1] == '%' && mindh+1 != 10)
                    {
                        v = mindv;
                        h = mindh+1;
                        break;
                    }
                    else if(board[mindv][mindh-1] == '%' && mindh-1 != -1)
                    {
                        v = mindv;
                        h = mindh-1;
                        break;
                    }
                    else
                    {
                        if (mindh-1 == -1)
                        h = mindh+1;
                        else
                        h = mindh-1;
                        v = mindv;
                        break;
                    }
                }
            }
            while(1);
        }
        if (beRandom == 0)
        {
            do
            {
                m_or_xpass = 0;
                h = rand()%10;
                v = rand()%10;
                if (board[v][h] == 'M' || board[v][h] == 'X')
                m_or_xpass = 1;
            }
            while(m_or_xpass);
        }
        if(board[v][h] == '%')
        {
            board[v][h] = 'X';
            sleep(2);
            printf("\a");
        }
        else if (board[v][h] == '~')
        {
            board[v][h] = 'M';
            printf("Missed.\n");
            sleep(2);
            pass = 0;
        }
        else
        {
            do
            {
                m_or_xpass = 0;
                h = rand()%10;
                v = rand()%10;
                if (board[v][h] == 'M' || board[v][h] == 'X')
                m_or_xpass = 1;
                else if (board[v][h] == '%')
                {
                    board[v][h] = 'X';
                    sleep(2);
                    printf("\a");
                    pass = 1;
                }
                else if (board[v][h] == '~')
                {
                    board[v][h] = 'M';
                    printf("Missed.\n");
                    sleep(2);
                    pass = 0;
                }
            }
            while(m_or_xpass);
        }
        PrintBoardForUser(board);
    }
    while(pass);
}
int ControlForStop(char board[ROW][COLUMN])
{
    int i, j;
    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j< COLUMN; j++)
        {
            if(board[i][j] == '%')
            return 1;
        }
    }
    return 0;
}
void PlayTheGame(char boardC[ROW][COLUMN], char boardU[ROW][COLUMN])
{
    int gameMod;
    int pass = 0, i;
    do
    {
        printf("Choose the game mod.\n1-Easy\n2-Hard\n");
        pass = 0;
        char location[5];
        fgets(location, 5, stdin);
        for(i = 0; location[i] != '\n'; i++)
        {
            if(isdigit(location[i]) == 0)
            {
                pass = 1;
                printf("Make sure you have entered a number value!\n");
                break;
            }
        }
        if (pass == 0)
        {
            gameMod = atoi(location);
            if(gameMod>=1 && gameMod<=2)
            continue;
            else
            {
                printf("Your number must be in range [1,2]\n");
                pass = 1;
            }
        }
    }
    while(pass);
    if(gameMod == 1)
    {
        int isDoneU, isDoneC;
        do
        {
            ShootingForUserEasy(boardC);
            sleep(1);
            isDoneU = ControlForStop(boardC);
            if (isDoneU == 0)
            break;
            ShootingForComputerEasy(boardU);
            sleep(1);
            isDoneC = ControlForStop(boardU);
            if (isDoneC == 0)
            break;
        }
        while(1);
        if(isDoneC == 0)
        printf("\n\n****** THE WINNER IS YOUR OPPONENT ******\n\n");
        else
        printf("\n\n****** YOU ARE THE WINNER ****** CONGRATULATIONS ******\n\n");
    }
    else if(gameMod == 2)
    {
        int isDoneU, isDoneC;
        do
        {
            ShootingForComputerHard(boardU);
            sleep(1);
            isDoneC = ControlForStop(boardU);
            if (isDoneC == 0)
            break;
            ShootingForUserHard(boardC);
            sleep(1);
            isDoneU = ControlForStop(boardC);
            if (isDoneU == 0)
            break;
        }
        while(1);
        if(isDoneC == 0)
        printf("\n\n****** THE WINNER IS YOUR OPPONENT ******\n\n");
        else
        printf("\n\n****** YOU ARE THE WINNER ****** CONGRATULATIONS ******\n\n");
    }
}
void ShootingForUserHard(char board[ROW][COLUMN])
{
    int v, h, isDone, pass = 0;
    do
    {
        isDone = ControlForStop(board);
        if (isDone == 0)
        break;
        PrintBoardForComputer(board);
        pass = 0;
        printf("Specify exact location to shoot.\n");
        printf("x axis : ");
        h = TakeLocationFromUser();
        printf("y axis : ");
        v = TakeLocationFromUser();
        if(board[v-1][h-1] == '%')
        {
            board[v-1][h-1] = 'X';
            sleep(2);
            printf("\a");
            pass = 1;
        }
        else if (board[v-1][h-1] == '~')
        {
            board[v-1][h-1] = 'M';
            printf("Missed.\n");
            sleep(2);
        }
        else if (board[v-1][h-1] == 'M')
        {
            printf("Missed.\n");
            sleep(2);
        }
        else if (board[v-1][h-1] == 'X')
        {
            printf("Missed.\n");
            sleep(2);
        }
        PrintBoardForComputer(board);
    }
    while(pass);
}
void ShootingForComputerEasy(char board[ROW][COLUMN])
{
    int v, h, pass = 0;
    printf("Your opponent is preparing to shoot.\n\n");
    do
    {
        pass = 0;
        h = rand()%10;
        v = rand()%10;
        if(board[v][h] == 'M' || board[v][h] == 'X' )
        pass = 1;
        else if (board[v][h] == '%')
        {
            printf("\a");
            board[v][h] = 'X';
            sleep(2);
            pass = 1;
        }
        else
        {
            board[v][h] = 'M';
            printf("Missed\n");
            sleep(2);
        }
        PrintBoardForUser(board);
    }
    while(pass);
}

void ShootingForUserEasy (char board[ROW][COLUMN])
{
    int v, h, isDone, pass = 0;
    do
    {
        isDone = ControlForStop(board);
        if (isDone == 0)
        break;
        pass = 0;
        PrintBoardForComputer(board);
        printf("Specify exact location to shoot.\n");
        printf("x axis : ");
        h = TakeLocationFromUser();
        printf("y axis : ");
        v = TakeLocationFromUser();
        if(board[v-1][h-1] == '%')
        {
            board[v-1][h-1] = 'X';
            sleep(2);
            printf("\a");
            pass = 1;
        }
        else if (board[v-1][h-1] == '~')
        {
            board[v-1][h-1] = 'M';
            printf("Missed.\n");
            sleep(2);
        }
        else if (board[v-1][h-1] == 'M')
        {
            printf("Already battered!\nTry for different location.\n");
            sleep(2);
            pass = 1;
        }
        else if (board[v-1][h-1] == 'X')
        {
            printf("Already battered!\nTry for different location.\n");
            sleep(2);
            pass = 1;
        }
        PrintBoardForComputer(board);
    }
    while(pass);
}

void Rules()
{
    printf("&&&&&&&&&&&&&&&&&&&&&&  AMIRAL BATTI  &&&&&&&&&&&&&&&&&&&&&&\n"
           "The Rules:\n"
           "-You have 5 ships which are 5,4,3,3,2 units.\n"
           "-Firstly, you will place the given ships to you.\n"
           "-The placement will be that, when you have entered a coordinate location this location will be your ship's prow.\n"
           "-Normally, vertical placement is top to bottom and horizontal placement is right to left.\n"
           "-If there is no enough place, placement will be the opposite exactly.\n"
           "-The ships cannot overlap and cannot touch each other.\n"
           "-When you completed the ship placing, you will choose the game mod. You would play with ordinary or formidable opponent.\n"
           "-Good luck!\n\n\n");
    sleep(15);

}



