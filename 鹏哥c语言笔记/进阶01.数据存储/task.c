#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////1.判断大小端
//int main()
//{
//	int a = 1; //0x 00 00 00 01 小端：低地址是低位01
//
//	if (*(char*)&a == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	
//	return 0;
//}

////2.char整型提升：signed char按符号位扩展；unsigned char零扩展
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	
//	printf("a=%d,b=%d,c=%d,a=%u", a, b, c, a);
//	//-1为整型，原码10000000 00000000 00000000 00000001
//			  //反码11111111 11111111 11111111 11111110
//			  //补码11111111 11111111 11111111 11111111
//	//赋值给char时截断为11111111
//	//对a和b整型提升补符号位1，11111111 11111111 11111111 11111111为补码，原码为-1
//	//c整型提升补0，00000000 00000000 00000000 11111111为补码=原码255
//	//对a、b打印%u时，11111111 11111111 11111111 11111111为无符号数=4294967295
//
//	return 0;
//}

////3.
////
//int main()
//{
//	char a[1000];
//	int i;
//
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//
//	printf("%d\n", strlen(a)); //补码数值上溢出循环，mod256
//							   //前128个字符是ASCII扩展码
//	return 0;
//}


////4.
//#include <string.h>
//int main()
//{
//	//printf("%zu\n", sizeof(size_t)); size_t在x86是4字节
//	//strlen返回size_t
//	if (strlen("abc") - strlen("abcdef") >= 0)
//		printf(">\n");
//	else
//		printf("<\n");
//
//	return 0;
//}

////5.浮点数存储规则
////(-1)^S*M*2^E	(-1)^S:符号位；M:有效数字，1<=M<2；2^E:指数位
////对32位浮点数，最高位为符号位，接下来8位为指数位，剩下23位为有效数字；
////对64位浮点数，最高位为符号位，接下来11位为指数位，剩下52位为有效数字 
////M整数位为1，可以存小数点后24位
////E=实际值+偏移量 flaot为127，double为1023
////取：
////E全为0，规定E实际为-126，无限接近于0
////E全为1，E实际为128，+/-无穷
//int main()
//{
//	//float f = 5.5f;
//	////101.1=1.011x10^2 -> 0 10000001 01100000000000000000000 ->0x40b00000
//
//	int n = 9;
//
//	float* pFloat = (float*)&n;
//
//	printf("n的值为：%d\n", n); //9
//
//	printf("*pFlaot的值为：%f\n", *pFloat); 
//	//整型9->00000000 00000000 00000000 00001001->S=0,E=0->0.00000000000000000001001*10^(-126)
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	//float9.0->1.001*10^3->0 10000001 00100000000000000000000->很大的整数
//	printf("*pFloat的值为：%f\n", *pFloat); //9.000000
//
//
//	return 0;
//}

////6.调整奇数偶数顺序，奇数全部位于偶数前面。
//void swap_odd_even(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left < right)
//	{
//		//从左往右直到遇到偶数停
//		while ((left < right) && (arr[left] % 2 == 1)) //避免全是奇数时数组越界
//		{
//			left++;
//		}
//		//从右往左直到遇到奇数停
//		while ((left < right) && (arr[right] % 2 == 0)) //避免全是偶数时数组越界
//		{
//			right--;
//		}
//		//left<right时交换
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//}
//
//int main()
//{
//	//输入
//	int arr[10] = { 0 };
//	
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", arr + i);
//	}
//
//	//调整
//	swap_odd_even(arr, sz);
//
//	//输出
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

////7.合并有序序列
//int main()
//{
//	//输入
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//
//	//合并
//	int arr[2000] = { 0 };
//	int j = 0, k = 0;
//	int r = 0;
//
//	while (j < n && k < m)
//	{
//		if (arr1[j] < arr2[k])
//		{
//			arr[r++] = arr1[j];
//			j++;
//		}
//		else
//		{
//			arr[r++] = arr2[k];
//			k++;
//		}
//	}
//	if (j < n)
//	{
//		for ( ; j < n; j++)
//		{
//			arr[r++] = arr1[j];
//		}
//	}
//	else
//	{
//		for ( ; k < m; k++)
//		{
//			arr[r++] = arr2[k];
//		}
//	}
//
//	//输出
//	for (i = 0; i < m + n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
