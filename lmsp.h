#ifndef LMSWH_H_INCLUDED
#define LMSWH_H_INCLUDED

struct User
{
    char userid[20];
    char pwd[20];

};
struct Category
{
    int id;
    char cat_name[20];
};
struct book
{
    int bookId;
    char bookName[50];
    char authorName[50];
    int categoryId;
    int quantity;
};
struct Student{
int roll;
char name[30];
};
struct IssueBook
{
    int roll;
    int bookId;
};
typedef struct IssueBook IssueBook;
typedef struct Student Student;
typedef struct book book;
typedef struct Category Category;
typedef struct User User;
int enterchoice();
void addUser();
void addStudent();
void addCategory();
void input();
int isUserpresent(char *,char*);
int showCategory();
book * getBookDetails();
void addbooks(book,int);
void show_books();
char * getCategoryName(int);
int searchmenu();
void searchBooks(int);
int issueMenu();
int issueBook();
void show_issued_books();
void search_issued_books();
char * get_book_name(int);
char * get_student_name(int);
void del_issue_book();
void updateBook();
#endif

