#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define LEN sizeof(linklist)

typedef struct node {
    int data;
    struct node* next;
    struct node* bef;
}linklist;
void fre(linklist* head) {
    if (head == NULL) return;

    linklist* temp = head;
    linklist* next;

    while (1) {
        next = temp->next;
        free(temp);
        temp = next;
        if (temp == head) break;
    }
}
linklist* ec() {
    int x;
    linklist* head, * p, * rear;
    head = (linklist*)malloc(sizeof(linklist));

    rear = head;
    printf("输入数字序列，以0结尾:\n\t");
    scanf("%d",&x);
    while (x != 0) {
        p = (struct node*)malloc(LEN);
        p->data = x;
        p->bef=rear;
        rear->next = p;
        rear = p;
        scanf("%d", &x);
    }
    rear->next = head;
    head->bef=rear;
    return(head);
}

void fx(linklist*head,int x){
    linklist*t=head;
    int sum=0;
    do{
        if(t->data==x){
            printf("第%d个节点值为%d\n",sum,x);
        }
        t=t->next;
        sum++;
    }while(t!=head);
}

void ab(linklist*head,int x,int y){
    linklist*t=head;
    do{
        if(t->data==x){
            linklist*a=t->bef;
            linklist*b=(struct node*)malloc(LEN);
            b->next=t;
            b->bef=t->bef;
            a->next=b;
            t->bef=b;
            b->data=y;
        }
        t=t->next;
    }while(t!=head);
}

void aa(linklist*head,int x,int y){
    linklist*t=head;
    do{
        if(t->data==x){
            linklist*a=t->next;
            linklist*b=(struct node*)malloc(LEN);
            b->bef=t;
            b->next=a;
            a->bef=b;
            t->next=b;
            b->data=y;
        }
        t=t->bef;
    }while(t!=head);
}

void dx(linklist*head,int x){
    linklist*t=head;
    do{
        if(t->data==x){
            linklist*a=t->bef;
            linklist*b=t->next;
            a->next=b;
            b->bef=a;
            free(t);
            t=a;
        }
        t=t->next;
    }while(t!=head);
}

void nz(linklist*head){
    linklist*t=head;
    do{
        linklist*b=t->next;
        t->next=t->bef;
        t->bef=b;
        t=b;
    }while(t!=head);
    head=head->bef;
}


void print(linklist* head) {
    linklist* p;
    p = head->next;
    while (p != NULL && p != head) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void main(){
    int choice;
    int keyx;
    int new;
    linklist* head;
    int i=0;
    do {
        printf("\n--- 双循环链表操作 ---\n");
        // 添加单循环链表的操作菜单
        printf("1. 尾插法初始化循环链表\n");
        printf("2. 逆置双循环链表\n");
        printf("3. 查找值为x的节点\n");
        printf("4. 在值为x的节点前面插入新节点\n");
        printf("5. 在值为x的节点后面插入新节点\n");
        printf("6. 删除值为x的节点\n");
        printf("7. 退出程序\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        // 对应的函数调用或逻辑
        switch (choice) {
        case 1:
            head=ec();
            print(head);
            i++;//头插法初始化
            printf("按任意键继续");getchar();getchar();break;
        case 2:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            nz(head);
            print(head);

            //尾插法初始化
            printf("按任意键继续");getchar();getchar();break;
        case 3:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入要查找位置的节点的值:");
            scanf("%d",&keyx);
            fx(head,keyx);// 查找值为x的节点
            printf("按任意键继续");getchar();getchar();break;
        case 4:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入前插入节点的节点值与要插入的节点的值:");
            scanf("%d %d",&keyx,&new);
            ab(head,keyx,new);
            print(head);// 在值为x的节点前面插入新节点
            printf("按任意键继续");getchar();getchar();break;
        case 5:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入后插入节点的节点值与要插入的节点的值:");
            scanf("%d %d",&keyx,&new);
            aa(head,keyx,new);
            print(head);// 在值为x的节点后面插入新节点
            printf("按任意键继续");getchar();getchar();break;
        case 6:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入要删除的节点的值:");
            scanf("%d",&keyx);
            dx(head,keyx);
            print(head);// 删除值为x的节点
            printf("按任意键继续");getchar();getchar();break;
        case 7:
            if(i==0){
                break;
            }
            fre(head);
            printf("退出程序\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
        }
    } while (choice != 7);
}