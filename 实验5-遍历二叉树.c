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
	//����һ����ջS,S->baseΪ�����ݵĶ�̬����
	S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base) exit(OVERFLOW);					//�洢����ʧ��
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack S) {                      //����ջ�Ƿ�Ϊ��
	return (S.base==S.top);
}

Status Push(SqStack *S,SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S->top-S->base>=S->stacksize) {				//ջ����׷�Ӵ洢�ռ�
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) exit (OVERFLOW);			    //�洢�ռ����ʧ��
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;									//top���ƣ�����ֵe
}

Status Pop(SqStack *S,SElemType *e) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������
	//OK;���򷵻�ERROR
	if(S->top==S->base) return ERROR;
	*e=*--S->top;								    //top����
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
    printf("%cλ��%d��\n",c,level);
    return OK;
}

Status PrintElement(TElemType e) {  //������ֵ  
    printf("%c-",e);
    return OK;
}

Status PreOrderTraverse(BiTree T,int level) {
    //���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
    if(T) {
        visit(T->data,level);
        PreOrderTraverse(T->lchild,level+1);
        PreOrderTraverse(T->rchild,level+1);
    }
    return OK;
}

Status PreOrderTraverse2(BiTree T,Status(*Visit)(TElemType e)) {
    //���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
     if (T) {
      if(PreOrderTraverse2(T->lchild,Visit))
        if(Visit(T->data))
            if(PreOrderTraverse2(T->rchild,Visit))  return OK;
      return ERROR;
   }
   else return OK;
}

Status PreOrderTraverse3(BiTree T) {
    //���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    //�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
    if (T) {
      if(!PreOrderTraverse3(T->lchild))  return ERROR;
      PreOrderTraverse3(T->rchild);
      PrintElement(T->data);
   }
   return OK;
}

Status InOrderTraverse5(BiTree T,Status(*Visit)(TElemType e)) {
    //�������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
    SqStack S;
    InitStack(&S);
    SElemType p;   //���������͵� 
    p=T;
    while(p||!StackEmpty(S)) {   //�߼���  ֻ��������һ������ 
        if(p) {
            Push(&S,p);             //��ָ���ջ������������
            p=p->lchild;
        }
        else {                      //��ָ����ջ�����ʸ��ڵ㣬����������
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
    printf("����������\n");
    PreOrderTraverse(T,level);
    printf("����������\n");
    PreOrderTraverse2(T,PrintElement);
    printf("\n����������\n");
    PreOrderTraverse3(T);
//    printf("\n����ǵݹ����\n");
//    PreOrderTraverse4(T,PrintElement);
    printf("\n����ǵݹ����\n");
    InOrderTraverse5(T,PrintElement);
    return OK;
}

