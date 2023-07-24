#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<string.h>

struct student
{
    char na[30];
    char cl[10];
    int rl;
}s;
struct teacher
{
   char tna[30];
   char tsub[30];
   int tid;
}t;

long si = sizeof(s);
///Student function call
void addmissionStd();
void display();
void search();
void searchByRoll();
void searchByName();
void modify();
void del();
void sort();
void sortByRoll();
void sortByName();
void adMin();

void checkStudent();
void entryStudent();

///End Student function
void adminPage();
///Teacher's function call
void entryTeacher();
void checkTeacher();

void addNewTeacher();
void displayTeacher();
void searchTeacher();
void searchByTeacherId();
void searchByTeacherName();
void modifyTeacher();
void deleteTeacher();

FILE *fp;

void main()
{

    char pass[32],password[]= {"password"};
    char uname[32],user[]= {"admin"};
    printf("\n\t\t    ***** Patel College Of Science And Technology *****");
    printf("\n\t===========================================================\n\n");
    printf("\t\tProject  Name: Patel College Of Science And Technology\n");
    printf("\t\tProject Developer Name: Sonu Kumar (Roll No. 0128CS191081)\n\n");
    printf("\t=============================================================\n\n");
    printf("\n\t\t\t\tLogin Page\n\n");
    printf("\t\t\tUser Name: ");
    scanf("%s",&uname);
    printf("\t\t\tPassword : ");
    scanf("%s",&pass);
    printf("\n");
    if(strcmp(uname,user)==0)
    {
        if(strcmp(pass,password)==0)
        {
            adminPage();
        }
         else
         {
            int ch;
            printf("\n\t===========================================================\n\n");
            printf("\n\t=>=>=>=>\tYour Password was incorrect\t<=<=<=<=\n");
            printf("\t=============================================================\n\n");
            printf("\n\t\t1 For Trying again");
            printf("\t0 To Exit\n ");
            printf("\t_____________________________________________________________\n\n");
            printf("\tSelect Option:");
            scanf("%d",&ch);
            switch(ch)
            {
                case 0:
                        exit(0);
                case 1:
                        main();
                        break;
                default:
                        printf("\n\tInvalid choice..");
            }
        }
    }
     else
    {
        int ch;
        printf("\n\t===========================================================\n\n");
        printf("\n\t=>=>=>=>\tYour Password was incorrect\t<=<=<=<=\n");
        printf("\t=============================================================\n\n");
        printf("\n\t\t1 For Trying again");
        printf("\t0 To Exit\n ");
        printf("\t_____________________________________________________________\n\n");
        printf("\tSelect Option:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                    exit(0);
            case 1:
                    main();
                    break;
            default:
                    printf("\n\tInvalid choice..");
        }
    }
    getch();
}

void adminPage()
{
            int ch;
            char pass[32],password[]= {"password"};
            while(1)
            {
                system("cls");
                printf("\n\t\t\t*** Patel College Of Science And Technology ***\n");
                printf("\t__________________________________________________________\n\n");
                printf("\t\tPress 1 For Admin ");
                printf("\tPress 2 For Teacher\n\n");
                printf("\t\tPress 3 For Student");
                printf("\tPress 0 To Exit\n");
                printf("\t__________________________________________________________\n\n");
                printf("\tSelect option :");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 0:
                            exit(0);
                    case 1:
                            printf("\n\t___________________________________________________________\n\n");
                            printf("\tEnter password : ");
                            scanf("%s",&pass);
                            printf("\n");
                            if(strcmp(pass,password)==0)
                            {
                                adMin();
                            }
                            else
                            {
                                int ch;
                                printf("\n\t===========================================================\n\n");
                                printf("\n\t=>=>=>=>\tYour Password was incorrect\t<=<=<=<=\n");
                                printf("\t=============================================================\n\n");
                                printf("\n\t\t1 For Trying again");
                                printf("\t0 To Exit\n ");
                                printf("\t_____________________________________________________________\n\n");
                                printf("\tSelect Option:");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                    case 0:
                                            exit(0);
                                    case 1:
                                           adminPage();
                                            break;
                                    default:
                                            printf("\n\tInvalid choice..");
                                }
                            }

                            break;
                    case 2:
                            checkTeacher();
                            break;
                    case 3:
                            checkStudent();
                            break;
                    default:
                            printf("\n\tInvalid choice..");
                }
            }
}


