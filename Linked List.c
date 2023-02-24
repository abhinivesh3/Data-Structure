#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

//struct node create
struct Node{
    int data;
    struct Node *next;
} *first=NULL;

// create an  linked list
void create(int a[],int n){
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

//Display linkedlist
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL");
}

//Recursive Display function
void Rdisplay(struct Node *p){
    if(p!=NULL){
        printf("%d->",p->data);
        Rdisplay(p->next);
    }
    //printf("NULL");
}

//counting element 
int Count(struct Node *p ){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

//Recursive counting element 
int Rcount(struct Node *p ){
    if(p!=NULL){
        return Rcount( p->next)+1;
    }
    else{
        return 0;
    }
}

//sum of elements
int Sum(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

//Recursive sum of elements
int Rsum(struct Node *p){
    if(p!=NULL){
        return Rsum(p->next)+p->data;
    }
    else{
        return 0;
    }
}

//maximum element in Linked list
int Max(struct Node *p){
    int max=INT_MIN; //INT32_MIN
    while(p!=NULL){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

// Recursive maximum element in Linked list
int Rmax(struct Node *p){
    int x=0;
    if(p==NULL){
        return INT_MIN;
    }
    else{
        x=Rmax(p->next);
        if(x>p->data){
            return x;
        }
        else{
            return p->data;
        }
    }
}

//Searching element with given position or index
struct Node* Search(struct Node *p,int key){
    while(p!=NULL){
        if(p->data==key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

//Recursive searching element with given position or index
struct Node* Rsearch(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p;
    }
    return Rsearch(p->next,key);
}

//Searching element with given position or index Linear Search
struct Node* LSearch(struct Node *p,int key){
    struct Node *q=NULL;
    while(p!=NULL){
        if(p->data==key){
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
    return q;
}

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index<0 || index>Count(p)){
        return ;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

//Insert sorting element in Linked List
void SortInsert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

//delete element in given index in linked list
int Delete(struct Node *p,int index){
    struct Node *q;
    int x=-1;
    if(index<1 || index>Count(p)){
        return -1;
    }
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

//Linked list is sorted or not 
int isSorted(struct Node *p){
    int x=-65536;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

///remove duplicates from sorted Linked list
void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

//Reverse element in linked list
void Reverse(struct Node *p){
    int *A,i=0;
    struct Node *q;
    A=(int*)malloc(sizeof(int)*count(p));
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse3(struct Node *q,struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
//main function
int main(){
    int a[]={3,6,8,20,7,16};
    create(a,6);
    Display(first);
    Rdisplay(first);
    printf("\nNumber of elements in Linked List : %d",Count(first));
    printf("\nRecursive Number of elements in Linked List : %d",Rcount(first));
    printf("\nSum of elements in Linked List : %d",Sum(first));
    printf("\nRecursive Sum of elements in Linked List : %d",Rsum(first));
    printf("\nMaximum element in Linked List : %d",Max(first));
    printf("\nRecursive Maximum element in Linked List : %d\n",Rmax(first));
    int pos;
    scanf("%d",&pos);
    printf("\nSearch element in Linked List : %d",Search(first,pos));
    printf("\nRecurive Search element in Linked List : %d",Rsearch(first,pos));
    printf("\nLinear Search element in Linked List : %d",LSearch(first,pos));
    int index,value;
    scanf("\n%d %d",&index,&value);
    Insert(first,index,value);
    printf("\nInsert element to linked list : ");
    Display(first);
    scanf("\n%d",&value);
    SortInsert(first,value);
    printf("\nInsert sorting in Linked list : ");
    scanf("\n%d",&index);
    printf("\nDelete element in Linked List : %d ", Delete(first,index));
    Display(first);
    if(isSorted(first)==1){
        printf("\nLinked List is sorted ");
    }
    else{
        printf("\nLinked List is not sorted");
    }
    RemoveDuplicate(first);
    Reverse(first);
    Reverse2(first);
    Reverse3(first,first)
}