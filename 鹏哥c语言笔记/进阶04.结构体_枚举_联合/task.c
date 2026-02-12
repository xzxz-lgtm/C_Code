#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////1.结构体内存对齐
////规则：
////1.第一个成员在与结构体变量偏移量为0的地址
////2.其他成员变量要对齐到对齐数的整数倍的地址（从0开始）处
////对齐数=8（VS默认的对齐数）和该成员大小的较小值
////3.结构体总大小为最大对齐数的整数倍
////4.若嵌套了结构体：嵌套的结构体对齐到自己的最大对齐数的整数倍处，
////结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
//#include <stddef.h>
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	struct S1 s1;
//	struct S2 s2;
//
//	printf("%zu\n", sizeof(struct S1));	//12
//	printf("%zu\n", sizeof(struct S2));	//8
//	//设计结构体时尽量让占用空间小的成员集中在一起
//
//	//计算结构体成员相对起始位置的偏移量
//	printf("%zu\n", offsetof(struct S1, c1));	//0	
//	printf("%zu\n", offsetof(struct S1, i));	//4
//	printf("%zu\n", offsetof(struct S1, c2));	//8
//
//	printf("%zu\n", offsetof(struct S2, c1));	//0	
//	printf("%zu\n", offsetof(struct S2, c2));	//1
//	printf("%zu\n", offsetof(struct S2, i));	//4
//
//	printf("%zu\n", sizeof(struct S4));
//
//	return 0;
//}

////2.默认对齐数
//#pragma pack(4)	//修改默认对齐数为4
//struct S
//{
//	int i;	//对齐数为4
//	double d;	//现在对齐数为4
//};
//#pragma pack()	//恢复默认值
//
//int main()
//{
//	printf("%zu\n", sizeof(struct S));	//12
//
//	return 0;
//}

////3.结构体传参
//struct S
//{
//	int data[1000];
//	int num;
//};
//
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
//
//void print2(const struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ps->data[i]);
//	}
//	printf("%d\n", ps->num);
//}
//
//int main()
//{
//	struct S s = { { 1,2,3 }, 100 };
//	print1(s);	//传值调用，会在栈区开辟空间
//	print2(&s);	//传址调用
//
//	return 0;
//}

////4.位段
////成员必须是unsigned int或signed int或char
//struct A
//{
//	int _a : 2; //2bit，可以节省内存，但跨平台问题
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//
//int main()
//{
//	printf("%zu\n", sizeof(struct A));	//8
//	//位段的空间是以4个字节（int）或1个字节（char）来开辟的
//	
//	return 0;
//}

////5.位段
//struct S
//{
//	char a : 3;	//1Byte
//	char b : 4;
//	char c : 5;	//1Byte
//	char d : 4;	//1Byte
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;	//截断为010
//	s.b = 12;	//1100
//	s.c = 3;	//00011
//	s.d = 4;	//0100
//	//00000000 00000000 00000000
//	//01100010 00000011 00000100
//	//0x62 03 04
//
//	printf("%d %d %d %d ", s.a, s.b, s.c, s.d);
//
//	return 0;
//}

//6.枚举