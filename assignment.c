#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "header.h"      

void main()    //main page    
{
    int choice = 0;
    printf("----------------------------------------------------------------------");
    printf("\n\t\t\tWELCOME TO DOSTA COFFEE SHOP!");
    printf("\n----------------------------------------------------------------------");
    printf("\nThere are three users:");
    printf("\n------------------------");
    printf("\n|[1]Staff               |");
    printf("\n|[2]First Time Customer |");
    printf("\n|[3]Registered Customer |");
    printf("\n------------------------");
    printf("\nPlease choose one user:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        staffpassword();
        break;

    case 2:
        system("cls");
        newcusregister();
        break;

    case 3:
        system("cls");
        registercuslogin();
        break;

    default:
        printf("\nInvalid operator.Please try again after 1 seconds.");
        Sleep(1000);
        system("cls");
        main();
        break;
    }
}

void staffpassword()   //staff key in pw to enter staff portal
{
    char username[20];
    char password[20];
    int g = 3;
    char pw[8] = "staff";
    //loop for user to key in three times, if wrong more than three times, will exit the loop
    while (g--) {
        printf("\n----------------------------------------------------------------------");
        printf("\n\t\t\t\tSTAFF LOGIN");
        printf("\n----------------------------------------------------------------------");
        printf("\nUsername: ");
        scanf("%s", username);
        printf("\nPassword: ");
        scanf("%s", password);
        //check password correct or not
        if (strcmp(pw, password) == 0)
        {
            printf("\nWelcome!Login Success!\n");
            Sleep(500);
            system("cls");
            staffMenu();
        }
        else
        {
            //looping for three times
            if (g == 0) 
            {
                printf("\nInput wrong more than 3 times.You are forced to exit this system.\n");
                exit(1);
            }
            printf("\n[Wrong username or password.Please try again]");
            Sleep(1000);
            system("cls");
            continue;          
        }
    }
}

void read() //read staffadd file into struct
{
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("staffadd.txt", "r");
    if (fp == NULL)
    {
        printf("Error file opening");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);

    FILE* fp1;
    int i = 0;
    char line[50];
    fp1 = fopen("staffadd.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error opening file\n");
    }
    else {
        for (i = 0;i < count;i++)
        {
            fscanf(fp1, "\t%d\t%s\t%s\t\t%f\n", &or [i].category, or [i].code, or [i].name, &or [i].price);
        }
    }
    fclose(fp1);
}

void readmenu() //read staffadd file into struct
{
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("staffadd.txt", "r");
    if (fp == NULL)
    {
        printf("Error file opening");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);

    FILE* fp1;
    int i = 0;
    char line[50];
    fp1 = fopen("staffadd.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error opening file\n");
    }
    else {
        for (i = 0;i < count;i++)
        {
            fscanf(fp1, "\t%d\t%s\t%s\t\t%f\n", &or1[i].category, or1[i].code, or1[i].name, &or1[i].price);
        }
    }
    fclose(fp1);
}

void staffMenu() //staff Menu
{
    read();
    int staffFunc = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\t\t\tSTAFF PORTAL");
    printf("\n----------------------------------------------------------------------");
    printf("\nThere are four functions:");
    printf("\n----------------------------");
    printf("\n|[1]Add new item            |");
    printf("\n|[2]Update menu item        |");
    printf("\n|[3]Delete menu item        |");
    printf("\n|[4]Create customer account |");
    printf("\n|[5]Seacrh customer order   |");
    printf("\n|[6]Search menu item        |");
    printf("\n|[7]Exit                    |");
    printf("\n----------------------------");
    printf("\nPlease choose one function:");
    scanf("%d", &staffFunc);
    switch (staffFunc)
    {
    case 1:
        system("cls");
        staffadd();
        back();
        break;
    case 2:
        system("cls");
        staffupdate();
        break;
    case 3:
        system("cls");
        staffdelete();
        break;
    case 4:
        system("cls");
        staffcreate();
        break;
    case 5:
        system("cls");
        staffsearchorder();
        break;
    case 6:
        system("cls");
        staffsearchitem();
        break;
    case 7: 
        system("cls");
        main();
        break;
    default:
        printf("\nInvalid operator.Please try again.");
        Sleep(1000);
        system("Pause");
        staffMenu();
        break;
    }
}

void back()        //back to main page or last page
{
    int l;
    printf("\n\t1.Back to main");
    printf("\n\t2.Back to last");
    printf("\n\t=========================");
    printf("\n\tEnter choice: ");
    scanf("%d", &l);
    switch (l) {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        staffMenu();
        break;
    default:
        printf("\tWrong input!Please try again.\n");
        Sleep(1000);
        back();
        break;
    }
}

void staffadd() //staff add new item into menu
{
    int i;
    readmenu();
    struct menu or [100];
    FILE* fp;
    fp = fopen("staffadd.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
    }
    int number;
    int j = 0;
    int k;
    int z = 0;
    system("cls");
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\tADD NEW MENU ITEM WITH RELATED DETAILS");
    printf("\n----------------------------------------------------------------------");
    printf("\n\nCategory:");
    printf("\n--------------------------------");
    printf("\n|[1]Hot drinks                  |");
    printf("\n|[2]Cold drinks                 |");
    printf("\n|[3]Sandwiches                  |");
    printf("\n|[4]Cakes                       |");
    printf("\n|[5]Pastries                    |");
    printf("\n|[6]Snacks                      |");
    printf("\n--------------------------------");
    printf("\nEnter total number of item to be updated: ");
    scanf("%d", &number);
    if (number > 0) {
        //loop the number to add
        for (i = 0;i < number;i++)
        {         
            printf("\nItem Number %d:\n", i + 1);
            printf("\tItem Category    : ");
            scanf("%d", &or [i].category);
            here:
            printf("\tItem Code(eg.A01): ");
            scanf("%s", or [i].code);
            //check item code exist or not
            for (j = 0;j < 100;j++)
            {
                if (strcmp(or [i].code, or1[j].code) == 0)
                {
                    //if exist, let the user to enter again
                    printf("\n\t[Item exist.Please enter again.]\n\n");
                    goto here;
                }
            }
            printf("\tItem Name        : ");
            scanf("%s", or [i].name);
            printf("\tItem Price       : ");
            scanf("%f", &or [i].price);
            fprintf(fp, "\t%d\t%s\t%s\t\t%.2f\n", or [i].category, or [i].code, or [i].name, or [i].price);
            printf("\n==========Item updated successfully!==========\n");           
        }
        fclose(fp);
        back();
    }
    else {
        printf("\tError!\n");
        Sleep(1000);
        system("cls");
        staffadd();
    }
}

