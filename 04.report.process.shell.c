#include<stdio.h>
int main(){
	printf("run ps ()\n");
	int x= fork();
	if(x==0){
		printf("i am child after work(), launching ps -ef\n");
		char *args[]= {"/bin/ps","-ef",NULL};
		execvp("/bin/ps",args);
		printf("Finished launchung ps -ef\n");
	}
	else{
		int y =folk();
		if (y ==0){
			printf("Run free -h\n");
			char *args2[]={"/usr/bin/free", "-h",NULL};
			execvp("/usr/bin/free", args2);
		}
	}
	return 0; 
}
