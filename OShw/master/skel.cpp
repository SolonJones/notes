
#include<queue>
#include<iostream>
#include<chrono>

using namespace std;

#define quant 5

struct process{
    int burst_t;
    int comp_p;
    int rema_p;
    long start;
    long end;
};

// the algo that mimic ps schduler
void rrobin();
void cpu();

int main(){

    //step1 read a file as input 
        // a file contains: num of ps + each burst time 
        // init a ps_num with num
        int ps_num; 
        cin >> ps_num;
        cout << ps_num;
        // enter a loop of ps_num
        // dynamically allocate num_ps struct of process 
        // init process value  
            // burst time = read in value 
            // comp =0
            // rema = brust time 
            // realt = curent time
        // dynamcially create second queue call finish 
        // create order counter = 0

    // done with step 1 

    //step2 call algo to process the queue 
        // rrobin check the queue is not empty
        // rrobin pop the front process
        // rrobin call cpu() to process 
            // cpu check if quant <= rema 
            // no: comp += rema; rema =0; call time_t measure end time; push process onto finish queue
            // yes: comp+=quant; rema-=quant; push proces back to queue 
        // rrobin repeat until the queue is empty

    //step3 report the result 
    return 0;
}

//need to do: 
// 1. record ps order of completion  nn
// 2. record ps wait time  nn
// 3. cal ave wait time 


//note: 
//use a real queue instead of write one 
//use reak time elapse than simulated time for real time 
