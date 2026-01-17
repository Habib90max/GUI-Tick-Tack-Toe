#include<graphics.h>
#include<conio.h>
#include<string>
using namespace std;

int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int current=1;
char ch[2];
int winner=0;
bool over=false;

int main()
{
    initwindow(600,600,(char*)"Tick-Tack-Toe");
    setbkcolor(BLUE);
    cleardevice();
    setcolor(WHITE);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(200,50,200,400);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(400,50,400,400);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(50,175,550,175);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(50,300,550,300);
    int w=500/3;
    int h=350/3;
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    outtextxy(150,430,(char*)"Player X turn");
    int count=0;
    while(true)
    {   int x=0,y=0;
        int r=0,c=0;
        int x1=0,y1=0;
        if(over==false&&ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x,y);
            count++;

            if(x<50||x>550||y<50||y>400)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                count--;
                continue;
            }
        
           if(x>=50&&x<=550&&y>=50&&y<=400)
           {
              r=(y-50)/h;
              c=(x-50)/w;
              x1=50+c*w+w/2;
              y1=50+r*h+h/2;
            }
            if(board[r][c]==0)
            {
                settextstyle(BOLD_FONT,HORIZ_DIR,5);
             if(current==1)
             {
              ch[0]='X';
              outtextxy(150,430,(char*)"Player O turn");
             }
            else
             {
               ch[0]='O';
               outtextxy(150,430,(char*)"Player X turn");
             }
              ch[1]='\0';
              settextstyle(BOLD_FONT,HORIZ_DIR,5);
             outtextxy(x1-10,y1-10,ch);
             clearmouseclick(WM_LBUTTONDOWN);
             board[r][c]=current;
               for(int i=0;i<3;i++)
                { if(board[i][0]!=0&&board[i][1]!=0&&board[i][2]!=0)
                    {
                        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
                         {
                           winner=board[r][c];
                           over=true;
                         }
                    }
                }
                for(int j=0;j<3;j++)
                { if(board[0][j]!=0&&board[1][j]!=0&&board[2][j]!=0)
                    {
                        if(board[0][j]==board[1][j]&&board[0][j]==board[2][j])
                         {
                           winner=board[r][c];
                           over=true;
                         }
                    }
                }
                if((board[0][0]!=0&&board[1][1]!=0&&board[2][2]!=0)||(board[0][2]!=0&&board[1][1]!=0&&board[2][0]!=0))
                {
                  if((board[0][0]==board[1][1]&&board[0][0]==board[2][2])||(board[0][2]==board[1][1]&&board[0][2]==board[2][0]))  
                    { winner=board[r][c];
                        over=true;
                    }
                }
                if(count==9&&over==false)
                 {
                    winner=-1;
                    over =true;
                 }     
                  
            
              if(current==1)
               {
                  current=2;
               } 
               else
               {
                  current=1;
               }
            }
            else
               {
                 continue;
               }
        }
        if(over==true)
        {
            if(winner==1)
              {
                outtextxy(150,430,(char*)"Player X won!");
              }
            else if(winner==2)
                {
                  outtextxy(150,430,(char*)"Player O won!");
                }
            else if(winner==-1)
               {
                   outtextxy(150,430,(char*)"It's a draw !");
               }

            outtextxy(75,500,(char*)"Press 'R' to restart");
            if(kbhit())
            {
                char ch=getch();
                if(ch=='r'||ch=='R')
                {
                    for(int a=0;a<3;a++)
                    {
                        for(int b=0;b<3;b++)
                        {
                            board[a][b]=0;
                        }
                    }
                    count =0;
                    current=1;
                    winner=0;
                    over=false;
                    cleardevice();
                      setlinestyle(SOLID_LINE,0,THICK_WIDTH);
                      line(200,50,200,400);
                      setlinestyle(SOLID_LINE,0,THICK_WIDTH);
                      line(400,50,400,400);
                      setlinestyle(SOLID_LINE,0,THICK_WIDTH);
                      line(50,175,550,175);
                      setlinestyle(SOLID_LINE,0,THICK_WIDTH);
                       line(50,300,550,300);
                      settextstyle(BOLD_FONT,HORIZ_DIR,5);
                      outtextxy(150,430,(char*)"Player X turn");
                      continue;
                }
            }
        }
    }
    closegraph();
    return 0;
}