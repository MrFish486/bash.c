//Compile with "gcc -o cp cp.c"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char **argv){
	FILE *f=fopen(argv[1],"r");
	FILE *t=fopen(argv[2],"a");
	char c;
	while((c=fgetc(f))!=EOF){
		fprintf(t,"%c",c);
	}
	fclose(f);
	fclose(t);
}
