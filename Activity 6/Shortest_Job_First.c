// C++ code
//
/*
  Warren L. Ingente
  BSCpE 4B
  
  Activity 6 - Embedded Operating System
*/

//Shortest Job First (SJF) - Scheduling Algorithm

/* 
execute time:   wait time:    service time:
        3           0         3
        4           3         7
        5           7         12
        6           12        18
        7           18        25
        8           25        33
Sum of all waiting time: 65
Sum of all service time: 98

Average of waiting time: 10.8333
Average of service time: 16.3333

the led will lights up in the following
	3
	4
	5
	6
	7
	8

*/

void setup()
{
  pinMode(13, OUTPUT); //This led = P0
  pinMode(12, OUTPUT); //This led = P1
  pinMode(11, OUTPUT); //This led = P2
  pinMode(10, OUTPUT); //This led = P3
  pinMode(9, OUTPUT);  //This led = P4
  pinMode(8, OUTPUT);  //This led = P5
}

void loop()
{
  
  //i just put a value of arrival time and execute time 
  int burst[6] = {5,3,8,6,4,7};
  int turn_around[6];
  int sum;
  int wait[6];
  int pid=6;
  int temp,count;
  
  
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
  int sum1=0;
  int sum2=0;
  float ave_wait,ave_turnaround;
  	//sum of all waiting time ang service time
  	for(int i=0;i<pid;i++){
		sum1 = sum1 + wait[i]; //The sum of waiting time is 65
		sum2 = sum2 + turn_around[i]; //The sum of service time is 98
		
	}
	
	//The average waiting time is 10.833
  	//and average service time is 16.333
	ave_wait=(float)sum1/(float)pid;
	ave_turnaround=(float)sum2/(float)pid;

  
  /*Each led represent as Process ID. The led will blink every second*/
  int p0=turn_around[0];
  digitalWrite(13, HIGH);
  delay(p0*1000);//p0 = element value of servie time[0]
  digitalWrite(13, LOW);
  

  int p1=turn_around[1]-p0;
  digitalWrite(12, HIGH);
  delay(p1*1000);//p1 = element value of servie time[1]
  digitalWrite(12, LOW);

  int p2=turn_around[2]-(p1+p0);
  digitalWrite(11, HIGH);
  delay(p2*1000);//p2 = element value of servie time[2]
  digitalWrite(11, LOW);
  
  int p3=turn_around[3]-(p0+p1+p2);
  digitalWrite(10, HIGH);
  delay(p3*1000);//p3 = element value of servie time[3]
  digitalWrite(10, LOW);
  
  int p4=turn_around[4]-(p0+p1+p2+p3);
  digitalWrite(9, HIGH);
  delay(p4*1000);//p4 = element value of servie time[4]
  digitalWrite(9, LOW);
  
  int p5=turn_around[5]-(p0+p1+p2+p3+p4);
  digitalWrite(8, HIGH);
  delay(p5*1000);//p5 = element value of servie time[5]
  digitalWrite(8, LOW);
  
}


