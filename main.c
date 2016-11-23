#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}*pnode;

pnode creat(int n)
{
    int i;
    pnode head,p1,p2;
    int a;
    head=NULL;
    for (i=1;i<=n;i++)
    {
        p1=(pnode)malloc(sizeof(pnode));
        printf("no.%d ",i);
        scanf("%d",&a);
        p1->data=a;
        if (head==NULL)
        {
            head=p1;
            p2=p1;
        }
        else
        {
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }
    return head;
}
pnode insert(pnode h, int n, int num)//
{
    pnode p1,p2,p3;
    int i=0;
    int a;
    p1=h;
    for (i=n;i>0;i--)
    {
        p1=p1->next;
    }
    p2=p1->next;
    p3=(pnode)malloc(sizeof(pnode));
    p3->data=num;
    p3->next=p2;
    p1->next=p3;
    return h;

}
pnode del(pnode h,int n)
{
    pnode p1,p2;
    if (n==0)
    {
        h=h->next;
        return h;
    }
    else
    {
        p1=h;
        while((n-1)!=0)
        {
            p2=p1;
            p1=p1->next;
            n--;
        }
        p2->next=p1->next;
        free(p1);
        return h;
    }

}

void main()
{
    int n;
    pnode q;
    pnode in;
    int innum;
    printf("the length:\n");
    scanf("%d",&n);
    q=creat(n);
    in = del(q,4);
    //printf("innum:\n");
    //scanf("%d",&innum);
    //in=insert(q,2,innum);
    printf("all the numbers:");
    while(in)
    {
        printf("%d",in->data);
        in=in->next;
    }

}


/*
char	MapAllowed[256];
int main(int argc,char *argv[])
{
    int c=0;
    extern char *optarg;
    while ((c = getopt(argc, argv, "ac:im:")) != EOF)
        switch(c)
        {
            case 'a': printf("a");break;
            case 'c':
                while (*optarg)
                {
                    MapAllowed[*optarg] = *optarg;
                    optarg++;
                }
                break;
            case 'i': printf("i"); break;
            case 'm': printf("m"); break;
        }
}
*/
