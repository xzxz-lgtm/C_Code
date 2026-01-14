#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//5.4.1
//不创建临时变量，实现两个数的交换
//int main()
//{
//	int a = 3;
//	int b = 5;
//
//	printf("交换前:a=%d,b=%d\n", a, b);
//	a = a + b;	//可能溢出
//	b = a - b;
//	a = a - b;
//	printf("交换后:a=%d,b=%d\n", a, b);
//
//	return 0;
//}
//异或
//int main()
//{
//	int a = 3;
//	int b = 5;
//	
//	printf("交换前:a=%d,b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后:a=%d,b=%d\n", a, b);
//	
//	return 0;
//}

////5.4.2求一个整数存储在内存中二进制中的1的个数
//int main()
//{
//	int input = 0;
//	int i = 0;
//	int count = 0;
//	scanf("%d", &input);
//	for (i = 1; i <= 32; i++)
//	{
//		count += (input & 1);
//		input >>= 1;
//	}
//	printf("%d\n", count);
//
//	return 0;
//}

////5.4.3把一个数的第二位改为1
//int main()
//{
//	int a = 13;	//00000000000000000000000000001101
//	a |= (1 << 1);
//	printf("%d\n", a);
//	a &= ~(1 << 1);
//	printf("%d\n", a);
//
//	return 0;
//}

////5.4.4逻辑短路
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);	//false&&anything
//													//true||anything 
//
//	return 0;
//}

////5.4.5 (结构体变量).和(结构体指针).操作符
//#include <string.h>
//struct Stu {
//	char name[20];
//	int age;
//	double score;
//};
//
//void set_stu(struct Stu* ps)
//{
//	strcpy(ps->name, "zhangsan");	//或者(*ps).name
//	ps->age = 20;
//	ps->score = 100.0;
//}
//void print_stu(struct Stu ss)
//{
//	printf("%s %d %.1lf\n", ss.name, ss.age, ss.score);
//}
//int main()
//{
//	struct Stu s = { 0 };
//	set_stu(&s);	
//	print_stu(s);
//	return 0;
//}

//5.4.6整形提升
//int main()
//{
//	char a = 5;
//	//00000000000000000000000000000101
//	//00000101
//	char b = 126;
//	//00000000000000000000000001111110
//	//01111110
//	char c = a + b;
//	//00000000000000000000000010000011 - c
//	//10000011 - c	-125的补码
//	printf("%d\n", c);
//	return 0;
//}
////另一个例子
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//
//	if (a == 0xb6)
//	{
//		printf("a");
//	}
//	if (b == 0xb600)
//	{
//		printf("b");
//	}
//	if (c == 0xb6000000)
//	{
//		printf("c");	//只打印c,a和b整形提升后为负数
//	}
//
//	return 0;
//}
////例子3
//int main()
//{
//	char c = 1;
//	printf("%zu\n", sizeof(c));
//	printf("%zu\n", sizeof(+c));
//	printf("%zu\n", sizeof(1*c));
//	//参与表达式运算后会发生整形提升
//
//	return 0;
//}

////作业BC117青蛙跳台阶
//int fib(n)
//{
//	if (n <= 2)
//		return n;
//	else
//		return fib(n - 1) + fib(n - 2);
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int count = fib(n);
//
//	printf("%d\n", count);
//
//	return 0;
//}

////BC98序列中删除指定元素(可能有重复元素)，序列长度和值都介于1-50
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int del = 0;
//	scanf("%d", &del);
//
//	int j = 0;	//下标j存放不删除的数据
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] != del)
//		{
//			arr[j++] = arr[i];
//		}
//	}
//
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

////BC48字母大小写转换，输出或输入每一行都只有一个字母
//int main()
//{
//	char ch = 0;
//
//	while (scanf("%c", &ch) == 1)	//scanf读取成功返回读取数据的个数，读取失败返回EOF
//	{
//		if (ch >= 'a' && ch <= 'z')
//			printf("%c\n", ch - ('a' - 'A'));
//		else if(ch>='A'&&ch<='Z')
//			printf("%c\n", ch + ('a' - 'A'));
//	}
//	//scanf(" %c",&ch);%c前加空格可以跳过下一个输入前的所有空格
//	//getchar();读取并丢弃换行符
//	return 0;
//}

////BC38求5位数的变种水仙花数eg:1461=1*461+14*61+146*1
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		int sum = 0;
//		int j = 0;
//		for (j = 1; j <= 4; j++)
//		{
//			int k = (int)pow(10, j);
//			sum += (i / k) * (i % k);
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//}

//作业第一题：统计二进制中1的个数
//int count_num_of_1(unsigned int num)//负数变为一个很大的正数
//{
//	int count = 0;
//	while (num)
//	{
//		//if (num % 2 == 1)	//类比十进制求每一位数
//		if ((num&1) == 1)
//		{
//			count++;
//		}
//		//num /= 2;
//		num >>= 1;
//	}
//	return count;
//}
////写法2
//int count_num_of_1(int num)	//不需要传无符号数
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
////写法三
//int count_num_of_1(int num)
//{
//	int count = 0;
//	while (num)
//	{
//		num &= (num - 1);	//将最低位的1变为0，循环次数等于1的个数
//		count++;			//判断一个数是否为2的幂:(n > 0) && ((n & (n - 1)) == 0) 
//	}
//	return count;
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int count = count_num_of_1(num);
//	printf("%d\n", count);
//
//	return 0; 
//}

////作业第三题：判断两个整型的二进制有多少位不同
//int count_diff_bit(int m, int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((m >> i) & 1) ^ ((n >> i) & 1))
//						  //!=
//		{
//			count++;
//		}
//	}
//	return count;
//}
////另解:统计m^n的二进制中1的个数
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	int ret = count_diff_bit(m, n);
//	printf("%d\n", ret);
//
//	return 0;
//}

////作业第四题
////全局变量和静态变量存放在静态区，默认初始化为0
////局部变量存放在栈区，初始化为随机值
//int i;
//int main()
//{
//	i--;
//	if (i > sizeof(i))	//-1>4，sizeof操作符计算结果返回size_t类型，是无符号整型
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//}

////BC68打印x型图案
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (i == j)
//				{
//					printf("*");
//				}
//				else if (i + j == n - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//BC54输入年份月份获取天数
//int is_leap_year(int year)
//{
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//
//	while (scanf("%d%d", &year, &month) == 2)	//多组输入
//	{
//		switch (month)
//		{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			day = 31;
//			break;
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//			day = 30;
//			break;
//		case 2:
//			if (is_leap_year(year) == 1)
//			{
//				day = 29;
//			}
//			else
//			{
//				day = 28;
//			}
//			break;
//		}
//		printf("day=%d\n", day);
//	}
//	return 0;
//}
////另解
////int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//

