#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////4.1冒泡排序
////将数组排成升序
////数组传参时形参有两种写法：1.数组int arr[]2.指针int* arr
//void bubble_sort(int arr[],int sz)
////数组名（大多数情况）本质上是数组首元素的地址，地址应使用指针来接收
////此处的arr为指针变量，若直接在函数内求sz=4/4=1
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)		//sz-1趟冒泡排序
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)	//每一趟比较sz-1-i次
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr,sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////4.2数组名
////数组名确实能表示首元素的地址，但是有两个特例
////1.sizeof(arr)表示整个数组的大小
////2.&arr表示取整个数组的地址
//int main()
//{
//	/*int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("--------------------\n");
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("--------------------\n");
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1);*/
//
//
//	int arr[3][4] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);		//二维数组的数组名表示第一行的地址
//
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));			//求行数
//	printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));		//求列数
//
//	return 0;
//}

