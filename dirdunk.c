#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>


char * checksize(int o_size){
	char * size;
	printf("Size is: %d", o_size);
	if(o_size > 1000000000){
		sprintf(size, "%dGB ", o_size % 1000000000);
		return strcat(size, checksize(o_size / 1000));
	}
	else if(o_size > 1000000){
		sprintf(size, "%dMB ", o_size % 1000000);
		return strcat(size, checksize(o_size / 1000));
	}
	else if(o_size > 1000){
		sprintf(size, "%dKB ", o_size % 1000);
		return strcat(size, checksize(o_size / 1000));
	}
	else{
		sprintf(size, "%dB", o_size);
		size[strlen(size)] = 0;
		return size;
	}
}

char * print_dir(char * name){
	DIR * d;
	d = opendir(name);
	printf("Printing directory: %s\n", name);
	struct dirent *entry;
	printf("FILES IN THE DIRECTORY: \n");
	int size;
	while(entry = readdir(d)){
		if(entry -> d_type == DT_DIR){
			printf("\t%s  [is a directory]\n", entry -> d_name);
			/* DIR * d2;
			d2 = opendir("testDir");
			struct dirent *entry2;
			print_dir(entry2, d2); */
		}
		else{
			printf("\t%s\n", entry->d_name);
		}
		size += entry -> d_reclen;
		//printf("THINGAROO%d", entry -> d_reclen);
		//printf("  %s\n", checksize(entry -> d_reclen));
	}
	printf("TOTAL SIZE OF THE DIRECTORY: %d\n", size);

	closedir(d);
}

int main(){
	print_dir("testDir");
}
