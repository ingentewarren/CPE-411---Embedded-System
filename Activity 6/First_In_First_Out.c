// C++ code
//
/*
  Warren L. Ingente
  BSCpE 4B
  
  Activity 6 - Embedded Operating System
*/

//First In First Out (FIFO) - Scheduling Algorithm

/*

arrival time:   execute time:   service time:
1               5                5
2               3                8
3               8                16
4               6                22
5               10               32
6               15               47

Sum of all waiting time: 109
Average of waiting time: 18
5
3
8
6
10
15

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
  	burst[i]= turn_around[i]-arrival[i];
  }
  
  int sum1=0;
  //add all elements of waiting time
	for(int i=0;i<pid;i++){
		 sum1 = sum1 + wait[i]; 
	}
	
	//The sum of all waiting time = 89
  	//The average of waiting time = 14.833
	int ave_waitingtime=(float)sum1/(float)pid;
  
  /*Each led represent as Process ID. The led will blink every second*/
  int p0=turn_around[0];
  digitalWrite(13, HIGH);
  delay(p0*1000);//p0 = element value of turn around time[0]
  digitalWrite(13, LOW);
  

  int p1=turn_around[1]-p0;
  digitalWrite(12, HIGH);
  delay(p1*1000);//p1 = element value of turn around time[1]
  digitalWrite(12, LOW);

  int p2=turn_around[2]-(p1+p0);
  digitalWrite(11, HIGH);
  delay(p2*1000);//p2 = element value of turn around time[2]
  digitalWrite(11, LOW);
  
  int p3=turn_around[3]-(p0+p1+p2);
  digitalWrite(10, HIGH);
  delay(p3*1000);//p3 = element value of turn around time[3]
  digitalWrite(10, LOW);
  
  int p4=turn_around[4]-(p0+p1+p2+p3);
  digitalWrite(9, HIGH);
  delay(p4*1000);//p4 = element value of turn around time[4]
  digitalWrite(9, LOW);
  
  int p5=turn_around[5]-(p0+p1+p2+p3+p4);
  digitalWrite(8, HIGH);
  delay(p5*1000);//p5 = element value of turn around time[5]
  digitalWrite(8, LOW);
  
}


