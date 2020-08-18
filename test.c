#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
//¡¥’ª
/////////////////////////////////////////////////////////
typedef char ElemType;
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;
void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
void LinkStackShow(LinkStack *pst);
int LinkStackSize(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);
/////////////////////////////////////////////////////

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

bool LinkStackIsEmpty(LinkStack *pst){
	return *pst == NULL;
}
void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = *pst;
	*pst = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if (*pst != NULL)
	{
		LinkStackNode *p = *pst;
		*pst = p->link;
		free(p);
	}
}
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst != NULL);
	return (*pst)->data;
}
int LinkStackSize(LinkStack *pst)
{
	assert(pst != NULL);
	int size = 0;
	LinkStackNode *p = *pst;
	while (p != NULL)
	{
		size++;
		p = p->link;
	}
	return size;
}
void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while (p != NULL)
	{
		*pst = p->link;
		free(p);
		p = *pst;
	}
}
//¿®∫≈∆•≈‰
/////////////////////////////////////////////////////
bool isValid(char * s){
	if (s == NULL){
		return false;
	}
	if (*s == '\0'){
		return true;
	}
	LinkStack L;
	ElemType item;
	LinkStackInit(&L);
	while (*s != '\0'){
		if (*s == '{' || *s == '(' || *s == '['){
			LinkStackPush(&L, *s);
		}
		else{
			if (LinkStackIsEmpty(&L)){
				return false;
			}
			item = LinkStackTop(&L);
			if ((item != '{'&&*s == '}') || (item != '('&&*s == ')') || (item != '['&&*s != ']')){
				return false;
			}
			LinkStackPop(&L);
		}
		s++;
	}
	if (!LinkStackIsEmpty(&L)){
		return false;
	}
	return true;
}
int main(){
	char *s = "(";
	bool w = isValid(s);
	return 0;
}