void print_table()
{
    printf("\n    Category    Code    Name            Price\n");
    printf("    -------------------------------------------------\n");
}

void show() //show the whole content in staffadd.txt
{
    FILE* ptr;
    char ch;
    print_table();
    ptr = fopen("staffadd.txt", "r");

    if (NULL == ptr) {
        printf("Error Opening File.\n");
    }
    do {
        ch = fgetc(ptr);
        printf("%c", ch);
    } while (ch != EOF);

    fclose(ptr);
    return 0;
}

void staffdelete() //staff delete item code details
{
    system("cls");
    int count = 100;
    char codedel[10];
    int a, v;
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\t\tDELETE MENU ITEM");
    printf("\n----------------------------------------------------------------------");
    printf("\nBelow is the menu:\n");
    show();
    here:
    printf("\n\tEnter code of item to delete:");
    scanf("%s", codedel);
    int i, j;
    for (i = 0;i < count; i++)
    {
        if (strcmp(or [i].code, codedel)==0)
        {
            printf("\n\tBelow are the information of item code %s:\n", codedel);
            print_table();
            printf("\t%d\t%s\t%s\t\t%.2f\n", or [i].category, or [i].code, or [i].name, or [i].price);
            here1:
            printf("\n\tDo you want to delete item?");
            printf("\n\t1.Confirm");
            printf("\n\t2.Cancel");
            printf("\n\t=========================");
            printf("\n\tEnter choice:");
            scanf("%d", &a);
            if (a == 1)
            {
                //loop to skip the line that want to delete
                for (j = i;j < count - 1;j++)
                {
                    or [j] = or [j + 1];
                }
                printf("\n\t=================[Deleted Successfully!]=================\n");
                count--;
                save(); 
                break;
            }
            else if (a == 2)
            {
                printf("\n\t\t     Item is not deleted!");
                printf("\n\t\tDirecting back to staff menu...");
                Sleep(1500);
                system("cls");
                staffMenu();
            }
            else
            {
                printf("\n\t\tInvalid operator. Please try again.");
                goto here1;
            }
        }
    }
    //if item not exist
    if (i == count)
    {
        printf("\n\t\t[Item not exist!]");
        printf("\n\t\tPlease try again.\n");
        Sleep(1000);
        system("cls");
        goto here;
    }
    printf("\n\tDo you want to continue?");
    printf("\n\t[1] Continue \n\t[2] Back\n");
    printf("\tEnter choice:");
    scanf("%d", &v);
    if (v == 1)
    {
        system("cls");
        staffdelete();
    }
    else
    {
        system("cls");
        staffMenu();
    }
}

void save() //save into staffadd.txt file
{
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("staffadd.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);
    FILE* fp1;
    int i = 0;
    int ret = 0;
    fp1 = fopen("staffadd.txt", "w");
    if (fp1 == NULL)
    {
        printf("\n\tError opening file\n");
    }
    for (i = 0; i < count; i++)
    {
        ret = fprintf(fp1, "\t%d\t%s\t%s\t\t%.2f\n", or [i].category, or [i].code, or [i].name, or [i].price);
    }
    if (ret < 0)
    {
        printf("\n\tError\n");
    }
    else
    {
        printf("\n\t===============Data updated successfully in txt file!===============\n");
    }
    fclose(fp1);
}

void staffupdate() //update item details
{
    system("cls");
    printf("\n----------------------------------------------------------------------");
    printf("\n                            UPDATE MENU ITEM");
    printf("\n----------------------------------------------------------------------");
    printf("\nBelow is the menu:\n");
    show();
    int count = 100;
    char name2[20];
    float price2;
    char codeupd[10];
    int category2=0, b=0, i = 0;
    here:
    printf("\n\tEnter item code to be updated:");
    scanf("%s", codeupd);
    for (int i = 0;i < count;i++)
    {
        //check item exist
        if (strcmp(or [i].code ,codeupd)==0)
        {
            printf("\nBelow are the information of item code %s:\n", codeupd);
            print_table();
            printf("\t%d\t%s\t%s\t\t%.2f\n", or [i].category, or [i].code, or [i].name, or [i].price);
            printf("\n\tPlease enter information to be updated and remain the old information if do not wish to update.\n");
            printf("\n\t***Item code is not available to be modified***");
            printf("\n\tItem Category :");
            scanf("%d", &category2);
            printf("\tItem Name     :");
            scanf("%s", name2);
            printf("\tItem Price(RM):");
            scanf("%f", &price2);
            here1:
            printf("\n\tDo you want to update item details?");
            printf("\n\t[1] Confirm");
            printf("\n\t[2] Cancel");
            printf("\n\t=========================");
            printf("\n\tEnter choice:");
            scanf("%d", &b);
            if (b == 1)
            {
                strcpy(or [i].name, name2);
                or [i].category = category2;
                or [i].price = price2;
                printf("\n\tHere are the details updated:\n");
                print_table();
                printf("\t%d\t%s\t%s\t\t%.2f\n", or [i].category, or [i].code, or [i].name, or [i].price);
                save();
                printf("\n\tDo you want to continue to update item?(y/n)");
                getchar();
                if (getchar() == 'y')
                {
                    system("cls");
                    staffupdate();
                }
                else {
                    back();
                }
            }
            else if (b == 2) {
                printf("\n\t     Update cancelled.");
                printf("\n\tDirecting back to staff menu...");
                Sleep(1000);
                system("cls");
                staffMenu();
            }
            else{
                printf("\n\n\t---Invalid input.Please try again!---\n");
                goto here1;
            }
        }
    }
    if (strcmp(or [i].code, codeupd) != 0)
    {
        printf("\n\tItem not exist.Please try again after 1 second\n");
        Sleep(1000);
        goto here;
    }
}

void readcusorder() { //read customer order from customerorder.txt into struct
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("customerorder.txt", "r");
    if (fp == NULL)
    {
        printf("Error file opening");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);

    FILE* fp1;
    int l = 0;
    fp1 = fopen("customerorder.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error opening file\n");
    }
    else {
        for (l = 0;l < count;l++)
        {
            fscanf(fp1, "%d\t%s\t%s\t%s\t%s\t%d\t%f\t%s\t%d\t%02d\t%02d\t%02d\t%02d\t%02d\n", &ord[l].ordercode, ord[l].cusid, ord[l].cusname, ord[l].itemid, ord[l].itemname, &ord[l].quantity, &ord[l].price, ord[l].paymentmethod, &ord[l].year, &ord[l].month, &ord[l].day, &ord[l].hour, &ord[l].min, &ord[l].sec);
        }
    }
    fclose(fp1);
}

