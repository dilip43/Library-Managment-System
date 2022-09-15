#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include"lmsp.h"
int main()
{
    gotoxy(35,10);
    textcolor(YELLOW);
    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM");
    gotoxy(25,13);
    textcolor(LIGHTGREEN);
    printf("*HAVING FUN IS NOT HARD.WHEN YOU HAVE LIBRARY CARD*");
    getch();
    textcolor(YELLOW);
    int i=0;
    addUser();
input();
addCategory();
addStudent();
clrscr();
int choice;
while(1)
{
    choice=enterchoice();
    if(choice==7)
       {
           exit(0);
       }
        switch(choice)
        {
        case 1:
            clrscr();
            book *b;
            char bchoice;
            int i;
            do
            {
                clrscr();
                i=showCategory();
                clrscr();
                b=getBookDetails();
                clrscr();
            addbooks(*b,i);
          gotoxy(25,20);
        textcolor(LIGHTGREEN);
        printf("do you want to add more books?(Y/N):");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%c",&bchoice);
    }
    while(bchoice=='Y'||bchoice=='y');
            break;
        case 2:
            clrscr();
            show_books();
            getch();
            break;
        case 3:
            clrscr();
            int ch=searchmenu();
            searchBooks(ch);
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            int c=issueMenu();
            switch(c)
            {
            case 1:
                clrscr();
                int i=issueBook();
              if(i==0)
            {

                 gotoxy(25,18);
                    printf("Booking Failed");
            }
            else
            {
                gotoxy(25,18);
                printf("booking Successful");
            }
getch();
                break;
            case 2:
                clrscr();
                show_issued_books();
                getch();
                break;

            case 3:
                clrscr();
                search_issued_books();
                getch();
                break;
            case 4:
 clrscr();
 del_issue_book();
 getch();
                break;

            //default:
              //  printf("wrong choice");
            }
            break;
        case 5:
            updateBook();
            break;
            case 6:
            delete_book();
            break;
            default:
                gotoxy(30,22);
                textcolor(LIGHTRED);
                printf("Wrong choice!Try again\n");
                getch();
                clrscr();
        }
        }


    return 0;
}
