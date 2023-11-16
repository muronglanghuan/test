#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define LEN sizeof(linklist)

typedef struct node {
    int data;
    struct node* next;
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
linklist* ehead_creat() {
    int x;
    linklist* head, * p, * rear;
    head = (linklist*)malloc(sizeof(linklist));

    rear = head;
    printf("输入数字序列，以0结尾:\n\t");
    scanf("%d",&x);
    while (x != 0) {
        p = (struct node*)malloc(LEN);
        p->data = x;

        rear->next = p;
        rear = p;
        scanf("%d", &x);
    }
    rear->next = NULL;
    return(head);
}

linklist* ecreat() {
    int x;
    linklist* head, * p, * rear;
    head = (linklist*)malloc(sizeof(linklist));

    rear = head;
    printf("输入数字序列，以0结尾:\n\t");
    scanf("%d",&x);
    while (x != 0) {
        p = (struct node*)malloc(LEN);
        p->data = x;

        rear->next = p;
        rear = p;
        scanf("%d", &x);
    }
    rear->next = head;
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
            }
            else {
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

linklist* hhead_creat() {
    int x;
    linklist* head, * p;
    head = (linklist*)malloc(sizeof(linklist));
    head->next = NULL;
    printf("输入数字序列，以0结尾:\n\t");
    scanf("%d", &x);
    while (x != 0) {
        p = (struct node*)malloc(LEN);
        p->data = x;
        p->next = head->next;

        head->next = p;

        scanf("%d", &x);
    }

    return(head);
}

linklist* hcreat() {
    int x;
    linklist* head, * p;
    head = (linklist*)malloc(sizeof(linklist));
    head->next = head;
    printf("输入数字序列，以0结尾:\n\t");
    scanf("%d", &x);
    while (x != 0) {
        p = (struct node*)malloc(LEN);
        p->data = x;
        p->next = head->next;

        head->next = p;

        scanf("%d", &x);
    }

    return(head);
}

void print(linklist* head) {
    linklist* p;
    p = head->next;
    while (p != NULL && p != head) {
        printf("%d\n", p->data);
        p = p->next;
    }
}
typedef struct {
    int data[MAX_SIZE];
    int length;
} SqList;

void initList(SqList* list) {
    printf("请输入顺序表的长度：");
    scanf("%d", &list->length);
    if (list->length > MAX_SIZE || list->length < 0) {
        printf("无效的长度！\n");
        exit(1);
    }
    printf("请输入顺序表的元素，用空格隔开：");
    for (int i = 0; i < list->length; i++) {
        scanf("%d", &list->data[i]);
    }
    printf("初始化成功！\n");
}

void insert(SqList* list, int position, int element) {
    if (position < 1 || position > list->length + 1) {
        printf("无效的位置！\n");
        return;
    }
    if (list->length >= MAX_SIZE) {
        printf("顺序表已满！\n");
        return;
    }
    for (int i = list->length - 1; i >= position - 1; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[position - 1] = element;
    list->length++;
    printf("插入成功！\n");
}

void delete(SqList* list, int position) {
    if (position < 1 || position > list->length) {
        printf("无效的位置！\n");
        return;
    }
    for (int i = position; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }
    list->length--;
    printf("删除成功！\n");
}

void printList(SqList* list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d \t", list->data[i]);
    }
    printf("\n");
}


int main() {
    int choice;
    do {
        printf("\n--- 主菜单 ---\n");
        printf("1. 顺序表\n");
        printf("2. 单链表\n");
        printf("3. 单循环链表\n");
        printf("4. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            SequentialListMenu();
            break;
        case 2:
            SingleLinkedListMenu();
            break;
        case 3:
            CircularLinkedListMenu();
            break;
        case 4:
            printf("退出程序。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
        }
    } while (choice != 4);

    return 0;
}

void SequentialListMenu() {
    SqList list;
    int choice, position, element;
    int i=0;

    do {
        printf("\n=====================\n");
        printf("1. 初始化顺序表\n");
        printf("2. 插入元素\n");
        printf("3. 删除元素\n");
        printf("4. 返回上一级菜单\n");
        printf("请选择一个操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            initList(&list);
            printList(&list);
            i++;
            printf("按任意键继续");getchar();getchar();break;
        case 2:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("请输入插入的位置和元素值：");
            scanf("%d %d", &position, &element);
            insert(&list, position, element);
            printList(&list);
            printf("按任意键继续");getchar();getchar();break;
        case 3:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("请输入删除元素的位置：");
            scanf("%d", &position);
            delete(&list, position);
            printList(&list);
            printf("按任意键继续");getchar();getchar();break;
        case 4:
            if(i==0){
                
                break;
            }
            printf("返回上一菜单。\n");
            break;
        default:
            printf("无效的输入！\n");
        } 

    } while (choice != 4);

}

void SingleLinkedListMenu() {
    int choice;
    int keyx;
    linklist* head;
    int i=0;
    do {
        printf("\n--- 单链表操作 ---\n");
        // 添加单链表的操作菜单
        printf("1. 头插法初始化\n");
        printf("2. 尾插法初始化\n");
        printf("3. 删除重复值的节点\n");
        printf("4. 统计值为x的节点数量\n");
        printf("5. 返回上一级菜单\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        // 对应的函数调用或逻辑
        switch (choice) {
        case 1:
            
            head = hhead_creat();
            print(head);// 头插法初始化
            i++;
            printf("按任意键继续");getchar();getchar();break;
        case 2:
            head = ehead_creat();
            print(head);// 尾插法初始化
            i++;
            printf("按任意键继续");getchar();getchar();break;
        case 3:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            delsame(head);
            print(head);// 删除重复值的节点
            printf("按任意键继续");getchar();getchar();break;
        case 4:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("请输入统计的节点值keyx：");
            scanf("%d", &keyx);
            printf("值为x的节点数量为:%d",countx(head, keyx));// 统计值为x的节点数量
            printf("按任意键继续");getchar();getchar();break;
        case 5:
            if(i==0){
                return;
            }
            fre(head);
            
            printf("返回上一菜单。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
        }
    } while (choice != 5);
}

void delx(linklist * head, int x) {

    if (head == NULL) return;
    linklist *temp = head;
    linklist *q=temp->next;
    do {
        if (q->data == x){
            temp->next=q->next;
            free(q);
            q=temp->next;

        }
        temp = temp->next;
        q=q->next;

    } while (temp != head);

}

void add_after(linklist* head, int x, int new_data) {
    if (head == NULL) return;
    linklist* temp = head;
    do {
        if (temp->data == x) {
            linklist* current = temp;
            linklist* new_node = (linklist*)malloc(sizeof(linklist));
            new_node->data = new_data;
            new_node->next = current->next;
            current->next = new_node;
        }
        temp = temp->next;

    } while (temp != head);
    
    
}

void add_before(linklist* head, int x, int new_data) {

    if (head == NULL) return;
    linklist* temp = head;
    do {
        if (temp->data == x) {
            linklist* current = temp;
            
            linklist* new_node = (linklist*)malloc(sizeof(linklist));
            new_node->data = new_data;
    
            if (head == current) {
                new_node->next = head;
                // 查找最后一个节点，将其 next 指向 new_node
                linklist* last = head;
                while (last->next != head) last = last->next;
                last->next = new_node;
                head = new_node;
            } else {
                linklist* prev = head;
                while (prev->next != current) prev = prev->next;
                prev->next = new_node;
                new_node->next = current;
            }

        }
        temp = temp->next;

    } while (temp != head);

}

void findx(linklist* head, int x) {
    if (head == NULL) return;

    int count = 0; // 用于记录节点的位置
    linklist* temp = head;
    do {
        if (temp->data == x) {
            printf("第%d个节点的值为%d\n", count, x);
        }
        temp = temp->next;

        count++;
    } while (temp != head);
}


void CircularLinkedListMenu() {
    int choice;
    int keyx;
    int new;
    linklist* head;
    int i=0;
    do {
        printf("\n--- 单循环链表操作 ---\n");
        // 添加单循环链表的操作菜单
        printf("1. 头插法初始化单循环链表\n");
        printf("2. 尾插法初始化单循环链表\n");
        printf("3. 查找值为x的节点\n");
        printf("4. 在值为x的节点前面插入新节点\n");
        printf("5. 在值为x的节点后面插入新节点\n");
        printf("6. 删除值为x的节点\n");
        printf("7. 返回上一级菜单\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        // 对应的函数调用或逻辑
        switch (choice) {
        case 1:
            head=hcreat();
            print(head);
            i++;//头插法初始化
            printf("按任意键继续");getchar();getchar();break;
        case 2:
            head=ecreat();
            print(head);
            i++;
            //尾插法初始化
            printf("按任意键继续");getchar();getchar();break;
        case 3:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入要查找位置的节点的值:");
            scanf("%d",&keyx);
            findx(head,keyx);// 查找值为x的节点
            printf("按任意键继续");getchar();getchar();break;
        case 4:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入前插入节点的节点值与要插入的节点的值:");
            scanf("%d %d",&keyx,&new);
            add_before(head,keyx,new);
            print(head);// 在值为x的节点前面插入新节点
            printf("按任意键继续");getchar();getchar();break;
        case 5:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入后插入节点的节点值与要插入的节点的值:");
            scanf("%d %d",&keyx,&new);
            add_after(head,keyx,new);
            print(head);// 在值为x的节点后面插入新节点
            printf("按任意键继续");getchar();getchar();break;
        case 6:
            if(i==0){
                printf("未初始化，请重新选择");
                printf("按任意键继续");getchar();getchar();break;
            }
            printf("输入要删除的节点的值:");
            scanf("%d",&keyx);
            delx(head,keyx);
            print(head);// 删除值为x的节点
            printf("按任意键继续");getchar();getchar();break;
        case 7:
            if(i==0){
                break;
            }
            fre(head);
            printf("返回上一菜单。\n");
            break;
        default:
            printf("无效选择，请重新输入。\n");
        }
    } while (choice != 7);
}
