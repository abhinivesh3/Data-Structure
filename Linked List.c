#include <stdio.h>
#include <stdlib.h>

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
    printf("NULL");
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

//sum of elements
int Sum(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

//maximum element in Linked list
int Max(struct Node *p){
    int max=INT32_MIN;
    while(p!=NULL){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
}

//main function
int main(){
    int a[]={3,6,8,20,7,16};
    create(a,6);
    Display(first);
    Rdisplay(first);
    printf("Number of elements in Linked List : ",Count(first));
    printf("Sum of elements in Linked List : ",Sum(first));
    printf("Maximum element in Linked List : ",Max(first));
}