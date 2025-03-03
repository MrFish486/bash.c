//Compile with "gcc -o cd cd.c"
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv){
	if(argc=0){
		if(chdir("~")){
			printf("Error changing directory!");
			return 1;
		}
	}
	if(chdir(argv[1])!=0){
		printf("Error changing directory!");
		return 1;
	}
	return 0;
}
