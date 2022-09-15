#ifndef LMSWH_C_INCLUDED
#define LMSWH_C_INCLUDED
#include<stdio.h>
#include"lmsp.h"
#include<string.h>
#include "conio2.h"
void addUser()
  {

      FILE *fp=fopen("user.bin","rb");
      if(fp==NULL)
      {
          FILE *fp=fopen("user.bin","wb");
          User u={"admin","abc"};
          fwrite(&u,sizeof(User),1,fp);
          fclose(fp);
      }

  else
    {
        fclose(fp);
    }
  }
void input()
{
    clrscr();
    int i,k;
    char user_id[20];
    char pass_word[20];
    gotoxy(28,1);
    textcolor(YELLOW);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    gotoxy(1,3);
    for(i=0;i<120;i++)
    {

        printf("%c",247);
    }
gotoxy(32,5);
textcolor(LIGHTGREEN);
printf("*LOGIN PANEL*");
gotoxy(1,7);
for(i=0;i<120;i++)
    {
        printf("%c",247);
    }
gotoxy(25,11);
textcolor(LIGHTCYAN);
printf("Enter user id:");
gotoxy(25,12);
printf("Enter password");
gotoxy(1,16);
textcolor(LIGHTGREEN);
for(i=0;i<120;i++)
    {
        printf("%c",247);
    }
do{
        int p=0;
    gotoxy(39,11);
    textcolor(WHITE);
    fgets(user_id,20,stdin);
    char *pos;
    pos=strchr(user_id,'\n');
*pos='\0';
gotoxy(39,12);
for( ; ;){
    pass_word[p]=getch();
if(pass_word[p]==13)
    break;
    printf("*");
    p++;
}
      pass_word[p]='\0';
      k=isUserPresent(user_id,pass_word);

}
while(k==0);
}
int isUserPresent(char * u,char *p)
  {
      if(*(u)==0||*(p)==0){
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("BOTH FIELDS ARE MANDATORY");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t");
        gotoxy(39,11);
        printf("\t\t\t\t");
        gotoxy(39,12);
        printf("\t\t\t");
        return 0;

      }
  FILE *fp=fopen("user.bin","rb");
  User user;
  fread(&user,sizeof(User),1,fp);
  if(strcmp(u,user.userid)||strcmp(p,user.pwd)){
    gotoxy(27,20);
    textcolor(LIGHTGREEN);
    printf("INVALID USER USERNAME/PASSWORD");
    getch();
    gotoxy(27,20);
    printf("\t\t\t\t");
    gotoxy(39,11);
    printf("\t\t\t");
    gotoxy(39,12);
    printf("\t\t");
    textcolor(YELLOW);
    fclose(fp);
    return(0);
  }
  fclose(fp);
  return(1);
  }
