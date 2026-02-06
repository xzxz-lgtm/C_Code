#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////1.两种字符指针
//int main()
//{
//	//1.
//	/*char ch = 'w';
//	char* pc = &ch;
//	*pc = 'b';*/
//
//	//2.
//	//char* p = "abcdef";
//	const char* p = "abcdef"; //把字符串的首地址赋值给p
//	//常量字符串
//
//	printf("%s\n", p);
//
//	return 0;
//}

////2.
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//
//	if (p1 == p2)
//	{
//		printf("p1==p2\n");		//常量区，只读，字符串相同首地址也相同
//	}
//	else
//	{
//		printf("p1!=p2\n");
//	}
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	if (arr1 == arr2)
//	{
//		printf("arr1==arr2\n");
//	}
//	else
//	{
//		printf("arr1!=arr2\n");		//栈区分配独立空间
//	}
//
//	return 0;
//}

////3.指针数组
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(*(parr + i) + j));
//			//parr[i][j]=*(parr[i]+j)=*(*(parr+i)+j)
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

////4.再次讨论数组名
////数组名通常表示的是数组首元素地址
////例外1：sizeof(数组名)，表示整个数组的大小
////例外2：&数组名，取出的是整个数组的地址
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1);
//
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1); //相差整个数组的大小即40Byte
//
//
//	return 0;
//}

////5.数组指针
//int main()
//{
//	int arr[10] = { 0 };
//
//	int* p1 = &arr;
//	int (*p2)[10] = &arr; //类型是int (*)[10]
//
//	/*char* arr[5] = { 0 };
//	char* (*p)[5] = &arr;*/
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(*p2 + i)); //不推荐
//		//*(p1 + i)更好
//		//p指向数组，*p相当于数组名，本质上为数组首元素的地址
//	}
//
//
//	return 0;
//}

////6.
////数组形式
//void print1(int arr[][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
////指针形式
//void print2(int (*p)[5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			printf("%d ", *(p[i] + j));
//			//printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	
//	print2(arr, 3, 5);
//
//	return 0;
//}

////7.函数指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	//&函数名和函数名都是函数的地址
//
//	int (*pf)(int, int) = &Add;
//	int ret = (*pf)(2, 3); //pf(2, 3)也合法
//	printf("%d\n", ret);
//
//	return 0;
//}

////8.函数指针
//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//
//	int (*pf)(const char*) = test;
//	(*pf)("abc");
//	pf("abc");	//两种写法等价，test是函数的地址
//
//	return 0;
//}


//9.计算器
void menu()
{
	printf("********************************\n");
	printf("******** 1.Add    2.Sub ********\n");
	printf("******** 3.Mul    4.Div ********\n");
	printf("******** 0.Exit         ********\n");
	printf("********************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

//回调函数
void cal(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请输入两个操作数:>");
	scanf("%d %d", &x, &y);

	ret = (*pf)(x, y);
	printf("%d\n", ret);
}

//int main()
//{
//	//1.选择菜单界面
//	menu();
//	
//	//2.
//	int input = 0;
//	
//	do
//	{
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			cal(Add);
//			break;
//		case 2:
//			cal(Sub);
//			break;
//		case 3:
//			cal(Mul);
//			break;
//		case 4:
//			cal(Div);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//
//	} while (input);
//
//
//	return 0;
//}

////10.函数指针数组
//int main()
//{
//	int (*arr[4])(int, int) = { Add,Sub,Mul,Div };
//
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int ret = arr[i](8, 4);
//		printf("%d\n", ret);
//	}
//
//	return 0;
//}

////11.函数指针数组实现计算器
////转移表
//int main()
//{
//	//1.选择菜单界面
//	menu();
//	
//	//2.计算器功能
//	int input = 0;
//	int ret = 0;
//	int x = 0;
//	int y = 0;
//
//	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };
//
//	do
//	{
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("退出程序\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}

////12.冒泡排序
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int flag = 1;	//假设本来有序
//	for (i = 0; i < sz - 1; i++)	//n-1趟
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag == 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;	//有序数组不会重复比较
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//13.qsort
//void qsort(void* base,	//待排序数据的起始位置
//		   size_t num,	//待排序数据的元素个数
//		   size_t width,	//待排序数据每个元素的大小（单位：字节）
//		   int (*cmp)(const void* e1, const void* e2)	//函数指针->比较函数,大于返回正数……
//)
//#include <stdlib.h>
//
////比较两个整型
//int cmp_int(const void* e1, const void* e2)
//{
//	//void*是无具体类型的指针，不能解引用，也不能+-整数
//	int arg1 = *((int*)e1);
//	int arg2 = *((int*)e2);
//
//	return arg1 - arg2;	//升序
//	//return arg2 - arg1;	//降序
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//bubble_sort(arr, sz);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


////14.qsort排序结构体
//#include <stdlib.h>
//#include <string.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//int main()
//{
//	struct Stu s[] = { {"zhangsan", 15}, {"lisi", 30}, {"wangwu", 25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("姓名：%-10s 年龄：%d\n", s[i].name, s[i].age);
//	}
//
//	return 0;
//}

//排序任意类型的冒泡排序
Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)	//一个字节一个字节地交换
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int cmp(const void*, const void*))
{
	int i = 0;
	int flag = 1;	//假设本来有序
	for (i = 0; i < sz - 1; i++)	//n-1趟
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			//char*一次加一个字节最小，结合width得e1和e2的地址
			//if (arr[j] > arr[j + 1])
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				//还需要width才能交换
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;	//有序数组不会重复比较
		}
	}
}