void checkTeacher()
{
    int ch;
    while(1)
    {
    system("cls");
    printf("\n\n\t\t\t*** Teacher's Information ***\n");
     printf("\t_____________________________________________________________\n\n");
    printf("\n\t\t1 Teacher List");
    printf("\t\t2 Teacher's Search\n\n");
    printf("\t\t3.Home");
    printf("\t\t\t0.Exit\n");
     printf("\n\t_____________________________________________________________\n\n");
    printf("\tSelect option :");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
           displayTeacher();
           break;
    case 2:
          searchTeacher();
          break;
    case 3:
            adminPage();
            break;
    default:
            printf("\n\tInvalid Choice..");
    }
   }
   getch();
}
void checkStudent()
{

    int ch;
    while(1)
    {
     system("cls");
     printf("\n\t\t\t*** Student's Details ***\n");
     printf("\t__________________________________________________________\n\n");
     printf("\n\t\t1.Student List");
     printf("\t\t2.Search By Roll\n\n");
     printf("\t\t3.Search By Name");
     printf("\t4.Home\n\n");
     printf("\t\t0.Exit\n");
     printf("\n\t__________________________________________________________\n\n");
     printf("\n\tSelect option :");
     scanf("%d",&ch);
     switch(ch)
     {
        case 0:
                exit(0);
        case 1:
                display();
                break;
        case 2:
                searchByRoll();
                break;
        case 3:
                searchByName();
                break;
        case 4:
               adminPage();
                break;
        default:
                printf("\nInvalid choice...");
     }
     getch();
   }
}
void adMin()
{

    int ch;
    while(1)
    {
        system("cls");
        printf("\n\t\t\t*** Admin Portal ***\n");
        printf("\t__________________________________________________________\n\n");
        printf("\n\t\tPress 1 For Teacher");
        printf("\tPress 2 For Student\n\n");
        printf("\t\tPress 3 Home");
        printf("\t\tPress 0 To Exit\n");
        printf("\n\t__________________________________________________________\n\n");
        printf("\n\tSelect option :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
               entryTeacher();
               break;
        case 2:
               entryStudent();
        case 3:
               adminPage();
               break;
        default:
                printf("\n\tInvalid choice...");
        }
        getch();
    }
}
void entryTeacher()
{

    int ch;
     while(1)
     {
            system("cls");
            printf("\n\t\t\t*** Teacher's Portal ***\n");
            printf("\t__________________________________________________________\n\n");
            printf("\t\t1.Take New Teacher Add\t");
            printf("2.Teacher Information\n\n");
            printf("\t\t3.Search\t");
            printf("\t4.Teacher Data Modify\n\n");
            printf("\t\t5. Delete\t");
            printf("\t6.Home\n\n");
            printf("\t\t0.Exit\n");
            printf("\t__________________________________________________________\n\n");
            printf("\tEnter Your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 0:
                        exit(0);
                case 1:
                        addNewTeacher();
                        break;
                case 2:
                        displayTeacher();
                        break;
                case 3:
                        searchTeacher();
                        break;
                case 4:
                        modifyTeacher();
                        break;
                case 5:
                        deleteTeacher();
                        break;
                case 6:
                       adminPage();
                        break;
                default:
                        printf("Invalid Choice");
            }
     }
}
void entryStudent()
{

    int ch;
     while(1)
     {
            system("cls");
            printf("\n\t\t\t*** Student Portal ***\n");
            printf("\t__________________________________________________________\n\n");
            printf("\t\t1.Take Admission\t");
            printf("2.Student Information\n\n");
            printf("\t\t3.Search\t");
            printf("\t4.Modify\n\n");
            printf("\t\t5.Delete\t");
            printf("\t6.Sort\n\n");
            printf("\t\t7.Home");
            printf("\t\t\t0.Exit\n");
            printf("\t__________________________________________________________\n\n");
            printf("\tEnter Your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 0:
                        exit(0);
                case 1:
                        addNewTeacher();
                        break;
                case 2:
                        display();
                        break;
                case 3:
                        search();
                        break;
                case 4:
                        modify();
                        break;
                case 5:
                        del();
                        break;
                case 6:
                        sort();
                        break;
                case 7:
                       adminPage();
                        break;
                default:
                        printf("Invalid Choice");
            }
     }
}

