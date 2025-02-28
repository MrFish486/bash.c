//Compile with "gcc -o rm rm.c"
//WARNING: will remove directories as well as files!
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char **argv){
	for(int i=1;i<argc;i++){
		if(remove(argv[i])!=0){
			printf("Couldn't remove %s, moving on...",argv[i]);
		}
	}
}
