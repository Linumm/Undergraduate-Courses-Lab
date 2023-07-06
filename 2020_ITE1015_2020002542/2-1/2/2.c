#include <stdio.h>

typedef struct
{
    int xpos;
    int ypos;
}Point;

Point getScale2xPoint(const Point* p)
{
    Point rp;
    rp.xpos=(p->xpos)*2;
    rp.ypos=(p->ypos)*2;
    return rp;
}

void swapPoints(Point* p1, Point* p2)
{
    Point temp;
    temp.xpos=p1->xpos;
    temp.ypos=p1->ypos;

    p1->xpos=p2->xpos;
    p1->ypos=p2->ypos;
    p2->xpos=temp.xpos;
    p2->ypos=temp.ypos;
}

int main(void)
{
    Point p1;
    scanf("%d %d", &p1.xpos, &p1.ypos);
    
    printf("Calling getScale2xPoint()\n");
    Point p2=getScale2xPoint(&p1);

    printf("P1: %d %d\n", p1.xpos, p1.ypos);
    printf("P2: %d %d\n", p2.xpos, p2.ypos);

    printf("Calling swapPoint()\n");
    swapPoints(&p1, &p2);
    
    printf("P1: %d %d\n", p1.xpos, p1.ypos);
    printf("P2: %d %d\n", p2.xpos, p2.ypos);

    return 0;
}