int enterchoice()
{clrscr();
    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("Library Management System\n");
    for(i=1;i<120;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(LIGHTGREEN);
    printf("*ADMIN PANEL*");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
    gotoxy(32,9);
    textcolor(YELLOW);
    printf("1-Add Books");
    gotoxy(32,10);
    printf("2-view all books");
    gotoxy(32,11);
    printf("3-search books");
    gotoxy(32,12);
    printf("4-issue books");
    gotoxy(32,13);
    printf("5-update books");
    gotoxy(32,14);
    printf("6-delete books");
    gotoxy(32,15);
    printf("7-quit");
gotoxy(1,17);
textcolor(LIGHTGREEN);
for(i=1;i<=240;i++)
    printf("%c",176);
gotoxy(32,20);
textcolor(YELLOW);
printf("Enter choice");
textcolor(WHITE);
scanf("%d",&choice);
return choice;
}
 void addCategory()
      {

          FILE *fp=fopen("category.bin","rb");
      if(fp==NULL){
         fp=fopen("category.bin","wb");
         Category cat[6]={
             {1,"CSE"},{2,"EC"},{3,"EX"},{4,"IT"},{5,"ME"},{6,"CIVIL"}
    };
    fwrite(cat,6*sizeof(Category),1,fp);
    fclose(fp);
}
else{
    //printf("ExIst");
    //getch();
    fclose(fp);
}}
int showCategory()
{
    int cat;
    clrscr();
    int i;
    gotoxy(34,2);
    textcolor(YELLOW);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<120;i++)
    {
        gotoxy(i,3);
        printf("%c",247);
    }
    textcolor(YELLOW);
    gotoxy(35,5);
    printf("* Categories *");
    textcolor(LIGHTGREEN);
    for(i=1;i<=240;i++)
    {
        gotoxy(i,6);
        printf("%c",176);
    }
    textcolor(15);
    gotoxy(40,9);
    printf("1. CSE");
    gotoxy(40,10);
    printf("2. EC");
    gotoxy(40,11);
    printf("3. EX");
    gotoxy(40,12);
    printf("4. IT");
    gotoxy(40,13);
    printf("5. ME");
    gotoxy(40,14);
    printf("6. CIVIL");
    textcolor(LIGHTGREEN);
    for(i=1;i<=240;i++)
    {
        gotoxy(i,16);
        printf("%c",176);
    }
    textcolor(14);
    gotoxy (38,19);
    printf("Select category:-");
    textcolor(WHITE);
    while(1)
    {
    scanf("%d",&cat);
    gotoxy(38,22);
   if(cat<1||cat>6)
{
    printf("Wrong Choice");
    gotoxy(55,19);
    printf("\t\t\t");
    gotoxy(55,19);
}
else
    break;}
    return cat;
}
int getBookId()
{
book b;
    int count=100;
    FILE *fp=fopen("book.bin","rb");
    if(fp==NULL)
    {
        return(count+1);
    }
    //fseek(fp,0L,SEEK_END);
    //int t=ftell(fp)/sizeof(book);
    //fclose(fp);
    //count=count+(++t);
    //return count;
    int max=0;
    while(fread(&b,sizeof(book),1,fp)==1)
    {

        if(max<b.bookId)
            max=b.bookId;
    }
    //fseek(fp,-1L*sizeof(book),SEEK_END);
    //int bid;
    //fread(&bid,sizeof(bid),1,fp);

    fclose(fp);
    return(max+1);
}
book* getBookDetails()
{
    static book b;
   int i;
   textcolor(YELLOW);
   gotoxy(28,1);
   printf("LIBRARY MANAGEMENT SYSTEM\n");
   for(i=0;i<120;i++)
    printf("%c", 247);
   gotoxy(29,5);
   textcolor(LIGHTGREEN);
   printf("*ADD BOOK PANEL*");
   gotoxy(1,6);
   for(i=1;i<=240;i++)
    printf("%c",176);
    gotoxy(1,15);
    for(i=1;i<=240;i++)
        printf("%c",176);
    textcolor(YELLOW);
    int id_b=getBookId();// generate book id
    b.bookId=id_b;
    gotoxy(10,9);
    char *pos;
    int valid;
    printf("Book Id:-");
    textcolor(WHITE);
    printf("%d",b.bookId);
    gotoxy(10,10);
    textcolor(YELLOW);
    printf("Enter Book Name:-");
    textcolor(WHITE);
    do
    {
        valid=1;
        fflush(stdin);
        fgets(b.bookName,50,stdin);
        pos=strchr(b.bookName,'\n'); // searchs a goven character in the string
        *pos='\0';
        if(strlen(b.bookName)==0)
        {
            valid=0;
            gotoxy(26,22);
            textcolor(LIGHTRED);
            printf("BOOK NAME IS MANDATORY");
            getch();
            gotoxy(26,22);
            textcolor(WHITE);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(26,9);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(26,9);
        }
    }while(valid==0);
    gotoxy(10,11);
    textcolor(YELLOW);
    printf("Enter Book Author:-");
    do
    {
        textcolor(WHITE);
        valid=1;
        fflush(stdin);
        fgets(b.authorName,50,stdin);
        pos=strchr(b.authorName,'\n');
        *pos='\0';
        int i=0;
        if(strlen(b.authorName)==0)
        {
            valid=0;
            gotoxy(26,22);
            textcolor(LIGHTRED);
            printf("AUTHOR NAME is mandatory");
            getch();
            gotoxy(26,22);
            printf("\t\t\t\t\t\t");
            gotoxy(28,11);
        }
        while(i<strlen(b.authorName))
        {
            if(!(isalpha(b.authorName[i]))) //check whether string contains alphabets
            {
                valid=0;
                gotoxy(26,22);
                textcolor(LIGHTRED);
                printf("Author name contains only alphabets");
                getch();
                gotoxy(26,22);
                printf("\t\t\t\t\t\t");
                gotoxy(28,11);
                printf("\t\t\t\t\t\t\t");
                gotoxy(28,11);
                break;
            }i++;
        }
    }while(valid==0);
    gotoxy(10,13);
    textcolor(YELLOW);
    printf("Enter book Quantity");
    do
    {
        textcolor(WHITE);
        valid=1;
        fflush(stdin);
        int check=scanf("%d",&b.quantity);
        if(check==0 || b.quantity<=0)
        {
            valid=0;
            gotoxy(30,22);
            textcolor(LIGHTRED);
            printf("QUANTITY SHOULD BE VALID");
            getch();
            gotoxy(25,22);
            printf("\t\t\t\t\t\t\t");
            gotoxy(30,13);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(30,13);
        }
        }while(valid==0);
        return (&b);

}
void addbooks(book b,int i)
{b.categoryId=i;
    FILE *fp;
    fp=fopen("book.bin","ab");
    fwrite(&b,sizeof(book),1,fp);
    fclose(fp);

}
void show_books()
{int i;
    gotoxy(40,1);
    textcolor(YELLOW);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    for(i=1;i<120;i++)
        printf("%c",247);
        textcolor(LIGHTGREEN);
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
    FILE *fp;
    fp=fopen("book.bin","rb");
    if(fp==NULL)
    printf("file not found");
book b;
gotoxy(1,9);
textcolor(YELLOW);
printf("BOOK ID:\tBOOK NAME\t\tAUTHOR NAME\t\t\t\tCATEGORY NAME\tQUANTITY");
int y=10;
while(fread(&b,sizeof(book),1,fp)==1)
{gotoxy(1,y);
printf("%d",b.bookId);
gotoxy(16,y);
printf("%s",b.bookName);
gotoxy(41,y);
printf("%s",b.authorName);
char *p;
p=getCategoryName(b.categoryId);
gotoxy(81,y);
printf("%s",p);
gotoxy(97,y);
printf("%d",b.quantity);
y++;
}
}char *getCategoryName(int i)
{
    static  Category cat[6];
FILE *k;
int a;
k=fopen("category.bin","rb");
fread(cat,6*sizeof(Category),1,k);
for(a=0;a<6;a++)
{
if((cat[a].id)==i)
{
    return(cat[a].cat_name);
}}}
int searchmenu()
{

    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    for(i=1;i<120;i++)
    {

        printf("%c",247);
    }
    gotoxy(32,5);
    textcolor(LIGHTGREEN);
    printf("*Search Panel*");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
    gotoxy(1,16);
    for(i=1;i<=240;i++)
        printf("%c",176);
    int ch;
    gotoxy(30,10);
textcolor(YELLOW);
printf("1.Search book by Id");
gotoxy(30,11);
printf("2.Search book by Name");
gotoxy(30,13);
textcolor(LIGHTGREEN);
printf("Enter your Choice");
textcolor(WHITE);
while(1)
    {
        scanf("%d",&ch);
        if(ch<1||ch>2){
            gotoxy(33,18);
            textcolor(LIGHTRED);
            printf("Incorrect Choice");
            getch();
            gotoxy(33,18);
            printf("\t\t\t");
            gotoxy(48,13);
            printf("\t\t");
            gotoxy(48,13);
            textcolor(WHITE);}
        else
            return ch;
    }
}
void searchBooks(int ch)
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("LIBRARY MANAGEMENT SYSYTEM\n");
    for(i=1;i<120;i++)
    {
        printf("%c",247);
    }
