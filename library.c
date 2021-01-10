#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "list.h"

char *s_gets(char *st ,int n);

int main(void)
{
	puts("请输入密码 (默认helloworld)");
	
	char password [20]; 
	s_gets(password,20);
	
	if(VerifyPassword (password) == true)
		puts("密码正确 \n"); 
	else	
	{
		fprintf( stderr, "密码错误 \n");
		exit(1); 
	}
	
	List books;	 
	Node temp;
	char tempname[MAXT];
	
	InitializeList(&books);
	
	puts ("输入第一本书名");

	while (s_gets(temp.title,MAXT)!=NULL&&temp.title[0]!='\0') 
		{
			printf("评分:");
			scanf("%d",&temp.rating);

			temp.state=1;
		
			while(getchar() != '\n')
			continue;
			
			AddBook(temp,&books);
			puts("输入下一本书名，或者回车退出。"); 
		}
	
	puts("这是您输入的图书,相同内容会打印到程序目录中的1.txt文件里(1表示可借阅)");
	Traverse(&books);
	
	printf("\n");
	
	puts("1：增加");
	puts("2：删除");
	puts("3：修改"); 
	puts("4：查找");
	puts("5：借阅");
	
	switch(getchar())
	{
	case '1' :
			printf("请输入书名 \n");
			fflush(stdin);
			while (s_gets(temp.title,MAXT)!=NULL&&temp.title[0]!='\0') 	//录入图书 
			{
				puts("输入评分");
				scanf("%d",&temp.rating);

				temp.state=1;
		
				while(getchar() != '\n')
				continue;
			
				AddBook(temp,&books);
				printf("输入下一本书名，或者回车退出。\n"); 
			}

			printf("这是您输入的图书,相同内容会打印到程序目录中的1.txt文件里\n");
			Traverse(&books);
			break;
	 
	case '2' :
			printf("请输入书名 \n");
			fflush(stdin);
			s_gets(temp.title,MAXT);
			
			DeleteBook(&books,temp.title);
			
			puts("这是您输入的图书,相同内容会打印到程序目录中的1.txt文件里\n");
			Traverse(&books);
			break;
			
	case '3' : 
			printf("请输入要修改的书名");
			fflush(stdin);
			s_gets(temp.title,MAXT);
			
			char newtitle[MAXT];
			puts("请输入修改后的书名");	
			fflush(stdin);
			s_gets(newtitle,MAXT);
			
			puts("请输入修改后的评分");
			scanf("%d",&temp.rating);
			
			ChangeBook(&books,temp.title,newtitle,temp.rating); 
			puts("这是您输入的图书,相同内容会打印到程序目录中的1.txt文件里\n");
			Traverse(&books);
			break; 
			
	case '4' :	 
			puts("请输入书名");	
			fflush(stdin);
			s_gets(tempname,MAXT);
			
			SearchTheBook(&books,tempname);
			break;
		
	case '5' :
			puts("请输入书名");	
			fflush(stdin);
			s_gets(tempname,MAXT);
			
			BorrowBook(&books,tempname);
			
			puts("这是您输入的图书,相同内容会打印到程序目录中的1.txt文件里\n");
			Traverse(&books);
}
	printf("任意键退出"); 
	getchar();
	return 0;
}
char *s_gets(char *st ,int n)
{
	char *ret_val;
	char *find;
	
	ret_val = fgets (st, n, stdin);
	if(ret_val)
	{
		find = strchr(st,'\n');
		if (find)
			*find= '\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}
