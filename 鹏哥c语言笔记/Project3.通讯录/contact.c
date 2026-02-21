#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//静态
//void InitContact(Contact* pc)
//{
//	assert(pc);
//
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

void CheckCapcity(Contact* pc)
{
	assert(pc);

	if (pc->count == pc->capacity)
	{
		PeoInfo* str = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (str == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		pc->data = str;
		pc->capacity += INC_SZ;
		printf("增容成功\n");
	}
}

void LoadContact(Contact* pc)
{
	FILE* pfRead = fopen("contact.txt", "r");
	if (pfRead == NULL)
	{
		perror("LocateContact");
		return;
	}

	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)	//一个一个联系人的读
	{
		//检查扩容
		CheckCapcity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

//动态
void InitContact(Contact* pc)
{
	assert(pc);

	pc->count = 0;
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	pc->capacity = DEFAULT_SZ;

	//加载文件的信息到通讯录
	LoadContact(pc);
}

void SaveContact(const Contact* pc)
{
	assert(pc);

	FILE* pfWrite = fopen("contact.txt", "w");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}

	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(&pc->data[i], sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}


void DestroyContact(Contact* pc)
{
	assert(pc);

	free(pc->data);
	pc->data = NULL;
}


//静态
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	//通讯录已满
//	if (pc->count == MAX_COUNT)
//	{
//		printf("通讯录已满，无法再添加\n");
//		return;
//	}
//
//	printf("开始添加联系人\n");
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入住址:>");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("添加联系人成功\n");
//}
//动态
void AddContact(Contact* pc)
{
	assert(pc);
	//扩容
	CheckCapcity(pc);

	printf("开始添加联系人\n");
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入住址:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("添加联系人成功\n");
}


//根据姓名查找指定联系人，并返回data数组下标
static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;	//没找到，返回-1
}

void DelContact(Contact* pc)
{
	assert(pc);
	printf("删除指定联系人\n");
	//通讯录为空
	if (pc->count == 0)
	{
		printf("通讯录为空，删除失败\n");
		return;
	}
	//1.查找
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除的联系人的姓名:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)	//从下标pos到count-1都往前挪一位
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->count--;
	printf("删除联系人成功\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	//1.查找
	printf("查找指定联系人\n");
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的联系人的姓名:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");	//空通讯录也会返回-1
		return;
	}
	//2.打印
	printf("%-12s\t%-5s\t%-10s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-12s\t%-3d\t%-10s\t%-12s\t%-30s\n",
		pc->data[pos].name, pc->data[pos].age,
		pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	//1.查找
	printf("修改指定联系人\n");
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的联系人的姓名:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");	//空通讯录也会返回-1
		return;
	}

	//2.修改
	printf("修改名字:>");
	scanf("%s", pc->data[pos].name);
	printf("修改年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("修改性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("修改电话:>");
	scanf("%s", pc->data[pos].tele);
	printf("修改住址:>");
	scanf("%s", pc->data[pos].addr);
	printf("修改联系人成功\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);

	printf("通讯录显示\n");
	//通讯录为空
	if (pc->count == 0)
	{
		printf("当前还没有存入任何联系人\n");
		return;
	}

	printf("当前存有%d个联系人\n", pc->count);
	printf("%-12s\t%-5s\t%-10s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%-12s\t%-3d\t%-10s\t%-12s\t%-30s\n",
			pc->data[i].name, pc->data[i].age,
			pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

static int CmpConByName(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	assert(pc);

	qsort(pc->data, pc->count, sizeof(pc->data[0]), CmpConByName);
	printf("排序成功\n");
}

