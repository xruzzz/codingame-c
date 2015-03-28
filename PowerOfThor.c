#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Coor
{
    int x;
    int y;
} SC;

typedef struct Direction
{
    char x;
    char y;
} DIR;

char getTrit(int x)
{
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
}

DIR finddir(SC posThor, SC light)
{
    DIR res;
    res.x = getTrit(light.x - posThor.x);
    res.y = getTrit(light.y - posThor.y);
    return res;
}

SC newThorPosition(SC curThorPos, DIR dir)
{
    curThorPos.x = curThorPos.x + (int) dir.x;
    curThorPos.y = curThorPos.y + (int) dir.y;
    return curThorPos;
}

char* dir2string(DIR dir)
{
    if (dir.x == 0 && dir.y == 0) return NULL;
    char dirTorX, dirTorY;
    switch (dir.x)
    {
        case 1:
            dirTorX = 'E';
            break;
        case -1:
            dirTorX = 'W';
            break;
    }
    switch (dir.y)
    {
        case -1:
            dirTorY = 'N';
            break;
        case 1:
            dirTorY = 'S';
            break;
    }
    char * dirTor;
    if (dir.x == 0)
    {
        dirTor = (char *)malloc(1);
        dirTor[0] = dirTorY;
    }
    if (dir.y == 0)
    {
        dirTor = (char *)malloc(1);
        dirTor[0] = dirTorX;
    }
    if (dir.x != 0 && dir.y != 0)
    {
        
        dirTor = (char *)malloc(2);
        dirTor[0] = dirTorY;
        dirTor[1] = dirTorX;
    }
    return dirTor;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int LX; // the X position of the light of power
    int LY; // the Y position of the light of power
    int TX; // Thor's starting X position
    int TY; // Thor's starting Y position
    scanf("%d%d%d%d", &LX, &LY, &TX, &TY);
    SC light, curThorPosition;
    light.x = LX;
    light.y = LY;
    curThorPosition.x = TX;
    curThorPosition.y = TY;
    DIR dir  = finddir(curThorPosition, light);
    while (1) {
        int E; // The level of Thor's remaining energy, representing the number of moves he can still make.
        scanf("%d", &E);
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
       // A single line providing the move to be made: N NE E SE S SW W or NW
        dir= finddir(curThorPosition, light);
        printf("%s\n",dir2string(dir));
        curThorPosition = newThorPosition(curThorPosition, dir);
    }
}
