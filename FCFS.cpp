#include <bits/stdc++.h>
using namespace std;
int nop;
struct link
{
    string Pid;
    int arrival=0;
    int cputime=0;
    int finishtime=0;
    int waitingtime=0;
    int TAT=0;
    link *n;
}*first=NULL;
void FCFS(string *p,int *ar,int *cp)
{
    int cont=0;
    int cpy=nop;
    while(cpy)
    {
        link *temp = new link;
        temp->Pid=p[cont];
        temp->arrival=ar[cont];
        temp->cputime=cp[cont];
        temp->waitingtime=0;
        temp->finishtime=temp->cputime;
        temp->TAT=temp->finishtime-temp->arrival;
        temp->n=NULL;
        if(first==NULL)
            first=temp;
        else
        {
          link *cu=first;
          while(cu->n!='\0')
          {
              cu=cu->n;
          }
          temp->waitingtime=cu->finishtime-temp->arrival;
          temp->finishtime=cu->finishtime+temp->cputime;
          temp->TAT=temp->finishtime-temp->arrival;
          cu->n=temp;
        }
        cpy--;
        cont++;
    }
}
void SJF()
{
    cout<<"Pid , Arrival , CPU Time , Waiting Time , Finish Time , TAT\n";
    link *cu=first;
    int cpy=nop;
    int cont=0;
    int minu=1000;
    int st[10];
    for(int i=0;i<10;i++)
        st[i]=0;
    int cutime=0;
    while(cu!='\0')
    {
        if(cu->arrival<=cutime)
        {
            st[cont]=cu->arrival;
            cont++;
        }
        cu=cu->n;
    }
    cu=first;
    cpy=0;
    link *b,*a;
    while(cu!='\0'&&cpy<=cont)
    {
        if(cu->arrival==st[cpy])
        {
            if(cu->cputime<minu)
                {
                    minu=cu->cputime;
                    b=cu;
                }
            cpy++;
        }
        cu=cu->n;
    }
    cu=first;
    link *x=first;
        while  (x->n!=b)
        x=x->n;
        x->n=b->n;
        if(cu->cputime==minu)
        {
          cout<<cu->Pid<<" "<<cu->arrival<<" "<<cu->cputime<<" "<<cu->waitingtime<<" "<<cu->finishtime<<" "<<cu->TAT<<"\n";
          delete cu;
        }
}
void Display()
{
    cout<<"Pid , Arrival , CPU Time , Waiting Time , Finish Time , TAT\n";
    link *cu=first;
    while(cu->n!='\0')
    {
        cout<<cu->Pid<<" "<<cu->arrival<<" "<<cu->cputime<<" "<<cu->waitingtime<<" "<<cu->finishtime<<" "<<cu->TAT<<"\n";
        cu=cu->n;
    }
    cout<<cu->Pid<<" "<<cu->arrival<<" "<<cu->cputime<<" "<<cu->waitingtime<<" "<<cu->finishtime<<" "<<cu->TAT<<"\n";
}
main()
{

        cout<<"Enter No. of Processes\n";
        cin>>nop;
        string pi[nop];
        int a[nop],cpt[nop];
        int flag=1;
        int ch;
        cout<<"Enter Pid , Arrival , CPU Time\n";
        for(int i=0;i<nop;i++)
        {
            cin>>pi[i];
            cin>>a[i]>>cpt[i];

        }
        while(flag)
        {
        cout<<"Select Method \n1.FCFS\n2.SJF\n3.Display Result\n4.Exit\n";
        cin>>ch;
        switch (ch)
        {
        case 1 :
            FCFS(pi,a,cpt);
            break;
        case 2:
            FCFS(pi,a,cpt);
            SJF();
            break;
        case 3:
            Display();
            break;
        case 4:
            flag=0;
            break;
        }
        }
}
