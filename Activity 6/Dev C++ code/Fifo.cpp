#include<iostream>

using namespace std;

int main(){
	
  int arrival[6] = {1,2,3,4,5,6};
  int burst[6] = {5,3,8,6,10,15};
  int turn_around[6];
  int sum;
  int wait[6];
  int pid=6;
  int temp,count;
  
  
  //in this loop add the each element of execute time and store it to service time
    for(int i=0;i<pid;i++)
    {
  	    sum = sum+burst[i];
  	    turn_around[i]=sum;
  	
    }
    sum=0;
  
  
  //to get the waiting time, subtract the service time and arrival time
      for(int i=0;i<pid;i++){
  	wait[i]= turn_around[i]-arrival[i];
  }

  
   	cout << "arrival time:\texecute time:\tservice time:"<< endl;
    for(int i=0;i<pid;i++)
    {
        cout << arrival[i] <<"\t        "<<burst[i]<<"\t         "<<turn_around[i]<<endl;
    }
    
    cout << "service time - arivval time: = \twaiting time:"<< endl;
    for(int i=0;i<pid;i++)
    {
        cout << turn_around[i] <<"\t     -  "<<arrival[i]<<"\t         "<<wait[i]<<endl;
    }
    
	
	int sum1=0;
	
	//add all elements of waiting time
	for(int i=0;i<pid;i++){
		sum1 = sum1 + wait[i];
	}
	
	cout<<"Sum of all waiting time: "<<sum1;
	
	int ave_waitingtime=(float)sum1/(float)pid;
	cout<<"\nAverage of waiting time: "<<ave_waitingtime<<endl;
	
	int p=turn_around[0];
	int p1=turn_around[1];
	int p2=turn_around[2];
	int p3=turn_around[3];
	int p4=turn_around[4];
	int p5=turn_around[5];
	
	cout<<p<<endl;
	cout<<p1-p<<endl;
	cout<<p2-p1<<endl;
	cout<<p3-p2<<endl;
	cout<<p4-p3<<endl;
	cout<<p5-p4<<endl;
	
	return 0;
}
