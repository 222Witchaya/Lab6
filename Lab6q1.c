#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

//64050222
int csum;
int msum;
int num;
void *childrunner(void *param);
int main(int argc, char *argv[]){
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid,&attr,childrunner,argv[1]);

        for(num = 0; num <= atoi(argv[1]); num++)
                        msum += num;

        pthread_join(tid,NULL);

        //printf("Child  = %d\n", csum);
        //printf("Parent = %d\n", msum);
        printf("Child - Parent = %d\n",csum - msum);
        return 0;
}
void *childrunner(void *param){
        int upper = atoi(param);
        upper = upper*2;
        csum = 0;
        if(upper > 0){
                for(num = 0; num <= upper; num++)
                        csum += num;
        }
        pthread_exit(0);
}
