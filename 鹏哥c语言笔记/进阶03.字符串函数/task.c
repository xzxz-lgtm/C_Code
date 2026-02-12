#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////1.strlen
//#include <string.h>
//#include <assert.h>
//
////方法1.计数器；2.指针-指针；3.递归
//size_t my_strlen(char* str)
//{
//	assert(str);	//空指针
//
//	size_t count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	//char arr[] = { 'b','i','t' };	//大于3的随机值
//	
//	//int len = strlen(arr);
//	size_t len = my_strlen(arr);
//
//	printf("%zu\n", len);
//
//	//if ((strlen("abc") - strlen("abcdef")) > 0)	//返回值size_t
//
//	return 0;
//}


////2.strcpy
//#include <string.h>
//
//int main()
//{
//	char* p = "abcdef";	//目标字符串必须可修改，p指向常量字符串，存储在只读区
//	char arr[] = "bit";
//	strcpy(p, arr);
//
//	return 0;
//}

//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//
//	char* start = dest;
//	while (*dest++ = *src++)	//包括src的'\0'
//	{
//		;
//	}
//
//	return start;
//}
//
//int main()
//{
//	char arr1[] = "abcde";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2, arr1);
//
//	printf("%s\n", arr2);
//
//	return 0;
//}


////3.strcat
//#include <string.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//
//	char* ret = dest;
//	//1.找到dest的'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.拷贝
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	
//	my_strcat(arr1, "world");
//
//	printf("%s\n", arr1);
//
//	return 0;
//}

////4.strcmp
//#include <string.h>
//#include <assert.h>
//int my_strcmp(const char* str1, const char* str2)	//不需要修改
//{
//	assert(str1 && str2);
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')	//两字符串完全相等
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "abc";
//
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf(">\n");
//	}
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf("=\n");
//	}
//
//	return 0;
//}

////长度受限制的字符串函数
////5.strncpy
//#include <string.h>
//#include <assert.h>
//char* my_strncpy(char* dest, const char* src, size_t n)	//src不可修改
//{
//	assert(dest && src);
//
//	//1.拷贝src
//	char* start = dest;
//	while (*src && n)
//	{
//		*dest++ = *src++;
//		n--;
//	}
//	*dest = '\0';
//	//2.多余的补'\0'
//	while (n)
//	{
//		*dest++ = '\0';
//		n--;
//	}
//
//	return start;
//}
//
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "bit";
//
//	my_strncpy(arr1, arr2, 2);	//多余的拷贝'\0'
//
//	printf("%s\n", arr1);
//
//	return 0;
//}

////6.strncat
//#include <string.h>
//#include <assert.h>
//char* my_strncat(char* dest, const char* src, size_t n)
//{
//	assert(dest && src);
//	char* start = dest;
//
//	//找到dest末尾
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//
//	//拼接
//	while (n && *src)
//	{
//		*dest++ = *src++;
//		n--;
//	}
//	*dest = '\0';	//末尾补'\0'，但不会补多余的n
//
//	return start;
//}
//
//int main()
//{
//	char arr1[20] = "hello\0xxxxx";
//	char arr2[] = "bit";
//
//	my_strncat(arr1, arr2, 6);	//拼接后会补'\0'，但n大时不会补多余的
//
//	printf("%s\n", arr1);
//
//	return 0;
//}

////7.strncmp
//#include <string.h>
//#include <assert.h>
//int my_strncmp(const char* str1, const char* str2, size_t n)	//不能修改原字符串
//{
//	assert(str1 && str2);
//
//	while (n > 0)
//	{
//		//1.遇见不相等就直接返回
//		if (*str1 != *str2)
//		{
//			return (int)(*str1 - *str2);
//		}
//		//2.两字符串完全相等
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		//3.比较下一个
//		str1++;
//		str2++;
//		n--;
//	}
//	//前n个字符相等
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "abcdef";
//
//	int ret = my_strncmp(arr1, arr2, 4);
//
//	if (ret > 0)
//	{
//		printf(">\n");
//	}
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf("=\n");
//	}
//
//	return 0;
//}

////8.strstr
//#include <string.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;	//起始位置
//
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')	//相等继续比较下一字符
//		{													//s1或s2结束就停止
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)p;
//		}
//		p++;
//	}
//	return NULL; 
//}
//
//int main()
//{
//	char email[] = "zpw@bitejiuyeke.com";
//	char substr[] = "bitejiuyeke";
//
//	char* ret = my_strstr(email, substr);
//	
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}

////9.strtok
//#include <string.h>
//int main()
//{
//	char email[] = "zhangpengwei@bitejiuyeke.com";
//	const char* sep = "@.";
//	char email_tmp[30] = { 0 };	//strtok会修改被操作的字符串，一般使用可修改的临时拷贝
//	strcpy(email_tmp, email);
//
//	char* ret = strtok(email_tmp, sep);	//将分隔符替换为'\0'，并返回分割字符串的起始位置
//	while (ret != NULL)
//	{
//		printf("%s\n", ret);
//
//		ret = strtok(NULL, sep);	//传入NULL；存在静态指针，从'\0'的下一字符开始
//	}
//
//	/*char* ret = NULL;
//	for (ret = strtok(email_tmp, sep);
//		ret != NULL;
//		ret = strtok(NULL, sep))
//	{
//		printf("%s\n", ret);
//	}*/
//
//
//
//	return 0;
//}

////10.strerror
////C语言的库函数，在执行失败时，都会设置错误码
// #include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//
//	}
//
//	return 0;
//}

//11.字符分类函数
//字符转换函数

////12.memcpy
//#include <string.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* start = dest;
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;	//char*方便一个一个字节地修改
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//
//	return start;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[10] = { 0 };
//
//	my_memcpy(arr2, arr1, sizeof(arr1));
//
//	int sz = sizeof(arr2) / sizeof(arr2[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//}

////13.memmove
////可以实现重叠内存之间的数据拷贝
//#include <string.h>
//#include <assert.h>
//
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	//dest<src时前->后
//	//src<dest<src+n数据会被覆盖，需要后->前
//	//dest>src+n两种方式均可
//	if (dest < src)
//	{
//		//前->后
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//后->前
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);	//从dest+num-1开始，num--
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//my_memcpy(arr + 2, arr, 20);	//数据被覆盖
//	my_memmove(arr, arr + 2, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

////14.memcmp
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,3,3 };
//	
//	int ret = memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);
//
//	return 0;
//}

//15.memset
#include <string.h>
int main()
{
	/*char arr[] = "hello bit";
	memset(arr + 6, 'x', 3);
	printf("%s\n", arr);*/

	int arr[10] = { 0 };
	memset(arr, 1, 40);	//会把每个字节初始化为1，arr[i]=01010101

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}