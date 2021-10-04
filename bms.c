#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int choice;
void sleep(int);
void menu();
void sleep(int a)
{
    int b,c;
    for(b=0;b<a;b++)
         c=b;
}
struct date
{
    int day;
    int month;
    int year;
};
struct details
{
    char name[20];
    int acc_no,age;
    char address[60];
    char aadhar[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    }add;
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void new_acc()
{
    int ch=0,newacc_no;
    FILE *file;
    file=fopen("record.bin","ab+");
    while(1)
    {
          if(ch==1)
        break;
    system("cls");
    printf("\n\n\t\t\t\t\t NEW ACCOUNT CREATION ZONE  ");
    printf("\n\t\t\t ---------------------------------------------------------");
    printf("\n\n\n\t\t\tEnter Today's Date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\n\n\t\t\tEnter the Desired Account Number:");
    scanf("%d",&newacc_no);
    fflush(stdin);
    while(  fread(&add, sizeof(struct details), 1, file) )
    {
     if (newacc_no==add.acc_no)
            {
               printf("\n\n\n\t\t\t\tACCOUNT NUMBER IS ALREADY IS USE BY ANOTHER CUSTOMER!!!!");
               sleep(1000000000);
               fseek(file, 0, SEEK_SET);
               break;
            }
    }
    if(newacc_no!=add.acc_no)
        ch=1;
    }
    add.acc_no=newacc_no;
    fflush(stdin);
    printf("\n\n\t\t\tEnter the Name:");
    scanf("%s",add.name);
    fflush(stdin);
    printf("\n\n\t\t\tEnter the Date of Birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\n\n\t\t\tEnter the Age:");
    scanf("%d",&add.age);
    fflush(stdin);
    printf("\n\n\t\t\tEnter the Address:");
    scanf("%s",add.address);
    printf("\n\n\t\t\tEnter the Aadhar Number:");
    scanf("%s",add.aadhar);
    printf("\n\n\t\t\tEnter the Phone Number: ");
    scanf("%lf",&add.phone);
    fflush(stdin);
    printf("\n\n\t\t\tEnter the Amount to Deposit:  Rs. ");
    scanf("%f",&add.amt);
    printf("\n\n\t\t\tType of Account:\n\t\t\t\t1.Saving\n\t\t\t\t2.Current\n\t\t\t\t3.Fixed1(for 1 year)(9%)\n\t\t\t\t4.Fixed2(for 2 years)(11%)\n\t\t\t\t5.Fixed3(for 3 years)(13%)\n\n\t\t\tENTER YOUR CHOICE(Write the Type to be Selected):");
    scanf("%s",add.acc_type);

    fwrite(&add, sizeof(struct details), 1, file);
    fclose(file);

    printf("\n\n\n\t\t\t\tACCOUNT CREATED SUCCESSFULLY!!!!");
     ch=0;
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to the Main Menu, 0 to Exit and 2 for Creating a New Account:");
        scanf("%d",&choice);
        fflush(stdin);
        system("cls");
    if (choice==1)
        menu();
    else if(choice==0)
         exit(0);
    else if(choice==2)
        {
            system("cls");
            new_acc();
        }
    else
        {
            printf("\n\n\n\t\t\t\tINVALID!!!!\a");
            sleep(1000000000);
        }
    }
}
void edit(void)
{
    int ch,t=0,update_acc_no,update_phone;
    char update_address[60],update_acc_type[10];
    FILE *old,*newrec;
    old=fopen("record.bin","rb");
    newrec=fopen("newrecord.bin","wb");
    printf("\n\n\n\t\t\t\t CUSTOMER INFORMATION ALTERING DOMAIN");
    printf("\n\t\t\t ----------------------------------------------------");
    printf("\n\n\n\t\t\tEnter the Account no. of the Customer whose Info You Desire to Alter:");
    scanf("%d",&update_acc_no);
    while(fread(&add, sizeof(struct details), 1, old))
    {
        if (add.acc_no==update_acc_no)
        {   t=1;
            printf("\n\n\t\t\tWhich Information do You Desire to Alter?\n\n\t\t\t\t1.Address\n\n\t\t\t\t2.Phone\n\n\t\t\t\t3.Account Type\n\n\n\t\t\tENTER YOUR CHOICE:");
            scanf("%d",&ch);
            system("cls");
            if(ch==1)
                {
                    printf("\n\n\n\t\t\tEnter the new address:");
                    scanf("%s",update_address);
                    strcpy(add.address,update_address);
                    fwrite(&add, sizeof(struct details), 1, newrec);
                    system("cls");
                    printf("\n\n\n\n\t\t\t\t\t\tCHANGES SAVED!!!!");
                }
            else if(ch==2)
                {
                    printf("\n\n\n\t\t\tEnter the new phone number:");
                    scanf("%lf",&update_phone);
                    add.phone = update_phone;
                    fwrite(&add, sizeof(struct details), 1, newrec);
                    system("cls");
                     printf("\n\n\n\n\t\t\t\t\t\tCHANGES SAVED!!!!");
                }
            else if(ch==3)
            {
                    printf("\n\n\n\t\t\tType of Account:\n\n\t\t\t1.Saving\n\n\t\t\t2.Current\n\n\t\t\t3.Fixed1(for 1 year)(9%)\n\n\t\t\t4.Fixed2(for 2 years)(11%)\n\n\t\t\t5.Fixed3(for 3 years)(13%)");
                    printf("\n\n\t\t\tEnter the New Account Type:");
                    scanf("%s",update_acc_type);
                    strcpy(add.acc_type,update_acc_type);
                    fwrite(&add, sizeof(struct details), 1, newrec);
                    system("cls");
                    printf("\n\n\n\n\t\t\t\t\t\tCHANGES SAVED!!!!");            }
        }
            else
                 fwrite(&add, sizeof(struct details), 1, newrec);
        }
    fclose(old);
    fclose(newrec);
    remove("record.bin");
    rename("newrecord.bin","record.bin");

if(t!=1)
        {
            system("cls");
            printf("\n\n\n\t\t\t\tRECORD NOT FOUND!!!!\a\a\a");
            ch=0;
            while(1)
            {
              printf("\nEnter 0 to Exit,1 to return to Main Menu and 2 to Try Again:");
              scanf("%d",&choice);
              fflush(stdin);
              system("cls");
                 if (choice==1)
                    menu();
                else if(choice==2)
                    edit();
                else if(choice==0)
                   exit(0);
                else
                    {
                        printf("\n\n\n\t\t\t\tINVALID!!!!\a");
                        sleep(100000000);
                    }
        }
        }
    else
        {
        while(1)
        {
        printf("\n\n\nEnter 1 to go to the Main Menu, 0 to Exit and 2 to Alter More Information:");
        scanf("%d",&choice);
        system("cls");
        if (choice==1)
            menu();
        else if(choice==0)
            exit(0);
        else if(choice==2)
        {
            system("cls");
            edit();
        }
        else
                    {
                        printf("\n\n\n\t\t\t\tINVALID!!!!\a");
                        sleep(100000000);
                    }
        }
        }
}
void transact(void)
{
    int ch,t=0,trans_acc_no;
    float trans_amt;
    FILE *old,*newrec;
    old=fopen("record.bin","rb");
    newrec=fopen("new.bin","wb");
    printf("\n\n\n\t\t\t\t\t TRANSACTION ZONE");
     printf("\n\t\t\t ------------------------------------------------");
    printf("\n\n\n\t\t\tEnter the Account no. of the Customer:");
    scanf("%d",&trans_acc_no);
    while( fread(&add, sizeof(struct details), 1,old))
       {
            if(add.acc_no==trans_acc_no)
            {
                 t=1;
                 printf("\n\n\n\t\t\t\t CURRENT BALANCE : Rs. %f",add.amt);
                if( strcmp(add.acc_type,"fixed1")==0 || strcmp(add.acc_type,"fixed2")==0 || strcmp(add.acc_type,"fixed3") || strcmp(add.acc_type,"FIXED1")==0 || strcmp(add.acc_type,"FIXED2")==0 ||  strcmp(add.acc_type,"FIXED3")==0 )
                {
                    printf("\n\n\n\n\t\t\tYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    while(1)
                    {
                    printf("\n\n\n\t\t\tEnter 0 to Exit,1 to Return to Main Menu and 2 to Try Again:");
                    scanf("%d",&choice);
                    system("cls");
                    if (choice==2)
                          {
                              system("cls");
                              transact();
                          }
                    else if (choice==1)
                           menu();
                    else if (choice==0)
                            exit(0);
                    else
                    {
                        printf("\n\n\n\t\t\t\tINVALID!!!!\a");
                        sleep(100000000);
                    }
                }
                }
                 while(1)
                 {
                printf("\n\n\n\t\t\t\tWhich Action Would You Like to Perform : \n\n\t\t\t\t1.Deposit\n\n\t\t\t\t2.Withdraw?\n\n\t\t\t\t3.Exit\n\n\n\t\t\t\tENTER YOUR CHOICE:");
                scanf("%d",&ch);
                if (ch==1)
                {
                    printf("\n\n\n\t\t\tEnter the amount you want to deposit: Rs.  ");
                    scanf("%f",&trans_amt);
                    add.amt+=trans_amt;
                    fwrite(&add, sizeof(struct details), 1, newrec);
                    printf("\n\n\t\t\t\tDEPOSITED SUCCESSFULLY!!!!");
                }
                else if (ch==2)
                {
                    printf("\n\n\n\t\t\tEnter the Amount You Want to Withdraw: Rs. ");
                    scanf("%f",&trans_amt);
                    add.amt-=trans_amt;
                    fwrite(&add, sizeof(struct details), 1, newrec);
                    printf("\n\n\t\t\tWITHDRAWN SUCCESSFULLY!!!!");
                }
                else if (ch==3)
                  exit(0);
                else
                {
                      printf("\n\n\n\t\t\t\tINVALID!!!!");
                      sleep(1000000000);
                 }
                 }
            }
            else
                 fwrite(&add, sizeof(struct details), 1, newrec);
   }
   fclose(old);
   fclose(newrec);
   remove("record.bin");
   rename("new.bin","record.bin");
   if(t!=1)
   {
       printf("\n\n\n\t\t\t\tRECORD NOT FOUND!!!!");
      while(1)
      {
      printf("\n\n\n\t\t\tEnter 0to Exit,1 to Return to Main Menu and 2 to Try Again:");
      scanf("%d",&choice);
      system("cls");
      if (choice==2)
        transact();
    else if (choice==1)
        menu();
     else if (choice==0)
        exit(0);
    else
    {
        printf("\n\n\n\t\t\t\tINVALID!!!!");
        sleep(1000000000);
    }
      }
 }
   else
   {
       while(1)
       {
       printf("\n\n\n\t\t\tEnter 1 to go to the Main Menu, 0 to Exit and 2 to Make more Transactions:");
        scanf("%d",&choice);
        system("cls");
        if (choice==1)
            menu();
        else if(choice==0)
            exit(0);
        else if(choice==2)
            transact();
         else
    {
        printf("\n\n\n\t\t\t\tINVALID!!!!");
        sleep(1000000000);
    }
       }
    }
}
void del_acc(void)
{
    FILE *old,*newrec;
    int t=0,del_acc_no;
    old=fopen("record.bin","rb");
    newrec=fopen("new.bin","wb");
    printf("\n\n\n\t\t\t\t\t ACCOUNT DELETION ZONE");
     printf("\n\t\t\t -----------------------------------------------------");
    printf("\n\n\n\t\t\tEnter the Account no. of the Customer You Desire to Obliterate:");
    scanf("%d",&del_acc_no);
    while (fread(&add, sizeof(struct details), 1, old))
   {
        if(add.acc_no!=del_acc_no)
         fwrite(&add, sizeof(struct details), 1, newrec);
        else
            {
                 t++;
                 printf("\n\n\n\t\t\t\tRECORD DELETED SUCCESSFULLY!!!!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.bin");
   rename("new.bin","record.bin");
   if(t==0)
        {
           printf("\n\n\n\t\t\t\tRECORD NOT FOUND!!!!\n");
            while(1)
            {
              printf("\n\n\n\t\t\tEnter 0 to Exit,1 to Return to Main Menu and 2 to Try Again:");
              scanf("%d",&choice);

                 if (choice==1)
                    menu();
                else if(choice==0)
                    exit(0);
                else if(choice==2)
                   del_acc();
                else
                    {
                    printf("\nINVALID!!!!\a");
                    }
            }
        }
    else
        {
        while(1)
        {
        printf("\nEnter 1 to go to the Main Menu, 0 to Exit and 2 to Obliterate More Accounts:");
        scanf("%d",&choice);
        system("clear");
        if (choice==1)
            menu();
        else if(choice==0)
            exit(0);
        else if(choice==2)
                del_acc();
        else
                    {
                        printf("\n\n\n\t\t\t\tINVALID!!!!\a");
                        sleep(100000000);
                    }
        }
        }
}
void displaycon(void)
{
    FILE *file;
    int t=0,rate,ch,newacc_no;
    float time,intrst;
    char name[20];
    file=fopen("record.bin","rb");
    printf("\n\n\n\t\t\t\t\t CUSTOMER RECORDS DISPLAY ZONE");
     printf("\n\t\t\t -------------------------------------------------------------");
    printf("\n\n\n\t\t\tYou Want to Check Through : \n\n\t\t\t1.Account Number\n\n\t\t\t2.Name\n\n\n\t\t\tENTER YOUR CHOICE:");
    scanf("%d",&ch);
    if (ch==1)
    {
        printf("\n\n\n\t\t\tEnter the Account Number:");
        scanf("%d",&newacc_no);

        while( fread(&add, sizeof(struct details), 1, file))
            {
            if(add.acc_no==newacc_no)
            {   system("cls");
                t=1;

                printf("\n\n\t\t\tAccount NO.:%d\n\n\t\t\tName:%s \n\n\t\t\tDOB:%d/%d/%d \n\n\t\t\tAge:%d \n\n\t\t\tAddress:%s \n\n\t\t\tAadhar No:%s \n\n\t\t\tPhone Number:%.0lf \n\n\t\t\tType Of Account:%s \n\n\t\t\tAmount deposited: %.2f \n\n\t\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmp(add.acc_type,"fixed1")==0 || strcmp(add.acc_type,"FIXED1")==0 )
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs. %.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"fixed2")==0 || strcmp(add.acc_type,"FIXED2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs.%.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"fixed3")==0 || strcmp(add.acc_type,"FIXED2")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs.%.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"savings")==0 || strcmp(add.acc_type,"SAVINGS")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs. %.2f as Interest on %d of Every Month",intrst,add.deposit.day);

                     }
                 else if(strcmp(add.acc_type,"current")==0 || strcmp(add.acc_type,"CURRENT")==0)
                    {

                        printf("\n\n\t\t\tYou will get No Interest.");

                     }

            }
        }
    }
    else if (ch==2)
    {   printf("\n\n\n\t\t\tEnter the name:");
        scanf("%s",&name);
        while( fread(&add, sizeof(struct details), 1,file))
        {
            if(strcmp(add.name,name)==0)
            {   system("cls");
                t=1;
                 printf("\n\n\t\t\tAccount NO.:%d\n\n\t\t\tName:%s \n\n\t\t\tDOB:%d/%d/%d \n\n\t\t\tAge:%d \n\n\t\t\tAddress:%s \n\n\t\t\tAadhar No:%s \n\n\t\t\tPhone Number:%.0lf \n\n\t\t\tType Of Account:%s \n\n\t\t\tAmount deposited: %.2f \n\n\t\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmp(add.acc_type,"fixed1")==0 || strcmp(add.acc_type,"FIXED1")==0 )
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs. %.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"fixed2")==0 || strcmp(add.acc_type,"FIXED2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs.%.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"fixed3")==0 || strcmp(add.acc_type,"FIXED2")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs.%.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"savings")==0 || strcmp(add.acc_type,"SAVINGS")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get Rs. %.2f as Interest on %d of every month",intrst,add.deposit.day);
                     }
                 else if(strcmp(add.acc_type,"current")==0 || strcmp(add.acc_type,"CURRENT")==0)
                    {
                        printf("\n\n\t\t\tYou will get No Interest.");
                     }
            }
        }
    }

    fclose(file);
     if(t!=1)
        {   system("cls");
            printf("\n\n\n\t\t\t\tRECORD NOT FOUND!!!!\a\a\a");
             while(1)
             {
              printf("\n\n\n\t\t\tEnter 1 to Return to Main Menu, 0 to Exit and 2 to Try Again:");
              scanf("%d",&choice);
              system("cls");
                 if (choice==1)
                    menu();
                else if(choice==0)
                    exit(0);
                else if(choice==2)
                    displaycon();
                else
                    {
                        printf("\n\n\n\t\t\t\tINVALID!!!!");
                        sleep(1000000000);
                        }
             }
        }
    else
        {
            while(1)
            {
            printf("\n\n\t\t\tEnter 1 to go to the Main Menu, 0 to Exit and 2 to view Records of Another Account:");
            scanf("%d",&choice);
            if (choice==1)
            {
                 system("cls");
                menu();
             }
            else if(choice==0)
                 exit(0);
            else if(choice==2)
            {
                system("cls");
                displaycon();
            }
            else
                    {
                        printf("\n\n\n\t\t\t\tINVALID!!!!\a");
                        sleep(100000000);
                    }
            }
        }
}
void display()
{
    FILE *display;
    display=fopen("record.bin","rb");
    int t=0;
    system("cls");
    printf("\n\n\n\t\t\t\t\t       CUSTOMER LIST");
     printf("\n\t\t\t ---------------------------------------------------------");
    printf("\n\n\nACC. NO.\t\tNAME\t\t\tADDRESS\t\t\tPHONE\t\t\tAADHAR\t\t\tACC_TYPE\n");

    while( fread(&add, sizeof(struct details), 1, display))
       {
           printf("\n\n%10d\t %10s\t\t\t%10s\t\t%.0lf\t\t%s\t\t%s",add.acc_no,add.name,add.address,add.phone,add.aadhar,add.acc_type);
           t++;
       }

    fclose(display);
    if (t==0)
        {
            system("cls");
            printf("\nNO RECORDS!!\n");
        }

    while(1)
    {
     printf("\n\nEnter 1 to go to the Main Menu and 0 to Exit:");
        scanf("%d",&choice);
        system("cls");
        if (choice==1)
            menu();
        else if(choice==0)
            exit(0);
        else
        {
            printf("\n\n\n\t\t\t\tINVALID!!!!");
            sleep(1000000000);
        }
    }
}
void login(void)
{
    char ch,pass[10],password[10]="bmssystem",user[10],username[10]="LUCIFER";
    int i=0;
    printf("\n\n\n\n\t\t\t\tENTER THE USERNAME TO LOGIN:");
    scanf("%s",user);
    printf("\n\n\n\n\t\t\t\tENTER THE PASSWORD TO LOGIN:");
    while (1)
        {
      if (i < 0)
      {
         i = 0;
      }
      ch = getch();
      if (ch == 13)
         break;
      if (ch == 8)
      {
         printf("\b");
         i--;
         putch(NULL);
      }
      if(ch==8)
         putch(ch);
      else
      {
      pass[i++] = ch;
      ch = '*';
      putch(ch);
      }
   }
   pass[i] = '\0';
    if (strcmp(pass,password)==0 && strcmp(user,username)==0)
    {
        printf("\n\n\n\t\t\t\tUSERNAME AND PASSWORD MATCH SUCCESSFUL!!!! \n\n\n\n\t\t\t\t LOADING ");
        for(i=0;i<=6;i++)
        {
            printf(".");
            sleep(100000000);
         }
         system("cls");
         menu();
     }
     else
     {
         printf("\n\n\n\t\t\t\tUSERNAME AND PASSWORD MATCH FAILED!!!! \n\n\n\n\t\t\t\t LOADING ");
          for(i=0;i<=6;i++)
        {
            printf(".");
            sleep(100000000);
         }
         system("cls");
         main();
     }
}
void menu(void)
{
     int ch;
    system("cls");
    printf("\n\n\n\t\t\t ---------------------------------------------------------");
    printf("\n\t\t\t\t\t BANKING MANAGEMENT SYSTEM");
    printf("\n\t\t\t ---------------------------------------------------------");
     printf("\n\n\n\t\t\t ---------------------------------------------------------");
    printf("\n\t\t\t\t\t WELCOME TO THE MAIN MENU ");
     printf("\n\t\t\t ---------------------------------------------------------");
    printf("\n\n\n\t\t\t1.CREATE A NEW ACCOUNT\n\n\t\t\t2.MODIFY PRE-EXISTING ACCOUNT INFORMATION\n\n\t\t\t3.TRANSACTIONS\n\n\t\t\t4.INSPECT EXISTING ACCOUNT\n\n\t\t\t5.DELETE EXISTING ACCOUNT\n\n\t\t\t6.DISPLAY CUSTOMER LIST\n\n\t\t\t7.LOG OUT\n\n\t\t\t8.EXIT\n\n\n\n\n\t\t\t ENTER YOUR CHOICE:");
    scanf("%d",&ch);

    system("cls");
    switch(ch)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:displaycon();
        break;
        case 5: del_acc();
        break;
        case 6:display();
        break;
        case 7:main();
        break;
        case 8:exit(0);
        break;
    }
    }
int main()
{
    printf("\n\n\n\t\t\t ---------------------------------------------------------");
    printf("\n\t\t\t\t\t BANKING MANAGEMENT SYSTEM");
    printf("\n\t\t\t ---------------------------------------------------------");
    login();
    return 0;
}
