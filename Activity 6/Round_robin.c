// C++ code
//
/*
  Warren L. Ingente
  BSCpE 4B
  
  Activity 6 - Embedded Operating System
*/

//Round Robin - Scheduling Algorithm

/*

arrival time:   burst time:      turn around time:      waiting time:
   1            5               16                       11
   2            3               4                        1
   3            8               25                       17
   4            6               19                       13
   5            10              27                       17
   6            15              -1                       -16
sorted turn around time:
-1
4
16
19
25
27

average turn around time: 15

average waiting time: 7

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
  
	int p=6,quantom,temp,count,sum=0,sum1=0,n=0;
	int arrival[6]={1,2,3,4,5,6};
	int burst[6]={5,3,8,6,10,15};
	int rem[6];
	int turn_around[6];
	int wait[6];
	float ave_wait=0.0,ave_turn=0.0;
	
	for(int i=0;i<p;i++){
		rem[i]=burst[i];
		for(int j=0;j<p;j++){
			if(arrival[i]<arrival[j]){
				temp=burst[i];
				burst[i]=burst[j];
				burst[j]=temp;
				
				temp=rem[i];
				rem[i]=rem[j];
				rem[j]=temp;
				
				temp = arrival[i];
				arrival[i]=arrival[j];
				arrival[j]=temp;
				
			}
		}
	}
	
	quantom=3; //i just inputing value for quantom
  for(int i=0;i<6;i++){
  count=0;
		for(int i=0;i<p;i++){
			temp=quantom;
			if(rem[i]==0){
				count++;
				continue;
			}
			
			if(rem[i]>quantom){
				rem[i]=rem[i]-quantom;
			}
			else{
				if(rem[i]>=0){
					temp=rem[i];
					rem[i]=0;
				}
			}
            n += temp;
			turn_around[i] = n-arrival[i];
		}
    if(count==p){
      break;
    }
  }
	
	for(int i=0;i<p;i++){
		sum += turn_around[i];
		wait[i] = turn_around[i]-burst[i];
		sum1+=wait[i];
		
	}
	
	ave_turn=sum/p; //average value of turn around time
	ave_wait=sum1/p; //average value of waiting time
	
	
	for(int i=0;i<p;i++){
		for(int j=0;j<p;j++){
			if(turn_around[i]<turn_around[j]){
				temp=turn_around[i];
				turn_around[i]=turn_around[j];
				turn_around[j]=temp;
			}
		}
	}
  
  
  
  
    int p0=turn_around[0];
    int p1=turn_around[1];
    int p2=turn_around[2];
    int p3=turn_around[3];
    int p4=turn_around[4];
    int p5=turn_around[5];
	
  
  	//sorting turn around time
	if (p0 > p1)
        swap(p0, p1);
        
	if (p0 > p2)
        swap(p0, p2);
	
	if (p0 > p3)
        swap(p0, p3);
        
    if (p0 > p4)
        swap(p0, p4);
		
	if (p0 > p5)
        swap(p0, p5);
		
	if (p1 > p2)
        swap(p1, p2);
		
	if (p1 > p3)
        swap(p1, p3);
		
	if (p1 > p4)
        swap(p1, p4);
		
	if (p1 > p5)
        swap(p1, p5);
	
	if (p2 > p3)
        swap(p2, p3);
		
	if (p2 > p4)
        swap(p2, p4);
		
	if (p2 > p5)
        swap(p2, p5);
		
	if (p3 > p4)
        swap(p3, p4);
        
    if (p3 > p5)
        swap(p3, p5);
		
	if (p4 > p5)
        swap(p4, p5);
  
 
  
  /*Each led represent as Process ID. 
  The led will blink every second*/

  int s0=sum-p4-p3-p2-p5-p1-p0;
  digitalWrite(13, HIGH);
  delay(s0*1000);
  digitalWrite(13, LOW);
  
  int s1=sum-(p4+p3+p2+p5+p0-s0);
  digitalWrite(12, HIGH);
  delay(s1*1000);
  digitalWrite(12, LOW);

  int s2=sum-(p4-p3-p5-p1-p0-s1-1);
  digitalWrite(11, HIGH);
  delay(s2*1000);
  digitalWrite(11, LOW);
  
  int s3=sum-(p5-p4-p2-p1-p0-s2+2);
  digitalWrite(10, HIGH);
  delay(s3*1000);
  digitalWrite(10, LOW);
  
  int s4=s3+2;
  digitalWrite(9, HIGH);
  delay(s4*1000);
  digitalWrite(9, LOW);
  
  int s5=s4+1;
  digitalWrite(8, HIGH);
  delay(s5*1000);
  digitalWrite(8, LOW);
  
}

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
