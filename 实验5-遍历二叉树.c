#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_TREE_SIZE 100

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char TElemType;

typedef int Status ;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTree SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S) {
	//构造一个空栈S,S->base为存数据的动态数组
	S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base) exit(OVERFLOW);					//存储分配失败
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack S) {                      //返回栈是否为空
	return (S.base==S.top);
}

Status Push(SqStack *S,SElemType e) {
	//插入元素e为新的栈顶元素
	if(S->top-S->base>=S->stacksize) {				//栈满。追加存储空间
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) exit (OVERFLOW);			    //存储空间分配失败
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;									//top上移，并赋值e
}

Status Pop(SqStack *S,SElemType *e) {
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回
	//OK;否则返回ERROR
	if(S->top==S->base) return ERROR;
	*e=*--S->top;								    //top下移
	return OK;
}

Status CreateBiTree(BiTree *T) {
    TElemType c;  //char c
    scanf("%c",&c);
    if(' '==c) {
        *T=NULL;
    }
    else {
        if(!(*T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
        (*T)->data=c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return OK;
}

Status visit(TElemType c,int level) {   //char
    printf("%c位于%d层\n",c,level);
    return OK;
}

Status PrintElement(TElemType e) {  //返回数值  
    printf("%c-",e);
    return OK;
}

Status PreOrderTraverse(BiTree T,int level) {
    //采用二叉链表存储结构，Visit是对数据元素操作的应用函数
    //先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
    if(T) {
        visit(T->data,level);
        PreOrderTraverse(T->lchild,level+1);
        PreOrderTraverse(T->rchild,level+1);
    }
    return OK;
}

Status PreOrderTraverse2(BiTree T,Status(*Visit)(TElemType e)) {
    //采用二叉链表存储结构，Visit是对数据元素操作的应用函数
    //中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
     if (T) {
      if(PreOrderTraverse2(T->lchild,Visit))
        if(Visit(T->data))
            if(PreOrderTraverse2(T->rchild,Visit))  return OK;
      return ERROR;
   }
   else return OK;
}

Status PreOrderTraverse3(BiTree T) {
    //采用二叉链表存储结构，Visit是对数据元素操作的应用函数
    //后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
    if (T) {
      if(!PreOrderTraverse3(T->lchild))  return ERROR;
      PreOrderTraverse3(T->rchild);
      PrintElement(T->data);
   }
   return OK;
}

Status InOrderTraverse5(BiTree T,Status(*Visit)(TElemType e)) {
    //中序遍历二叉树T的非递归算法，对每个数据元素调用函数Visit
    SqStack S;
    InitStack(&S);
    SElemType p;   //二叉树类型的 
    p=T;
    while(p||!StackEmpty(S)) {   //逻辑或  只满足其中一个即可 
        if(p) {
            Push(&S,p);             //根指针进栈，遍历左子树
            p=p->lchild;
        }
        else {                      //根指针退栈，访问根节点，遍历右子树
            Pop(&S,&p);
            if(!Visit(p->data))
                return ERROR;
            p=p->rchild;
        }
    }
    //DestoryStack(&S);
    return OK;
}
int main() {
    int level=1;
    BiTree T=NULL;
    CreateBiTree(&T);
    printf("先序遍历输出\n");
    PreOrderTraverse(T,level);
    printf("中序遍历输出\n");
    PreOrderTraverse2(T,PrintElement);
    printf("\n后序遍历输出\n");
    PreOrderTraverse3(T);
//    printf("\n先序非递归输出\n");
//    PreOrderTraverse4(T,PrintElement);
    printf("\n中序非递归输出\n");
    InOrderTraverse5(T,PrintElement);
    return OK;
}