void staffsearchorder() //search customer order based on their customer ids
{
    int l = 0;
    readcusorder(); 
    int count = 100;
    char c;
    char cusid1[10];
    int ordercode1=0;
    int password = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n                       SEARCH CUSTOMER ORDER");
    printf("\n----------------------------------------------------------------------");
    printf("\nOrder ID:");
    scanf("%d",&ordercode1);
    printf("\nCustomer ID:");
    scanf("%s", cusid1);
    //looping
    while (l < count)
    {
        if (strcmp(ord[l].cusid, cusid1) == 0 && ord[l].ordercode == ordercode1)
        {
            printf("\nBelow are the order details:\n");
            printf("\n\tOrder Code     : %d", ord[l].ordercode);
            printf("\n\tCustomer ID    : %s", ord[l].cusid);
            printf("\n\tCustomer Name  : %s", ord[l].cusname);
            printf("\n\tItem ID        : %s", ord[l].itemid);
            printf("\n\tItem Name      : %s", ord[l].itemname);
            printf("\n\tQuantity       : %d", ord[l].quantity);
            printf("\n\tTotal Price    : RM%.2f", ord[l].price);
            printf("\n\tPayment Method : %s", ord[l].paymentmethod);
            printf("\n\tDate           : %d-%02d-%02d", ord[l].year, ord[l].month, ord[l].day);
            printf("\n\tTime           : %02d:%02d:%02d", ord[l].hour, ord[l].min, ord[l].sec);
            printf("\n\n\tDo you want to continue searching(y/n)?:");
            getchar();
            if (getchar() == 'y')
            {
                printf("\n\tDirecting back to search order page.");
                Sleep(3000);
                system("cls");
                staffsearchorder();
            }
            else {
                printf("\n\tDirecting back to staff menu.");
                Sleep(3000);
                system("cls");
                staffMenu();
            }
        }
        else {
            l++;
        }

        if (strcmp(ord[l].cusid, cusid1) != 0 && ord[l].ordercode != ordercode1)
        {
            printf("\nIncorrect customer id or order code.Please try again");
            Sleep(1000);
            system("cls");
            staffsearchorder();
        }
    }
}

void staffsearchitem() //search menu item
{
    int l;
    printf("\tSearch By:\t\n");
    printf("\t   1.Code \t\n");
    printf("\t   2.Name \t\n");
    printf("\t   3.Back  \n");
    printf("\t   4.Exit  \n");
    printf("\t=================================\n");
    printf("\tEnter choice: ");
    scanf("%d", &l);
    switch (l) {
    case 1:
        system("cls");
        staffsearchcode();
        backsearch();
        break;
    case 2:
        system("cls");
        staffsearchname();
        backsearch();
        break;
    case 3:
        system("cls");
        staffMenu();
        break;
    case 4:
        printf("Goodbye！\n");
        exit(0);
    default:
        printf("Wrong input.Please try again.\n");
        Sleep(500);
        system("cls");
        staffsearchitem();
        break;
    }
}

void staffsearchcode() //search menu item by item code
{
    int count = 100;
    char code3[10];
    int i;
    printf("\n----------------------------------------------------------------------");
    printf("\n                       SEARCH MENU ITEM BY CODE");
    printf("\n----------------------------------------------------------------------");
    printf("\nEnter item code:");
    scanf("%s", code3);
    for (i = 0;i < count;i++)
    {
        if (strcmp(or [i].code , code3)==0)
        {
            printf("\n\tBelow are the item details:");
            printf("\n\t================================");
            printf("\n\tItem Category  : %d", or [i].category);
            printf("\n\tItem Code      : %s", or [i].code);
            printf("\n\tItem Name      : %s", or [i].name);
            printf("\n\tItem Price(RM) : %.2f", or [i].price);
            break;
        }
    }
    if (i == count)
    {
        printf("\n\tItem code does not exist.\n");
    }
    printf("\n\n\tDo you want to continue searching(y/n)?:");
    getchar();
    if (getchar() == 'y')
    {
        Sleep(500);
        system("cls");
        staffsearchcode();
    }
    else {
        printf("\n\t----Directing back to staff menu-----");
        Sleep(2000);
        system("cls");
        staffMenu();
    }
}

