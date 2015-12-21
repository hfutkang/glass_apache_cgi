#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
//char filename[500][30];

#define MAX_PATH_LENGTH	128

int listfiles(char* path)
{
	DIR *d;//声明一个句柄
	struct dirent *file;//readdir函数的返回值就存放在这个结构体中
	struct stat sb;  

	if(!(d = opendir(path)))
	{
		printf("<result>error:%d</result>\n", errno);
		return -1;
	}

	while((file = readdir(d)) != NULL)
	{
		//把当前目录.，上一级目录..及隐藏文件都去掉，避免死循环遍历目录
		if(strncmp(file->d_name, ".", 1) == 0)
		    continue;
		printf("<name>%s</name>\n", file->d_name);
		//strcpy(filename[len++], file->d_name);//保存遍历到的文件名
		//判断该文件是否是目录，及是否已搜索了三层，这里我定义只搜索了三层目录，太深就不搜了，省得搜出太多文件
	}

	closedir(d);
	return 0;
}
int main()
{
	char *dir = NULL;
	char path[MAX_PATH_LENGTH];

	dir = getenv("QUERY_STRING");	

	printf("Content-type: text/plain; charset=iso-8859-1\r\n\r\n");
	printf("<%s>\n", dir);
	
	if(dir != NULL) {

		sprintf(path, "/data/apache/GlassData/%s", dir);
		listfiles(path);
	}
	else
		printf("<result>error</result>\n");

	printf("</%s>\n", dir);
	return 0;
}
