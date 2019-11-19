#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define MAX 16
#define THREAD_MAX 4

int array[MAX] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };

int key = 5;
int flag = 0; //flag to indicate that item is found in the array or not
int current_thread = 0;

//void pthread_exit(void *rval_ptr);

void* ThreadSearch(void* args) { //This is linear search function. It will be running using all threads
   int i, j;
   int num = current_thread++;
   int *myid = (int *)args;
   for (i = num * (MAX / 4); i < ((num + 1) * (MAX / 4)); i++){
      printf("Thread ID: %d \n array[i]=%i\n i=%i num=%i current_thread=%i\n \n", *myid, array[i], i, num, current_thread);
      if (array[i] == key){
         flag = 1; //set flag if key is found
         j=i;
         //exit(j);
      }
     //exit(-1);    
   }
         pthread_exit(NULL);

}

int main() {

   //int j;
   int test;

   int *child_return = (int *)&test;

   pthread_t thread[THREAD_MAX];
   for (int i = 0; i < THREAD_MAX; i++) { //create multiple threads
      //printf("%i\n %s\n", i, thread[i]);
      pthread_create(&thread[i], NULL, ThreadSearch, (void*)&thread[i]);
   }
   for (int i = 0; i < THREAD_MAX; i++) {
      pthread_join(thread[i], (void*)&(test)); //wait untill all of the threads are completed
   }




   if (flag == 1)
      printf("fuck you i found it.  its here, bitch.\n (void*)&test = %p\n child_return = %i\n", (void*)&test, **&child_return);
   else
      printf("it's not here, dumbass\n");


pthread_exit(NULL);

}

