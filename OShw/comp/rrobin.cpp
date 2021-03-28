

#include<queue>
#include<iostream>

using namespace std;

#define MAX 1000
#define Q 5
#define test 1
/* 
if(test ==1){cout<<;}
*/

struct Process{
    int brst_t;
    int cmpt_t;
    int rmnd_t;
    int wait_t;
};

// the algo that mimic ps schduler
void rrobin();
void cpu();

//step 0 prep for the queue 
Process workingQ[MAX];
Process compeleteQ[MAX];

    int wk_end, wk_front, cp_end, cp_front;

int main(){


    //step1 read a file as input 
    // a file contains: num of ps + each burst time 
    // init a ps_num with num
    int ps_num; 
    cin >> ps_num;
    if(test ==1){cout<<"ps_num good"<< endl;}
    int readin_t;
    int dummy =0;
    // enter a loop of ps_num
    // init process value  
    // burst time = read in value 
    // comp =0
    // rema = brust time 
    // realt = curent time
    for(int i=0; i<ps_num; i++){
        cin >> readin_t;
        workingQ[i].brst_t = readin_t;
        workingQ[i].cmpt_t = dummy;
        workingQ[i].rmnd_t = readin_t;
        workingQ[i].wait_t = dummy;
    }

    if( test ==1){
        for(int i=0; i< ps_num; i++){
            cout << workingQ[i].brst_t << endl;
        } 
        cout<<"ps_num good"<< endl;}

    wk_end = ps_num;
    int size = ps_num;

    // done with step 1 

    //step3 report the result 
    return 0;
}

void rrobin(){
    // while the wokringQ still have ps the scheduler continues
    while( size > 0  ) {
        // cpu update rmnd_t, cmpt_t  
        // if rmnd_t is 0 cpu will notify 
        // 
        cpu(workingQ[wk_front]);
        // update all other process wait time 
        for(int i = wk_front+1; wk_end; i++){
            workingQ[i].wait_t+=quant;
        }

    }
}
    //step2 call algo to process the queue 
    // rrobin check the queue is not empty
    // rrobin pop the front process
    // rrobin call cpu() to process 
    // cpu check if quant <= rema 
    // no: comp += rema; rema =0; call time_t measure end time; push process onto finish queue
    // yes: comp+=quant; rema-=quant; push proces back to queue 
    // rrobin repeat until the queue is empty


