#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH_LENGTH	128
#define MAX_FILE_COUNT	1024

int deletefiles(char (*files)[MAX_PATH_LENGTH], int count) {
	
	int delcount = 0;
	while(count-- != 0) {
		if(remove(*files) != -1)
			delcount++;
		
		files++;
			
	}
	
	return delcount;
}


int main() {
	
	char files[MAX_FILE_COUNT][MAX_PATH_LENGTH];
	
	char *param = getenv("QUERY_STRING");
//	char p[] = "photos&1&2";
//	char *param = p;
	char *tempname = NULL;
	char *dir = strsep(&param, "&");
	int filescount = 0;
	int delcount = 0;

	char (*tempfile)[MAX_PATH_LENGTH] = files;

	printf("Content-type: text/plain; charset=iso-8859-1\r\n\r\n");	
	printf("<smartglass>\n");

	while(param) {
		tempname = strsep(&param, "&");
		sprintf(*tempfile, "/data/apache/GlassData/%s/%s", dir, tempname);
		tempfile++;
		filescount++;
	}
	
	delcount = deletefiles(files, filescount);
	if(delcount != filescount)
		printf("<error>%d</error>\n", errno);
	printf("<result>%d</result>\n", delcount);
	printf("</smartglass>\n");
	return 0;
}
