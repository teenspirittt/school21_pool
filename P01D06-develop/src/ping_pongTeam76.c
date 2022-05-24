
#include <stdio.h>

#define fieldWidth 80
#define fieldHeight 25
#define rocketLength 3
#define ballSize 1

char field[fieldWidth+1][fieldHeight];

typedef struct  {
    int x;
    int y;
    int length;
} TRocket;

TRocket rocketLeft;
TRocket rocketRight;
    
void initRocket(TRocket* rocket, int x, int y)
{
    rocket->x = x;
    rocket->y = y;
    rocket->length = rocketLength;
}

void putRocket(TRocket rocket)
{
    for(int i = 0; i < rocketLength; i++)
    {
        field[rocket.x][i+rocket.y] = '@';
    }
}

void initField()
{
    for(int i = 0; i < fieldHeight; i++)
    {
        for(int j = 0; j < fieldWidth; j++)
        {
            field[j][i] = ' ';
        }
        field[fieldWidth][i] = '\0';
    }
    
    for(int i = 0; i < fieldHeight; i++)
    {
        field[fieldWidth/2-1][i] = '|';
    }
}

void show()
{
    //show field
    for(int i = 0; i < fieldHeight; i++)
    {
        for(int j = 0; j < fieldWidth; j++)
        {
            printf("%c", field[j][i]);
        }
        printf("\n");
    }
}

int main() {
    initField();
    initRocket(&rocketLeft, 0, (int)fieldHeight/2);
    initRocket(&rocketRight, fieldWidth-1, (int)fieldHeight/2);
    putRocket(rocketLeft);
    putRocket(rocketRight);
    show();
    return 0;
}