
#include<iostream>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int A[12][12]={0};//frtoken
int B[12][12]={0};//forproperty

int bal1;
int bal2;


struct data
{
    char name[50];
    int price,mortage;
    int rent,h1,h2,h3,h4,hotel,i,j;
}ss[22];

struct property{

char name[50];
    int price,mortage;
    int rent,h1,h2,h3,h4,hotel,i,j;
    int noah;
    struct property *next;
} *sp1=NULL,*sp2=NULL,*ep1,*ep2,*temp;


void houseprint(struct property *s)
{
    struct property *temp;
    int i,j;
    for(temp=s;temp!=NULL;temp=temp->next)
       { i=temp->i;
          j=temp->j;

                    if(i==0)
                    {
                        if(temp->noah >=1)
                        {

                          readimagefile("house.bmp",84+(48*(j-1)),60,104+(48*(j-1)),80);
                        }
                        if(temp->noah >=2)
                        {
                             readimagefile("house.bmp",84+(48*(j-1))+20,60,104+(48*(j-1))+20,80);
                        }
                        if(temp->noah>=3)
                        {
                             readimagefile("house.bmp",84+(48*(j-1)),0,104+(48*(j-1)),20);
                        }
                        if(temp->noah>=4)
                        {
                                readimagefile("house.bmp",84+(48*(j-1))+20,0,104+(48*(j-1))+20,20);
                        }

                    }
                    else if(j==0)
                    {
                        if(temp->noah >=3)
                        {

                           readimagefile("house.bmp",0,84+(48*(i-1)),20,104+(48*(i-1)));
                        }
                        if(temp->noah >=4)
                        {
                             readimagefile("house.bmp",0,20+84+(48*(i-1)),20,124+(48*(i-1)));
                        }
                        if(temp->noah>=1)
                        {
                             readimagefile("house.bmp",0+60,84+(48*(i-1)),0+80,104+(48*(i-1)));

                        }
                        if(temp->noah>=2)
                        {
                                readimagefile("house.bmp",0+60,84+(48*(i-1))+20,0+80,104+(48*(i-1))+20);

                        }

                    }
                    else if(i==10)
                    {
                        if(temp->noah >=3)
                        {

                          readimagefile("house.bmp",84+(48*(j-1)),520+60,104+(48*(j-1)),520+80);
                        }
                        if(temp->noah >=4)
                        {
                             readimagefile("house.bmp",84+(48*(j-1))+20,520+60,104+(48*(j-1))+20,520+80);
                        }
                        if(temp->noah>=1)
                        {
                             readimagefile("house.bmp",84+(48*(j-1)),520+0,104+(48*(j-1)),520+20);
                        }
                        if(temp->noah>=2)
                        {
                                readimagefile("house.bmp",84+(48*(j-1))+20,520+0,104+(48*(j-1))+20,520+20);
                        }

                    }
                    else if(j==10)
                    {
                        if(temp->noah >=1)
                        {

                           readimagefile("house.bmp",520,84+(48*(i-1)),520+20,104+(48*(i-1)));
                        }
                        if(temp->noah >=2)
                        {
                             readimagefile("house.bmp",520,104+(48*(i-1)),520+20,124+(48*(i-1)));
                        }
                        if(temp->noah>=3)
                        {
                             readimagefile("house.bmp",520+60,84+(48*(i-1)),520+80,104+(48*(i-1)));

                        }
                        if(temp->noah>=4)
                        {
                                readimagefile("house.bmp",520+60,84+(48*(i-1))+20,520+80,104+(48*(i-1))+20);

                        }

                    }
            }

       }




void buying(int ii,int jj,int a)
{
    int i,j,k;
    temp=(struct property *)malloc(sizeof(struct property));
    temp->next=NULL;
    temp->noah=0;
    for(i=0;i<22;i++)
    {


            if(ii==ss[i].i && jj==ss[i].j)
            {
                    temp->h1=ss[i].h1;
                    temp->h2=ss[i].h2;
                    temp->h3=ss[i].h3;
                    temp->h4=ss[i].h4;
                    temp->hotel=ss[i].hotel;
                    temp->i=ss[i].i;
                    temp->j=ss[i].j;
                    temp->mortage=ss[i].mortage;
                    temp->price=ss[i].price;
                    strcpy(temp->name,ss[i].name);
                    temp->rent=ss[i].rent;
            }

    }
if(a==1)
    {if(sp1==NULL)
    {
        sp1=temp;
        ep1=temp;
    }
    else
    {
        ep1->next=temp;
        ep1=temp;
    }
    }
else
        {if(sp2==NULL)
    {
        sp2=temp;
        ep2=temp;
    }
    else
    {
        ep2->next=temp;
        ep2=temp;
    }
    }
}





void data()
{
     int ii,jj,k;
    FILE *fp;
    fp=fopen("mdata.txt","r");

   for(ii=0;ii<22;ii++)
   {
       //printf("%d",ii);
    fscanf(fp,"%s %d %d %d %d %d %d %d %d %d %d\n",ss[ii].name,
           &ss[ii].price,&ss[ii].mortage,&ss[ii].rent,&ss[ii].h1,
           &ss[ii].h2,&ss[ii].h3,&ss[ii].h4,&ss[ii].hotel,&ss[ii].i,&ss[ii].j);

           B[ss[ii].i][ss[ii].j]=3;
   }




    fclose(fp);


}




