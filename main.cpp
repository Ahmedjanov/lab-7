#include <graphics.h>
#include <conio.h>
#include <stdio.h>

struct department
{
    char lastname[15];
    char initials[10];
    int yearofborth;
    float salary;
}otdel[9];


void scrin();
void read();
void sortlastname(int);
void sortinitials(int);
void sortyearofborth(int);
void sortsalary(int);
void mouse(void *buff);
int main(void)
{
   int GrDr, GrMod, rez ;
    GrDr=DETECT ;

   initgraph(&GrDr,&GrMod," ") ; // GrDr - графический драйвер;
                                                         //GrMod -графический режим;
// третий параметр- путь до графического       //драйвера;

   rez=graphresult() ;
   if(rez != grOk)
{
    printf("\n ООError graph modeи") ;
   return(1) ;
 }
scrin();

    void *buff;
    unsigned size;
    size=imagesize(9,90,629,460);
    buff=malloc(size);
    getimage(9,90,629,460,buff);


settextstyle(NORM_WIDTH,0,1);
read();

mouse(buff);

closegraph() ;
return(0) ;
}


//////////////////////////////////////////////////////////
void scrin()
{

    setcolor(0);
    setfillstyle(1,8);
    bar(0,0,639,479);
    int i,j=0;
    for(i=0;i<12;i++)
    {
        line(9,(j+9),629,(j+9));
j+=41;
    }
line(9,9,9,460);
line(629,9,629,460);

line(220,50,220,460);
line(370,50,370,460);
line(520,50,520,460);

settextstyle(BOLD_FONT,0,1);
setbkcolor(8);
outtextxy(180,20,"Human Resources Department");
outtextxy(49,65,"Last name");
outtextxy(260,65,"Initials");
outtextxy(380,65,"Year of birth");
outtextxy(540,65,"Salary");

}
///////////////////////////////////////////////////
void read()
{
    int i=0,j=0;
    char st[10];
    FILE *f;
   if((f = fopen("file.txt","r"))==NULL)
    {
        outtextxy(200,120,"Error while opening file");
    }
    else
    {
         while((fscanf(f, "%s %s %d %f\n", otdel[i].lastname,otdel[i].initials,&otdel[i].yearofborth,&otdel[i].salary))!=EOF)
        {

            outtextxy(19,(j+105),otdel[i].lastname);
            outtextxy(270,(j+105),otdel[i].initials);
            sprintf(st,"%d",otdel[i].yearofborth);
            outtextxy(420,(j+105),st);
            sprintf(st,"%0.2f",otdel[i].salary);
            outtextxy(540,(j+105),st);
            i++;
            j+=41;
        }
        fclose(f);
    }
}
/////////////////////////////////////////////////////////////
void sortlastname(int x)
{
int i,j,k=0;
char st[10];
char ct[10],ctr[10];
struct department dep;

for(i=0;i<9;i++)
{
    ct[i]=otdel[i].lastname[0];
    ctr[i]=otdel[i].lastname[1];
}

for(i=0;i<9;i++)
{
    for(j=i+1;j<9;j++)
    {
        if(x==2)
            {
        if(ct[j] > ct[i])
        {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }

        else if(ct[j]==ct[i])
        {
            if(ctr[j] > ctr[i])
            {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
            }
        }

            }
        if(x==1)
            {
        if(ct[j] < ct[i])
        {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }

        else if(ct[j]==ct[i])
        {
            if(ctr[j] < ctr[i])
            {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
            }
        }


            }
    }
                outtextxy(19,(k+105),otdel[i].lastname);
            outtextxy(270,(k+105),otdel[i].initials);
            sprintf(st,"%d",otdel[i].yearofborth);
            outtextxy(420,(k+105),st);
            sprintf(st,"%0.2f",otdel[i].salary);
            outtextxy(540,(k+105),st);
            k+=41;

}

}
////////////////////////////////////////////////////////////
void sortinitials(int y)
{
struct department dep;
char st[10];
char ct[10];
int i,j,k=0;
for(i=0;i<9;i++)
{
    ct[i]=otdel[i].initials[0];
}
for(i=0;i<9;i++)
{
    for(j=i+1;j<9;j++)
    {
        if(y==2)
            {
        if(ct[j] > ct[i])
        {
             dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }

            }
        if(y==1)
        {
            if(ct[j] < ct[i])
        {
             dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }

        }
    }
                outtextxy(19,(k+105),otdel[i].lastname);
            outtextxy(270,(k+105),otdel[i].initials);
            sprintf(st,"%d",otdel[i].yearofborth);
            outtextxy(420,(k+105),st);
            sprintf(st,"%0.2f",otdel[i].salary);
            outtextxy(540,(k+105),st);
            k+=41;

}
}
//////////////////////////////////////////////////////////////
void sortyearofborth(int z)
{
struct department dep;
int i,j,k=0;
char st[10];
for(i=0;i<9;i++)
{
    for(j=i+1;j<9;j++)
    {
        if(z==2)
            {
        if(otdel[j].yearofborth > otdel[i].yearofborth)
        {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }
            }
        else if(z==1)
        {
            if(otdel[j].yearofborth < otdel[i].yearofborth)
        {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }
        }
    }
            outtextxy(19,(k+105),otdel[i].lastname);
            outtextxy(270,(k+105),otdel[i].initials);
            sprintf(st,"%d",otdel[i].yearofborth);
            outtextxy(420,(k+105),st);
            sprintf(st,"%0.2f",otdel[i].salary);
            outtextxy(540,(k+105),st);
            k+=41;

}
}
//////////////////////////////////////////////////////////////
void sortsalary(int t)
{
struct department dep;
int i,j,k=0;
char st[10];
for(i=0;i<9;i++)
{
    for(j=i+1;j<9;j++)
    {
        if(t==2)
            {
        if(otdel[j].salary > otdel[i].salary)
        {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }
            }
        if(t==1)
        {
            if(otdel[j].salary < otdel[i].salary)
        {
            dep=otdel[j];
            otdel[j]=otdel[i];
            otdel[i]=dep;
        }
        }
    }
                outtextxy(19,(k+105),otdel[i].lastname);
            outtextxy(270,(k+105),otdel[i].initials);
            sprintf(st,"%d",otdel[i].yearofborth);
            outtextxy(420,(k+105),st);
            sprintf(st,"%0.2f",otdel[i].salary);
            outtextxy(540,(k+105),st);
            k+=41;

}
}
/////////////////////////////////////////////////////////
void mouse(void *buff)
{
        void (*sort[4]) (int) = {sortlastname,sortinitials,sortyearofborth,sortsalary};
    char key;
    int mouse=0;
    int x=0,x1=0,x2=0,x3=0,x4=0;
    while(mouse < 5)
    {
        if(kbhit())
            {
        key=getch();
            }
            (*sort[mouse]) (x);

        int xz, yz;
            getmouseclick(WM_LBUTTONDOWN, xz,yz);

if((xz>9)&&(yz>50)&&(xz<220)&&(yz<101))
{
  putimage(9,90,buff,COPY_PUT);
  mouse = 0;
  x1++;
  if(x1==3)
  x1=1;

  x2=0;
  x3=0;
  x4=0;
  x=x1;
  }
if((xz>220)&&(yz>50)&&(xz<370)&&(yz<101))
{
   putimage(9,90,buff,COPY_PUT);
   mouse = 1;
   x2++;
  if(x2==3)
    x2=1;

    x1=0;
    x3=0;
    x4=0;
    x=x2;
}
if((xz>370)&&(yz>50)&&(xz<520)&&(yz<101))
{
    putimage(9,90,buff,COPY_PUT);
  mouse = 2;
    x3++;
  if(x3==3)
  x3=1;

  x1=0;
  x2=0;
  x4=0;
  x=x3;
}
if((xz>520)&&(yz>50)&&(xz<629)&&(yz<101))
{
    putimage(9,90,buff,COPY_PUT);
  mouse = 3;
    x4++;
  if(x4==3)
  x4=1;

  x1=0;
  x2=0;
  x3=0;
  x=x4;
}
    }
}
