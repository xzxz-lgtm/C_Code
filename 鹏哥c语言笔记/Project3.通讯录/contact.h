#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

#define DEFAULT_SZ 3	//初始联系人数量
#define INC_SZ 2	//每次扩容联系人的数量
#define MAX_COUNT 100	//最大联系人存储数量
#define MAX_NAME 12
#define MAX_SEX 10	//最大性别
#define MAX_TELE 12	//最大电话
#define MAX_ADDR 30	//最大地址

//类型的声明
//人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录
//静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX_COUNT];	//姓名等信息
//	int count;	//当前通讯录存储人数
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo* data;
	int capacity;	//当前通讯录容量
	int count;	//当前通讯录存储人数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//文件保存通讯录
void SaveContact(const Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//打印通讯录信息
void ShowContact(const Contact* pc);	//不修改通讯录

//排序通讯录
//按照姓名
void SortContact(Contact* pc);

