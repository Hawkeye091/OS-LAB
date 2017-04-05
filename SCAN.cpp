#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

double cutime=0.0;

struct av
{
  int id;
  av *next;
}*avail=new av;

struct q
{
  int arr;
  int reqtrack;
  int reqsector;
  int id;
  q *next;
}*requeue;

void disp_req()
{
    q *cu=requeue;
    while(cu->next!=NULL)
    {
       cout<<cu->reqtrack<<"\n";
       cu=cu->next;
    }
    cout<<cu->reqtrack<<"\n";
}

void add_time(int trdiff,int sec)
{
    cutime+=10+0.1*trdiff+sec;
}
void execute()
{
    if(cutime==0)
    {
        add_time(requeue->reqtrack,requeue->reqsector);
    }
    else
    {
        q *cu=requeue;
        while(cu->next!='\0')
        {
            if(cu->arr<cutime)
            {
                av *cuav=new av;
                cuav->next=NULL;
                if(avail==NULL)
                    {
                        avail->id=cu->id;;
                    }
                else
                {
                    while(cuav->next!='\0')
                    {
                        cuav=cuav->next;
                    }
                    cuav->id=cu->id;
                }
            }
            cu=cu->next;
        }
    }


}

void go_front()
void go_back()

main()
{
  requeue=new q;
  int n;
  cout<<"Enter No. of Request\n";
  cin>>n;
  cout<<"Enter Arrival Time , Track Request , Sector Request \n";
  for(int i=0;i<n;i++)
  {
     q *temp=new q;
     cin>>temp->arr;
     cin>>temp->reqtrack;
     cin>>temp->reqsector;
     temp->next=NULL;
     if(i==0)
     {
         temp->id=0;
         requeue=temp;

     }
     else
     {
         temp->id=i;
         q *cu=requeue;
         while (cu->next!='\0')
         {
             cu=cu->next;
         }
         cu->next=temp;
     }
  }
}
