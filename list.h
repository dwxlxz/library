#ifndef LIST_H_
#define LIST_H_ 
#include<stdbool.h>
#define MAXT 40
#define MAXA 40
typedef struct Node
{
	char title[MAXT];
	char author[MAXA]; 
	int rating;
	int state;
	struct Node *next;
 } Node;
 
typedef Node *List;

bool VerifyPassword(char password[]); 

void InitializeList(List *plist);

void AddBook(Node temp,List *plist);

void DeleteBook(const List *plist, char BookName[]);

void ChangeBook( List *plist, char BookName[],char NewName[], char NewAuthor[],int BookRating);

void BorrowBook(const List *plist, char BookName[]);

void Traverse(const List *plist);

void SearchBook(const List *plist, char bookname[]);
#endif
