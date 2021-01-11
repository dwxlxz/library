#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "list.h"

char *s_gets(char *st ,int n);

int main(void)
{
	puts("���������� (Ĭ��helloworld)");
	
	char password [20]; 
	s_gets(password,20);
	
	if(VerifyPassword (password) == true)
		puts("������ȷ \n"); 
	else	
	{
		fprintf( stderr, "������� \n");
		exit(1); 
	}
	
	List books;	 
	Node temp;
	char tempname[MAXT];
	
	InitializeList(&books);
	
	puts ("�����һ������");

	while (s_gets(temp.title,MAXT)!=NULL&&temp.title[0]!='\0') 
		{	
			printf("����:");
			fflush(stdin);
			s_gets(temp.author,MAXT);
			
			printf("����:");
			scanf("%d",&temp.rating);

			temp.state=1;
		
			while(getchar() != '\n')
			continue;
			
			AddBook(temp,&books);
			puts("������һ�����������߻س��˳���"); 
		}
	
	puts("�����������ͼ��,��ͬ���ݻ��ӡ������Ŀ¼�е�1.txt�ļ���(1��ʾ�ɽ���)");
	Traverse(&books);
	
	printf("\n");
	
	puts("1������");
	puts("2��ɾ��");
	puts("3���޸�"); 
	puts("4������");
	puts("5������");
	
	switch(getchar())
	{
	case '1' :
			printf("���������� \n");
			fflush(stdin);
			while (s_gets(temp.title,MAXT)!=NULL&&temp.title[0]!='\0') 	//¼��ͼ�� 
			{	
				printf("����:");
				
				fflush(stdin);
				s_gets(temp.author,MAXT);
				
				printf("����:");
				scanf("%d",&temp.rating);

				temp.state=1;
		
				while(getchar() != '\n')
				continue;
			
				AddBook(temp,&books);
				printf("������һ�����������߻س��˳���\n"); 
			}

			printf("�����������ͼ��,��ͬ���ݻ��ӡ������Ŀ¼�е�1.txt�ļ���\n");
			Traverse(&books);
			break;
	 
	case '2' :
			printf("���������� \n");
			fflush(stdin);
			s_gets(temp.title,MAXT);
			
			DeleteBook(&books,temp.title);
			
			puts("�����������ͼ��,��ͬ���ݻ��ӡ������Ŀ¼�е�1.txt�ļ���\n");
			Traverse(&books);
			break;
			
	case '3' : 
			puts("������Ҫ�޸ĵ�����");
			fflush(stdin);
			s_gets(temp.title,MAXT);
			
			char newtitle[MAXT];
			
			puts("�������޸ĺ������");	
			fflush(stdin);
			s_gets(newtitle,MAXT);
			
			puts("�������޸ĺ������");
			char newauthor[MAXA];
			fflush(stdin);
			s_gets(newauthor,MAXT);
			
			puts("�������޸ĺ������");
			scanf("%d",&temp.rating);
			
			ChangeBook(&books,temp.title,newtitle,newauthor,temp.rating); 
			puts("�����������ͼ��,��ͬ���ݻ��ӡ������Ŀ¼�е�1.txt�ļ���\n");
			Traverse(&books);
			break; 
			
	case '4' :	 
			puts("����������");	
			fflush(stdin);
			s_gets(tempname,MAXT);
			
			SearchTheBook(&books,tempname);
			break;
		
	case '5' :
			puts("����������");	
			fflush(stdin);
			s_gets(tempname,MAXT);
			
			BorrowBook(&books,tempname);
			
			puts("�����������ͼ��,��ͬ���ݻ��ӡ������Ŀ¼�е�1.txt�ļ���\n");
			Traverse(&books);
	}
	printf("������˳�"); 
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
