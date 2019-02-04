#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *print_integer(void * number){
    int num;
    num = *(int *) number;

    sleep(3);
    printf("Number = %d\n",num);
}

void *print_string(void * string){
    char * message;
    message = (char *) string;

    sleep(3);
    printf("String = %s\n",message);
}

int main(){
    pthread_t thread;
    int iret;
    int number = 1;
    int * number_pointer;
    char * message = "MYNIGGA";

    number_pointer = &number;
    iret = pthread_create(&thread, NULL, print_integer, (void *) number_pointer);

    if (iret){
        fprintf(stderr, "ERROR return code: %d", iret);
    }

    //pthread_join(thread, NULL);

    iret = pthread_create(&thread, NULL, print_string, (void *) message);

    if (iret){
        fprintf(stderr, "ERROR return code: %d", iret);
    }

    pthread_join(thread, NULL);
}