void staffsearchname() //search menu item by item name
{
    int count = 100;
    int i;
    char name1[20];
    printf("\n----------------------------------------------------------------------");
    printf("\n                       SEARCH MENU ITEM BY NAME");
    printf("\n----------------------------------------------------------------------");
    printf("\nEnter item name:");
    scanf("%s", name1);
    for (i = 0;i < count;i++)
    {
        if (strcmp(or [i].name, name1) == 0)
        {
            printf("\n\tBelow are the item details:");
            printf("\n\t============================");
            printf("\n\tItem Category : %d", or [i].category);
            printf("\n\tItem Code     : %s", or [i].code);
            printf("\n\tItem Name     : %s", or [i].name);
            printf("\n\tItem Price    : %.2f", or [i].price);
            break;
        }
    }
    if (i == count)
    {
        printf("\n\tItem name is not found.");
    }
    printf("\n\n\tDo you want to continue searching(y/n)?:");
    getchar();
    if (getchar() == 'y')
    {
        Sleep(500);
        system("cls");
        staffsearchname();
    }
    else {
        printf("\n\t-----Directing back to staff menu-----");
        Sleep(2000);
        system("cls");
        staffMenu();
    }
}

void backsearch() //back to main menu,staff menu or last page
{
    int l;
    printf("\n\t1.Back to main");
    printf("\n\t2.Back to staff menu");
    printf("\n\t3.Back to last");
    printf("\n\t=========================");
    printf("\n\tEnter choice: ");
    scanf("%d", &l);
    switch (l) {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        staffMenu();
        break;
    case 3:
        system("cls");
        staffsearchitem();
        break;
    default:
        printf("\n\tInvalid input.Please input again after 3 seconds.\n");
        Sleep(3000);
        backsearch();
        break;
    }
}

void staffcreate()  //staff create new customer account
{
    readcus1();
    FILE* fp;
    fp = fopen("customerdetails.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.");
        exit;
    }
    system("cls");
    struct account acc[100];
    int confirmpw = 0;
    int i = 0,j=0,k=0;
    int count = 0;
    int num = 0;
    int choice = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\t\tCREATE CUSTOMER ACCOUNT");
    printf("\n----------------------------------------------------------------------");
    printf("\nEnter number of customer account to create:");
    scanf("%d", &num);
    if (num > 0) {
        for (int i = 0;i < num;i++) {
            printf("\nEnter customer name:");
            scanf("%s", acc[i].name);
            printf("\nEnter customer username(without blank and number,only lower case alphabet available):");
            scanf("%s", acc[i].username);
            printf("\nEnter customer contact number(eg.0123456789):");
            scanf("%d", &acc[i].contactno);
            printf("\nEnter customer email address(eg.renee@gmail.com):");
            scanf("%s", acc[i].email);
            here:
            printf("\nEnter customer ID(username+bd,eg.renee1306):");
            scanf("%s", acc[i].cusid);
            for (k = 0;k < 100;k++)
            {
                if (strcmp(acc [i].cusid, acc1[k].cusid) == 0)
                {
                    printf("\n\t[Customer ID exists.Please enter again.]\n");
                    goto here;
                }
            }
            printf("\nEnter customer password(6 digit numbers):");
            scanf("%d", &acc[i].password);
            k = acc[i].password;
            while (k != 0)
            {
                k /= 10;
                count++;
            }
            if (count != 6)
            {
                printf("\n\t[Invalid input. You are not entering 6 digits. Please try again after 1 second]\n");
                Sleep(2000);
                staffcreate();
            }
            else {
                printf("\nConfirm password:");
                scanf("%d", &confirmpw);
                if (acc[i].password != confirmpw)
                {
                    printf("\n\tThe two passwords to not match.Please choose one:");
                    printf("\n\t[1] Continue");
                    printf("\n\t[2] Exit");
                    printf("\n\tEnter choice:");
                    scanf("%d", &choice);
                    switch (choice) {
                    case 1:
                        printf("\n\tPlease try to register account again.");
                        printf("\n\t-----Directing back to try again-----");
                        Sleep(1000);
                        staffcreate();
                        break;
                    case 2:
                        printf("\n\tBack to main menu.");
                        system(1000);
                        main();
                        break;
                    default:
                        printf("\n\tInvalid operator.Please try again.");
                        break;
                    }
                }
                else {
                    printf("\n\n--------------Account created successfully--------------");
                    printf("\n\nHere are the details of customer account:\n");
                    printf("\n\tCustomer ID   :%s", acc[i].cusid);
                    printf("\n\tName          :%s", acc[i].name);
                    printf("\n\tUsername      :%s", acc[i].username);
                    printf("\n\tContact Number:%d", acc[i].contactno);
                    printf("\n\tEmail Address :%s", acc[i].email);
                    printf("\n\tPassword      :%d", acc[i].password);
                    fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%d\n", acc[i].cusid, acc[i].name, acc[i].username, acc[i].contactno, acc[i].email, acc[i].password);
                    printf("\n\n******************Data saved successfully in file*******************");
                    printf("\n\n***Customer are required to login from registered customer portal***\n");
                    fclose(fp);
                }
            }
        } 
        back();
    }
    else {
        printf("\tInvalid input!Please try again.\n");
        system("cls");
        staffcreate();
    }
}

