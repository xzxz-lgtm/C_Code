//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
////1.BC116小乐乐改数字
////#include <math.h>
////int main()
////{
////	int n = 0;
////	scanf("%d", &n);
////	
////	int tmp = n;
////	int cnt = 1;	//位数
////	while (tmp /= 10)
////	{
////		cnt++;
////	}
////	//printf("%d\n", cnt);
////
////	int ret = 0;
////	int i = 0;
////	for (i = 0; i < cnt; i++)
////	{
////		int cur_digit = 0;
////		int new_digit = 0;
////		cur_digit = (n / (int)pow(10, i)) % 10;
////		new_digit = cur_digit % 2; //偶数为0，奇数为1
////		
////		ret += new_digit * pow(10, i);
////	}
////
////	printf("%d\n", ret);
////}
//
//////优化
////int main()
////{
////	int n = 0;
////	if (scanf("%d", &n) != 1) return 0;
////
////	if (n == 0)	//特殊情况，0不会进入while
////	{
////		printf("0\n");
////		return 0;
////	}
////	
////	int cur_digit = 0;
////	int new_digit = 0;
////	int weight = 1;	//十进制每一位的权
////	int sum = 0;
////	while (n)
////	{
////		cur_digit = n % 10;
////		new_digit = cur_digit % 2;	//偶数为0，奇数为1
////
////		sum += new_digit * weight;
////
////		weight *= 10;	//位权进位
////		n /= 10;	//获取下一位
////	}
////
////	printf("%d\n", sum);
////
////	return 0;
////}
//
////2.左旋字符串
////#include <string.h>
////void left_rotate(char arr[], int k)
////{
////	
////	char tmp = *arr;
////	int len = strlen(arr);
////	k %= len; //优化k>len时的移动次数
////
////	while (k--)
////	{
////		//移动一个字符
////		//1.暂存第一个字符
////		tmp = *arr;
////		//2.将字符串往前移一位
////		int i = 0;
////		for (i = 0; i < len - 1; i++)
////		{
////			arr[i] = arr[i + 1];
////		}
////		//3.最后一个字符
////		arr[len - 1] = tmp;
////	}
////}
//
////优化
////左右两字符串各自逆序，再整体逆序
//#include <string.h>
//#include <assert.h>
//void reverse(char* left, char* right)
//{
//	assert(left && right);
//
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_rotate(char arr[], int k)
//{
//	int len = strlen(arr);
//	k %= len;
//
//	reverse(arr, arr + k - 1);
//	reverse(arr + k, arr + len - 1);
//
//	reverse(arr, arr + len - 1);
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//	scanf("%d", &k);
//
//	left_rotate(arr, k);
//
//	printf("%s\n", arr);
//
//	return 0;
//}