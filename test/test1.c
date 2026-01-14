#define _CRT_SECURE_NO_WARNINGS 1

//2.2.1_1
//顺序表的静态分配
// 
//#include <stdio.h>
//#include <string.h>
//
//#define MAXSIZE 10
//typedef struct {
//	int data[MAXSIZE];
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//
//int main()
//{
//	SqList L;
//	InitList(&L);
//	printf("length:%d\n", L.length);
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		printf("%d", L.data[i]);
//	}
//
//	return 0;
//}
//
//void InitList(SqList* L)
//{
//	memset(L->data, 0, sizeof(L->data));
//	L->length = 0;
//}

//2.2.1_2
//顺序表的动态分配
//#include <stdio.h>
//#include <stdlib.h>
//
//#define INITSIZE 10
//typedef struct
//{
//	int* data;
//	int maxsize;
//	int length;
//}SqList;
//
//void InitList(SqList* L);
//void IncreseSize(SqList* L, int len);
//
//int main()
//{
//	SqList L;
//	InitList(&L);
//	return 0;
//}
//
//void InitList(SqList* L)
//{
//	L->data = (int*)malloc(INITSIZE * sizeof(int));
//	L->length = 0;
//	L->maxsize = INITSIZE;
//}
//
//void IncreseSize(SqList* L, int len)
//{
//	int* p = L->data;
//	L->data = (int*)malloc((L->maxsize + len) * sizeof(int));
//	for (int i = 0; i < L->length; i++)
//	{
//		L->data[i] = p[i];
//	}
//	L->maxsize += len;
//	free(p);
//}


//2.2.2_1
//顺序表的插入
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MAXSIZE 10
//typedef struct
//{
//	int data[MAXSIZE];
//	int length;
//}SqList;
//
//bool ListInsert(SqList* L, int i, int e);
//
//int main()
//{
//	SqList L;
//	InitList(&L);
//	//此处省略一些代码，插入几个元素
//
//	ListInsert(&L, 3, 3);
//
//	return 0;
//}
//
//bool ListInsert(SqList* L, int i, int e)
//{
//	if ((i < 1) || (i > L->length+1))
//	{
//		return false;
//	}
//	if else(L->length >= MAXSIZE)
//	{
//		return false;
//	}
//	else
//	{
//		for (int j = L->length; j >= i; j--)
//		{
//			L->data[j] = L->data[j - 1];
//		}
//		L->data[i - 1] = e;
//		L->length++;
//		return true;
//	}
//}



//2.2.2_2
//顺序表的删除
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MAXSIZE 10
//typedef struct 
//{
//	int data[MAXSIZE];
//	int length;
//}SqList;
//
//bool ListDelete(SqList* L, int i, int e);
//
//int main()
//{
//	SqList(L);
//	InitList(&L);
//	//省略，插入几个元素
//	int e = -1;
//	if (ListDelete(&L, 3, e))
//	{
//		printf("已删除第三个元素，删除值=%d\n", e);
//	}
//	else
//	{
//		printf("位序i不合法\n");
//	}
//	return 0;
//}
//
//bool ListDelete(SqList* L, int i, int e)
//{
//	if ((i < 1) || (i > L->length))
//	{
//		return false;
//	}
//	else
//	{
//		e = L->data[i - 1];
//		for (int j = i; j < L->length; j++)
//		{
//			L->data[j - 1] = L->data[j];
//		}
//		L->length--;
//		return true;
//	}
//}


