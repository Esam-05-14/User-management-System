#include "UserManagementSystem.h"



int main(){
    User* root= init();

    int choice=-1;
    printf("Please choose one of the options by entering its index:\n");
    printf("1.Create_user\n2.Count_users\n3.Delete_user\n4.Modify_user\n5.Print_user\n6.Print_system\n");
    printf("7.Add_group\n8.Export_system\n9.Exit\n10.Show_the_menu\n");



    while(choice){
        scanf("%i",&choice);
        if(choice==1){
            printf("Please Enter the name of User\n");
            char name[15];
            scanf("%s",name);
            printf("Please Enter the age of User\n");
            int age;
            scanf("%i",&age);
            printf("Please Enter the Id of User\n");
            char id[8];
            scanf("%s",id);
            printf("Please Enter the Groups of User\nEnter -1 if he deosn't belong to the group\n");
            int groups[GROUP_NUM];
            for(int i = 0 ; i < GROUP_NUM ; i++){
                int groupnum;
                scanf("%i",&groupnum);
                groups[i]=groupnum;
            }
            User* newuser = create_user(root,name,age,id,groups);
            printf("Creation Done!\n");
            printf("enter another choice,10 for menu,or 9 for exit\n");


        }
        else if(choice == 2){
            int count = count_users(root);
            printf("The number of users is %i\n",count);
            printf("enter another choice,10 for menu,or 9 for exit\n");

        }
        else if(choice==3){
            printf("Please Enter the Id of User\n");
            char id[8];
            scanf("%s",id);
            delete_user(root,id);
            printf("enter another choice,10 for menu,or 9 for exit\n");

        }
        else if(choice == 4){
            
            printf("Please Enter the Id of User\n");
            char id[8];
            scanf("%s",id);
            printf("Please Enter the new name of the User\n");
            char name[15];
            scanf("%s",name);
            modify(root,id,name);
            printf("enter another choice,10 for menu,or 9 for exit\n");

        }
        else if (choice == 5){
            printf("Please Enter the Id of User\n");
            char id[8];
            scanf("%s",id);
            print_user(root,id);
            printf("enter another choice,10 for menu,or 9 for exit\n");


        }
        else if (choice == 6){
            print_system(root);
            printf("enter another choice,10 for menu,or 9 for exit\n");

        }
        else if (choice == 7){
            printf("Please Enter the Id of User\n");
            char id[8];
            scanf("%s",id);
            printf("Please Enter the new group for User\n");
            int newgroup;
            scanf("%i",&newgroup);
            add(root,id,newgroup);
            printf("enter another choice,10 for menu,or 9 for exit\n");


        }
        else if(choice == 8){
            char filename[20];
            printf("enter the name of the file\n");
            scanf("%s",filename);
            system_export(root,filename);
            printf("enter another choice,10 for menu,or 9 for exit\n");

        }
        else if(choice == 9){
            delete_system(&root);
            printf("enter another choice,10 for menu,or 9 for exit\n");

            return 0;
        }
        else if(choice == 10){
            printf("1.Create_user\n2.Count_users\n3.Delete_user\n4.Modify_user\n5.Print_user\n6.Print_system\n");
            printf("7.Add_group\n8.Export_system\n9.Exit\n10.Show_the_menu\n");
        }
        else{
        printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    delete_system(&root);


    

}