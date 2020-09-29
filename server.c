#include<stdio.h>
#include<stdlib.h>
#include "header.h"

//To insert new planes to the queue end on arrival
void EndIns(struct plane ** head, int name)
{
    struct plane*newplane = (struct plane*)malloc(sizeof(struct plane));
    newplane->id=name;
    if(*head==NULL)
    {
        *head = newplane;
        return;
    }
    struct plane*tail = *head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next= newplane;
    newplane->next =NULL;
}

//To delete planes from the queue on landing or take-off
void Frontdel(struct plane **head)
{
  struct plane *tmp;
  if(head == NULL || *head == NULL) return;
  tmp = *head;
  *head = (*head)->next;
  free(tmp);
}

//To remove planes from queue end after refusal
void end_delete(struct plane *head)
{
  struct plane *temp =head;
  struct plane *t;
  if(head->next==NULL)
  {
    free(head);
    head=NULL;
  }
  else
  {
     while(temp->next != NULL)
     {
        t=temp;
        temp=temp->next;
     }
     free(t->next);
     t->next=NULL;
  }

}

//To count number of planes in the queue
int getCount(struct plane* head)
{
    int count = 0;  // Initialize count
    struct plane* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}