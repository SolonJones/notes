#include<stdio.c>
#include<stdlib.c>

#define MAX 1000
#define Q 1 

struct Process{
    int burst_t;
    int comp_p;
    int rema_p;
    int wait_t;
}

// the algo that mimic ps schduler
void rrobin();

// system wide queue for all mimic ps to wait 
// track for begin and end, mimic round queue 
struct ps[MAX] queue; 
int beg,end; 


int main(){

    //step1 read a file as input 
        // a file contains: num of ps + each burst time 
        // init a ps_num with num
        // create struct Process and init var
        // fill the queue with ps accoring to readin orders 
        // init value of beg/end for tracking the wokring order
        // create a completion list[ps_num] for complete ps 
    //step2 call algo to process the queue 
        // rrobin update process struct 
        // rrobin update queue order and beg/end 
    //report the result 
    return 0;
}

//need to do: 
// 1. record ps order of completion 
// 2. record ps wait time 
// 3. cal ave wait time 


//note: 
//use a real queue instead of write one 
