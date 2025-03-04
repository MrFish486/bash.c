#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define _USER_COLOR "\033[1;32m"
#define _PATH_COLOR "\033[1;34m"
#define _HOST_COLOR "\033[1;33m"
int main(int argc, char **argv){
	char * user = getlogin();
	char path[512];
	char hostname[64];
	while(1){
		char c;
		char * command = (char *)calloc(512, sizeof(char));
		getcwd(path,512);
		char homedir[32];
		char ** arguments = calloc(8, sizeof(char));
		for(int q = 0;q < 8;q++){
			arguments[q] = calloc(1, sizeof(char) * 128);
		}
		sprintf(homedir,"/home/%s/",path);
		gethostname(hostname,64);
		if(strcmp(path,homedir)){
			printf("%s%s\033[0;38m@%s%s\033[0;38m:%s~\033[0;38m$ ", _USER_COLOR, user, _HOST_COLOR, hostname, _PATH_COLOR);
		}else{
			printf("%s%s\033[0;38m@%s%s\033[0;38m:%s%s\033[0;38m$ ", _USER_COLOR, user, _HOST_COLOR, hostname, _PATH_COLOR, path);
		}
		int a = 0;
		int b = 0;
		int d = 0;
		while(c = getchar()){
			if(c == ' '){
				b++;
				d = 0;
			}
			if(c == '\n' || c == '\0'){
				break;
			}else{
				command[a] = c;
				if(c != ' '){
					arguments[b][d] = c; //This (used to) throw a segfault, probably because I allocated "char ** arguments;" without set lengths.
				}
				a++;
				d++;
			}
		}
		printf("%s\n",arguments[1]);
		if(strcmp(command, "") == 0){
			//Nothing
		}else{
			if(strcmp(command, "clear") == 0){
				printf("\e[1;1H\e[2J");
			}else if(strcmp(command, "cd") == 0){
				if(chdir(arguments[1]) != 0){
					printf("Error changing directory.\n");
				}
			}
		}
		free(command);
		free(arguments);
	}
}
