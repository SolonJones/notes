

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
void cpu(int *);
void print(Process p);
void updateQ();
void move_to_complete();

//step 0 prep for the queue 
Process workingQ[MAX];
Process compeleteQ[MAX];

    int size, wk_end, wk_front, cp_end, cp_front;

int main(){


    //step1 read a file as input 
    // a file contains: num of ps + each burst time 
    // init a ps_num with num
    int ps_num; 
    cin >> ps_num;
    if(test ==1){cout<<"ps_num good"<< endl;}
    size = ps_num;
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
            cout << workingQ[i].brst_t << "\t" ;
        } 
        cout<< endl<<"working q good"<< endl;}

    wk_end = ps_num;
    int size = ps_num;

    // done with step 1 
    // test updateQ 
    if( test ==1){
	    cout << "wk_front: " << wk_front << endl;
	    cout << "wk_end: " << wk_end<< endl;
	    for(int i=0; i< ps_num; i++){
		    cout << workingQ[i].brst_t << '\t';
	    } 
	    updateQ();
	    cout << "wk_front: " << wk_front << endl;
	    cout << "wk_end: " << wk_end<< endl;
	    for(int i=0; i< ps_num; i++){
		    cout << workingQ[i].brst_t << '\t';
	    }
	    cout<<"ps_num good"<< endl;}


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
			cpu(&timer);
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
// cpu only work with the wk_front of the working Q 
// cpu will remove wk_front it to complete if its rmnd_t is zero 
void cpu(int* t){
	Process run = workingQ[wk_front];	
	if(run.rmnd_t = *t){
		// run finished 
		// set timer to zero
		// update wk_front, mv to cpQ
		run.rmnd_t -= *t;
		*t = 0;
		move_to_complete();
	}
	else if(run.rmnd_t < *t){
		// run will be finshed, may or may not used up all the time 
		// reduce timer
		// update wk_front mv to cpQ
		*t -=run.rmnd_t;
		run.rmnd_t=0;
		move_to_complete();
	}
	else{
		// run will not be finshed 
		// set timer to zero
		run.rmnd_t -= *t;
		*t = 0;

	}

	// update wait time for all ps 
	// wether *t is 0 or not, 
	// cpu have worked Q-*t by now 
	for(int i = wk_front+1;i<=wk_end;i++){
		workingQ[i].wait_t+=(Q-*t);
	}
}

void move_to_complete(){
	;
}


void print(Process p){
	cout << "{" << '\t' ;
	cout << "\t" << p.brst_t << "\t"; 
	cout << "\t" << p.cmpt_t << "\t"; 
	cout << "\t" << p.rmnd_t << "\t"; 
	cout << "\t" << p.wait_t<< "\t"; 
	cout << "}" << endl;


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
