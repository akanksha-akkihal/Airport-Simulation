#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main()
{
    struct plane *r1 ,*r2,*r3 ,*p,*prev , *r3_t;
    int time,i,j,k,newid;
    int idletime,land,takeoff,refuse;
    idletime=0;
    land=0;
    takeoff=0;
    refuse=0;
    float arr, dep;
    int flag=0;
    printf("-----------------WELCOME TO AIRPORT SIMULATION---------------");
    printf("\n\n\t->Program that simulates an airport with 3 runways.\n");
    printf("\t->One plane can land or depart from each runway in each unit of time.\n");
    printf("\t->Runway 1 is for LANDING and Runway 2 is for TAKEOFF and Runway 3 is for EXCESS LANDING \n\tor EXCESS TAKE-OFF when landing queue is empty.\n");
    printf("\nHow many time units the simulation will run ?:");
    scanf("%d",&time);

    do{
    printf("Expected arrivals per unit time :");
    scanf("%f",&arr);
    printf("Expected departures per unit time :");
    scanf("%f",&dep);

    if(arr + dep >6)
            {printf("Airport saturated, read new values:\n\n");
            flag=1;}
    else
        {
            flag=0;
        }
    }
    while(flag==1);

    r1=NULL;
    r2=NULL;
    r3=NULL;
    r3_t=NULL;

    //run through i units of time
    for(i=1;i<=time;i++)
    {   printf("\n\n%d:\n",i);
        for(j=1;j<=(rand()%2)+1;j++)//random number of plane arrivals for landing
        {
            if(getCount(r1)==0)
            {
                p=malloc(sizeof(struct plane));//creating a linked list in runway-1
                p->id=(rand()%50)+1;
                printf("Plane %d ready to land\n",p->id);
                p->next=NULL;
                if(r1==NULL)
                    r1=p;
                else
                    prev->next=p;
                prev=p;
            }
            else if(getCount(r1)>0)//sending excess planes to runway-3
            {
                p=malloc(sizeof(struct plane));
                p->id=(rand()%50)+1;
                printf("Plane %d ready to land\n",p->id);
                p->next=NULL;
                if(r3==NULL)
                    r3=p;
                else
                    prev->next=p;
                prev=p;

                if(getCount(r3)+getCount(r1)>2)
                {
                    printf("Plane %d refused\n",p->id);
                    end_delete(r3);
                    refuse++;

                }
            }

            else
            {
                newid=(rand()%50)+1;
                EndIns(&r1, newid);
                printf("Plane %d ready to land\n",newid);
            }

            }

    //deletion from queue after landing
    printf("Plane %d landed on runway-1, in queue %d units\n",r1->id,getCount(r1)+getCount(r3)-1);
    Frontdel(&r1);
    land++;

    if (getCount(r3)>0)
    {
        printf("Plane %d landed on runway 3\n",r3->id);
        Frontdel(&r3);
        land++;
    }

//random number of planes ready for takeoff
        for(k=1;k<=(rand()%2)+1;k++)
        {
            if(getCount(r2)==0)
            {
                p=malloc(sizeof(struct plane));
                p->id=(rand()%50)+1;
                printf("Plane %d ready to take-off\n",p->id);
                p->next=NULL;
                if(r2==NULL)
                    r2=p;
                else
                    prev->next=p;
                prev=p;
            }
            else if(getCount(r3)==0 && getCount(r2)>1)//sending excess planes to runway_3
            {
                p=malloc(sizeof(struct plane));
                p->id=(rand()%50)+1;
                printf("Plane %d ready to take-off\n",p->id);
                p->next=NULL;
                if(r3_t==NULL)
                    r3_t=p;
                else
                    prev->next=p;
                prev=p;

                }

            else
            {
                newid=(rand()%50)+1;
                EndIns(&r2, newid);
                printf("Plane %d ready to take-off\n",newid);
            }
        }



//deletion from queue after take-off
    printf("Plane %d took-off from runway-2, in queue %d units\n",r2->id,getCount(r2)-1);
    Frontdel(&r2);
    takeoff++;


    if(getCount(r3)==0 && getCount(r2)>1)
    {
        printf("No excess landing in runway-3,so used for take-off\n");
        printf("Plane %d took-off from runway-3\n",r3_t->id);
        Frontdel(&r3_t);
        takeoff++;
    }

    }

    printf("\n\tSimulation has concluded after %d units.\n", time);
    printf("\tTotal number of planes processed: %d\n",land+takeoff+refuse+ getCount(r1)+getCount(r3)+getCount(r2));
    printf("\tNumber of planes landed: %d\n",land );
    printf("\tNumber of planes taken off: %d\n",takeoff );
    printf("\tNumber of planes refused use: %d\n", refuse);
    printf("\tNumber of planes left ready to land: %d\n", getCount(r1)+getCount(r3));
    printf("\tNumber of planes left ready to take off: %d\n", getCount(r2));

}
