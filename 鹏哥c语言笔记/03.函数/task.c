#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//2.1
#include <string.h>
int main()
{
	/*char arr1[20] = { 0 };
	char arr2[] = "hello world";

	strcpy(arr1, arr2);
	printf("%s\n", arr1);*/

	char arr[20] = "hello world";
	memset(arr + 6, 'y', 3);
	printf("%s\n", arr);
}

////2.2
//int get_max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int m = get_max(a, b);
//	printf("%d\n", m);
//
//	return 0;
//}

//void swap(int* px, int* py)
//{
//	int z = *px;
//	*px = *py;
//	*py = z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("交换前：a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("交换后：a=%d,b=%d\n", a, b);
//
//	return 0;
//}

////4.3练习
////4.3.1打印100-200间的素数
//#include <math.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+= 2)
//	{
//		if (is_prime(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}

////4.3.2闰年1000-2000
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}

////4.3.3整形有序数组的二分查找
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;	//找到了
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 9;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//找到了返回下标 
//	//找不到返回-1
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//	{
//		printf("找到了，下标是：%d", ret);
//	}
//
//	return 0;
//}

////4.3.4每调用一次num+1
//void add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num = 0;
//	add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);
//
//	return 0;
//}

////递归
////7.2.1无符号整型，按顺序打印每一位
//void print(unsigned int n)
//{
//	if (n / 10 == 0)
//	{
//		printf("%u ", n);
//	}
//	else
//	{
//		print(n / 10);
//		printf("%u ", n % 10);
//	}
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//
//	print(num);
//
//	return 0;
//}

//7.2.2编写函数不允许创建临时变量，求字符串长度（模拟strlen）
////int my_strlen(char str[])参数部分写成数组形式
//int my_strlen(char* str)	//参数部分写成指针形式
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr); 
//	printf(" % d\n",len);
//
//	return 0;
//}

////递归
////my_strlen("abc")->1+my_strlen("bc")
//int my_strlen(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//
//}
//
//int main()
//{
//	int len = my_strlen("abc");
//	printf("%d\n", len);
//
//	return 0;
//}

////7.2.3求n！
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d", ret);
//
//	return 0;
//}

//7.2.4求第n个斐波那契数
//递归(耗时）
//int fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//}
////迭代
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//	{
//		int a = 1;
//		int b = 1;
//		int c = 0;
//		for (int i = 3; i <= n; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//	
//	return 0;
//}

////作业第七题
////将三个整数按从大到小输出
//void swap(int* px, int* py)
//{
//	int temp = *px;
//	*px = *py;
//	*py = temp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//
//	if (a < b)
//	{
//		swap(&a, &b);
//	}
//	if (a < c)
//	{
//		swap(&a, &c);
//	}
//	if (b < c)
//	{
//		swap(&b, &c);
//	}
//	printf("%d %d %d", a, b , c);
//
//	return 0;
//}

////第九题求两个数的最大公约数
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	scanf("%d%d", &a, &b);
//	int min = (a < b) ? a : b;
//	for (int i = min; i > 0; i--)
//	{
//		if (b % i == 0&&a%i==0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}
////辗转相除法求最大公约数，且两数相乘=最大公约数*最小公倍数
////当a小于b时，经过一次即a、b调换顺序,也成立
//int find_gcd(int a, int b)
//{
//	int rem = 0;
//	while (rem=a%b)
//	{
//		a = b;
//		b = rem;
//	}
//
//	return b;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//
//	int ret = find_gcd(a, b);
//	printf("%d", ret);
//
//	return 0;
//}


////作业第三题：计数1-100间出现了多少个数字9
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		//个位为9
//		if (i % 10 == 9)
//			count++;
//		//十位为9
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("%d\n", count);
//
//	return 0;
//}


////作业第四题，计算1/1-1/2+1/3+……-1/100
//int main()
//{
//	int i = 0;
//	float sum = 0.0f;
//	int flag = 1;	//加减交错
//
//	for (i = 1; i <= 100; i++)
//	{
//		sum += (1.0 / i) * flag;	//1/i=0;
//		flag = -flag;
//	}
//
//	printf("%f\n", sum);
//	return 0;
//}


////作业第五题，求10个整数中的最大值
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int max = arr[0];
//	for (int i = 1; i <= 9; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//
//	return 0;
//}


////作业第六题，输出九九乘法口诀表
////1*1=1
////2*1=2 2*2=4
//int main()
//{
//	for (int i = 1; i <= 9; i++)	//打印9行
//	{
//		for (int j = 1; j <= i; j++)	//打印i列
//		{	
//			printf("%d*%d=%-2d\t", i, j, i * j);	//%2d默认右对齐，%-2d左对齐
//													//\t水平制表符
//		}
//		printf("\n");
//	}
//	return 0;
//}


////作业第八题:打印乘法口诀表，可输入行列数
//void print_multi_table(int n)
//{
//	//打印n行
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_multi_table(n);
//	return 0;
//}

//作业第六题：递归实现字符串逆序
// 非递归
//#include <string.h>
//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//int sz=strlen(arr)-1;
//	int left = 0;
//	int right = sz - 2;	//\0
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//
//		left++;
//		right--;
//	}
//	printf("%s\n", arr);
//
//	return 0;
//}
//递归
//#include <string.h>
//一个参数
//void reverse_string(char* str)
//{
//	char tmp = *str;
//	int len = strlen(str);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (strlen(str) >= 2)
//		reverse_string(str + 1);
//	*(str + len - 1) = tmp;
//}
////多个参数
//void reverse_string(char arr[], int left, int right)
//{
//	if(left<right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		reverse_string(arr, left + 1, right - 1);
//	}
//}


//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = strlen(arr);
//	int left = 0;
//	int right = sz - 1;
//	reverse_string(arr,left,right);
//	printf("%s\n", arr);
//
//	return 0;
//}

////作业第七题：递归求每一位数字和
//int digit_sum(unsigned int n)
//{
//	if (n > 9)
//		return digit_sum(n / 10) + n % 10;
//	else
//		return n;
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	int sum = digit_sum(n);
//	printf("%d\n", sum);
//
//	return 0;
//}

////作业第八题:递归求n^k
//double pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	else if (k > 0)
//		return n * pow(n, k - 1);
//	else
//		return 1.0 / pow(n, -k);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = pow(n, k);
//	printf("%lf\n", ret);
//
//	return 0;
//}