void addNewTeacher()
{
    system("cls");

   printf("\n\t\t\t*** Teacher's New Add Portal ***\n");
    printf("\t***********************************************************\n");
    fp = fopen("th.txt","ab");
    printf("\tEnter Teacher Name: ");
    fflush(stdin);
    gets(t.tna);
    printf("\tEnter Subject: ");
    scanf("%s",t.tsub);
    printf("\tEnter ID: ");
    scanf("%d",&t.tid);
    fwrite(&t, sizeof(t),1,fp);
    printf("\n\tRecord Saved Successfully...\n");
    fclose(fp);
}

void displayTeacher()
{
    system("cls");
    printf("\n\t\t\t*** Teacher's Details List ***\n");
    printf("\t__________________________________________________________\n");
    printf("\tID\t\t|  Name\t\t\t|  Subject");
    printf("\n\t__________________________________________________________\n");
    fp = fopen("th.txt","rb");
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        printf("\t%d ",t.tid);
        printf("\t\t\t   %s ",t.tna);
        printf("\t\t   %s\n",t.tsub);
    }
    printf("\t__________________________________________________________\n\n");
fclose(fp);
printf("\n\tPress any key to continue...\n");
}

void searchTeacher()
{
   int ch;

    while(1)
    {
        system("cls");
        printf("\n\t\t\t*** Teacher's Search Portal ***\n");
        printf("\t__________________________________________________________\n\n");
        printf("\t\t1.Search By ID");
        printf("\t\t2.Search By Name\n\n");
        printf("\t\t0.Back To Main Menu\n");
        printf("\t__________________________________________________________\n\n");
        printf("\tEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0:
                    adminPage();
                    break;

            case 1:
                    searchByTeacherId();
                    break;

            case 2:
                    searchByTeacherName();
                    break;

            default:
                    printf("Invalid Choice");

        }
        getch();
    }
}

void searchByTeacherId()
{
    system("cls");
    int tid,f=0;
    printf("\n\tEnter ID to search: ");
    scanf("%d",&tid);
    printf("\n\t\t\t***Teacher Search by Id ***\n");
    printf("\t__________________________________________________________\n");
    printf("\tID\t\t|  Name\t\t|  Subject");
    printf("\n\t__________________________________________________________\n");
    fp=fopen("th.txt","rb");
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(tid == t.tid)
        {
            f=1;
            printf("\t%d",t.tid);
            printf("\t\t  %s",t.tna);
            printf("\t\t%  s\n",t.tsub);
            break;
        }
    }
    printf("\t__________________________________________________________\n");
    fclose(fp);
    if(f==0)
    printf("\n\tRecord Not Found...");

    else
    printf("\n\tRecord Found Successfully...");
    printf("\n\n\tPress any key...");


}

void searchByTeacherName()
{
    system("cls");
   char tna[30];
    int f=0;
    printf("\n\tEnter Name to search: ");
    fflush(stdin);
    gets(tna);
    printf("\n\t\t\t***Teacher Search by Nmae ***\n");
    printf("\t__________________________________________________________\n");
    printf("\n\tID\t\tName\t\tSubject\n");
    printf("\t__________________________________________________________\n\n");
    fp=fopen("th.txt","rb");
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(strcmpi(tna,t.tna)==0)
        {
            f=1;
            printf("\t%d",t.tid);
            printf("\t\t%s",t.tna);
            printf("\t\t%s\n",t.tsub);
            printf("\t__________________________________________________________\n");
            break;
        }
    }
    fclose(fp);
    if(f==0)
        printf("\n\tRecord Not Found...");
    else
        printf("\n\tRecord Found Successfully...");

}


