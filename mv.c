//Compile with "gcc -o mv mv.c"
#include <stdio.h>
int main(int argc, char **argv){
	FILE *f=fopen(argv[1],"r");
	FILE *t=fopen(argv[2],"a");
	char c;
	while((c=fgetc(f))!=EOF){
		fprintf(t,"%c",c);
	}
	fclose(f);
	remove(argv[1]);
	fclose(t);
}
