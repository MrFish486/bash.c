//Compile with "gcc -o ls ls.c -lm"
#include <stdio.h>
#include <dirent.h>
#include <math.h>
int main(int argc, char **argv){
	if(argc!=1){
		for(int i=1;i<argc;i++){
			struct dirent *de;
			DIR *dr = opendir(argv[i]);
			if(dr == NULL){
				printf("\033[1;31mError; can't open folder \033[1;33m%s\033[0;38m\n",argv[i]);
				return 1;
			}else{
				while((de=readdir(dr))!=NULL){
					if(de->d_type==DT_DIR){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:Dir       \033[1;33m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_REG){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:File      \033[1;32m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_LNK){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:Link      \033[1;31m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_BLK){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:Blk       \033[1;31m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_CHR){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:Chr       \033[1;31m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_FIFO){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:Fifo      \033[1;31m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_SOCK){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:Sock      \033[1;31m%s\033[0;38m",de->d_name);
					}else if(de->d_type==DT_UNKNOWN){
						int d=0;
						d=(de->d_ino==0)?1:log10(de->d_ino)+1;
						printf("Inode:%d",de->d_ino);
						for(int q=0;q<10-d;q++){
							printf(" ");
						}
						printf("Type:???       \033[1;31m%s\033[0;38m",de->d_name);
					}
					printf("\n");
				}
			}
		}
	}else{
		struct dirent *de;
		DIR *dr = opendir(".");
		if(dr == NULL){
			printf("\033[1;31mError; can't open folder \033[1;33m.\033[0;38m\n");
			return 1;
		}else{
			while((de=readdir(dr))!=NULL){
				if(de->d_type==DT_DIR){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:Dir       \033[1;33m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_REG){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:File      \033[1;32m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_LNK){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:Link      \033[1;31m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_BLK){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:Blk       \033[1;31m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_CHR){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:Chr       \033[1;31m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_FIFO){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:Fifo      \033[1;31m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_SOCK){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:Sock      \033[1;31m%s\033[0;38m",de->d_name);
				}else if(de->d_type==DT_UNKNOWN){
					int d=0;
					d=(de->d_ino==0)?1:log10(de->d_ino)+1;
					printf("Inode:%d",de->d_ino);
					for(int q=0;q<10-d;q++){
						printf(" ");
					}
					printf("Type:???       \033[1;31m%s\033[0;38m",de->d_name);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
