#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <errno.h>
////1.malloc
//int main()
//{
//	//动态内存开辟
//	int* p = (int*)malloc(INT_MAX);	//x86：Not enough space
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}	//若没有free，这里程序结束时系统会自动回收内存空间


////2.calloc
////void* calloc (size_t num, size_t size);
//int main()
//{
//	//int* p = (int*)malloc(40);
//	int* p = (int*)calloc(10, sizeof(int));	//会把申请的空间初始化为0
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

////3.realloc
//int main()
//{
//	int* p = (int*)malloc(40);	
//	//int* p = (int*)realloc(NULL, 40);	//等价于malloc
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//扩容
//	int* ptr = realloc(p, 80);	
//	//两种方式原地扩容；异地搬家
//	// int* p = realloc(p, 80);	//error
//	//使用临时指针。若分配失败，p=NULL，之前的内存泄露
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));	//之前的数据会自动拷贝
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

////4.err版本
////void GetMemory(char* p)
////{
////	p = (char*)malloc(100);	//内存泄露
////}
//
////void GetMemory(char** p)
////{
////	*p = (char*)malloc(100);
////}
//
//char* GetMemory()
//{
//	char* p = (char*)malloc(100);
//	return p;
//}
//
//void Test()
//{
//	char* str = NULL;
//	//GetMemory(str);	//err //值传递，str仍然为空指针，解引用空指针
//	//GetMemory(&str);	//1.二级指针
//	str = GetMemory();	//2.接收返回值
//	if (str == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	strcpy(str, "hello");
//	printf("%s\n", str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


////5.柔性数组
////结构体中的最后一个元素允许是未知大小的数组
////前面必须有至少一个其他成员
////sizeof返回的这种结构大小不包含柔性数组的内存
//struct S
//{
//	int n;
//	int arr[];
//};
//
//int main()
//{
//	//printf("%zu\n", sizeof(struct S));	//4
//
//	//柔性数组的使用
//	//第一次分配
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);
//	if (ps == NULL) return 1;
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	//第二次分配
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 80);
//	if (ptr == NULL)
//	{
//		perror("realloc failed");
//		free(ps);
//		ps = NULL;
//		return 1;
//	}
//	ps = ptr;
//	ptr = NULL;
//
//	//...
//
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}

//6.柔性数组vs指针
//需要两次内存开辟，free也需要两次
struct S
{
	int n;
	int* arr;
};

int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		perror("ps malloc failed");
		return 1;
	}
	ps->n = 100;
	ps->arr = (int*)malloc(40);
	if (ps->arr == NULL)
	{
		perror("arr malloc failed");
		free(ps);
		ps = NULL;
		return 1;
	}

	//...使用

	free(ps->arr);
	free(ps);
	ps = NULL;


	return 0;
}