void modifyTeacher()
{
    system("cls");
    int tid, f=0;
    printf("\n\tEnter ID To Modifiy: ");
    scanf("%d",&tid);
    fp=fopen("th.txt","rb+");
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(tid == t.tid)
        {
            f=1;
            printf("\tEnter New Name: ");
            fflush(stdin);
            gets(t.tna);
            printf("\tEnter Subject: ");
            scanf("%s",t.tsub);
            printf("\tEnter New ID: ");
            scanf("%d",&t.tid);
            fseek(fp,-tid,1);
            fwrite(&t,sizeof(t),1,fp);
            fclose(fp);
            break;
        }
    }
    if(f==0)
        printf("\n\tRecord Not Found...\n");
    else
        printf("\n\tModified Successfully...\n");

}


void deleteTeacher()
{
    system("cls");
   int tid, f=0;
    printf("\n\tEnter ID to delete: ");
    scanf("%d",&tid);

    FILE *ft;
    fp = fopen("th.txt","rb");
    ft = fopen("temp.txt","ab");

    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(tid == t.tid)
        {
            f=1;
        }
        else
        {
            fwrite(&t,sizeof(t),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("ts.txt");
    rename("temp.txt","ts.txt");

    if(f==0)
    printf("\n\tRecord Not Found...\n");
    else
    printf("\n\tRecord Deleted Successfully...\n");
}

void addmissionStd()
{
    system("cls");
    printf("\n\t\t\t*** Student's Admission Portal ***\n");
    printf("\t***********************************************************\n");
    fp = fopen("st.txt","ab");
    printf("\tEnter Student Name: ");
    fflush(stdin);
    gets(s.na);
    printf("\tEnter Class: ");
    scanf("%s",s.cl);
    printf("\tEnter Roll: ");
    scanf("%d",&s.rl);
    fwrite(&s, sizeof(s),1,fp);
    printf("\n\tRecord Saved Successfully...\n");
    fclose(fp);
}

void display()
{
    system("cls");
    printf("\n\t\t\t*** Student Information ***\n");
    printf("\t__________________________________________________________\n");
    printf("\tName\t\t\t|  Class\t\t|  Roll");
    printf("\n\t__________________________________________________________\n");
    fp = fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("\t%s ",s.na);
        printf("\t\t\t   %s ",s.cl);
        printf("\t\t\t   %d\n",s.rl);
    }
    printf("\t__________________________________________________________\n\n");
fclose(fp);
printf("\n\tPress any key to continue...");
}

void search(){
int ch;

while(1)
{
system("cls");
printf("\n\t\t\t*** Student's Search Portal ***\n");
printf("\t__________________________________________________________\n\n");
printf("\t\t1.Search By Roll");
printf("\t2.Search By Name\n\n");
printf("\t\t0.Back To Main Menu\n");
printf("\t__________________________________________________________\n\n");
printf("\tEnter your choice: ");
scanf("%d",&ch);

switch(ch){
case 0:
adminPage();
break;

case 1:
searchByRoll();
break;

case 2:
searchByName();
break;

default:
printf("Invalid Choice");

}
getch();
}
}

void searchByRoll()
{
    system("cls");
    int rl,f=0;
    printf("\n\tEnter Roll to search: ");
    scanf("%d",&rl);
    printf("\n\t\t\t***Students Search by Roll ***\n");
    printf("\t__________________________________________________________\n");
    printf("\n\tName\t\t|Class\t\t|Roll");
    printf("\n\t__________________________________________________________\n");
    fp=fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(rl == s.rl)
        {
            f=1;
            printf("\t%s",s.na);
            printf("\t\t%s",s.cl);
            printf("\t\t%d\n",s.rl);
            printf("\t__________________________________________________________\n");
            break;
        }
    }

    fclose(fp);
    if(f==0)
    printf("\n\tRecord Not Found...");
    else
    printf("\n\tRecord Found Successfully...");
    printf("\n\n\tPress any Key...");

}

void searchByName()
{
    system("cls");
    char na[30];
    int f=0;
    printf("\n\tEnter Name to search: ");
    fflush(stdin);
    gets(na);
    printf("\n\t\t\t***Students Search by Name ***\n");
    printf("\t__________________________________________________________\n");
    printf("\tName\t\tClass\t\tRoll\n");
    printf("\t__________________________________________________________\n\n");
    fp=fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmpi(na,s.na)==0)
        {
            f=1;
            printf("\t%s",s.na);
            printf("\t\t%s",s.cl);
            printf("\t\t%d\n",s.rl);
            printf("\t__________________________________________________________\n");
            break;
        }
    }
    fclose(fp);
    if(f==0)
        printf("\n\tRecord Not Found...");
    else
        printf("\n\tRecord Found Successfully...");
        printf("\n\n\tPress any Key...");
}

