//Compile with "gcc -o date date.c"
#include <stdio.h>
#include <time.h>
int main(int argc, char **argv){
	time_t t;
	struct tm * timeInfo;
	time(&t);
	timeInfo=localtime(&t);
	printf("%s",asctime(timeInfo));
	return 0;
}
