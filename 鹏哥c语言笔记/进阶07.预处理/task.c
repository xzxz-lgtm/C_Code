//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>

//1.预定义符号
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("file:%s line=%d date:%s time:%s i=%d\n", 
//			__FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//
//	//printf("%d", __STDC__);
//
//	return 0;
//}

//2.宏 宏无法调试
//#define SQUARE(X) ((X)*(X))	//规范写法
//int main()
//{
//	int r = SQUARE(5);
//	printf("%d\n", r);
//
//	int m = SQUARE(5 + 1);
//	printf("%d\n", m);	//X*X: 5+1*5+1
//
//	return 0;
//}

//3.#
////#define PRINT(N) printf("the value of N is %d\n", N);
//#define PRINT(N) printf("the value of "#N" is %d\n", N);	//字符串化操作符
//
//int main()
//{
//	int a = 10;
//	PRINT(a);
//
//	int b = 20;
//	PRINT(b);
//
//	return 0;
//}

////4.##记号连接符
//#define CAT(Class, Num) Class##Num
//
//int main()
//{
//	int Class106 = 100;
//	printf("%d\n", CAT(Class, 106));
//
//	return 0;
//}

////5.宏的副作用
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//
//int main()
//{
//	int a = 5;
//	int b = 4;
//	int m = MAX(a++, b++);
//	//((a++) > (b++) ? (a++) : (b++))
//
//	printf("a=%d b=%d m=%d\n", a, b, m);	//7 5 6
//
//	return 0;
//}

//6.#undef
//#define M 100
//int main()
//{
//	printf("%d\n", M);
//#undef M
//	printf("%d\n", M);
//
//	return 0;
//}

//7.条件编译
//#define M 3

//int main()
//{
//#if M < 5
//	printf("hehe\n");
//#elif M == 5
//	printf("haha\n");
//#else
//	printf("heihei\n")
//#endif
//
//	return 0;
//}

//int main()
//{
////#if defined(M)	
//#ifdef M
////#if !defined(M)
////#ifndef M
//	printf("hehe\n");
//#endif
//	return 0;
//}

//8.防止头文件重复包含
//#ifndef __TEST_H__
//#define __TEST_H__
//
//int Add(int x, int y);
//
//#endif
//新写法
//#pragma once

////9.offsetof实现
//#include <stddef.h>
//
//#define MY_OFFSETOF(type, mem) (size_t)&(((type*)0)->mem)
////假设0x00000000处存放struct S变量的地址
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//int main()
//{
//	struct S s = { 0 };
//	//printf("%zu\n", offsetof(struct S, c1));
//	//printf("%zu\n", offsetof(struct S, i));
//	//printf("%zu\n", offsetof(struct S, c2));
//
//	printf("%zu\n", MY_OFFSETOF(struct S, c1));
//	printf("%zu\n", MY_OFFSETOF(struct S, i));
//	printf("%zu\n", MY_OFFSETOF(struct S, c2));
//
//	return 0;
//}
//
