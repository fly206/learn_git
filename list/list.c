#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//
//链表相关练习
//链表结构体建立
//
typedef struct list {
    int a;
    char c;
    struct list *next;
}list;
//
//链表创建
//
void create_list(list *head)
{
    list *node=NULL;
    list *addnode=NULL;
    //list *head=NULL;
    int i=0;
    printf("please input i:\n");
    scanf("%d",&i);
    node=(list *)malloc(sizeof(list));
    if(node==NULL){
        printf("malloc error\n");
    }
    head=node;
    while(i--){
        addnode=(list *)malloc(sizeof(list));
        if(addnode==NULL){
            printf("malloc error\n");
        }
        else {
            node->next=addnode;
            node=node->next;
        }
    }
    printf("ok\n");
}
//
//将链表内容输出屏幕
//
void print_list(list *head)
{
    list *node=NULL;
    node=head;
    while(node!=NULL){
        printf("%d %c\n",node->a,node->c);
        node=node->next;
    }
}
//
//链表清除
//
void destroy_list(list *head)
{
    list *node=NULL;
    list *dehead=head;
    while(dehead!=NULL){
        node=dehead;
        dehead=dehead->next;
        free(node);
    }
}
//
//链表复制
//
void cp_list(list *head,list *lis2)
{
    list *node1=NULL;
    list *node2=NULL;
    list *cp=NULL;
    node1=head;
    node2=lis2;
    while(node1!=NULL){
        node1->a=node2->a;
        node1->c=node2->c;
        node1=node1->next;
        if(node2->next){
            cp=(list *)malloc(sizeof(list));
            node2->next=cp;
            node2=node2->next;
        }
        else {
            node2=node2->next;
        }
    }
    free(cp);
}
//
//链表节点删除
//
void det_list(list *head)
{
    list *node=NULL;
    list *det=NULL;
    char s='\n';
    node=head;
    print_list(node);
    printf("please input the number you want to detect\n");
    scanf("%c\n",&s);
    while(node!=NULL){
        det=node->next;
        if(head->a=s-'0'){
            head=head->next;
            free(node);
            node=head;
        }
        if(det->a=s-'0'){
            node->next=det->next;
            free(det);
        }
    }
    printf("please input char you want to detect\n");
    scanf("%c\n",&s);
    while(node!=NULL){
        det=node->next;
        if(head->c=s){
            head=head->next;
            free(node);
            node=head;
        }
        if(det->c=s){
            node->next=det->next;
            free(det);
        }
    }
    print_list(head);
}
//
//链表赋值
//
void scan_list(list *head)
{
    list *node=NULL;
    char s;
    node=head;
    scanf("%c",&s);
    while(s!='\n'){
        node->c=s;
        node=node->next;
        if(node==NULL){
            break;
        }
    }
    print_list(head);
}


int main()
{
    list head;
    list h2;
    create_list(&head);
    scan_list(&head);
    cp_list(&head,&h2);
    print_list(&h2);
    det_list(&h2);
    destroy_list(&h2);
    print_list(&head);
    destroy_list(&head);
   return 0;
}

