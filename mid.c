#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
int main(int argc, char **argv){
	if(argc == 1){
		printf("No file!\n");
		return 1;
	}
	// Reading
	char * buf = 0;
	FILE* o = fopen(argv[1], "r");
	fseek(o, 0L, SEEK_END);
	long long size = ftell(o);
	long long int lines = 0;
	char c;
	rewind(o);
	buf = malloc(size);
	if(buf){
		fread(buf, 1, size, o);
	}
	rewind(o);
	while((c = fgetc(o)) != EOF){
		if(c == '\n'){
			lines++;
		}
	}
	fclose(o);
	// Reading / writing to terminal
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int ws = w.ws_row;
	int ww = w.ws_col;
	system("clear");
	if(ws < lines){
		printf("\e[1;33mFile doesn't fit on screen.\e[0;38m\n");
	}else{
		printf("\e[1;32mFile fits on screen.\e[0;38m\n");
	}
	printf("Size  : %lliB\nLines : %lli\nEnter to continue.", size, lines);
	getchar();
	system("clear");
	if(ws < lines){
		// Split buf into lines
		//char linestore[lines][256];
		char ** linestore = calloc(sizeof(char) * 256, lines);
		for(int i = 0; i < lines; i++){
			linestore[i] = calloc(sizeof(char) * 256, 1);
		}
		long long int a = 0; // Line
		long long int b = 0; // Readhead
		long long int c = 0; // Writehead
		while(1){
			if(buf[b] == '\n'){
				a++;
				c = 0;
			}
			if(a == lines){
				break;
			}
			linestore[a][c] = buf[b];
			b++;
			c++;
		}
		char d;
		for(long long int progress = 0; progress < (lines - ws) + 4; progress++){
			system("clear");
			printf("\e[%dHLine : \e[1;35m%lli\e[0;38m / \e[7m%d\e[0;38m (\e[1;31m[q]\e[0;38m : quit, \e[1;33m[p]\e[0;38m : page down, \e[1;32m[enter]\e[0;38m : continue) ", ws, progress, (lines - ws) + 4);
			printf("\e[0H");
			for(int i = 0; i < (ws - 2); i++){
				printf("%s", linestore[i + progress]);
			}
			d = getchar();
			if(d == 'q'){
				return 2;
			}else if(d == 'p'){
				if(progress < (lines - ws)){
					progress = (lines - ws) - 2;
				}else{
					progress += ws - 2;
				}
			}
		}
		free(linestore);
	}else{
		printf("%s", buf);
	}
	// Exit
	free(buf);
}
