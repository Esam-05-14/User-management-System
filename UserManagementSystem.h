#ifndef USERMANAGEMENTSYSTEM_H 
#define USERMANAGEMENTSYSTEM_H
#define GROUP_NUM 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Group {root_user=0,system_user=200,operator_user=1001,observer_user};

typedef struct{
    char name[20];
    int age;
    char id[8];
    enum Group groups[4];
    struct User* ptr;

}User;

User* init();
int count_users(User* root);
void print_user(User* root, const char* id);
void print_system(User* root);
User* create_user(User* root,char* name ,int age , const char* id , int groupss[]);
void modify(User* root , const char* id , char* name);
void delete_user(User* root,const  char* id);
void add(User* root ,  const char* id , int newgroup);
void system_export(User* root,char* filename);
void delete_system(User** root);

#endif
