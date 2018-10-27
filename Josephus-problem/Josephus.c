#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
struct node * pointer;
struct node *insert(struct node *last,int data)
{
    struct node*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
 if(last==NULL)
 {
     last=tmp;
     tmp->next=last;
     return last;
 }
 tmp->next=last->next;
 last->next=tmp;
 last=tmp;
 return last;
}
struct node *delete(struct node *last,int k)
{
    int i;
    for(i=1;i<k;i++)
      pointer=pointer->next;
      printf("%d killed\n",pointer->info);
      struct node *tmp;
    if(pointer==last->next)
    {
        tmp=last->next;
        pointer=tmp->next;
        last->next=tmp->next;
        free(tmp);
        return last;
    }
    else if(pointer==last)
    {
    pointer=last->next;
    struct node *p=last;
    while(p->next!=last)
        p=p->next;
     p->next=last->next;
     last=p;
     return last;
    }
     else
     {
        struct node *q=last;
        while(q->next!=pointer)
            q=q->next;
        q->next=pointer->next;
        struct node *tmp=pointer;
        pointer=q->next;
        free(tmp);
        return last;
     }
}
int main()
{
    int n,k;
    printf("Enter no. of peoples in the circle and steps to move after kill respectively\n");
    scanf("%d%d",&n,&k);
    struct node *head=NULL;
    int i;
    for(i=1;i<=n;i++)
    head=insert(head,i);
    pointer=head->next;
    for(i=1;i<=n-1;i++)
    head=delete(head,k);
    printf("%d will remain at last\n",head->info);
    return 0;
}
