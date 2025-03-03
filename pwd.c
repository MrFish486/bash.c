//Compile with "gcc -o pwd pwd.c"
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv){
	char d[512];
	printf("%s\n",getcwd(d,512));
}
