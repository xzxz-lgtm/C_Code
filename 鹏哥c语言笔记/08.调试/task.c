#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//8.1
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

//8.2 例子1：1! + 2! + 3! + ……
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

////8.3 例子2：死循环
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

////8.4 字符串复制
//#include <assert.h>
////返回类型char*：实现链式访问，返回目标空间的起始地址
//char* my_strcpy(char* dest, const char* src)	//const保证不会修改src
//{
//	char* ret = dest;
//	//断言
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	/*while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;*/
//	//简洁写法
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//return dest //err
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXXXXXXXXXX";
//	char arr2[] = "hello bit";
//	char* p = NULL;
//
//	//my_strcpy(arr1, p);
//
//	//printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1, arr2));
//
//	return 0;
//}

////8.5 const修饰指针
//int main()
//{
//	const int num = 10;
//	////1.const在*左边：修饰*p
//	////p指向的对象不能通过p来改变，但是p变量本身的值可以改变
//	//const int* p = &num; //等价于int const* p
//	////*p = 20; //err
//	//int n = 100;
//	//p = &n; //ok
//
//	//printf("%d\n", *p);
//
//	////2.const在*右边：修饰p
//	////p指向的对象是可以通过p来改变的，但是不能修改p变量本身的值
//	//int* const p = &num;
//	//int n = 100;
//	//*p = 0; //ok
//	////p = &n; //err
//
//	//printf("%d\n", num);
//
//	//3. const int* const p;
//
//	return 0;
//}

////8.6求字符串长度
//#include <assert.h>
//int my_strlen(char* str)
//{
//	int cnt = 0;
//	assert(str);
//	while (*str != '\0')
//	{
//		cnt++;
//		str++;
//	}
//
//	return cnt;
//}
//
//int main()
//{
//	char arr[] = "hello bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}

////遗留题目
////BC51 判断三角形
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	while (scanf("%d %d %d", &a, &b, &c) == 3)
//	{
//		if ((a + b > c) && (a + c > b) && (b + c > a))
//		{
//			if ((a == b) && (b == c))
//				printf("等边三角形\n");
//			else if ((a == b) || (a == c) || (b == c))
//				printf("等腰三角形\n");
//			else
//				printf("普通三角形\n");
//		}
//		else
//		{
//			printf("不是三角形\n");
//		}
//	}
//
//	return 0;
//}

