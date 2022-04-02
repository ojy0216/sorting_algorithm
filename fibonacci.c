#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct timeval time_st;

typedef unsigned long long ull;

#define SEC_TO_US 1000000

long getTimediff(time_st start, time_st end){
    return (long)((end.tv_sec - start.tv_sec) * SEC_TO_US + (end.tv_usec - start.tv_usec));
}

ull fib(int n){
    if(n <= 2)
        return (ull)1;
    else
        return fib(n - 1) + fib(n - 2);
}

ull mem_bu[100] = {0, 1, 1, 0};
ull mem_td[100] = {0, 1, 1, 0};

void fib_dp_bu(int n){
    for(int i = 3; i <= n; i++)
        mem_bu[i] = mem_bu[i - 1] + mem_bu[i - 2];
}

ull fib_dp_td(int n){
    // if(mem_td[n] != 0)
    //     return mem_td[n];
    // else{
    //     if(n <= 2)
    //         return mem_td[n];
    //     else
    //         return fib_dp_td(n - 1) + fib_dp_td(n - 2);
    // }

    if(n <= 2)
        return mem_td[n];
    
    if(mem_td[n - 1] == 0)
        mem_td[n - 1] = fib_dp_td(n - 1);
    if(mem_td[n - 2] == 0)
        mem_td[n - 2] = fib_dp_td(n - 2);

    return mem_td[n - 1] + mem_td[n - 2];
}

ull fib_mine(int n){
    ull mem_mine[2] = {1, 1};
    ull tmp;

    for(int i = 3; i <= n; i++){
        tmp = mem_mine[0] + mem_mine[1];
        mem_mine[0] = mem_mine[1];
        mem_mine[1] = tmp;
    }

    return mem_mine[1];
}

ull fib_mine_2(int n){
    ull mem_mine[2] = {1, 1};
    int flag = 1;

    for(int i = 3; i <= n; i++){
        mem_mine[flag] = mem_mine[0] + mem_mine[1];
        flag = !flag;
    }

    return mem_mine[!flag];
}

int main(int argc, char* argv[]){
    int num = atoi(argv[1]);

    time_st start, end;

    gettimeofday(&start, NULL);
    printf("%llu\n", fib(num));
    gettimeofday(&end, NULL);
    printf("Fibonnaci w/o DP\n");
    printf("Time: %ld us\n\n", getTimediff(start, end));

    sleep(1);

    gettimeofday(&start, NULL);
    fib_dp_bu(num);
    gettimeofday(&end, NULL);
    printf("%llu\n", mem_bu[num]);
    printf("Fibonnaci w/ DP(bottom up)\n");
    printf("Time: %ld us\n\n", getTimediff(start, end));

    sleep(1);

    gettimeofday(&start, NULL);
    printf("%llu\n", fib_dp_td(num));
    gettimeofday(&end, NULL);
    printf("Fibonnaci w/ DP(top down)\n");
    printf("Time: %ld us\n\n", getTimediff(start, end));

    sleep(1);

    gettimeofday(&start, NULL);
    printf("%llu\n", fib_mine(num));
    gettimeofday(&end, NULL);
    printf("Fibonnaci w/ DP(2 mem)\n");
    printf("Time: %ld us\n\n", getTimediff(start, end));

    sleep(1);

    gettimeofday(&start, NULL);
    printf("%llu\n", fib_mine_2(num));
    gettimeofday(&end, NULL);
    printf("Fibonnaci w/ DP(2 mem, no change)\n");
    printf("Time: %ld us\n", getTimediff(start, end));

}