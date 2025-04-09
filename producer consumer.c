#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void wait() {
    --mutex;
}

void signal() {
    ++mutex;
}

void producer() {
    wait();
    ++full;
    --empty;
    x++;
    printf("Producer has produced: Item %d\n", x);
    signal();
}

void consumer() {
    wait();
    if (full > 0) {
        --full;
        ++empty;
        printf("Consumer has consumed: Item %d\n", x);
        x--;
    } else {
        printf("Buffer is empty!\n");
    }
    signal();
}

void main(){

    int choice;

    while(1){
        printf("Enter the option:\n1. Produce\n2. Consume\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                printf("\nExit Successful!\n");
                exit(0);

            default:
                printf("\nInvalid option\n");

        }
    }

}
