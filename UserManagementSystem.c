#include "UserManagementSystem.h"



User* init(){
    User* user = (User*)malloc(sizeof(User));
    strcpy(user->name,"root");
    user->age = 33;
    strcpy(user->id,"0");
    user->groups[0]=root_user;
    user->groups[1]=system_user;
    user->groups[2]=operator_user;
    user->groups[3]=observer_user;
    user->ptr = NULL;
    return user;
}
int count_users(User* root){
    int count =0;
    User* current = root;
    while(current!=NULL){
        count++;
        current=current->ptr;
    }
    return count;
}


void print_user(User* root, const char* id){
    User* current = root;
    while(current != NULL){
        if(strcmp(current->id,id)==0){
            printf("Name: %s\nAge: %i\nID: %s\n",current->name,current->age,current->id);
            printf("Groups:\n");
            for(int i = 0; i <GROUP_NUM ; i++ ){
                if(current->groups[i]!=-1){
                    printf("%i\t",current->groups[i]);
                }   
            }
            printf("\n");

            return;


        }

        current=current->ptr;


    }
}



void print_system(User* root) {
    User* current = root;
    while (current != NULL) {
        print_user(current,current->id);
        current = current->ptr;
    }
}
User* create_user(User* root,char* name ,int age , const char* id , int groupss[]){
    User* new_user=(User*)malloc(sizeof(User));
    strcpy(new_user->name,name);
    new_user->age=age;
    strcpy(new_user->id,id);
    for(int i = 0; i < GROUP_NUM;i++ ){
        new_user->groups[i]=groupss[i];
    }
    new_user->ptr= root->ptr;
    root->ptr=new_user;
    return new_user;
}
void modify(User* root , const char* id , char* name){
    User* current = root;
    while(current != NULL){
        if(strcmp(current->id,id)==0){
            strcpy(current->name,name);
            printf("Modification Done!\n");

            return;
        }
        
        current=current->ptr;
        
    }
    printf("User wasn't found\n");

}
void delete_user(User* root, const char* id) {
    User* current = root;
    User* prev = NULL;

    while (current != NULL && strcmp(current->id,id)!=0) {
        prev = current;
        current = current->ptr;
    }

    if (current == NULL) {
        printf("User with ID %s not found.\n", id);
        return;
    }

    if (prev != NULL) {
        prev->ptr = current->ptr;
    }

    printf("Deleting user with ID: %s\n", id);
    free(current);
}
void delete_system(User** root) {
    User* current = *root;
    while (current != NULL) {
        User* temp = current;
        current = current->ptr;
        free(temp);
    }
    *root = NULL; // Reset the root pointer to NULL to indicate the system is empty
    printf("All users have been deleted.\n");
}

void add(User* root , const char* id , int newgroup){
    User* current = root;
    while(current != NULL){
        int len =0;
        for(int i = 0 ; i < GROUP_NUM ; i++){
            if(current->groups[i]!=-1){
                len++;
            }
        }
        
        if(strcmp(current->id,id)==0){
            if(len == GROUP_NUM){
                fprintf(stderr,"User already has four groups\n");
                return;
            }else{
                for(int i = 0 ; i < GROUP_NUM ; i++){
                    if(current->groups[i]==-1){
                        current->groups[i]=newgroup;
                    }
                }
                printf("Done!\n");

            }
        }
        current=current->ptr;
    }
    printf("No such user with this ID!\n");
}
void system_export(User* root,char* filename){
    FILE* file = fopen(filename,"w");
    User* current= root;
    while(current!=NULL){
        fprintf(file,"Name: %s,\t",current->name);
        fprintf(file,"Age: %i,\t",current->age);
        fprintf(file,"Id: %s\n",current->id);
        for(int j = 0 ; j <GROUP_NUM;j++){
            fprintf(file,"Group %i: %i\t\n",j+1,current->groups[j]);
                //printf("\n");
        }
            //printf("\n");
            current=current->ptr;

        }
    
    
    fclose(file);
}