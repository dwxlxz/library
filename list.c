#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static void CopyToNode(Node temp, Node *pnode);
static void CopyToNode(Node temp, Node *pnode)
{
	*pnode = temp;						
}

bool VerifyPassword(char password[])
{
		char  str[] = "helloworld";
        char *res = getMd5(str);  
        char *input = getMd5(password);  
		if (strcmp(res,input) == 0)
			return true;
		else
			return false;
}

void InitializeList(List *plist)
{
	*plist = NULL;
}

void AddBook(Node temp,List *plist)
{
	Node *pnew;
	pnew = (Node *) malloc(sizeof(Node));
	
	CopyToNode(temp,pnew);
	pnew->next = NULL;
	
	Node *scan = *plist;
	if(scan == NULL)
		*plist = pnew;
	else
	{
		while(scan->next != NULL)
			scan = scan->next;
			scan->next=pnew; 
	}
}

void DeleteBook(const List *plist, char BookName[])	
{	
	Node *temp;
	Node *pnode = *plist;
	int i = 0 ;
	while(strcmp(pnode->next->title,BookName) != 0)
			pnode = pnode->next;
		
	temp = pnode->next;
	pnode->next = temp->next;
}

void ChangeBook( List *plist, char BookName[],char NewName[], char NewAuthor[],int BookRating)
{
	Node *pnode = *plist;
	while( strcmp(pnode->title,BookName) != 0)
		pnode = pnode->next;
	strcpy(pnode->title,NewName);
	strcpy(pnode->author,NewAuthor);
	pnode->rating = BookRating;
}

void BorrowBook(const List *plist, char BookName[])
{
	Node *pnode = *plist;
	while( strcmp(pnode->title,BookName) != 0)
		pnode = pnode->next;
	pnode->state = 0; 
}

void Traverse(const List *plist)
{
	int i = 0; 
	Node *pnode = *plist;
	while(pnode != NULL)
	{
		i++;
	FILE *fp;
	fp = fopen ("1.txt","a+");
	printf("%d£ºbook: %s author:%s rating: %d state: %d \n",i,pnode->title,pnode->author,pnode->rating,pnode->state);
	fprintf(fp,"%d£ºbook: %s author:%s rating: %d state: %d \n",i,pnode->title,pnode->author,pnode->rating,pnode->state);
	pnode = pnode->next; 
	}	
	
	FILE *fp;
	fp = fopen ("1.txt","a+");
	fprintf(fp,"\n");
}

void SearchTheBook(const List *plist, char BookName[])
{
	Node *pnode = *plist;
	while(strcmp(pnode->title,BookName) != 0)
		pnode = pnode->next;
	printf("book: %s author:%s rating: %d state: %d \n",pnode->title,pnode->author,pnode->rating,pnode->state);
}
