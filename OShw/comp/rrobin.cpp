

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
void cpu(Process, int *);

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

void updateQ(){
	workingQ[++wk_end] = workingQ[wk_front++];

    if( test ==1){
        cout<<"front update to" << wk_front<< endl;
        cout<<"back update to" << wk_end << endl;}

 
}
void rrobin(){
	// while the wokringQ still have ps the scheduler continues
	while( size > 0  ) {
		// set timer for each burst 
		int timer = Q; 
		while(timer > 0){
			// when still have timer left, let cpu working with the front of the queue 
			cpu(workingQ[wk_front], &timer);
			if( timer <= 0){
				break;
			}
			else{
				// cpu will mark the complete ps to complete queue 
				// update front only 
				wk_front++;
			}

		}
		// when current timer has been used all updateQ 
		updateQ();
	}
}

void cpu(Process p, int* t){
	
}



/*************below here is only for reference ***********/


//step2 call algo to process the queue 
// rrobin check the queue is not empty
// rrobin pop the front process
// rrobin call cpu() to process 
// cpu check if quant <= rema 
// no: comp += rema; rema =0; call time_t measure end time; push process onto finish queue
// yes: comp+=quant; rema-=quant; push proces back to queue 
// rrobin repeat until the queue is empty



/* the timer is 4, ps1 have only 1 sec left, ps2 will give the remining 3 sec of execution. after current burst, we assume ps2 wilr * */ 