void newcusregister() //new customer register their account
{
    readcus1();
    FILE* fp;
    fp = fopen("customerdetails.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.");
        exit;
    }
    system("cls");
    struct account acc[100];
    int confirmpw = 0;
    int num = 1;
    int j = 0;
    int i = 0;
    int k = 0;
    int count = 0;
    int choice = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n                   FIRST TIME CUSTOMER REGISTER ACCOUNT");
    printf("\n----------------------------------------------------------------------");
    printf("\nYou are required to register a new account.\n");
    if (num > 0) {
        for (i = 0;i < num;i++)
        {
            printf("\nEnter your name:");
            scanf("%s", acc[i].name);
            printf("\nEnter your username(without blank and number,only lower case alphabet available):");
            scanf("%s", acc[i].username);
            printf("\nEnter your contact number(eg.0123456789):");
            scanf("%d", &acc[i].contactno);
            printf("\nEnter your email address(eg.renee@gmail.com):");
            scanf("%s", acc[i].email);
            here:
            printf("\nEnter your customer ID(username+bd,eg.renee1306):");
            scanf("%s", acc[i].cusid);
            for (k = 0;k < 100;k++)
            {
                if (strcmp(acc[i].cusid, acc1[k].cusid) == 0)
                {
                    printf("\n\t[Customer ID exist.Please enter again.]\n");
                    goto here;
                }
            }
            printf("\nEnter your password(6 digit numbers):");
            scanf("%d", &acc[i].password);
            j = acc[i].password;
            while (j != 0)
            {
                j /= 10;
                count++;
            }
            if (count != 6)
            {
                printf("\nInvalid input. You are not entering 6 digits. Please try again after 1 second.");
                Sleep(1000);
                newcusregister();
            }
            else {
                printf("\nConfirm password:");
                scanf("%d", &confirmpw);
                if (acc[i].password != confirmpw)
                {
                    printf("\n\tThe two passwords to not match.Please choose one:");
                    printf("\n\t[1] Continue");
                    printf("\n\t[2] Exit");
                    printf("\n\tEnter choice:");
                    scanf("%d", &choice);
                    switch (choice) {
                    case 1:
                        printf("\n\tPlease try to register account again.");
                        printf("\n\t-----Directing back to try again-----");
                        newcusregister();
                        break;
                    case 2:
                        printf("\n\tBack to main menu.");
                        system(500);
                        main();
                        break;
                    default:
                        printf("\n\tInvalid operator.Please try again.");
                        break;
                    }
                }
                else {
                    printf("\n\n--------------Account created successfully--------------");
                    printf("\n\nHere are the details of your account:");
                    printf("\n\tCustomer ID   :%s", acc[i].cusid);
                    printf("\n\tName          :%s", acc[i].name);
                    printf("\n\tUsername      :%s", acc[i].username);
                    printf("\n\tContact Number:%d", acc[i].contactno);
                    printf("\n\tEmail Address :%s", acc[i].email);
                    printf("\n\tPassword      :%d", acc[i].password);
                    fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%d\n", acc[i].cusid, acc[i].name, acc[i].username, acc[i].contactno, acc[i].email, acc[i].password);
                    printf("\n\n****************[Data saved successfully in file]****************");
                    printf("\n\n****You are required to login from registered customer portal****\n");
                    fclose(fp);
                    int l;
                    printf("\n\tPlease choose one:");
                    printf("\n\t[1] Back");
                    printf("\n\t[2] Exit Program");
                    printf("\n\t=========================");
                    printf("\n\tEnter choice: ");
                    scanf("%d", &l);
                    switch (l) {
                    case 1:
                        system("cls");
                        main();
                        break;
                    case 2:
                        system("cls");
                        exit(1);
                        break;
                    default:
                        printf("\tWrong input!Please try again.\n");
                        back();
                        break;
                    }
                }
            }
        }
    }
}

void registercuslogin() //registered customer login with customer id and password
{
    int count = 100;
    readcus();
    char cusid1[10];
    int password = 0;
    int i = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\t\tREGISTERED CUSTOMER LOGIN");
    printf("\n----------------------------------------------------------------------");
    printf("\nCustomer ID      :");
    scanf("%s", cusid1);
    printf("\nCustomer Password:");
    scanf("%d", &password);
    while (i < count)
    {
        if (strcmp(acc[i].cusid, cusid1) == 0 && acc[i].password == password)
        {
            printf("\nWelcome!Login Success!\n");
            Sleep(1000);
            system("cls");
            registeredcusMenu();
        }
        else {
            i++;
        }
    }
    while (i==count)
    {
        printf("\nIncorrect username or password.Please try again");
        Sleep(1000);
        system("cls");
        registercuslogin();
        }
}

void registeredcusMenu() //registered customer menu
{
    system("cls");
    int registeredcusFunc = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\t\tREGISTERED CUSTOMER PORTAL");
    printf("\n----------------------------------------------------------------------");
    printf("\nThere are five functions:");
    printf("\n----------------------------------");
    printf("\n|[1] Modify your details         |");
    printf("\n|[2] Place order and make payment|");
    printf("\n|[3] Cancel order placed         |");
    printf("\n|[4] Show receipt                |");
    printf("\n|[5] Exit                        |");
    printf("\n----------------------------------");
    printf("\nPlease choose one function:");
    scanf("%d", &registeredcusFunc);
    switch (registeredcusFunc)
    {
    case 1:
        system("cls");
        registeredmodify();
        break;
    case 2:
        system("cls");
        registeredorder();
        break;
    case 3:
        system("cls");
        registeredcancel();
        break;
    case 4:
        system("cls");
        registeredreceipt();
        break;
    case 5:
        system("cls");
        main();
        break;
    default:
        printf("Invalid operator.Please try again.");
        system("Pause");
        break;
    }
}

void readcus() //read customer details from customerdetails.txt file into struct
{
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("customerdetails.txt", "r");
    if (fp == NULL)
    {
        printf("\nError opening file.");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);

    FILE* fp1;
    int i = 0;
    fp1 = fopen("customerdetails.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error opening file\n");
    }
    else {
        for (i = 0;i < count;i++)
        {
            fscanf(fp1, "%s\t%s\t%s\t%d\t%s\t%d\n", acc[i].cusid, acc[i].name, acc[i].username, &acc[i].contactno, acc[i].email, &acc[i].password);
        }
    }
    fclose(fp1);
}

void readcus1() { //read customer details from customerdetails.txt file into struct
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("customerdetails.txt", "r");
    if (fp == NULL)
    {
        printf("\nError opening file.");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);

    FILE* fp1;
    int i = 0;
    fp1 = fopen("customerdetails.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error opening file\n");
    }
    else {
        for (i = 0;i < count;i++)
        {
            fscanf(fp1, "%s\t%s\t%s\t%d\t%s\t%d\n", acc1[i].cusid, acc1[i].name, acc1[i].username, &acc1[i].contactno, acc1[i].email, &acc1[i].password);
        }
    }
    fclose(fp1);
}

