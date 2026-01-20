#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//例子1：1! + 2! + 3! + ……
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		int fac = 1;
//		for (j = 1; j <= i; j++)
//		{
//			fac *= j;	//得到i！
//		}
//		sum += fac;
//	}
//
//	printf("1!+2!+3!+…+n!=%d", sum);
//	return 0;
//}
////优化的写法
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 0;
//	int fac = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		fac *= i; //利用i!=i*(i-1)!
//		sum += fac;
//		printf("%d!", i);
//		if (i != n)
//		{
//			printf("+"); //打印的等式左侧只显示到输入指定的n
//		}
//		else
//		{
//			printf("=");
//		}
//	}
//
//	printf("%d", sum);
//
//	return 0;
//}

////例子2：死循环
////局部变量存储在栈区，栈区内存使用是先使用高地址再使用低地址。
////而数组随着下标增长地址由低到高。
////这里的地址关系：从高到低：i，适当空间，arr[9]-arr[0];数组越界访问可能访问到i，把i改为0。
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;	//arr[12]和i地址相同
//		printf("hehe\n");
//	}
//
//	return 0;
//}

#include <assert.h>
void my_strcpy(char* dest, const char* src)	//const保证不会修改src
{
	//断言
	assert(dest != NULL);
	assert(src != NULL);

	/*while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = *src;*/
	//简洁写法
	while (*dest++ = *src++)
	{
		;
	}
}

int main()
{
	char arr1[20] = "XXXXXXXXXXXXXXX";
	char arr2[] = "hello bit";
	char* p = NULL;

	my_strcpy(arr1, p);

	printf("%s\n", arr1);

	return 0;
}

