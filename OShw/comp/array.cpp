

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
void print(Process);


int main(){
    
    //step 0 prep for the queue 
    Process workingQ[MAX];
    Process compeleteQ[MAX];
    
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
            print(workingQ[i]);
        } 
        cout<<"ps_num good"<< endl;}
    // create order counter = 0
    
    int wk_end, wk_front, cp_end, cp_front;
    wk_end = ps_num;
    wk_front = cp_end = cp_front = 0 ;

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
//
void print(Process p){
    cout << "{" << endl;
    cout << "\t" << p.brst_t << endl; 
    cout << "\t" << p.cmpt_t << endl; 
    cout << "\t" << p.rmnd_t << endl; 
    cout << "\t" << p.wait_t << endl; 
    cout << "\t" << "}" << endl;

}
