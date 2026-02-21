#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <errno.h>

////1.打开文件
//int main()
//{
//	//FILE * fopen ( const char * filename, const char * mode );
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("");
//		return 1;
//	}
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//2.读写文件
//int main()
//{
//	//FILE* pf = fopen("test.txt", "w");
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		perror("");
//		return 1;
//	}
//
//	////写
//	//char i = 0;
//	//for (i = 'a'; i < 'z'; i++)
//	//{
//	//	fputc(i, pf);
//	//}
//
//	//读
//	/*int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}*/
//
//	//写一行数据
//	//"w"会先清空再写入；"a"是追加
//	//fputs("hello bit", pf);
//
//	//读一行数据
//	char arr[20] = { 0 };
//	fgets(arr, 5, pf);	//最多读4个字符，会补'\0'
//	printf("%s\n", arr);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//3.fprintf
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};

//int main()
//{
//	struct S s = { "zhangsan", 25, 50.5f };
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fprintf(pf, "%s %d %.1f", s.arr, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//fscanf
//int main()
//{
//	struct S s = { 0 };
//
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fscanf(pf, "%s %d %f", s.arr, &(s.age), &(s.score));
//	//printf("%s %d %.1f\n", s.arr, s.age, s.score);
//	fprintf(stdout, "%s %d %.1f\n", s.arr, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//流 FILE*
//C程序运行时默认打开三个流
//FILE* stdin	标准输入流（键盘）
//FILE* stdout  标准输出流（屏幕）
//FILE* stderr  标准错误流（屏幕）


//4.二进制读写
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};

//int main()
//{
//	struct S s = { "zhangsan", 25, 50.5f };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//二进制写
//	//size_t fwrite(const void* ptr, size_t size, size_t count, FILE * stream);
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//二进制读
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
//	fread(&s, sizeof(struct S), 1, pf);
//	printf("%s %d %.1f\n", s.arr, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//5.sprintf
//将格式化的数据转换为字符串
//sscanf
//从字符串中转换格式化的数据
//struct S
//{
//	char arr[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { "zhangsan", 25, 50.5f };
//	struct S tmp = { 0 };
//	char buf[100] = { 0 };
//
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.score);
//	printf("%s\n", buf);
//
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
//	printf("%s %d %f\n", tmp.arr, tmp.age, tmp.score);
//
//	return 0;
//}

//6.文件的随机读写
//fseek
int fseek(FILE* stream, long int offset, int origin);
int main()
{
	FILE* pf = fopen("test.txt", "r");	//abcdef
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fseek(pf, 2, SEEK_SET);	//c
	int ch = fgetc(pf);
	printf("%c\n", ch);
	
	//fseek(pf, 2, SEEK_CUR);	//f，因为fgetc读取字符后指针会自动向后移动一位
	fseek(pf, -1, SEEK_END);	//f,SEEK_END为EOF的下标
	ch = fgetc(pf);
	printf("%c\n", ch);
	//ftell求相对于文件起始位置的偏移量
	printf("%d\n", ftell(pf));	//6
	//rewind让文件指针回到起始位置
	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);


	fclose(pf);
	pf = NULL;

	return 0;
}

