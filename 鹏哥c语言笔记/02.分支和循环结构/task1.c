#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////BC13
//int main()
//{
//	int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	while (i < sz)
//	{
//		printf("%c", arr[i]);
//		i++;
//	}
//
//	return 0;
//}
//
////BC14
//int main()
//{
//	int year = 0, month = 0, date = 0;
//	scanf(" %4d %2d %2d", &year, &month, &date);
//
//	printf("year=%d\n", year);
//	printf("month = %02d\n", month);
//	printf("date=%02d\n", date);
//
//	return 0;
//}

////BC123最大数
//int findMaxNum(int arr[])
//{
//	int max = arr[0];
//	for (int i = 1; i < 4; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//
//	return max;
//}
//
//int main()
//{
//	int arr[4] = { 0 };
//	for (int i = 0; i < 4; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	printf("%d", findMaxNum(arr));
//	
//	return 0;
//}

////BC27球体积
//int main()
//{
//	double r = 0.0;
//	double v = 0.0;
//	scanf("%lf", &r);
//	v = 4 / 3.0 * 3.1415926 * r * r * r;
//	printf("%.3lf", v);
//}

////BC25bmi
//int main()
//{
//	int weight = 0;
//	int height = 0;
//	scanf("%d%d", &weight, &height);
//	float bmi = weight / (height / 100.0) / (height / 100.0);
//
//	printf("%.2f", bmi);
//
//	return 0;
//}


//3.4练习
//3.4.1求n!
//int factorial(int n)
//{
//	int res = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		res *= i;
//	}
//	return res;
//}
//3.4.2求1!+2!+……+n!
//int main()
//{
//	int sum = 0;
//	for (int n = 1; n <= 10; n++)
//	{
//		sum += factorial(n);
//	}
//	printf("%d", sum);
//
//	return 0;
//}
//算法2
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//
//	for(n = 1; n <= 3;n++)
//	{
//		ret = 1;		//重置
//		for (i = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//
//	printf("%d\n", sum);
//	return 0;
//}

//3.4.3有序表查找
//顺序查找
//int mian()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 17;
//	int i = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] = k)
//		{
//			printf("找到了，下标是：%d", i);
//			break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("没找到");
//	}
//	return 0;
//}
//二分查找
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 17;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int mid = (left + right) / 2;
//	//int mid=left+(right-left)/2避免溢出
//
//	while (left <= right)
//	{
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d", mid);
//			break;
//		}
//		mid = (left + right) / 2;
//	}
//
//	if (left > right)
//	{
//		printf("没找到");
//	}
//
//	return 0;
//}

////3.4.4字符从两端向中间汇聚
//#include <string.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	//int right=sizeof(arr1)/sizeof(arr1[0])-2
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(500);		//休眠100ms #include <windows.h>
//		system("cls");	//清空屏幕 #include <stdlib.h>
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//}

////3.4.5用户登录，只允许输入三次密码,密码“abcdef”
//#include <string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "abcdef") == 0)
//		//比较两个字符串是否相等，不能使用==，使用strcmp #include <string.h>
//		//如果返回值为0，表示里两个字符串相等
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均输入错误，退出程序");
//	}
//
//	return 0;
//}

//项目：猜数字游戏
//电脑产生一个随机数（1~100)
//提示猜大猜小
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("*******************************\n");
	printf("**********  1.play   **********\n");
	printf("**********  0.exit   **********\n");
	printf("*******************************\n");
}

void game()
{
	int guess = 0;
	//1.生成随机数1~100
	int ret = rand()%100+1;		//0~RAND_MAX(32767)
	//printf("%d\n", ret);
	//2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了");
		}
		else if (guess > ret)
		{
			printf("猜大了");
		}
		else
		{
			printf("恭喜你猜对了");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf(" 请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}
	} while(input);
}

////4.关机程序
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("请注意，你的电脑在60s内关机，输入我是猪取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}