#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(linklist)

typedef struct node{
	int data;
	struct node *next;
}linklist;

linklist *ehead_creat(){
	int x;
	linklist *head,*p,*rear;
	head=(linklist*)malloc(sizeof(linklist));
	
	rear=head;
	printf("输入数字序列，以0结尾:\n\t");
	scanf("%d",&x);
	while(x!=0){
		p=(struct node*)malloc(LEN);
		p->data=x;
		
		rear->next=p;
		rear=p;
		scanf("%d",&x);
	}
	rear->next=NULL;
	return(head);
}
void delsame(struct node* head) {
    struct node* p = head;
    struct node* q = NULL;
    struct node* temp = NULL;

    // 外循环，遍历每个节点
    while (p != NULL) {
        q = p;
        // 内循环，检查后面的节点是否与当前节点的值相同
        while (q->next != NULL) {
            if (q->next->data == p->data) {
                // 发现重复，删除q->next节点
                temp = q->next;
                q->next = q->next->next;
                free(temp); // 释放内存
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

int countx(struct node* head, int x) {
    struct node* p = head->next; // 跳过头节点开始遍历
    int count = 0;

    // 遍历链表
    while (p != NULL) {
        if (p->data == x) {
            count++;
        }
        p = p->next;
    }

    return count;
}

linklist *hhead_creat(){
	int x;
	linklist *head,*p;
	head=(linklist*)malloc(sizeof(linklist));
	head->next=NULL;
	printf("输入数字序列，以0结尾:\n\t");
	scanf("%d",&x);
	while(x!=0){
		p=(struct node*)malloc(LEN);
		p->data=x;
		p->next=head->next;
		
		head->next=p;
		
		scanf("%d",&x);
	}

	return(head);
}

void print(linklist *head){
	linklist *p;
	p=head->next;
	while (p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}

int main(){
	linklist *head;
	head=ehead_creat();
	print(head);
	return 0;
}