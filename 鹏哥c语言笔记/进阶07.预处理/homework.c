#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

////1.一个数组中只有两个数字出现一次，其他数字都出现了两次
////全部异或后为a^b，一定不为0，根据异或结果为1的某位将数字分成两组
////每一组异或各自得到一个single
//void findSingle(int arr[], int sz, int* p1, int* p2)
//{
//	//1.全部异或
//	int tmp = 0;	//代表全部异或的结果
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		tmp ^= arr[i];
//	}
//
//	//2.求异或结果哪一位为1
//	int digit = 1;	//m从低到高第几位为1
//	/*while ((tmp & 1) == 0)
//	{
//		tmp >>= 1;
//		digit++;
//	}*/
//	//lowbit操作
//	digit = tmp & (-tmp);
//
//	//3.分2组
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> (digit - 1)) & 1) == 0)
//		{
//			*p1 ^= arr[i];
//		}
//		else
//		{
//			*p2 ^= arr[i];
//		}
//	}
//
//}
//
////101^111=010
//int main()
//{
//	int arr[] = { -1,2,3,-5,-1,2,3,10329 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int single1 = 0;
//	int single2 = 0;
//
//	findSingle(arr, sz, &single1, &single2);
//
//	printf("%d %d", single1, single2);
//
//	return 0;
//}

////2.模拟实现atoi
//enum Status
//{
//	VALID,
//	INVALID
//}sta = INVALID;	//默认非法
//
//int my_atoi(const char* str)
//{
//	sta = INVALID;	//默认非法
//	assert(str);
//	//空字符串
//	if (*str == '\0')
//	{
//		return 0;	//非法0
//	}
//	//跳过空白字符
//	while (isspace(*str))
//	{
//		str++; 
//	}
//	//若有+-添加符号
//	int flag = 1;	//默认为正
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//
//	if (isdigit(*str) == 0)	//没遇到数字就遇到非数字
//	{
//		return 0;	//非法0
//	}
//	//获取字符直到非数字字符
//	int ret = 0;
//	while (isdigit(*str))
//	{
//		int digit = *str - '0';
//		ret = ret * 10 + digit;	//字符-‘0‘=对应数字
//		if ((ret > INT_MAX / 10) || 
//		   ((ret == INT_MAX / 10) && (digit > INT_MAX % 10)))
//		{
//			return (flag == 1) ? INT_MAX : INT_MIN;	//溢出时根据正负返回极限值
//		}
//		str++;
//	}
//	sta = VALID;
//	return ret * flag;
//}
//
//int main()
//{
//	char arr[200] = "    -123456789101010abc345";
//	int ret = my_atoi(arr);
//	if (sta == VALID)
//	{
//		printf("合法转换：%d\n", ret);
//	}
//	else
//	{
//		printf("非法返回：%d\n", ret);
//	}
//	
//	return 0;
//}

//3.写一个宏，将一个整数的二进制位的奇数位和偶数位交换
//#define SWAP_BIT(n) ((((n) & 0x55555555) << 1) | (((n) & 0xaaaaaaaa) >> 1))
////掩码
////获取偶数位：01010101 01010101 01010101 01010101 左移
////获取奇数位：10101010 10101010 10101010 10101010 右移
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", SWAP_BIT(n));
//
//	return 0;
//}

//4.给一个数n，返回与斐波那契数的最小差值 1<=n<=1000000
//#define MIN(x,y) ((x) < (y) ? (x) : (y))
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int a = 0;
//	int b = 1;
//	int c = 1;
//	while (n > c)
//	{
//		a = b;
//		b = c;
//		c = a + b;
//	}
//	int res = MIN(n - b, c - n);
//	printf("%d\n", res);
//
//
//
//	return 0;
//}

