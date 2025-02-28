//Compile with "gcc -o rm rm.c"
//WARNING: will remove empty directories as well as files!
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char **argv){
	int removed=0;
	for(int i=1;i<argc;i++){
		if(remove(argv[i])!=0){
			printf("Couldn't remove %s, moving on...\n",argv[i]);
		}
	}
	return 0
}