gotoxy(32,5);
textcolor(LIGHTGREEN);
printf("*Search Panel*");
gotoxy(1,6);
for(i=1;i<=240;i++)
    {
        printf("%c",176);
    }
    gotoxy(1,19);
    for(i=1;i<=240;i++)
        printf("%c",176);
int id,f=0,result;
book b;
char bName[50];
FILE *fp=fopen("book.bin","rb");
if(ch==1)
    {
        gotoxy(30,10);
        textcolor(YELLOW);
        printf("Enter Book Id");
        scanf("%d",&id);
    }
else if(ch==2){
    gotoxy(20,10);
    textcolor(YELLOW);
    printf("Enter Book NAme you want to search:");
    fflush(stdin);
    gets(bName);
}
while(fread(&b,sizeof(book),1,fp)==1)
{

    result=(ch==1)?(id==b.bookId):(strcmpi(bName,b.bookName)==0);
    if(result==1)
    {
        gotoxy(30,12);
        textcolor(LIGHTGREEN);
        printf("Book is Available");
        textcolor(LIGHTCYAN);
        gotoxy(30,14);
        printf("Book id is %d",b.bookId);
        gotoxy(30,15);
        printf("Book Name is %s",b.bookName);
        gotoxy(30,16);
        printf("Quantity is %d",b.quantity);
        gotoxy(30,17);
        printf("Author name is %s",b.authorName);
        f=1;
        getch();
    }
}
if(f==0)
{

    gotoxy(33,15);
    textcolor(LIGHTRED);
    printf("No Book Found");
}
fclose(fp);
}
int issueMenu()
{int i,choice;
    gotoxy(30,1);
    textcolor(YELLOW);
    printf("LIBRARY MANAGEMENT SYSYTEM\n");
    for(i=1;i<120;i++)
        printf("%c",247);
    gotoxy(40,6);
    printf("*Search Panel*\n");
    for(i=0;i<=240;i++)
    {
        printf("%c",176);

    }
gotoxy(40,12);
    textcolor(YELLOW);
    printf("1.Issue a Book");
    gotoxy(40,13);
    printf("2.View Issued Book");
    gotoxy(40,14);
    printf("3.Search Issued Book");
    gotoxy(40,15);
    printf("4.Remove Issued Book");
    gotoxy(40,16);
    printf("5.Quit");
    gotoxy(1,17);
    for(i=0;i<=240;i++)
    {
        printf("%c",176);
    }
    textcolor(YELLOW);
    gotoxy(38,25);
    printf("Enter Choice:");
    textcolor(WHITE);
while(1){
    scanf("%d",&choice);
        if(choice>5||choice<1)
    {
    gotoxy(38,23);
textcolor(LIGHTRED);
    printf("Wrong Input please enter again");
    getch();
gotoxy(38,23);
    printf("\t\t\t\t\t");
gotoxy(51,25);
printf("\t");
gotoxy(51,25);
    }
else
    return(choice);
}}
void addStudent()
{
    FILE *fp=fopen("student.bin","rb");
    if(fp==NULL)
{fp=fopen("student.bin","wb");
Student stu[10]={
{101,"Ajay"},{102,"Ajit kumar"},{103,"Dinesh Raj"},{104,"Mayank Rathore"},{105,"Rashmi sharma"},{106,"ram kumar"},{107,"raju"},{108,"arpit"},

    {109,"sapna choudary"},{"110","amrita singh"}
};
fwrite(stu,10*sizeof(Student),1,fp);
}
fclose(fp);
}
int issueBook()
{

    int bookid,i;
    book b;
    int bookfound=0,bookq=0;
    Student stu;
    int roll;
    FILE *fpi=fopen("issuebook.bin","ab");
    FILE *fp=fopen("book.bin","rb+");
    FILE *fps=fopen("student.bin","rb");
    if(fpi==NULL||fp==NULL||fps==NULL)
        return 0;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    for(i=1;i<120;i++)
    {
        printf("%c",247);
}
    gotoxy(32,5);
    textcolor(LIGHTGREEN);
    printf("*BOOK ISSUE PANEL*");
    gotoxy(1,4);
    for(i=1;i<=240;i++)
        printf("%c",176);
    gotoxy(1,12);
    for(i=1;i<=240;i++)
        printf("%c",176);
    gotoxy(25,8);
    printf("Enter book id to be issued:");
    textcolor(WHITE);
    scanf("%d",&bookid);
    while(fread(&b,sizeof(book),1,fp)==1)
    {
        if(b.bookId==bookid)
        {
            bookfound=1;
            if(b.quantity>0)
            {
                bookq=1;
            }
        break;}
    }
if(bookfound==0)
    {
        gotoxy(25,17);
        printf("No book found with the id %d",bookid);
        getch();
        fclose(fpi);
        fclose(fps);
        fclose(fp);
        return 0;
    }
    if(bookq==0)
    {
        gotoxy(25,17);
        printf("Out Of Stock");
        getch();
        fclose(fpi);
        fclose(fps);
        fclose(fp);
        return 0;
    }
int stufound=0;
gotoxy(25,9);
textcolor(LIGHTGREEN);
printf("Enter student roll no.");
textcolor(WHITE);
scanf("%d",&roll);
while(fread(&stu,sizeof(Student),1,fps)==1)
    {
        if(stu.roll==roll)
        {
            stufound=1;
            break;
        }
    }
    if(stufound==0)
    {
        gotoxy(25,17);
        printf("Incorrect Roll No.");
        getch();
        fclose(fpi);
        fclose(fps);
        fclose(fp);
        return(0);
    }
    IssueBook ib;
    ib.roll=roll;
    ib.bookId=bookid;
    fwrite(&ib,sizeof(ib),1,fpi);
    fseek(fp,-4,SEEK_CUR);
    int quant=b.quantity-1;
    fwrite(&quant,sizeof(quant),1,fp);
    fclose(fp);
    fclose(fpi);
    fclose(fps);
    return 1;
}
char * get_book_name(int bid)
{
    static char bname[50];
    FILE *fp=fopen("book.bin","rb");
    book b;
    while(fread(&b,sizeof(book),1,fp)==1)
    {
        if(b.bookId==bid)
        {
            strcpy(bname,b.bookName);
            fclose(fp);
            return bname;
        }
    }
fclose(fp);
return NULL;
}
void show_issued_books()
{
    IssueBook t;
    int i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("LIBRARY MANGEMENT SYSTEM\n");
    for(i=1;i<120;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(LIGHTGREEN);
    printf("*ISSUED BOOK DETAILS*");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
        gotoxy(1,9);
    textcolor(YELLOW);
    printf("Roll Number\t    Book Name");
    FILE *fp=fopen("issuebook.bin","rb");
    int y=10;
    while(fread(&t,sizeof(IssueBook),1,fp)==1)
    {

        gotoxy(1,y);
        textcolor(YELLOW);
        printf("%d",t.roll);
        gotoxy(22,y);
        printf("%s",get_book_name(t.bookId));
        y++;
    }
    textcolor(LIGHTGREEN);
    printf("\n");
    gotoxy(1,20);
for(i=1;i<=240;i++)
    printf("%c",176);
fclose(fp);

}
void search_issued_books()
{

    int i;
    int id,f=0;
    IssueBook ib;
    clrscr();
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    for(i=1;i<120;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(LIGHTGREEN);
    printf("*Search Panel*");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
    gotoxy(1,19);
    for(i=1;i<=240;i++)
        printf("%c",176);
    FILE *fp=fopen("issuebook.bin","rb");
    gotoxy(30,10);
    textcolor(YELLOW);
    printf("Enter Book ID");
    scanf("%d",&id);
    while(fread(&ib,sizeof(IssueBook),1,fp)==1)
    {
        if(id==ib.bookId)
        {
            gotoxy(30,12);
            textcolor(LIGHTGREEN);
            printf("Issued book details:");
            textcolor(LIGHTCYAN);
            gotoxy(30,14);
            printf("Roll no. %d",ib.roll);
            gotoxy(30,15);
            printf("Student Name %s",get_student_name(ib.roll));
            gotoxy(30,16);
            printf("Book Id :%d",ib.bookId);
            gotoxy(30,17);
            printf("Book Name %s",get_book_name(ib.bookId));
            f=1;
            getch();
        }
    }
if(f==0)
    {
        gotoxy(31,15);
        textcolor(LIGHTRED);
        printf("No details of book %d found in issued books",id);

    }
fclose(fp);
}
char * get_student_name(int r)
{
    static char str[50];
    FILE *fp=fopen("student.bin","rb");
    Student s;
    while(fread(&s,sizeof(Student),1,fp)==1)
    {if(r==s.roll){
        strcpy(str,s.name);
        fclose(fp);
        return(str);}
    }
fclose(fp);
return NULL;
}
void delete_book()
{

    int i;
    int result;
    int id,f=0;
    book b;
    clrscr();
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    for(i=1;i<120;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(LIGHTGREEN);
    printf("*Delete Panel*");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
    gotoxy(1,19);
    for(i=1;i<=240;i++)
        printf("%c",176);
    FILE *fp=fopen("book.bin","rb");
    gotoxy(30,10);
    textcolor(YELLOW);
    printf("Enter Book Id");
    scanf("%d",&id);
    fseek(fp,0L,SEEK_END);
    long rec_count=ftell(fp)/sizeof(struct book);
    rewind(fp);
    book *p=(book *)malloc((rec_count)*sizeof(struct book));
    i=0;
    while(fread(&b,sizeof(book),1,fp)==1)
    {
        if(id!=b.bookId)
        {
            *(p+i)=b;
            i++;
        }
        else
            f=1;
    }
if(f==0)
    {

        gotoxy(33,15);
        textcolor(LIGHTRED);
        printf("No Book Found Of Id %d",id);
    fclose(fp);
    free(p);
    return;
    }
    fp=fopen("book.bin","wb");
    getch();
    fwrite(p,i*sizeof(struct book),1,fp);
    fclose(fp);
    free(p);
    gotoxy(33,15);
    textcolor(LIGHTGREEN);
    printf("Book of id %d deleted successfully",id);
    return;
}
void del_issue_book()
{book s;
    int i,w=0,f=0;
    IssueBook t;
    int roll,bid;
  gotoxy(30,1);
  textcolor(YELLOW);
  printf("LIBRARY MANAGEMENT SYSTEM\n");
  for(i=1;i<120;i++)
  printf("%c",247);
  gotoxy(1,6);
textcolor(LIGHTGREEN);
  for(i=1;i<=240;i++)
    printf("%c",176);
  FILE *fp=fopen("issuebook.bin","rb");
  FILE *fpi=fopen("book.bin","rb+");
  gotoxy(30,10);
  textcolor(LIGHTCYAN);
  printf("Enter roll and bookid to be return");
  textcolor(WHITE);
  scanf("%d %d",&roll,&bid);
  fseek(fp,0L,SEEK_END);
  int rec=ftell(fp)/sizeof(IssueBook);
  rewind(fp);
  IssueBook *b=(IssueBook *)malloc((rec)*sizeof(IssueBook));
  while(fread(&t,sizeof(IssueBook),1,fp)==1)
  {
       if((bid!=t.bookId)||(roll!=t.roll))
       {
           *(b+w)=t;
           w++;
       }
       else
        f=1;
  }
  if(f==0)
  {
    printf("Book is not in issued list");
    fclose(fp);
    free(b);
  return;
}
fp=fopen("issuebook.bin","wb");
getch();
fwrite(b,w*sizeof(IssueBook),1,fp);
while(fread(&s,sizeof(book),1,fpi)==1)
{
if(s.bookId==bid)
    {fseek(fpi,-4L,SEEK_CUR);
    int quant=s.quantity+1;
fwrite(&quant,sizeof(quant),1,fpi);
fclose(fpi);
fclose(fp);
free(b);
printf("Book is Removed");
return;}
}
fclose(fpi);
fclose(fp);
free(b);
return;
}
void updateBook()
{ int w;
gotoxy(40,1);
printf("LIBRARY MANAGEMENT SYSTEM\n");
textcolor(YELLOW);
for(w=1;w<120;w++)
    printf("%c",247);
    gotoxy(1,6);
    textcolor(LIGHTGREEN);
    for(w=1;w<=240;w++)
        printf("%c",176);
    int *pos;
    book b,t;
     int bid;
int i=0,f=0;
    clrscr();
    gotoxy(30,10);
    //int ch=searchmenu();
      //      searchBooks(ch);
printf("Enter Book ID to be updated:");
scanf("%d",&bid);
clrscr();
gotoxy(40,1);
textcolor(YELLOW);
printf("LIBRARY MANAGEMENT SYSTEM\n");
gotoxy(40,4);
printf("*SEARCHED BOOK DETAIL*\n");
textcolor(LIGHTCYAN);
 FILE *fp=fopen("book.bin","rb");
 while(fread(&t,sizeof(book),1,fp)==1)
{
    if(t.bookId==bid)
    {
        printf("Book  Id %d\n",t.bookId);
    printf("Book Name is %s\n",t.bookName);
    printf("Author Name is %s\n",t.authorName);
    printf("CategoryId is %d\n",t.categoryId);
    printf("Quantity is %d",t.quantity);
    break;
    }
     }       //gotoxy(40,28);
            //printf("Updated Version");
          //  gotoxy(40,29);
      // printf("id:");
 //rewind(fp);
       fseek(fp,0L,SEEK_END);
       int rec=ftell(fp)/sizeof(book);
       rewind(fp);
       book *p=(book *)malloc(rec*sizeof(book));
       //book b;
       //p=&b;
       while(fread(&b,sizeof(book),1,fp)==1)
       {
           if(b.bookId!=bid)
           {
            *(p+i)=b;
           i++;
       }
       else
        f=1;
       }
       if(f==0)
       {
        printf("no book found to be updated");
        fclose(fp);
        free(p);
        return;
       }
        fp=fopen("book.bin","wb");
        fwrite(p,i*sizeof(book),1,fp);
        //printf("book to be updated is:");
        //printf("id",b.bookId);
        //printf("bookname %s",b.bookName);
        //printf("author %s",b.authorName);
        //printf("category %s",b.categoryId);
        //printf("quan %d",b.quantity);
gotoxy(40,18);
textcolor(YELLOW);
            printf("Updated Version");
            gotoxy(40,19);
       printf("id:");

       gotoxy(40,20);
       printf("Book name:");
  //gotoxy(43,29);
    //   scanf("%d",&(b.bookId));
      // gotoxy(50,30);
       //scanf("%s",&(b.bookName));
       gotoxy(40,21);
       printf("author:");
       gotoxy(40,22);
       printf("Category:");
       gotoxy(40,23);
       printf("Quantity:");
       //gotoxy(47,31);
       gotoxy(43,19);
       scanf("%d",&(b.bookId));
fflush(stdin);
       gotoxy(50,20);
fgets(b.bookName,50,stdin);
        pos=strchr(b.bookName,'\n');
        *pos='\0';
       gotoxy(47,21);
       fgets(b.authorName,50,stdin);
        pos=strchr(b.authorName,'\n');
        *pos='\0';
       gotoxy(49,22);
       scanf("%d",&(b.categoryId));
       gotoxy(49,23);
       scanf("%d",&(b.quantity));
       fwrite(&b,sizeof(book),1,fp);
       fclose(fp);
       free(p);
       return;
}

#endif // LMSWH_C_INCLUDED
