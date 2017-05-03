// del_Stop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;


int main(void)
{
	int i, n = 0, x;
	FILE *fstop, *fs, *fd, *list;
	if (NULL == (list = fopen("filelist.txt", "r"))) return 1;  //打开文件列表
	char str[20];
	char s1[30] = "E:\\ligang\\src\\";  //源文件查找路径
	char s2[30] = "E:\\ligang\\dst\\";  //生成文件存放路径
	char s3[30];
	char s4[30];

	char stop[1293][30];   //1293个停用词
	char buf[50];        //一行50个字符
	if (NULL == (fstop = fopen("stop.txt", "r"))) return 1;
	//读入停用词
	while (!feof(fstop))
	{
		fscanf(fstop, "%s", stop[n]);
		n++;
	}
	fclose(fstop);
	//删除停用词
	while (1)
	{

		char s1[30] = "E:\\ligang\\src\\";
		char s2[30] = "E:\\ligang\\dst\\";
		memset(s3, '\0', sizeof(s3));
		memset(s4, '\0', sizeof(s4));
		if (NULL == fgets(str, 20, list)) break;
		if ('\n' == str[0]) continue;
		str[strlen(str) - 1] = 0;
		strcpy(s3, strcat(s1, str));
		strcpy(s4, strcat(s2, str));
		if (NULL == (fs = fopen(s3, "r"))) return 1;
		if (NULL == (fd = fopen(s4, "w"))) return 1;

		//删除文档中的停用词

		while (!feof(fs))
		{
			fscanf(fs, "%s", buf);

			for (i = 0;i < n;i++)
			{
				if (strcmp(buf, stop[i]) == 0 || strlen(buf) <= 2)
				{
					x = 1;
					break;
				}
			}
			if (x == 1)
			{
				x = 0;
				continue;
			}
			else
				fprintf(fd, "%s\n", buf);
			memset(buf, '\0', sizeof(buf));
		}
		fclose(fs);
		fclose(fd);
		memset(s1, '\0', sizeof(s1));
		memset(s2, '\0', sizeof(s2));
	}
	return 0;
}

