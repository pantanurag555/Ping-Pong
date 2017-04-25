#include<windows.h>
#include<process.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

char map[22][60], cd=221, p1d=222;
int dir, bx, by, p1, c;

void dispmap()
{
    system("CLS");
    int i,j;
    map[by][bx]=254;
    for(i=0;i<22;i++)
    {
        for(j=0;j<60;j++)
        {
            if(j==1 && (i==c || i==c+1 || i==c+2 || i==c+3))
            {
                cout<<cd;
            }
            else if(j==58 && (i==p1 || i==p1+1 || i==p1+2 || i==p1+3))
            {
                cout<<p1d;
            }
            else
                cout<<map[i][j];
        }
        cout<<endl;
    }
    for(i=0;i<60;i++)
    {
        cout<<"-";
    }
    map[by][bx]=32;
    Sleep(50);
}

void p1move()
{
   if(bx>29)
    {
        if(dir==2)
        {
            if(by>p1+3)
            {
                p1+=2;
            }
        }
        else if(dir==1)
        {
            if(by<p1)
            {
                p1-=2;
            }
        }
    }
}

void cmove()
{
    if(bx<=29)
    {
        if(dir==3)
        {
            if(by<c)
            {
                c-=2;
            }
        }
        else if(dir==4)
        {
            if(by>c+3)
            {
                c+=2;
            }
        }
    }
}

void moveball()
{
    if(by==0)
    {
        if(dir==1)
        {
            bx++;
            by++;
            dir=2;
            goto end;
        }
        else if(dir==3)
        {
            bx--;
            by++;
            dir=4;
            goto end;
        }
    }
    else if(by==21)
    {
        if(dir==2)
        {
            bx++;
            by--;
            dir=1;
            goto end;
        }
        else if(dir==4)
        {
            bx--;
            by--;
            dir=3;
            goto end;
        }
    }
    if(dir==1)
    {
        bx++;
        by--;
    }
    else if(dir==2)
    {
        bx++;
        by++;
    }
    else if(dir==3)
    {
        bx--;
        by--;
    }
    else if(dir==4)
    {
        bx--;
        by++;
    }
    end:
    if(bx==1)
    {
        if(by==c || by==c+1 || by==c+2 || by==c+3)
        {
            bx+=2;
            if(dir==3)
            {
                dir=1;
            }
            else if(dir==4)
            {
                dir=2;
            }
        }
    }
    else if(bx==58)
    {
        if(by==p1 || by==p1+1 || by==p1+2 || by==p1+3)
        {
            bx-=2;
            if(dir==1)
            {
                dir=3;
            }
            else if(dir==2)
            {
                dir=4;
            }
        }
    }
}

int checkwin()
{
    if(bx==0)
    {
        return 1;
    }
    if(bx==59)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i,j,w,x,cs=0,p1s=0;
    while(1)
    {
        srand(time(NULL));
        x=(rand()%4)+1;
        dir=x;
        srand(time(NULL));
        x=(rand()%10)+6;
        by=x;
        srand(time(NULL));
        x=(rand()%20)+21;
        bx=x;
        p1=10;
        c=10;
        for(i=0;i<22;i++)
        {
            for(j=0;j<60;j++)
            {
                map[i][j]=32;
            }
        }
        dispmap();
        getch();
        w=0;
        while(1)
        {
            p1move();
            cmove();
            moveball();
            dispmap();
            w=checkwin();
            if(w!=0)
            {
                if(w==1)
                {
                    p1s++;
                }
                else if(w==2)
                {
                    cs++;
                }
                goto out;
            }
        }
        out:
        getch();
        system("CLS");
        cout<<"-----------SCORE-----------"<<endl;
        cout<<"PLAYER 1 : "<<cs<<endl;
        cout<<"PLAYER 2 : "<<p1s<<endl;
        if(p1s==3 || cs==3)
        {
            if(p1s==3)
            {
                cout<<endl<<"-----PLAYER 2 WINS-----";
            }
            else
            {
                cout<<endl<<"-----PLAYER 1 WINS-----"<<endl<<endl;
            }
            break;
        }
        getch();
    }
}
