

#include<stdio.h>
#include<math.h>
// #include<password.h>
#include<string.h>
int process=0;
struct login{
    char *name;
    char *pasword;
    char *enc;
    int incre;
    char oldpass[5][20];
    int balance;
}obj;
void encryption(char pas[]){
    // printf("r");
    char j[20];
    strcpy(j,pas);
for(int i=0;j[i]!='\0';i++)
{
    j[i]=j[i]+2;
}
// printf("%s",pas);
obj.enc=j;
}

void display(){
    printf("Name: %s\n",obj.name);
    printf("Password:%s\n",obj.pasword);
    printf("Encry Password:%s\n",obj.enc);
}

void deposit(){
    printf("Minimum amount to deposit is 10000\nEnter your deposit amount:");
    int deposit;
    label:
    scanf("%d",&deposit);
    if(deposit<10000){
        printf("Its not a valid amount\n");
        goto label;
    }
    else{
        obj.balance=deposit;
    }
}
void transaction(){
    printf("Enter the account id:");
    int id;
    scanf("%d",&id);
    int amt;
    printf("Enter the amount:");
    scanf("%d",&amt);
    obj.balance=obj.balance-amt-50;
    printf("Transaction made!\n");
}

int loginin(){
    char Name[20];
    char Password[20];
    name:
    printf("Enter the Name to login:");
    scanf("%s",Name);
    pass:
    printf("Enter the Password:");
    scanf("%s",Password);
    if(strcmp(obj.name,Name)==0){
        // printf("%s %s",obj.pasword,Password);
        if(strcmp(obj.pasword,Password)==0){
        return 1;
    }
    else{
        printf("Password Incorrect");
        goto pass;
    }
    }
    else{
        printf("Name not exsist");
        goto name;
    }
    
}

int main(){

    // // struct login ob[];
    // for(int i=0;i<1;i++){
    char Name[20];
    char Password[20];
    char ConfirmPassword[20];
    printf("Enter the Name:");
    scanf("%s",Name);
    Pass:
    printf("Enter the Password:");
    scanf("%s",Password);
    printf("Confirm Password:");
    scanf("%s",ConfirmPassword);
    // std::cout << Name <<" "<< Password;
    if(strcmp(Password,ConfirmPassword)==0){
        // obj[i]=(struct login)malloc(sizeof(struct login));
        obj.name=Name;
        obj.pasword=Password;
        encryption(Password);
    }
    else{
        printf("Password Mismatch");
        goto Pass;
    }
        // // printf("in1");
        // printf("PRESS Y TO DISPLAY DETAILS:");
        // char ch;
        // scanf("\n%c",&ch);
        // if(ch=='Y'){
        //     display();
        // }
    // do{
    // printf("Do you want to change the password?");
    // scanf("\n%c",&ch);
    // if(ch=='Y'){
    //     printf("Enter the Password:");
    // scanf("%s",Password);
    // printf("Confirm Password:");
    // scanf("%s",ConfirmPassword);
    // if(strcmp(Password,ConfirmPassword)==0){
    //     obj.name=Name;
    //     obj.pasword=Password;
    //     encryption(Password);
    // }
    // else{
    //     printf("Password Mismatch");
    //     goto Pass;
    // }
    // }
    // }while(ch!='N');
    printf("Account Created\n");
    if(loginin()){
    printf("Enter your Choice:-\n");
    printf("1.deposit\n2.transaction\n3.display details\n4.exit");
    int choice;
    while(1){
    scanf("%d",&choice);
    switch(choice){
        case 1:
        {
            deposit();
            break;
        }
        case 2:
        {
            transaction();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:{
            break;
        }
    }
    printf('Enter ur choice');
    scanf("%d",&choice);
    }
}}