void pos(int k,int l)
{
    int ii;
    char c[50];
for(ii=0;ii<22;ii++)
   {
       if(ss[ii].i==k && ss[ii].j==l)

        {

printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d %d",ss[ii].name,ss[ii].price,ss[ii].mortage,ss[ii].rent,ss[ii].h1,ss[ii].h2,ss[ii].h3,ss[ii].h4,ss[ii].hotel,ss[ii].i,ss[ii].j);
sprintf(c,"Name - %s",ss[ii].name);
outtextxy(610,330,c);
sprintf(c,"Price - $%d",ss[ii].price);
outtextxy(610,350,c);
sprintf(c,"Mortage Value- $%d",ss[ii].mortage);
outtextxy(610,370,c);
sprintf(c,"Rent - $%d",ss[ii].rent);
outtextxy(610,390,c);

sprintf(c,"Rent with house1 - $%d",ss[ii].h1);
outtextxy(610,410,c);

sprintf(c,"Rent with house2 - $%d",ss[ii].h2);
outtextxy(610,430,c);
sprintf(c,"Rent with house3 - $%d",ss[ii].h3);
outtextxy(610,450,c);
sprintf(c,"Rent with house4 - $%d",ss[ii].h4);
outtextxy(610,470,c);


break;
      }
   }

}



