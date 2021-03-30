
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

#define MAX 1000
#define Q 4
#define test 1
#define pass 0
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
void move_to_finish();
void print_header();

//step 0 prep for the queue 
Process workingQ[MAX];
Process finishQ[MAX];

int size, wk_end, wk_front, cp_end, cp_front;
bool vul = false;

int main(){


	//step1 read a file as input 
	// a file contains: num of ps + each burst time 
	// init a ps_num with num
	int ps_num; 
	cin >> ps_num;
	if(pass ==1){cout<<"ps_num good"<< endl;}
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

	if( pass ==1){
		for(int i=0; i< ps_num; i++){
			cout << workingQ[i].brst_t << "\t" ;
		} 
		cout<< endl<<"working q good"<< endl;}

	wk_end = ps_num-1;

	// done with step 1 
	// test updateQ 
	if( pass ==1){
		for(int i= wk_front; i<=wk_end; i++){
			cout << workingQ[i].brst_t << '\t';
		} 
		cout<<endl;
		updateQ();
		for(int i= wk_front; i<=wk_end; i++){
			cout << workingQ[i].brst_t << '\t';
		}
		cout<<endl;
		updateQ();
		for(int i= wk_front; i<=wk_end; i++){
			cout << workingQ[i].brst_t << '\t';
		}

		cout<<endl;
		cout<<"updateQ() good"<< endl;}


	// testing move to finish  
	// little issue with cp_end adj
	if( pass ==1){
		move_to_finish();
		cout<< "workingQ:"<< endl;
		for(int i= wk_front; i<=wk_end; i++){
			cout << workingQ[i].brst_t << '\t';
		}
		cout<< endl;
		cout<< "finishQ:"<< endl;
		for(int i= cp_front; i<=cp_end; i++){
			cout << finishQ[i].brst_t << '\t';
		}
		cout<< endl;
	}


	// testing cpu
	if( pass ==1){
		cout << "wk front:" << wk_front<< endl;
		cout << "wk end :" << wk_end<< endl;

		int t = Q;		
		cpu(&t);
		for(int i= wk_front; i<=wk_end; i++){
			print(workingQ[i]);
		}

		cout << "wk front:" << wk_front<< endl;
		cout << "wk end :" << wk_end<< endl;
		cout << "timer left:" << t << endl;


	}

	// test rrobin()

	if( pass==1){
		cout << "size : "<< size << endl; 

		cout << "workingQ before rrobin: "<< endl; 
		for(int i= wk_front; i<=wk_end; i++){
			print(workingQ[i]);
		}
		rrobin();
		cout << "workingQ after rrobin: "<< endl; 
		for(int i= wk_front; i<=wk_end; i++){
			print(workingQ[i]);
		}

		cout << "finishQ after rrobin: "<< endl; 
		for(int i= cp_front; i<=cp_end; i++){
			print(finishQ[i]);
		}



	}

	//step3 report the result 
	cout << "ps start in oder: "<< endl;
	print_header();
	for(int i=wk_front; i <=wk_end; i++){
		print(workingQ[i]);
	}

	rrobin();
	double total_wait = 0;
	for(int i=0; i < cp_end; i++){
		total_wait+=finishQ[i].wait_t;
	}
	cout << "average wait time: "<< total_wait/(double) ps_num << endl; 

	cout << "ps finsihed in oder: "<< endl;
	print_header();
	for(int i=0; i < cp_end; i++){
		print(finishQ[i]);
	}
	return 0;
}




void updateQ(){
	workingQ[++wk_end] = workingQ[wk_front++];

}
void rrobin(){
	// while the wokringQ still have ps the scheduler continues
	while( size > 0  ) {
		// set timer for each burst 
		int timer = Q; 
		while(timer > 0){
			// when still have timer left, let cpu working with the front of the queue 

			if( pass==1){
				cout << "size:" << size << " timer:" << timer << " front:";
				for(int i= wk_front; i<=wk_end; i++){
					print(workingQ[i]);
				}
				cout << endl;
			}
			cpu(&timer);
			if(size <=0){break;}
		}
	}
}
// cpu only work with the wk_front of the working Q 
// cpu will remove wk_front it to finish if its rmnd_t is zero 
void cpu(int* t){
	// update wait time for all ps 
	// wether *t is 0 or not, 
	// cpu have worked Q-*t by now 
	// then work with the front 
	// this must occured after t updated but before workingQ order changed 
	Process run = workingQ[wk_front];	
	if(run.rmnd_t == *t){
		for(int i = wk_front+1;i<=wk_end;i++){
			workingQ[i].wait_t+=(min(run.rmnd_t, *t));
		}
		// use all the time and 
		// run finished 
		// set timer to zero
		// mv the cur to finshQ 
		// mv_to_fin automatically update wk_front, cp_end, and size 
		run.rmnd_t -= *t;
		run.cmpt_t += *t;
		*t = 0;
		workingQ[wk_front] = run;



		if( pass ==1){print(workingQ[wk_front]);}
		move_to_finish();
	}
	else if(run.rmnd_t < *t){

		for(int i = wk_front+1;i<=wk_end;i++){
			//
			workingQ[i].wait_t+=(min(run.rmnd_t, *t));
		}


		// not used up all the time 
		// run finshed, 
		// reduce timer
		// update wk_front mv to cpQ
		// mv_to_fin automatically update wk_front, cp_end, and size 
		*t -=run.rmnd_t;
		run.cmpt_t += run.rmnd_t;
		run.rmnd_t=0;
		workingQ[wk_front] = run;

		vul=true;
		move_to_finish();
	}
	else{

		// update wait time for the rest ps 
		for(int i = wk_front+1;i<=wk_end;i++){
			//
			workingQ[i].wait_t+=(min(run.rmnd_t, *t));
		}

		// update cur ps 
		// used all the time 
		// run will not be finshed 
		// set timer to zero
		// call updateQ() to update wkfornt and wk_end
		run.cmpt_t += *t;
		run.rmnd_t -= *t;
		*t = 0;

		workingQ[wk_front] = run;
		/* can not make update wait time compressed, must repeat 3 times in each case */
		// allow vulentary giveup time 
		if(vul==false){
			updateQ();
		}
		else{
			vul=false;
		}
	}
	// not used all the time and not finsihed case does not exist 
}

void move_to_finish(){
	// moving current wk_front into cp_end
	// update wk_front+=1
	// size--
	if(size <=0){
		cout << "move_to_fin : error" << endl;
		exit(1);
	}
	finishQ[cp_end++]=workingQ[wk_front++];
	size--;
}


void print(Process p){
	cout << "{" << '\t' ;
	cout << p.brst_t << "    "; 
	cout << p.cmpt_t << "    "; 
	cout << p.rmnd_t << "       "; 
	cout << p.wait_t << "   "; 
	cout << "}" << endl;


}

void print_header(){
	cout << "{" << '\t' ;
	cout << "burst" << " "; 
	cout << "run"   << " "; 
	cout << "remind"<< " "; 
	cout << "wait " << " "; 
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
