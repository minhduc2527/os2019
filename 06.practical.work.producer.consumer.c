#include<studio.h>
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

int main(){
	item* orderfirst = makeItem('1', 8, '1');
	item* ordersecond = makeItem('0', 9, '1');
	printf("what you just log: \nfirst = %d\tlast = %d\n\n", first, last);
	produce(order1);
	produce(order2);
	consume();
	return 0;

}
