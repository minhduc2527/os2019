/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 10

typedef struct {
	    char type; // 0=fried chicken, 1= french fries
	    int amount; // pieces or weight
	    char unit; //0=gram, 1=things
} item;

item buffer [BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	    while ((first + 1) % BUFFER_SIZE == last){
	    printf("No free buffer (s)\n");
 	    }
	    memcpy(&buffer[first], i, sizeof(item));
	    first = (first + 1) % BUFFER_SIZE;
	    printf("first = %d\t last = %d\n", first, last);
}

item *consume() {
	    item *i = malloc(sizeof(item));
	    while (first == last){
	    printf("Nothing to consume");
	    }
	    memcpy(i, &buffer[last], sizeof(item));
	    last = (last +1) % BUFFER_SIZE;
	    printf("first = %d\t last = %d\n", first, last);
	    return i;

}

item* makeItem(char type, int amount, char unit){
	    item* i = malloc(sizeof(item));
	    i->type= type;
	    i->amount = amount;
	    i->unit = unit;
	    return i;
    	    }   
void *threadProduce(void *param){
	    produce(makeItem('0', 8, '1'));
	    produce(makeItem('0', 28, '0'));
	    produce(makeItem('1', 40, '1'));
            }
void *threadConsume(void *param){
	    consume(makeItem('0', 40, '1'));
	    consume(makeItem('1', 8, '0'));
	    }
int main(int argc, char const *argv[]){
	    pthread_t tid1,tid2;
	    pthread_create(&tid1, NULL,threadProduce, NULL);
	    pthread_create(&tid2, NULL,threadConsume, NULL);
	    pthread_join(tid1, NULL);
	    pthread_join(tid2, NULL);
	     return 0;
	    }