void save1() //save customer details updated
{
    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("customerdetails.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);
    FILE* fp2;
    int i = 0;
    int ret = 0;
    fp2 = fopen("customerdetails.txt", "w");
    if (fp2 == NULL)
    {
        printf("\n\tError opening file\n");
    }
    for (i = 0; i < count; i++)
    {
        ret = fprintf(fp, "%s\t%s\t%s\t%d\t%s\t%d\n", acc[i].cusid, acc[i].name, acc[i].username, acc[i].contactno, acc[i].email, acc[i].password);
    }
    if (ret < 0)
    {
        printf("\n\tError\n");
    }
    else
    {
        printf("\n\t[Data updated successfully in txt file!]\n");
    }
    fclose(fp2);
}

void registeredmodify() //registered customer modify their details
{
    char user[20];
    int count = 100;
    char cusid1[20];
    char username1[20];
    char name1[20];
    int contactno1;
    char email1[20];
    int password1;
    int b = 0;
    int i;
    printf("\n----------------------------------------------------------------------");
    printf("\n                     MODIFY ACCOUNT DETAILS");
    printf("\n----------------------------------------------------------------------");
    here:
    printf("\nEnter your Customer ID:");
    scanf("%s", user);
    for (i = 0;i < count;i++)
    {
        if (strcmp(acc [i].cusid,user)==0)
        {
            printf("\n\t             Below are the information of your account");
            printf("\n\t=====================================================================");
            printf("\n\tCustomer ID       : %s", acc[i].cusid);
            printf("\n\tCustomer Name     : %s", acc[i].name);
            printf("\n\tCustomer Username : %s", acc[i].username);
            printf("\n\tContact Number    : %d", acc[i].contactno);
            printf("\n\tCustomer Email    : %s", acc[i].email);
            printf("\n\tCustomer Password : %d", acc[i].password);
            printf("\n\n\tPlease enter information to be modified and remain the old information if do not wish to update.\n");
            printf("\n\tCustomer ID cannot be modified.");
            printf("\n\tUsername      :");
            scanf("%s",username1);
            printf("\tName          :");
            scanf("%s", name1);
            printf("\tContact Number:");
            scanf("%d", &contactno1);
            printf("\tEmail         :");
            scanf("%s", email1);
            printf("\tPassword      :");
            scanf("%d", &password1);
            here1:
            printf("\n\tDo you want to update your details?");
            printf("\n\t[1] Confirm");
            printf("\n\t[2] Cancel");
            printf("\n\t=========================");
            printf("\n\tEnter choice:");
            scanf("%d", &b);
            if (b == 1)
            {
                strcpy(acc [i].username , username1);
                strcpy(acc[i].name , name1);
                acc [i].contactno = contactno1;
                acc[i].password = password1;
                strcpy(acc[i].email, email1);
                printf("\n           Here are the details updated:");
                printf("\n\t=================================================");
                printf("\n\tCustomer ID       : %s", acc[i].cusid);
                printf("\n\tCustomer Name     : %s", acc[i].name);
                printf("\n\tCustomer Username : %s", acc[i].username);
                printf("\n\tContact Number    : %d", acc[i].contactno);
                printf("\n\tCustomer Email    : %s", acc[i].email);
                printf("\n\tCustomer Password : %d\n", acc[i].password);
                save1();
                back1();
            }
            else if (b == 2) {
                printf("\n\t            Modified cancelled.              ");
                printf("\n\tDirecting back to registered customer menu...");
                Sleep(1000);
                system("cls");
                registeredcusMenu();
            }
            else {
                printf("\n\n\t---Invalid input.Please try again!---\n");
                goto here1;
            }
        }
    }
    if (i == count)
    {
        printf("\n     [Customer ID do not exist.]\n");
        printf("\n         Please enter again.");
        Sleep(2000);
        system("cls");
        goto here;
    }
}

void back1() //back to main page or last page
{
    int l;
    printf("\n\t1.Back to main");
    printf("\n\t2.Back to last");
    printf("\n\t=========================");
    printf("\n\tEnter choice: ");
    scanf("%d", &l);
    switch (l) {
    case 1:
        system("cls");
        main();
        break;
    case 2:
        system("cls");
        registeredcusMenu();
        break;
    default:
        printf("\tInvalid operator.Please try again after 1 second.\n");
        Sleep(1000);
        back();
        break;
    }
}

void registeredorder() //registered customer place order
{
    read();
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int i = 0, j = 0, k = 0,l=0;
    int num = 0;
    int choice = 0,choice1=0;
    char cusid1[10];
    int count = 100;
    char itemcode[20];
    float totprice;
    struct order ord[100];
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\tPLACE ORDER AND MAKE PAYMENT");
    printf("\n----------------------------------------------------------------------");
    here2:
    printf("\nEnter your customer id:");
    scanf("%s", cusid1);
    for (i = 0;i < count;i++)
    {
        if (strcmp(cusid1, acc[i].cusid) == 0)
        {
            printf("\n\t%s, Welcome!\n", acc[i].name);
            printf("\n\tBelow is the menu:\n");
            show();
            here3:
            printf("\n\t\tEnter item code:");
            scanf("%s", itemcode);
            system("cls");
            for (k = 0;k < count;k++)
            {
                if (strcmp(itemcode, or [k].code) == 0)
                {
                    printf("\n\tHere are the details of item:");
                    printf("\n\t================================");
                    printf("\n\tItem Code : %s", or [k].code);
                    printf("\n\tItem Price: RM%.2f", or [k].price);
                    printf("\n\tItem Name : %s", or [k].name);
                    printf("\n\n\tEnter quantity:");
                    scanf("%d", &ord[l].quantity);
                    ord[l].price = or [k].price * ord[l].quantity;
                    printf("\n\t*********************************");
                    printf("\n\tTotal Price : RM%.2f", ord[l].price);
                    printf("\n\t*********************************\n");
                    here:
                    printf("\n\tDo you want to place order?");
                    printf("\n\t[1] Yes");
                    printf("\n\t[2] No");
                    printf("\n\t-----------------------------");
                    printf("\n\tEnter choice:");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                    here1:
                        printf("\n\t**********************************");
                        printf("\n\t*Please select payment method:   *");
                        printf("\n\t*[1] Cash                        *");
                        printf("\n\t*[2] Ewallet                     *");
                        printf("\n\t*[3] Credit cards                *");
                        printf("\n\t*[4] Online Banking              *");
                        printf("\n\t**********************************");
                        printf("\n\tEnter choice:");
                        scanf("%d", &choice1);
                        switch (choice1) {
                        case 1:
                            strcpy(ord[l].paymentmethod, "Cash");
                            break;
                        case 2:
                            strcpy(ord[l].paymentmethod,"Ewallet");
                            break;
                        case 3:
                            strcpy(ord[l].paymentmethod,"CreditCard");
                            break;
                        case 4:
                            strcpy(ord[l].paymentmethod,"OnlineBanking");
                            break;
                        default:
                            printf("\n\tInvalid input.Please try again");
                            goto here1;
                            break;
                        }
                        FILE* fp;
                        int count = 0;
                        char c;
                        fp = fopen("customerorder.txt", "r");
                        if (fp == NULL)
                        {
                            printf("\nError opening file.");
                            return 0;
                        }
                        for (c = getc(fp); c != EOF; c = getc(fp)) {
                            if (c == '\n')
                            {
                                count = count + 1;
                            }
                        }
                        fclose(fp);

                        ord[i].ordercode = count + 1;
                        printf("\n[Done payment by Customer Name:%s , Customer ID :%s]", acc[i].name, acc[i].cusid);
                        printf("\nOrder Date: %d-%02d-%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
                        printf("\nOrder Time: %02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
                        printf("\n***Your order code is #%d***\n", ord[l].ordercode);
                        printf("\n---------------Thanks for visiting Dosta Coffee Shop---------------");
                        printf("\n-----------------------Hope to see you again!-----------------------");
                        strcpy(ord[l].cusid, cusid1);
                        strcpy(ord[l].cusname, acc[i].name);
                        strcpy(ord[l].itemid, or [k].code);
                        strcpy(ord[l].itemname, or [k].name);
                        ord[l].year = tm.tm_year + 1900;
                        ord[l].month = tm.tm_mon + 1;
                        ord[l].day = tm.tm_mday;
                        ord[l].hour = tm.tm_hour;
                        ord[l].min = tm.tm_min;
                        ord[l].sec = tm.tm_sec;
                        FILE* fp1;
                        int l = 0;
                        fp1 = fopen("customerorder.txt", "a");
                        if (fp1 == NULL)
                        {
                            printf("\n\tError opening file\n");
                        }
                        else
                        {
                            fprintf(fp1, "%d\t%s\t%s\t%s\t%s\t%d\t%.2f\t%s\t%d\t%02d\t%02d\t%02d\t%02d\t%02d\n", ord[l].ordercode, ord[l].cusid, ord[l].cusname, ord[l].itemid, ord[l].itemname, ord[l].quantity, ord[l].price, ord[l].paymentmethod, ord[l].year,ord[l].month, ord[l].day, ord[l].hour, ord[l].min, ord[l].sec);
                            printf("\n\n\t\t[Data updated successfully in txt file!]\n");
                        }
                        fclose(fp1);
                        printf("\n\tDo you want to continue ordering(y/n)?:");
                        getchar();
                        if (getchar() == 'y')
                        {
                            printf("\n\tDirecting back to order page.");
                            Sleep(3000);
                            system("cls");
                            registeredorder();
                                                       
                        }
                        else {
                            printf("\n\tDirecting back to registered customer menu.");
                            Sleep(2000);
                            system("cls");
                            registeredcusMenu();                         
                        }
                    case 2:
                        printf("\n\n[Ordered cancelled]");
                        printf("\n\nDirecting back to registered customer main menu...");
                        Sleep(3000);
                        registeredcusMenu();
                        break;
                    default:
                        printf("\nInvalid operator.Please try again.");
                        goto here;
                        break;
                    }
                }
            }
            if (k == count)
            {
                printf("\nItem Code not found !Please try again.");
                Sleep(1000);
                system("cls");
                goto here3;
            }
            }
        }
    if (i == count)
    {
        printf("\nCustomer ID not found.Please try again");
        Sleep(1000);
        system("cls");
        goto here2;
        }
}

void registeredcancel() //registered customer cancel order
{
    readcusorder();
    system("cls");
    int count = 100;
    int codedel=0;
    int a, v;
    char cusdel[10];
    printf("\n----------------------------------------------------------------------");
    printf("\n\t\t\tCANCEL ORDER PLACED");
    printf("\n----------------------------------------------------------------------");
    here:
    printf("\nEnter order code to delete:");
    scanf("%d", &codedel);
    printf("\nEnter customer id:");
    scanf("%s", cusdel);
    int i=0, j=0;
    for (i = 0;i < count; i++)
    {
        if (strcmp(ord[i].cusid, cusdel) == 0 && ord[i].ordercode == codedel)
        {
            printf("\n\tBelow are the order details:\n");
            printf("\n\tOrder Code     : %d", ord[i].ordercode);
            printf("\n\tCustomer ID    : %s", ord[i].cusid);
            printf("\n\tCustomer Name  : %s", ord[i].cusname);
            printf("\n\tItem ID        : %s", ord[i].itemid);
            printf("\n\tItem Name      : %s", ord[i].itemname);
            printf("\n\tQuantity       : %d", ord[i].quantity);
            printf("\n\tTotal Price    : RM%.2f", ord[i].price);
            printf("\n\tPayment Method : %s", ord[i].paymentmethod);
            printf("\n\tDate           : %d-%02d-%02d", ord[i].year, ord[i].month, ord[i].day);
            printf("\n\tTime           : %02d:%02d:%02d", ord[i].hour, ord[i].min, ord[i].sec);
            here1:
            printf("\n\n\tDo you want to cancel order?");
            printf("\n\t1.Confirm");
            printf("\n\t2.Cancel");
            printf("\n\t=========================");
            printf("\n\tEnter choice:");
            scanf("%d", &a);
            if (a == 1)
            {
                for (j = i;j < count - 1;j++)
                {
                    ord [j] = ord [j + 1];
                }
                printf("\n\t=======================[Canceled Successfully!]=======================\n");
                count--;
                save2();
                break;
            }
            else if (a==2)
            {
                printf("\n\tOrder is not deleted!");
                printf("\n\tDirecting back to registered customer memu.");
                registeredcusMenu();
            }
            else
            {
                printf("\n\tInvalid operator.Please enter again.");
                goto here1;
            }
        }
    }
    if (i == count)
    {
        printf("\n\tOrder id or customer id can't be found.Please try again\n");
        goto here;
    }

    printf("\n\tDo you want to continue?");
    printf("\n\t1.Continue \n\t2.Back\n");
    printf("\tEnter choice：");
    scanf("%d", &v);
    if (v == 1)
    {
        system("cls");
        registeredcancel();
    }
    else
    {
        system("cls");
        registeredcusMenu();
    }
}

void save2() //save into file after update details
{

    FILE* fp;
    int count = 0;
    char c;
    fp = fopen("customerorder.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.");
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);
    FILE* fp2;
    int i = 0;
    int ret = 0;
    fp2 = fopen("customerorder.txt", "w");
    if (fp2 == NULL)
    {
        printf("\n\tError opening file\n");
    }
    for (i = 0; i < count; i++)
    {
        ret = fprintf(fp2, "%d\t%s\t%s\t%s\t%s\t%d\t%.2f\t%s\t%d\t%02d\t%02d\t%02d\t%02d\t%02d\n", ord[i].ordercode, ord[i].cusid, ord[i].cusname, ord[i].itemid, ord[i].itemname, ord[i].quantity, ord[i].price, ord[i].paymentmethod, ord[i].year, ord[i].month, ord[i].day, ord[i].hour, ord[i].min, ord[i].sec);
    
    if (ret < 0)
    {
        printf("\n\tError\n");
    }
    else
    {
        printf("\n\t===============Data updated successfully in txt file!===============\n");
    }
    fclose(fp2);
    }
}

void registeredreceipt() //generate receipt after place order
{
    int l = 0;
    readcusorder();
    int count = 100;
    char c;
    char cusid1[10];
    int ordercode1 = 0;
    int password = 0;
    printf("\n----------------------------------------------------------------------");
    printf("\n                          SHOW RECEIPT");
    printf("\n----------------------------------------------------------------------");
    printf("\nEnter order ID:");
    scanf("%d", &ordercode1);
    printf("\nEnter customer ID:");
    scanf("%s", cusid1);
    while (l < count)
    {
        if (strcmp(ord[l].cusid, cusid1) == 0 && ord[l].ordercode == ordercode1)
        {
            printf("\t\t______________________________________________________________\n");
            printf("\t\t|                      Dosta Coffee Shop,                     |\n");
            printf("\t\t|                      No.666,Jalan Bunga,                    |\n");
            printf("\t\t|                      34567 Kuala Lumpur.                    |\n");
            printf("\t\t|  --------------------------------------------------------   |\n");
            printf("\t\t|                           RECEIPT                           |\n");
            printf("\t\t|           =======================================           |\n");
            printf("\t\t|  Order Code   : #%-10d   Date: %d-%02d-%02d              |\n", ord[l].ordercode, ord[l].year, ord[l].month, ord[l].day);
            printf("\t\t|  Customer ID  : %-10s    Time: %02d:%02d:%02d                |\n", ord[l].cusid, ord[l].hour, ord[l].min, ord[l].sec);
            printf("\t\t|  Customer Name: %-10s    Payment Method:%-10s     |\n", ord[l].cusname, ord[l].paymentmethod);
            printf("\t\t|           =======================================           |\n");
            printf("\t\t|                                                             |\n");
            printf("\t\t|  Name             Quantity              Total(RM)           |\n");
            printf("\t\t|  ---------------------------------------------------------  |\n");
            printf("\t\t|  %-10s           %-3d                  %.2f             |\n", ord[l].itemname, ord[l].quantity, ord[l].price);
            printf("\t\t|                                                             |\n");
            printf("\t\t|                                                             |\n");
            printf("\t\t|                                                             |\n");
            printf("\t\t|                                                             |\n");
            printf("\t\t|                                                             |\n");
            printf("\t\t|                                                             |\n");
            printf("\t\t|       ==========================================            |\n");
            printf("\t\t|        Sub Total                      %.2f                  |\n", ord[l].price);
            printf("\t\t|       ===========================================           |\n");
            printf("\t\t|                 Thanks for visiting us                      |\n");
            printf("\t\t|                  Hope to see you again                      |\n");
            printf("\t\t|_____________________________________________________________|\n");            
            printf("\n\t\t\tDo you want to continue to print receipt(y/n)?:");
            getchar();
            if (getchar() == 'y')
            {
                printf("\n\tDirecting back.Please try again.");
                Sleep(3000);
                system("cls");
                registeredreceipt();
            }
            else {
                printf("\n\tDirecting back to registered customer menu.");
                Sleep(3000);
                system("cls");
                registeredcusMenu();
            }
        }
        else {
            l++;
        }

    if (strcmp(ord[l].cusid, cusid1) != 0 && ord[l].ordercode != ordercode1)
        {
        printf("\nIncorrect customer id or order code.Please try again");
        Sleep(1000);
        system("cls");
        registeredreceipt();
        }
    }
}
