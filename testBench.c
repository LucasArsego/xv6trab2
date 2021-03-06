#include "types.h"
#include "user.h"

#define STDOUT 1			// Nomenclature used by xv6 for outputs
#define CHILDS 8			// Number of thread to be created on test
#define QUANTUM 112345678		// 10^8 = Time of thread execution


// Execution time of process:
void quantumLoop(){
	int i;
	i = QUANTUM;
	while(i--){
	}
	i = QUANTUM;
	while(i--){
	}
}

int randstate=1;
int random(){
  randstate = randstate * 1664525 + 1013904223;
  if(randstate<0){
    return (randstate*-1);
  }
   return randstate;
 }
// Instanciation of multiple process to test:
int main(){
	int pid;
	int i;
	for(i = 0; i < CHILDS; i++){
		pid= fork((random()%CHILDS)*40);
		if(pid == 0){
        quantumLoop();
    		exit();
		}
	}

	// Waits for process end and print his informations:
	for(;;){
		  pid = wait();
     	if(pid<0)break;
     	printf(STDOUT,"Child %d finished\n",pid );
	}
	exit();
}
