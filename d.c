#include <stdio.h>
#include <stdint.h>

#define max 20

typedef struct{
    int a[max];
    int top;
} qu;

qu st,*s;

void  csh(qu*s){
    int x;
    scanf("%d",&x);
    
    int top=0;
    while (x!=0&&top!=max){
        s->a[top]=x;
        top++;
        scanf("%d",&x);
        if(top==max){
            printf("栈已满");
            break;
        }
    }
    s->top=top-1;
    while (x!=0){
        scanf("%d",&x);
    }
}

void cz(qu*s){
    if(e(s)==1){
            int top=s->top;
            s->a[top]=s->a[top+1];
            s->top--;

    }
    else printf("此栈为空");
    

}

void rz(qu*s,int x){
    s->top++;
    s->a[s->top]=x;
}

void fx(qu*s,int x){
    if(e(s)==1){
        int n=s->top;
        for(int i=0;i<=n;i++){
            if(s->a[i]==x){
                printf("第%d个位置的值为%d",i+1,x);
            }
        }
    }
    else printf("此栈为空");
}

int e(qu*s){
    if(s->top>=0){
        return 1;
    }
    else return 0;
}

void get(qu*s){
    if(e(s)==1){
        printf("%d\n",s->a[s->top]);

    }
    else printf("此栈为空\n");
}

typedef struct {
    int a[max];
    int head;
    int rear;
}dl;

void cs(dl*c){
    int x;
    c->head=c->rear=0;

    scanf("%d",&x);
    while(x!=0){
        c->a[c->rear]=x;
        if(c->rear+2==max){
            printf("队列已满，停止继续初始化\n");
            break;
        }
        else c->rear++;

        scanf("%d",&x);
    }
    while(x!=0){
        scanf("%d",&x);
    }

}

void cd(dl*c){
    if(c->head-c->rear<=0){
        c->a[(c->head)%max]=c->a[(c->rear+1)%max];
    c->head++;
    }else printf("此队列已空");
    

}

int yk(dl*c){
    if(c->head-c->rear<=0){
        return 1;
    }else return 0;
}

void rd(dl*c,int x){
    if((c->rear+2)%max==max){
        printf("队列已满，停止继续初始化");
        return;
    }
    c->rear++;
    c->a[(c->rear)%max]=x;
}

void qt(dl*c){
    printf("队头元素为%d\n",c->a[(c->head)%max]);
}

int main() {
    int choice, data;
    qu stack;
    dl queue;

    while(1) {
        printf("请选择操作类型：\n1. 栈\n2. 循环队列\n3. 退出\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // 栈操作
                int sss;
                do{
                
                printf("栈操作：\n1. 初始化\n2. 入栈\n3. 出栈\n4. 打印栈顶\n5. 检查是否为空\n6.返回\n");
                scanf("%d", &sss);
                switch(sss) {
                    case 1:
                        csh(&stack);
                        printStack(&stack); // 初始化后打印栈的内容
                        break;
                    case 2:
                        printf("输入要入栈的数据：");
                        scanf("%d", &data);
                        rz(&stack, data);
                        printStack(&stack); // 入栈后打印栈的内容
                        break;
                    case 3:
                        cz(&stack);
                        printStack(&stack); // 初始化后打印栈的内容
                        break;
                    case 4:
                        get(&stack);
                        printStack(&stack); // 初始化后打印栈的内容
                        break;
                    case 5:
                    
                        if (e(&stack) == 0) {
                            printf("栈为空\n");
                        } else printf("栈不空\n");
                        printStack(&stack); // 初始化后打印栈的内容
                        break;

                    // 其他栈操作的案例...
                }
                
        }while(sss!=6);break;
            case 2: // 循环队列操作
                int xxx;
                do{printf("队列操作：\n1. 初始化\n2. 入队\n3. 出队\n4. 显示队首\n5. 检查是否为空\n6.返回\n");
                scanf("%d", &xxx);
                switch(xxx) {
                    case 1:
                        cs(&queue);
                        printQueue(&queue); // 初始化后打印队列的内容
                        break;
                    case 2:
                        printf("输入要入队的数据：");
                        scanf("%d", &data);
                        rd(&queue, data);
                        printQueue(&queue); // 入队后打印队列的内容
                        break;
                    case 3:
                        cd(&queue);
                        printQueue(&queue); // 初始化后打印栈的内容
                        break;
                    case 4:
                        qt(&queue);
                        printQueue(&queue); // 初始化后打印栈的内容
                        break;
                    case 5:
                        if (yk(&queue) == 0) {
                            printf("队列为空\n");
                        } else printf("队列不空\n");
                        printQueue(&queue); // 初始化后打印栈的内容
                        break;
                    // 其他队列操作的案例...
                }
                }
            while(xxx!=6);break;
            case 3:
                printf("退出程序...\n");
                return 0;
            default:
                printf("无效选择，请重试。\n");
        }
    }
    return 0;
}
 

// 打印栈内容的函数
void printStack(qu *s) {
    if (e(s) == 0) {
        printf("栈为空\n");
    } else {
        
        printf("栈内容：");
        for (int i = 0; i <=s->top; i++) {
            printf("%d ", s->a[i]);
        }
        printf("\n");
    }
}

// 打印队列内容的函数
void printQueue(dl *c) {
    if (yk(c) == 0) {
        printf("队列为空\n");
    } else {
        printf("队列内容：");
        for (int i = c->head; i < c->rear; i++) {
            printf("%d ", c->a[i % max]);
        }
        printf("\n");
    }
}