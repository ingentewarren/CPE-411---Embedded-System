#include<iostream>

using namespace std;

int main(){
		
  int burst[6] = {5,3,8,6,4,7};
  int turn_around[6];
  int sum;
  int wait[6];
  int pid=6;
  int temp,count;
  
  float ave_waitingtime=0.00,ave_servicetime=0.00;
  
  
  for(int i=0;i<pid;i++)
  {
  	for(int j=0;j<pid;j++){
  		if(burst[i]<burst[j])
  		{
	        temp=burst[i];
  		    burst[i]=burst[j];
  		    burst[j]=temp;
  		}
 	}
  }
  
  //in this loop add the each element of execute time and store it to service time
    for(int i=0;i<pid;i++)
    {
    	wait[i]=sum;
    	sum=sum+burst[i];
    	turn_around[i]=sum;
    	
    }
    sum=0;
  

  
   	cout << "execute time:\twait time:    service time:"<< endl;
    for(int i=0;i<pid;i++)
    {
        cout<<"\t"<<burst[i]<<"\t    "<<burst[i]<<"\t      "<<burst[i]<<endl;
    }
    
    
	int sum1 = 0;
	int sum2 = 0;
	//add all elements of waiting time
	for(int i=0;i<pid;i++){
		sum1 = sum1 + wait[i];
		sum2 = sum2 + turn_around[i];
		
	}
	
	cout<<"Sum of all waiting time: "<<sum1<<endl;
	cout<<"Sum of all service time: "<<sum2<<endl;
	
	ave_waitingtime=(float)sum1/(float)pid;
	ave_servicetime=(float)sum2/(float)pid;
	cout<<"\nAverage of waiting time: "<<ave_waitingtime<<endl;
	cout<<"\nAverage of service time: "<<ave_servicetime<<endl;
	
	
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
