#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////6.1.1指针类型
//int main()
//{
//	int a = 0x11223344;
//	char* pc = (char*)&a;
//	//int* pc = &a;
//	
//	*pc = 0;
//	printf("%x\n", a);
//	//只修改了一个字节
//	//指针类型决定了指针在被解引用时访问几个字节
//
//	return 0;
//}

////6.1.2
//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = (char*)&a;
//
//	printf("pa=%p\n", pa);
//	printf("pa+1=%p\n", pa+1);
//	printf("pc=%p\n", pc);
//	printf("pc+1=%p\n", pc+1);
//	//指针类型决定了指针加减时跳过的字节数
//
//	return 0;
//}

//6.2实现strlen
////方法一
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
////方法二：递归
//int my_strlen(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}
////方法三：指针-指针
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//
//	return 0;
//}

////6.3指针数组:存放指针的数组
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* parr[10] = { &a,&b,&c };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", *(parr[i]));
//	}
//	return 0;
//}
//int main()
//{
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 2,3,4,5 };
//	int arr3[4] = { 3,4,5,6 };
//
//	int* parr[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", parr[i][j]);
//			//printf("%d ", *(*(parr + i) + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//一些题目
//小端序：LSB在最低位 arr[0]:0x00000001 存储：01 00 00 00
int main()
{
	int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr; //解引用和自增时访问两个字节
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		*(p + i) = 0; //连续四次把两个字节赋值为0
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]); //0，0，3，4，5
	}

	return 0;
}
