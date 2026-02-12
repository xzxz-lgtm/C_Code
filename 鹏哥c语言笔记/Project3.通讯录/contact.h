#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

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
typedef struct Contact
{
	PeoInfo data[MAX_COUNT];	//最多100个人的信息
	int count;	//当前通讯录存储人数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

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