void modify()
{
    system("cls");
    int rl, f=0;
    printf("\n\tEnter Roll To Modifiy: ");
    scanf("%d",&rl);
    fp=fopen("st.txt","rb+");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(rl == s.rl)
        {
            f=1;
            printf("\tEnter New Name: ");
            fflush(stdin);
            gets(s.na);
            printf("\tEnter Class: ");
            scanf("%s",s.cl);
            printf("\tEnter New Roll: ");
            scanf("%d",&s.rl);
            fseek(fp,-si,1);
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            break;
        }
    }
    if(f==0)
        printf("\n\tRecord Not Found...\n");
    else
        printf("\n\tModified Successfully...\n");
}

void del()
{
    system("cls");
    int rl, f=0;
    printf("\n\tEnter roll to delete: ");
    scanf("%d",&rl);

    FILE *ft;
    fp = fopen("st.txt","rb");
    ft = fopen("temp.txt","ab");

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(rl == s.rl)
        {
            f=1;
        }
        else
        {
            fwrite(&s,sizeof(s),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("st.txt");
    rename("temp.txt","st.txt");

    if(f==0)
    printf("\n\tRecord Not Found...\n");
    else
    printf("\n\tRecord Deleted Successfully...\n");

}

void sort()
{
    int ch;

    while(1)
    {
        system("cls");

        printf("\n\t\t\t*** Student's Sort Portal ***\n");
        printf("\t__________________________________________________________\n\n");
        printf("\t\t1.Sort By Roll");
        printf("\t\t2.Sort By Name\n\n");
        printf("\t\t0.Back To Main Menu\n");
         printf("\t__________________________________________________________\n");
        printf("\n\tEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0:
                   adminPage();
                    break;

            case 1:
                    sortByRoll();
                    break;

            case 2:
                    sortByName();
                    break;

            default:
                    printf("Invalid Choice");

        }
    getch();
    }

}

void sortByRoll()
{
    system("cls");
    int c=0, i, j;
    struct student s1[50],t;

    printf("\n\t\t*** Student's Sorting By Roll No ***\n");
    printf("\t__________________________________________________________\n");
    fp = fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    s1[c++]=s;

    for(i=0; i<c-1; i++)
    {
        for(j=i+1; j<c; j++)
        {
            if(s1[i].rl >s1[j].rl)
            {
                t = s1[i];
                s1[i]=s1[j];
                s1[j]=t;
            }
        }
    }

    printf("\tName\t\t| Class\t\t| Roll\n");
    printf("\t__________________________________________________________\n\n");

    for(i=0; i<c; i++)
    {
        printf("\t%s",s1[i].na);
        printf("\t\t  %s",s1[i].cl);
        printf(" \t\t  %d\n",s1[i].rl);
    }
     printf("\t__________________________________________________________\n\n");
     printf("\n\tPress any key..");
}

void sortByName()
{
    system("cls");
    int c=0, i, j;
    struct student s1[50],t;
    printf("\n\t\t*** Student's Sorting By Name ***\n");
    printf("\t__________________________________________________________\n");
    fp = fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    s1[c++]=s;

    for(i=0; i<c-1; i++)
    {
        for(j=i+1; j<c; j++)
        {
            if(strcmpi(s1[i].na, s1[j].na)>1)
            {
                t = s1[i];
                s1[i]=s1[j];
                s1[j]=t;
            }
        }
    }

    printf("\n\tName\t\t|  Class\t\t|  Roll\n");
    printf("\t__________________________________________________________\n");
    for(i=0; i<c; i++)
    {
        printf("\t%s",s1[i].na);
        printf("\t\t  %s",s1[i].cl);
        printf("\t\t  %d\n",s1[i].rl);
    }
    printf("\t__________________________________________________________\n");
     printf("\n\tPress any key..");
}
