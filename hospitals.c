#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ad
{
    char name[30];
    char disease[30];
    int age,cabin;
    double phone;
} x[100];

int n,i,j=0,a=0,sum=0,g,flag,num;
void menu();
void read();
void add();
void view();
void search();
void edit();
void del();
void write();
int main()
{
    read();
    //int c,i,q;
    printf("Hospital Management System\n");
    menu();
}
    
void menu()
{
    int c;
    printf("\n1. View Records\n2. Add Records\n3. Search Records\n4. Edit Records\n5. Delete Records\n6. Exit\n\nEnter your choice: ");
    scanf("%d",&c);
    fflush(stdin);//clearing buffer
    switch(c)
    {
        case 1:system("cls");
            view();break;
            
        case 2:system("cls");
            add(); break;
            
        case 3:system("cls");
            search(); break;
            
        case 4:system("cls");
            edit();break;
            
        case 5:system("cls");
            del();break;
            
        case 6:system("cls");
            exit(1);break;
            
        default:printf("\nInvalid choice, pick again!\n");
            break;
    }
}

void add()
{
    printf("\n");
    printf("How many records would you like to add?\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's name: ");
        scanf(" %s",x[i].name);
        fflush(stdin);
        printf("Enter condition: ");
        scanf("%s",x[i].disease);
        fflush(stdin);
        printf("Enter age: ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("Enter ward number: ");
        scanf("%d",&x[i].cabin);
        fflush(stdin);
        printf("Enter phone number: ");
        scanf("%lf",&x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
    write();
    menu();
}

void view()
{
    printf("Existing records: %d\n\n",num);//how many records already exist
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("Serial Number: %d\n",i);
        printf("Name: ");
        puts(x[i].name);
        printf("Condition: ");
        puts(x[i].disease);
        printf("Age: %d\nWard Number: %d\nPhone Number: %.lf\n",x[i].age,x[i].cabin,x[i].phone);
        printf("\n");
    }
    menu();
}

void edit()
{
    int q,p;
    fflush(stdin);
    printf("Enter the serial number of patient(0 - %d): ",num-1);
    scanf("%d",&p);
    if (p<num)
    {
        printf("\n");
        printf("What would you like to change?\n");
        printf("1. Name\n2. Condition\n3. Age\n4. Ward number\n5. Phone number\n");
        printf("Enter your choice: ");
        scanf("%d",&q);
        if(q<=5)
        {
            fflush(stdin);
            if(q==1)
            {
                printf("Enter updated name: ");
                scanf(" %s",x[p].name);

            }
            else if(q==2)
            {
                printf("Enter updated condition: ");
                scanf(" %s",x[p].disease);
            }
            else if(q==3)
            {
                printf("Enter updated age: ");
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                printf("Enter updated ward number: ");
                scanf("%d",&x[p].cabin);
            }

            else if(q==5)
            {
                printf("Enter updated phone number: ");
                scanf("%lf",&x[p].phone);
            }
        }
        else
        {
            printf("\nInvalid option\nPlease choose again!\n\n");
        }
    }
    else
    {
        printf("\nInvalid serial number, patient doesn't exist.\nPlease choose again!\n");
    }
    menu();
}

void search()
{
    int s,h,f;
    char u[100];
    char v[100];
    printf("Choose search criteria:\n");
    printf("1. Serial number\n2. Name\n3. Condition\n4. Age\n5. Ward number\n6. Phone number\nOption: ");
    scanf("%d",&h);
    if(h==1)
    {
        printf("\nEnter serial number to search by(0-%d): ",(num-1));
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number: %d\n",s);
            printf("Name: ");
            puts(x[s].name);
            printf("Condition: ");
            puts(x[s].disease);
            printf("Age: %d\nWard number: %d\nPhone number: %.lf\n",x[s].age,x[s].cabin,x[s].phone);
            printf("\n");
        }
        else
            printf("\n\nNo records found. Invalid serial number!\n\n");
    }
    else if(h==2)
    {
        int f=1;
        fflush(stdin);
        printf("Enter name to search by: ");
        scanf(" %s",u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial number: %d\n",g);
                printf("Name: ");
                puts(x[g].name);
                printf("Condition: ");
                puts(x[g].disease);
                printf("Age: %d\nWard number: %d\nPhone number: %.lf",x[g].age,x[g].cabin,x[g].phone);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNo records found.\n");
    }
    else if(h==3)
    {
        int f=1;
        printf("Enter the condition to search by: ");
        scanf(" %s",v);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(v,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number: %d\n",g);
                printf("Name: ");
                puts(x[g].name);
                printf("Condition: ");
                puts(x[g].disease);
                printf("Age: %d\nWard number: %d\nPhone number: %.lf\n",x[g].age,x[g].cabin,x[g].phone);
                printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("\nNo records found.\n");
     }
     else if(h==4)
     {
         int f=1;
         int r;
         printf("Enter age to search by: ");
         scanf("%d",&r);
         fflush(stdin);
         for(g=0; g<num; g++)
         {
             if(r==x[g].age)
             {
                 printf("\n");
                 printf("Serial number: %d\n",g);
                 printf("Name: ");
                 puts(x[g].name);
                 printf("Condition: ");
                 puts(x[g].disease);
                 printf("Age: %d\nWard number: %d\nPhone number: %.lf\n",x[g].age,x[g].cabin,x[g].phone);
                 printf("\n\n");
                 f=0;
             }
         }
         if(f==1)
             printf("No records found.\n\n");

     }
     else if(h==5)
     {
        int f=1;
         int r;
        printf("Enter ward number to search by: ");
        scanf("%d",&r);
        for(g=0; g<num; g++)
        {
            if(r==x[g].cabin)
            {
                printf("\n");
                printf("Serial number: %d\n",g);
                printf("Name: ");
                puts(x[g].name);
                printf("Condition: ");
                puts(x[g].disease);
                printf("Age: %d\nWard number: %d\nPhone number: %.lf\n",x[g].age,x[g].cabin,x[g].phone);
                printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("No records found\n\n");
    }
    else if(h==6)
    {
        int f=1;
        double r;
        printf("Enter phone number to search by: ");
        scanf("%lf",&r);
        for(g=0; g<num; g++)
        {
            if (r==x[g].phone)
            {
                printf("\n");
                printf("Serial number: %d\n",g);
                printf("Name: ");
                puts(x[g].name);
                printf("Condition: ");
                puts(x[g].disease);
                printf("Age: %d\nWard number: %d\nPhone number: %.lf\n",x[g].age,x[g].cabin,x[g].phone);
                printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("Not Found\n\n");
    }
    else
    {
        printf("\n\nInvalid choice, choose again!\n\n");
        search();
    }
    menu();
}

void del()
{
    int f,h;
    printf("Enter the serial number of the patient whose records are to be deleted: ");
    scanf("%d",&f);
    if(f<num)
    {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin=x[f+1].cabin;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        printf("Record deleted successfully!\n");
    }
    else
        printf("\n\nInvalid serial number! Patient does not exist.\n");
    menu();
}
void read()
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it in next execution
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, file created\n");
    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad),num, fp);

    fclose(fp);
}