void printing(int a)
  {  int i,j;
     char c[20];
        //cleardevice();
        houseprint(sp1);
                              houseprint(sp2);
         readimagefile("m.bmp",0,0,600,600);
         outtextxy(650,10,"MENU");
         outtextxy(650,30,"1.Throw Dice");
         outtextxy(650,50,"2.View Properties or");
         outtextxy(650,70,"   Setup houses");
         outtextxy(650,90,"3.Mortage/Unmortage");
         outtextxy(650,130,"5.Finish Game");
         outtextxy(650,110,"4.Sell");


if(a==1)
{
    sprintf(c,"Player %d",1);


    outtextxy(620,150,c);
    sprintf(c,"Available balance-> %d",bal1);


    outtextxy(620,170,c);
}

else {
    sprintf(c,"Player %d",2);


    outtextxy(620,150,c);
    sprintf(c,"Available balance-> %d",bal2);


    outtextxy(620,170,c);
}


    for(i=0;i<11;i++)
     {
         for(j=0;j<11;j++)
         {
             if( (A[i][j]==1&&i==0) || (A[i][j]==1&&j==0) )
             {

                   readimagefile("blue.bmp",(j*50)+35,(i*50)+35,(j*50)+55,(i*50)+55);
             }

             if(((A[i][j]==1&&i==10) && j!=0)   || ((A[i][j]==1&&j==10)&& i!=0)  )
             {


             readimagefile("blue.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
             }



         }
     }


    for(i=0;i<11;i++)
     {
         for(j=0;j<11;j++)
         {
             if( (A[i][j]==2&&i==0) || (A[i][j]==2&&j==0) )
             {

                   readimagefile("black.bmp",(j*50)+35,(i*50)+35,(j*50)+55,(i*50)+55);
             }

             if(((A[i][j]==2&&i==10) && j!=0)   || ((A[i][j]==2&&j==10)&& i!=0)  )
             {


             readimagefile("black.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
             }



         }
     }
for(i=0;i<11;i++)
     {
         for(j=0;j<11;j++)
         {
             if( (A[i][j]==3&&i==0) || (A[i][j]==3&&j==0) )
             {

                   readimagefile("green.bmp",(j*50)+35,(i*50)+35,(j*50)+55,(i*50)+55);
             }

             if(((A[i][j]==3&&i==10) && j!=0)   || ((A[i][j]==3&&j==10)&& i!=0)  )
             {


             readimagefile("green.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
             }



         }
     }


}

void diceprint(int x,int z)
{
    int i,j;
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
        {
            if(x==i && z==j)
            {
                if(i==1)
                readimagefile("1.bmp",700,250,750,300);
                else if(i==2)
                readimagefile("2.bmp",700,250,750,300);
                else if(i==3)
                readimagefile("3.bmp",700,250,750,300);
                else if(i==4)
                readimagefile("4.bmp",700,250,750,300);
                else if(i==5)
                readimagefile("5.bmp",700,250,750,300);
                else if(i==6)
                readimagefile("6.bmp",700,250,750,300);

                if(j==1)
                readimagefile("1.bmp",750,250,800,300);
                else if(j==2)
                readimagefile("2.bmp",750,250,800,300);
                else if(j==3)
                readimagefile("3.bmp",750,250,800,300);
                else if(j==4)
                readimagefile("4.bmp",750,250,800,300);
                else if(j==5)
                readimagefile("5.bmp",750,250,800,300);
                else if(j==6)
                readimagefile("6.bmp",750,250,800,300);

            }
        }
    }

houseprint(sp1);
                              houseprint(sp2);
}
void mortage( struct property *s,int *bal,int x)
 {
     struct property *temp;
     int i,j,ba;
      int ar;
      char t,d[100];
      ba=*bal;
     temp=s;

    while(temp!=NULL)
                    {
                     cleardevice();




                             i=temp->i;
                             j=temp->j;
                    readimagefile("m.bmp",0,0,600,600);
                     houseprint(s);

             readimagefile("green.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
                       sprintf(d,"Name - %s",temp->name);
                    outtextxy(610,130,d);
                sprintf(d,"Price - $%d",temp->price);

                                outtextxy(610,150,d);
                                sprintf(d,"Mortage Value- $%d",temp->mortage);
                                outtextxy(610,170,d);
                                sprintf(d,"Current Balance- $%d",bal1);
                                outtextxy(610,110,d);
                                sprintf(d,"Rent - $%d",temp->rent);
                                outtextxy(610,190,d);

                                sprintf(d,"Rent with house1 - $%d",temp->h1);
                                outtextxy(610,210,d);

                                sprintf(d,"Rent with house2 - $%d",temp->h2);
                                outtextxy(610,230,d);
                                sprintf(d,"Rent with house3 - $%d",temp->h3);
                                outtextxy(610,250,d);
                                sprintf(d,"Rent with house4 - $%d",temp->h4);
                                outtextxy(610,270,d);


                               if(temp->noah!=0)
                               {

                                sprintf(d,"ENTER THE NUMBER OF  ");

                                outtextxy(610,290,d);
                                 sprintf(d,"HOUSES YOU WANT TO SELL ");

                                outtextxy(610,310,d);
                                ar=getch();
                                ar-=48;
                                if(ar<=temp->noah)
                                { temp->noah-=ar;
                                             if(i==0)
                                             {
                                                ba+=(ar*75);
                                             }
                                             if(i==10)
                                             {
                                                ba+=(ar*25);
                                             }
                                             if(j==0)
                                             {
                                                ba+=(ar*50);
                                             }
                                             if(j==10)
                                             {
                                                ba+=(ar*100);
                                             }

                                             sprintf(d,"HOUSES SUCCESSFULLY  REMOVED ");

                                outtextxy(610,330,d);
                                }
                                else
                                {
                                  sprintf(d,"Wrong Option");

                                outtextxy(610,350,d);
                                }

                               }
                               if(B[i][j]!=4 && temp->noah==0)
                               {sprintf(d,"ENTER Y if u want to mortage the property ");

                                outtextxy(610,350,d);
                                t=getch();
                                if(t=='y'||t=='Y')
                                {
                                 ba+=temp->mortage;
                                 sprintf(d,"SUCCESSFULLY MORTAGED");

                                outtextxy(610,370,d);
                                 B[i][j]=4;
                                }


                                }
                                if(B[i][j]==4 )
                               {sprintf(d,"ENTER Y if u want to unmortage the property ");

                                outtextxy(610,350,d);
                                t=getch();
                                if(t=='y'||t=='Y')
                                {

                                 if(ba>=temp->mortage)
                                 {  sprintf(d,"SUCCESSFULLY UNMORTAGED");

                                outtextxy(610,370,d);
                                 B[i][j]=x;
                                      ba-=temp->mortage;
                                 }
                                else
                                {sprintf(d,"Insufficient balance");

                                outtextxy(610,370,d);

                                }
                                }


                                }



                                sprintf(d,"PRESS ANY KEY FOR NEXT PROPERTY ");
                                outtextxy(610,430,d);
                                getch();
                                temp=temp->next;

                    }
                    *bal=ba;
}


void community(int *pi,int *pj ,int *bal1,int *bal2,int z)
{
	int x,k;
	x=rand()%10+1;
	if(x==1)
	{
		outtextxy(610, 400,"You inherit $100");
		getch();

		if(z==1)
		*bal1+=100;
		else
		*bal2+=100;
	}
	else if( x==2)
	{
outtextxy( 610, 400,"Advance to Go (Collect $200)");
		if(A[*pi][*pj]==z)
		{A[*pi][*pj]=0;}
		else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

		A[10][10]=z;
		*pi=10;
		*pj=10;

		getch();

	}
	else if( x==3)
	{
		outtextxy(610,400 ,"Bank error in your favor");
		outtextxy(610,420 ,"Collect $200");
			getch();

			if(z==1)
		*bal1+=200;
		else
		*bal2+=200;
	}
	else if( x==4)
	{   outtextxy(610,400 ,"Doctor's fees  Pay $50");
		getch();

		if(z==1)
		{
			if(*bal1>=50)
			*bal1-=50;
			else
			{
				mortage(sp1,bal1,1);
				*bal1-=50;
			}


		}
		if(z==2)
		{
			if(*bal2>=50)
			*bal2-=50;
			else
			{
				mortage(sp2,bal2,2);
				*bal2-=50;
			}
		}

	}
	else if(x==5)
	{outtextxy( 610, 400,"Go to Jail");

				if(A[*pi][*pj]==z)
		{A[*pi][*pj]=0;}
		else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

		A[10][0]=z;


         if(z==1)
             {
                 *bal1-=50;
             }
             else
               {
                 *bal2-=50;
               }

		*pi=10;
		*pj=0;
		getch();
	}
	else if(x==6)
	{
		outtextxy( 610,400 ,"Holiday Fund matures");
		outtextxy( 610,420 ,"collect $100 ");

		getch();

		if(z==1)
		{
			if(z==1)
		*bal1+=100;
		else
		*bal2+=100;
		}

	}
	else if(x==7)
	{
		outtextxy( 610,400 ,"Income tax refund");
		outtextxy( 610,420 ,"Collect $20");

		getch();

		if(z==1)
		*bal1+=20;
		else
		*bal2+=20;
	}
	else if(x==8)
	{
		outtextxy( 610,400 ,"Life insurance matures");
		outtextxy( 610,420 ,"Collect $100");
		getch();

		if(z==1)
		*bal1+=100;
		else
		*bal2+=100;
	}else if(x==9)
	{
		outtextxy(610 ,400 ,"Pay hospital fees of $100");
		getch();

		if(z==1)
		{
			if(*bal1>=100)
			*bal1-=100;
			else
			{
				mortage(sp1,bal1,1);
				*bal1-=100;
			}


		}
		if(z==2)
		{
			if(*bal2>=100)
			*bal2-=100;
			else
			{
				mortage(sp2,bal2,2);
				*bal2-=100;
			}
		}

	}else if(x==10)
	{
		outtextxy(610 ,400 ,"Pay school fees of $150");
		getch();

		if(z==1)
		{
			if(*bal1>=150)
			*bal1-=150;
			else
			{
				mortage(sp1,bal1,1);
				*bal1-=150;
			}


		}
		if(z==2)
		{
			if(*bal2>=150)
			*bal2-=150;
			else
			{
				mortage(sp2,bal2,2);
				*bal2-=150;
			}
		}

	}

}



void chances(int *pi,int *pj ,int *bal1,int *bal2,int z)
{
	int x,k,i,j;
	x=rand()%8+1;
	if(x==1)
	{
		outtextxy( 610, 400,"Advance to Go");
		outtextxy( 610, 420,"(Collect $200)");
		if(A[*pi][*pj]==z)
		{A[*pi][*pj]=0;}
		else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

		A[10][10]=z;
		*pi=10;
		*pj=10;

		getch();
	}
	else if( x==2)
	{
		outtextxy(610, 400,"Advance to ");
		outtextxy(610, 420,"Trafalagur Square");
	     		if(A[*pi][*pj]==z)
		{A[*pi][*pj]=0;}
		else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

		A[0][4]=z;




		*pi= 0;
		*pj= 4;
		getch();

	}
	else if( x==3)
	{
		outtextxy(610, 400,"Advance to Paul mall");

				if(A[*pi][*pj]==z)
		{A[*pi][*pj]=0;}
		else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

		A[9][0]=z;



		*pi= 9;
		*pj= 0;
		getch();
	}
	else if( x==4)
	{
		outtextxy(610, 400,"Go Back 3 Spaces");
		getch();

		i=*pi;
		j=*pj;
		if(i==10&&j==3)
        {  if(A[*pi][*pj]==z)
		     {A[*pi][*pj]=0;}

		     else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

           A[10][6]=z;
           *pi=10;
           *pj=6;

        }
        if(i==0&&j==2)
        {  if(A[*pi][*pj]==z)
		     {A[*pi][*pj]=0;}

		     else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

           A[1][0]=z;
           *pi=1;
           *pj=0;

        }

		if(i==6&&j==10)
        {  if(A[*pi][*pj]==z)
		     {A[*pi][*pj]=0;}

		     else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

           A[3][10]=z;

           *pi=3;
           *pj=10;

        }

}
	else if(x==5)
	{
		outtextxy( 610, 400,"Go to Jail");

				if(A[*pi][*pj]==z)
		{A[*pi][*pj]=0;}
		else
           {
               if(z==1)
                A[*pi][*pj]=2;
               else
                A[*pi][*pj]=1;
           }

		A[10][0]=z;


         if(z==1)
             {
                 *bal1-=50;
             }
             else
               {
                 *bal2-=50;
               }

		*pi=10;
		*pj=0;
		getch();
	}
	else if(x==6)
	{
		outtextxy(610, 400,"Pay poor tax of $15");
		getch();
		if(z==1)
		{
			if(*bal1>=15)
			*bal1-=15;
			else
			{
				mortage(sp1,bal1,1);
					*bal1-=15;
			}
		}
		if(z==2)
		{
			if(*bal2>=15)
			*bal2-=15;
			else
			{
				mortage(sp2,bal2,2);
					*bal2-=15;
			}
		}

	}
	else if(x==7)
	{
		outtextxy( 610, 400,"You have won a crossword");
		outtextxy( 610, 420,"competition - Collect $100");

		getch();
		if(z==1)
		*bal1+=100;
		else
		*bal2+=100;
	}
	else if(x==8)
	{
		outtextxy( 610, 400,"Your building loan");
		outtextxy( 610, 420,"matures Collect $150");

		getch();
		if(z==1)
		*bal1+=150;
		else
		*bal2+=150;
	}

}

void dice(int *t,int *h,int y)
{  cleardevice();
    printing(y);
    int i,j,sum;

    char c[10];
    int x=rand()%6 + 1;
    int z=rand()%6 +1;
     sprintf(c,"Dice => %d",x+z);


sum=x+z;
    outtextxy(700,200,c);
     delay(0);
    int p1i,p1j;
    p1i=*t;
    p1j=*h;

while(sum>0)
{  if(p1i==10 && p1j!=0)
  {  if(A[p1i][p1j]==3 && y==1)
       {
           A[p1i][p1j]=2;
       }
       else if(A[p1i][p1j]==3 && y==2)
       {
           A[p1i][p1j]=1;
       }
       else
       {A[p1i][p1j]=0;}

     if(A[p1i][p1j-1]!=0)
     {A[p1i][p1j-1]=3;}
     else
     {
         A[p1i][p1j-1]=y;
     }
     p1j=p1j-1;
     diceprint(x,z);
     printing(y);

  }
else if(p1i!=0 && p1j==0)
  {
          if(A[p1i][p1j]==3 && y==1)
        {
           A[p1i][p1j]=2;
        }
        else if(A[p1i][p1j]==3 && y==2)
        {
           A[p1i][p1j]=1;
        }
            else
                {A[p1i][p1j]=0;}


      if(A[p1i-1][p1j]!=0)
     {A[p1i-1][p1j]=3;}
     else
     {
         A[p1i-1][p1j]=y;
     }


     p1i=p1i-1;
       diceprint(x,z);
     printing(y);

  }
 else if(p1i==0 && p1j!=10)
  {
        if(A[p1i][p1j]==3 && y==1)
        {
            A[p1i][p1j]=2;
        }
       else if(A[p1i][p1j]==3 && y==2)
       {
           A[p1i][p1j]=1;
       }
       else
       {
           A[p1i][p1j]=0;
       }




if(A[p1i][p1j+1]!=0)
     {A[p1i][p1j+1]=3;}
     else
     {
         A[p1i][p1j+1]=y;
     }

     p1j++;
     diceprint(x,z);
     printing(y);

  }
      else
  {

    if(A[p1i][p1j]==3 && y==1)
       {
           A[p1i][p1j]=2;
       }
       else if(A[p1i][p1j]==3 && y==2)
       {
           A[p1i][p1j]=1;
       }
       else
       {A[p1i][p1j]=0;}



        if(A[p1i+1][p1j]!=0)
     {A[p1i+1][p1j]=3;}
     else
     {
         A[p1i+1][p1j]=y;
     }

     p1i++;
      diceprint(x,z);
     printing(y);

      }
      if(p1i==10&&p1j==10)
      { if(y==1)
             {
                 bal1+=200;
             }
             else
                bal2+=200;

      }
      houseprint(sp1);
                              houseprint(sp2);
delay(300);sum--;
}
if( (p1i==0&&p1j==2)||(p1i==10&&p1j==3)||(p1j==10&&p1i==6) )
{

    chances(&p1i,&p1j,&bal1,&bal2,y);
}
if( (p1i==3&&p1j==0)||(p1i==10&&p1j==8)||(p1j==10&&p1i==3) )
{

    community(&p1i,&p1j,&bal1,&bal2,y);
}

if(p1i==10&&p1j==10)
      { if(y==1)
             {
                 bal1+=200;
             }
             else
                bal2+=200;

      }

if(p1i==0 && p1j==10)
{ A[0][10]=0;
 A[10][0]=2;
    p1i=10;
    p1j=0;
       if(y==1)
             {
                 bal1-=50;
             }
             else
               {
                 bal2-=50;
               }
             }

*t=p1i;
*h=p1j;

pos(p1i,p1j);
}



void sell(struct property *s,int *bal,int x)
{  struct property *temp,*flag=NULL;

     int i,j,ba;
      int ar;
      char t,d[100];
      ba=*bal;
     temp=s;


    while(temp!=NULL)
                    {
                     cleardevice();




                             i=temp->i;
                             j=temp->j;
                    readimagefile("m.bmp",0,0,600,600);
                     houseprint(s);

             readimagefile("green.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
                       sprintf(d,"Name - %s",temp->name);
                    outtextxy(610,130,d);
                sprintf(d,"Price - $%d",temp->price);

                                outtextxy(610,150,d);
                                sprintf(d,"Mortage Value- $%d",temp->mortage);
                                outtextxy(610,170,d);
                                sprintf(d,"Current Balance- $%d",bal1);
                                outtextxy(610,110,d);
                                sprintf(d,"Rent - $%d",temp->rent);
                                outtextxy(610,190,d);

                                sprintf(d,"Rent with house1 - $%d",temp->h1);
                                outtextxy(610,210,d);

                                sprintf(d,"Rent with house2 - $%d",temp->h2);
                                outtextxy(610,230,d);
                                sprintf(d,"Rent with house3 - $%d",temp->h3);
                                outtextxy(610,250,d);
                                sprintf(d,"Rent with house4 - $%d",temp->h4);
                                outtextxy(610,270,d);




                                sprintf(d," PRESS Y IF YOU WANT");

                                outtextxy(610,290,d);
                                 sprintf(d,"TO SELL THE PROPERTY");

                                outtextxy(610,310,d);
                                t=getch();
                                if(t=='y'||t=='Y')
                                {ar=temp->noah;

                                if(ar<=temp->noah)
                                  { temp->noah=0;
                                             if(i==0)
                                             {
                                                ba+=(ar*75);
                                             }
                                             if(i==10)
                                             {
                                                ba+=(ar*25);
                                             }
                                             if(j==0)
                                             {
                                                ba+=(ar*50);
                                             }
                                             if(j==10)
                                             {
                                                ba+=(ar*100);
                                             }


                                }



                               if(B[i][j]!=4 && temp->noah==0)
                                    {
                                 ba+=temp->mortage;
                                 B[i][j]=4;
                                      }

                                      if(flag==NULL && x==1)
                                      {    ba+=temp->mortage;
                                          sp1=NULL;
                                          B[i][j]=3;
                                          sprintf(d,"PROPERTY SOLD");
                                outtextxy(610,430,d);
                                getch();
                                break;
                                      }
                                      else if(flag==NULL && x==2)
                                      {    ba+=temp->mortage;
                                          sp2=NULL;
                                          B[i][j]=3;
                                          sprintf(d,"PROPERTY SOLD");
                                outtextxy(610,430,d);
                                getch();
                            break;
                                      }
                                      else
                                      {   ba+=temp->mortage;
                                          flag->next=temp->next;
                                          B[i][j]=3;
                                          sprintf(d,"PROPERTY SOLD");
                                outtextxy(610,430,d);
                                getch();
                                break;

                                      }


                                }

                                sprintf(d,"PRESS ANY KEY FOR NEXT PROPERTY ");
                                outtextxy(610,430,d);
                                getch();
                                flag=temp;
                                temp=temp->next;

                    }
                    *bal=ba;
}

int endgame(struct property *x)

{
    int ar,ba=0,i,j;
    struct property *temp;
    ar=temp->noah;
i=temp->i;
j=temp->j;
    for(temp=x;temp!=NULL;temp=temp->next)
    {

                                            if(i==0)
                                             {
                                                ba+=(ar*75);
                                             }
                                             if(i==10)
                                             {
                                                ba+=(ar*25);
                                             }
                                             if(j==0)
                                             {
                                                ba+=(ar*50);
                                             }
                                             if(j==10)
                                             {
                                                ba+=(ar*100);
                                             }


     if(B[temp->i][temp->j]!=4)

     {ba+=temp->price;}
     else
     {
         ba+=temp->mortage;
     }

    }
    return(ba);
}

int main()
{
     int i,j,z=1,a;
A[10][10]=3;
bal1=1500;
bal2=1500;
char d[100],e,g,h;
int p2i=10,p2j=10;
int p1i=10,p1j=10;

initwindow(920,600);
  readimagefile("cover.bmp",0,0,920,600);

{    int i;

settextstyle(1,0,1);

setcolor(BLUE);
setfillstyle(1,BLUE);
bar(339,463,657,492) ;
setfillstyle(1,YELLOW);
for(i=340;i<655;i+=5)
    {
    bar(340,465,i,490);
    delay(50);
    }

}

cleardevice();
setcolor(WHITE);
settextstyle(0,HORIZ_DIR,0);
int c;
data();

while(1)
{     houseprint(sp1);
     houseprint(sp2);

if(z%2==1)
{
    printing(1);
    houseprint(sp1);
                              houseprint(sp2);
                                                  if(bal2<0)
                                                {


                                                    while(bal2<0)
                                                    {  if(sp2==NULL)
                                                         {
                                                         cleardevice();
                                                          readimagefile("m.bmp",0,0,600,600);
                                                          outtextxy(610,300,"Player 1 wins");
                                                          getch();
                                                          exit(1);
                                                         }


                                                        sprintf(d,"Balance  %d$",bal2);
                                                       outtextxy(600,500,d);
                                                    outtextxy(600,520,"Press 1 to mortage");
                                                    outtextxy(600,540,"Press 2 to sell");

                                                        h=getch();
                                                    h-=48;

                                                        if(h==1)
                                                        {mortage(sp2,&bal2,2);}
                                                        if(h==2)
                                                        {
                                                            sell(sp2,&bal2,2);
                                                        }
                                                    }
                                                }
                                                if(bal1<0)
                                                {


                                                    while(bal1<0)
                                                    {  if(sp1==NULL)
                                                         {
                                                         cleardevice();
                                                          readimagefile("m.bmp",0,0,600,600);
                                                          outtextxy(610,300,"Player 1 wins");
                                                          getch();
                                                          exit(1);
                                                         }


                                                         sprintf(d,"Balance  %d$",bal1);
                                                       outtextxy(600,500,d);
                                                       outtextxy(600,520,"Press 1 to mortage");
                                                    outtextxy(600,540,"Press 2 to sell");

                                                        h=getch();
                                                    h-=48;

                                                        if(h==1)
                                                        {mortage(sp2,&bal1,2);}
                                                        if(h==2)
                                                        {
                                                            sell(sp2,&bal1,2);
                                                        }
                                                    }
                                                }











    delay(0);
c=getch();
switch(c)
{  houseprint(sp1);
                              houseprint(sp2);
    case '1': {
                    dice(&p1i,&p1j,1);
                              houseprint(sp1);
                              houseprint(sp2);

                                  if(B[p1i][p1j]==3 )
                                  {
                                         sprintf(d,"Wanna Buy the property(Y/N):-");
                                         outtextxy(610,510,d);
                                         e=getch();
                                         if(e=='y'||e=='Y')
                                         {
                                                              for(i=0;i<22;i++)
                                              {if(p1i==ss[i].i && p1j==ss[i].j)
                                                         {j=ss[i].price;break;}}
                                                         if(bal1>=j)
                                                     {buying(p1i,p1j,1);
                                                      bal1-=j;
                                                      B[p1i][p1j]=1;
                                                     outtextxy(610,530,"Bought successfully");}
                                                     else
                                                     {
                                                          outtextxy(610,530,"Insufficient Balance");
                                                     }
                                                     sprintf(d,"Available balance-> %d",bal1);
                                                     outtextxy(620,170,d);
                                              delay(500);
                                              cleardevice();
                                         }
                                         else
                                         {
                                           cleardevice();
                                         }

                                  }
                                  else if(B[p1i][p1j]==2)
                                    {
                                                for(temp=sp2;temp!=NULL;temp=temp->next)
                                                {
                                                    if(p1i==temp->i && p1j==temp->j)
                                                    {
                                                        if(temp->noah==0)
                                                        {
                                                            bal1-=temp->rent;
                                                            bal2+=temp->rent;

                                                        }
                                                        else if(temp->noah==1)
                                                        {
                                                            bal1-=temp->h1;
                                                               bal2+=temp->h1;
                                                        }
                                                        else if(temp->noah==2)
                                                        {
                                                            bal1-=temp->h2;

                                                               bal2+=temp->h2;


                                                        }else if(temp->noah==3)
                                                        {
                                                               bal2+=temp->h3;

                                                            bal1-=temp->h3;
                                                        }else if(temp->noah==4)
                                                        {
                                                            bal1-=temp->h4;

                                                               bal2+=temp->h4;

                                                        }

                                                    }

                                                }

                                                if(bal1<0)
                                                {


                                                    while(bal1<0)
                                                    {
                                                        if(sp1==NULL)
                                                         {
                                                         cleardevice();
                                                          readimagefile("m.bmp",0,0,600,600);
                                                          outtextxy(610,300,"Player 1 wins");
                                                          getch();
                                                          exit(1);
                                                         }

                                                        sprintf(d,"Balance   %d$",bal1);
                                                       outtextxy(600,500,d);
                                                    outtextxy(600,520,"Press 1 to mortage");
                                                    outtextxy(600,540,"Press 2 to sell");

                                                        h=getch();
                                                    h-=48;

                                                        if(h==1)
                                                        {mortage(sp1,&bal1,2);}
                                                        if(h==2)
                                                        {
                                                            sell(sp1,&bal1,2);
                                                        }
                                                    }
                                                }


                                    }

                                  cleardevice();

                             break;}


    case '2':{
                    temp=sp1;

                    while(temp!=NULL)
                    {

                     cleardevice();



                             i=temp->i;
                             j=temp->j;
                    readimagefile("m.bmp",0,0,600,600);
                     houseprint(sp1);

             readimagefile("green.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
                       sprintf(d,"Name - %s",temp->name);
                    outtextxy(610,130,d);
                sprintf(d,"Price - $%d",temp->price);
                int ar;
                                outtextxy(610,150,d);
                                sprintf(d,"Mortage Value- $%d",temp->mortage);
                                outtextxy(610,170,d);
                                sprintf(d,"Current Balance- $%d",bal1);
                                outtextxy(610,110,d);
                                sprintf(d,"Rent - $%d",temp->rent);
                                outtextxy(610,190,d);

                                sprintf(d,"Rent with house1 - $%d",temp->h1);
                                outtextxy(610,210,d);

                                sprintf(d,"Rent with house2 - $%d",temp->h2);
                                outtextxy(610,230,d);
                                sprintf(d,"Rent with house3 - $%d",temp->h3);
                                outtextxy(610,250,d);
                                sprintf(d,"Rent with house4 - $%d",temp->h4);
                                outtextxy(610,270,d);
                                if(temp->noah<4 && B[i][j]!=4)
                                {


                                sprintf(d,"Wanna setup houses(Y/N)");
                                outtextxy(610,330,d);
                                g=getch();
                                if(g=='Y'||g=='y')
                                 {
                                    if(temp->j==10)
                                    {
                                        sprintf(d,"Cost of each house is $200");
                                             outtextxy(610,350,d);


                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal1>=(ar*200)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal1-=a*200;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                             houseprint(sp1);
                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds ");
                                outtextxy(610,390,d);}
                                    }
                                    if(temp->j==0)
                                    {
                                        sprintf(d,"Cost of each house is $100");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal1>=(ar*100)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal2-=a*100;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                           houseprint(sp1);
                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                    if(temp->i==10)
                                    {
                                        sprintf(d,"Cost of each house is $50");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal1>=(ar*50)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal1-=a*50;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                          houseprint(sp1);

                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                    if(temp->i==0)
                                    {
                                        sprintf(d,"Cost of each house is $150");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal1>=(ar*150)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal1-=a*150;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                          houseprint(sp1);
                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                 }
                                }

                                   sprintf(d,"PRESS ANY KEY FOR NEXT PROPERTY ");

                                outtextxy(610,430,d);
                                getch();
                                temp=temp->next;

                    }
                    cleardevice();

               z--;

        break;}

    case'5':{
                   outtextxy(610,443,"Press Y to finish the game");
                   g=getch();
                   if(g=='y'||g=='Y')
                   {


                cleardevice();
               readimagefile("m.bmp",0,0,600,600);

               outtextxy(610,260,"Player 1");
               sprintf(d,"Current Balance:-$%d",bal1);
               outtextxy(610,300,d);
               i=endgame(sp1);
               sprintf(d,"Value of Properties:-$%d",i);
               outtextxy(610,320,d);
               line(600,343,850,343);
              bal1=bal1+i;
               sprintf(d,"Total:-$%d",bal1);
               outtextxy(610,363,d);


            outtextxy(610,60,"Player 2");
               sprintf(d,"Current Balance:-$%d",bal2);
               outtextxy(610,100,d);
               i=endgame(sp2);
               sprintf(d,"Value of Properties:-$%d",i);
               outtextxy(610,120,d);
               line(600,143,850,143);
              bal2=bal2+i;
               sprintf(d,"Total:-$%d",bal2);
               outtextxy(610,163,d);

                 if(bal1>bal2)
                 {
                     outtextxy(610,483,"PLAYER 1 WINS");
                 }
                 else if(bal2>bal1)
                 {
                     outtextxy(610,483,"PLAYER 2 WINS");
                 }
                 else
                 {
                     outtextxy(610,483,"ITS A DRAW");
                 }

                getch();

        exit(1);} z--;


        break;}
    case '4':sell(sp1,&bal1,1); z--;cleardevice();break;
    case '3':mortage(sp1,&bal1,1);z--;cleardevice();
             break;
      default:z--;  };
}
else
{
    printing(2);
     houseprint(sp1);
                              houseprint(sp2);
    delay(500);
c=getch();
switch(c)
{ houseprint(sp1);
                              houseprint(sp2);
    case '1': {   dice(&p2i,&p2j,2); houseprint(sp1);
     houseprint(sp2);

                                  if(B[p2i][p2j]==3 )
                                  {
                                         sprintf(d,"Wanna Buy the property(Y/N):-");
                                         outtextxy(610,510,d);
                                         e=getch();
                                         if(e=='y'||e=='Y')
                                         {
                                                              for(i=0;i<22;i++)
                                              {if(p2i==ss[i].i && p2j==ss[i].j)
                                                         {j=ss[i].price;break;}}
                                                         if(bal2>=j)
                                                     {buying(p2i,p2j,2);
                                                      bal2-=j;
                                                      B[p2i][p2j]=2;
                                                     outtextxy(610,530,"Bought successfully");}
                                                     else
                                                     {
                                                          outtextxy(610,530,"Insufficient Balance");
                                                     }


                                              sprintf(d,"Available balance-> %d",bal2);
                                                     outtextxy(620,170,d);
                                                     delay(500);
                                              cleardevice();
                                         }
                                          else
                                         {
                                           cleardevice();
                                         }

                                  }
                                  else if(B[p2i][p2j]==1)
                                    {
                                                for(temp=sp1;temp!=NULL;temp=temp->next)
                                                {
                                                    if(p2i==temp->i && p2j==temp->j)
                                                    {
                                                        if(temp->noah==0)
                                                        {  bal1+=temp->rent;
                                                            bal2-=temp->rent;
                                                        }
                                                        else if(temp->noah==1)
                                                        {   bal1+=temp->h1;
                                                            bal2-=temp->h1;
                                                        }
                                                        else if(temp->noah==2)
                                                        {     bal1+=temp->h2;
                                                            bal2-=temp->h2;
                                                        }else if(temp->noah==3)
                                                        {    bal1+=temp->h3;
                                                            bal2-=temp->h3;
                                                        }else if(temp->noah==4)
                                                        {    bal1+=temp->h4;
                                                            bal2-=temp->h4;
                                                        }

                                                    }

                                                }
                                                if(bal2<0)
                                                {


                                                    while(bal2<0)
                                                    {  if(sp2==NULL)
                                                         {
                                                         cleardevice();
                                                          readimagefile("m.bmp",0,0,600,600);
                                                          outtextxy(610,300,"Player 1 wins");
                                                          getch();
                                                          exit(1);
                                                         }


                                                        sprintf(d,"Balance  %d$",bal2);
                                                       outtextxy(600,500,d);
                                                    outtextxy(600,520,"Press 1 to mortage");
                                                    outtextxy(600,540,"Press 2 to sell");

                                                        h=getch();
                                                    h-=48;

                                                        if(h==1)
                                                        {mortage(sp2,&bal2,2);}
                                                        if(h==2)
                                                        {
                                                            sell(sp2,&bal2,2);
                                                        }
                                                    }
                                                }

                                    }


                                    cleardevice();


                             break;}

    case '2':{
                    temp=sp2;

                    while(temp!=NULL)
                    {cleardevice();

                       int ar;

                             i=temp->i;
                             j=temp->j;
                   readimagefile("m.bmp",0,0,600,600);
                   houseprint(sp2);

             readimagefile("green.bmp",(j*50)+45,(i*50)+45,(j*50)+65,(i*50)+65);
                       sprintf(d,"Name - %s",temp->name);
                    outtextxy(610,130,d);
                sprintf(d,"Price - $%d",temp->price);
                                sprintf(d,"Current Balance- $%d",bal1);
                                outtextxy(610,110,d);
                                outtextxy(610,150,d);
                                sprintf(d,"Mortage Value- $%d",temp->mortage);
                                outtextxy(610,170,d);
                                sprintf(d,"Rent - $%d",temp->rent);
                                outtextxy(610,190,d);

                                sprintf(d,"Rent with house1 - $%d",temp->h1);
                                outtextxy(610,210,d);

                                sprintf(d,"Rent with house2 - $%d",temp->h2);
                                outtextxy(610,230,d);
                                sprintf(d,"Rent with house3 - $%d",temp->h3);
                                outtextxy(610,250,d);
                                sprintf(d,"Rent with house4 - $%d",temp->h4);
                                outtextxy(610,270,d);
                                if(temp->noah<4  && B[i][j]!=4)
                                {


                                sprintf(d,"Wanna setup houses(Y/N)");
                                outtextxy(610,330,d);
                                g=getch();
                                if(g=='Y'||g=='y')
                                 {
                                    if(temp->j==10)
                                    {
                                        sprintf(d,"Cost of each house is $200");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal2>=(ar*200)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal2-=a*200;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                             houseprint(sp2);
                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                    if(temp->j==0)
                                    {
                                        sprintf(d,"Cost of each house is $100");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal2>=(ar*100)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal2-=a*100;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                           houseprint(sp2);
                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                    if(temp->i==10)
                                    {
                                        sprintf(d,"Cost of each house is $50");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal2>=(ar*50)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal2-=a*50;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                          houseprint(sp2);

                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                    if(temp->i==0)
                                    {
                                        sprintf(d,"Cost of each house is $150");
                                             outtextxy(610,350,d);
                                         sprintf(d,"Enter the number of houses");
                                          outtextxy(610,370,d);
                                          ar=getch();
                                          ar-=48;
                                          a=ar;
                                          ar+=temp->noah;
                                          if(bal2>=(ar*150)&&ar<5)
                                          {
                                              temp->noah=ar;
                                              bal2-=a*150;
                                              sprintf(d,"House Successfully Setup");
                                          outtextxy(610,390,d);
                                          houseprint(sp2);
                                          }
                                          else
                                          {sprintf(d,"Insufficient Funds");
                                outtextxy(610,390,d);}
                                    }
                                 }
                                }

                                   sprintf(d,"PRESS ANY KEY TO CONTINUE");

                                outtextxy(600,420,d);
                                getch();
                                temp=temp->next;

                    }

                   cleardevice();               z--;

        break;}
     case '4':sell(sp2,&bal2,2);z--;break;cleardevice();
    case'5':{

                   outtextxy(610,443,"Press Y to finish the game");
                   g=getch();
                   if(g=='y'||g=='Y')
                   {


                cleardevice();
               readimagefile("m.bmp",0,0,600,600);

               outtextxy(610,260,"Player 1");
               sprintf(d,"Current Balance:-$%d",bal1);
               outtextxy(610,300,d);
               i=endgame(sp1);
               sprintf(d,"Value of Properties:-$%d",i);
               outtextxy(610,320,d);
               line(600,343,850,343);
              bal1=bal1+i;
               sprintf(d,"Total:-$%d",bal1);
               outtextxy(610,363,d);


            outtextxy(610,60,"Player 2");
               sprintf(d,"Current Balance:-$%d",bal2);
               outtextxy(610,100,d);
               i=endgame(sp2);
               sprintf(d,"Value of Properties:-$%d",i);
               outtextxy(610,120,d);
               line(600,143,850,143);
              bal2=bal2+i;
               sprintf(d,"Total:-$%d",bal2);
               outtextxy(610,163,d);

                 if(bal1>bal2)
                 {
                     outtextxy(610,483,"PLAYER 1 WINS");
                 }
                 else if(bal2>bal1)
                 {
                     outtextxy(610,483,"PLAYER 2 WINS");
                 }
                 else
                 {
                     outtextxy(610,483,"ITS A DRAW");
                 }

                getch();

        exit(1);} z--;


        break;}
        case'3':mortage(sp2,&bal2,2);z--;cleardevice();
            break;
            default:z--;}

}

z++;
}
cin>>i;

    closegraph();
}
