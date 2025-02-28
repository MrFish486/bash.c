//Compile with "gcc -o cat cat.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv){
	if(argc>1){
		for(int i=1;i<argc;i++){
			FILE* h=fopen(argv[i],"r");
			char c;
			while((c=fgetc(h))!=EOF){
				printf("%c",c);
			}
			fclose(h);
		}
	}else{
		while(1){ // Didn't want <stdbool.h>
			char in[1];
			scanf("%c",&in);
			printf(in);
		}
	}
	return 0;
}
