#include<stdio.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, * Link;

void add(Link head){
    int x;
    printf("请输入数据");
    scanf("%d" , &x);
    Link p,p1 = head;
    p.data = x;
    if(head->next = NULL){
        head = p;
    }else{
        while(p1->next != NULL){
            p1 = p1->next;
        }
        p1 -> next = p;
    }
}
int main(){
    Link head;
    add(head);
    add(head);
    printf("%d",head->next->data);
    printf("1");
    return 0;
}
