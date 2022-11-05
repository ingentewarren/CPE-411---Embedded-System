#include<iostream>

using namespace std;

int main(){
	
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
	
	/*
	quantom=3; //i just inputing value for quantom
	while(true){
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
		if(p==count){
			break;
		}
	}
	*/
	
		quantom=3; //i just inputing value for quantom
  for(int j=0;j<6;j++){
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
  }
	
	for(int i=0;i<p;i++){
		sum += turn_around[i];
		wait[i] = turn_around[i]-burst[i];
		sum1+=wait[i];
		
	}
	
	ave_turn=sum/p;
	ave_wait=sum1/p;
	
	cout<<"\narrival time: \tburst time: \t turn around time: \twaiting time: "<<endl;
	for(int i=0;i<p;i++){
		cout<<"   "<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<turn_around[i]<<"\t\t\t "<<wait[i]<<endl; 
		
	}
	
	for(int i=0;i<p;i++){
		for(int j=0;j<p;j++){
			if(turn_around[i]<turn_around[j]){
				temp=turn_around[i];
				turn_around[i]=turn_around[j];
				turn_around[j]=temp;
			}
		}
	}
	
	cout<<"sorted turn around time: "<<endl;
	for(int i=0;i<p;i++){
		cout<<turn_around[i]<<endl;
	}
	
	int p0=0;
	int p1=0;
	int p2=0;
	int p3=0;
	int p4=0;
	int p5=0;
  
    p0=p0+turn_around[0];
    p1=p1+turn_around[1];
    p2=p2+turn_around[2];
    p3=p3+turn_around[3];
    p4=p4+turn_around[4];
    p5=p5+turn_around[5];
	
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
        
	
	/*
	//sotring
	if (p0 > p1)
        std::swap(p0, p1);
        
	if (p0 > p2)
        std::swap(p0, p2);
	
	if (p0 > p3)
        std::swap(p0, p3);
        
    if (p0 > p4)
        std::swap(p0, p4);
		
	if (p0 > p5)
        std::swap(p0, p5);
		
	if (p1 > p2)
        std::swap(p1, p2);
		
	if (p1 > p3)
        std::swap(p1, p3);
		
	if (p1 > p4)
        std::swap(p1, p4);
		
	if (p1 > p5)
        std::swap(p1, p5);
	
	if (p2 > p3)
        std::swap(p2, p3);
		
	if (p2 > p4)
        std::swap(p2, p4);
		
	if (p2 > p5)
        std::swap(p2, p5);
		
	if (p3 > p4)
        std::swap(p3, p4);
        
    if (p3 > p5)
        std::swap(p3, p5);
		
	if (p4 > p5)
        std::swap(p4, p5);*/
		  
		  
	
/*	cout<<p0<<endl;
	cout<<p1-p0<<endl;
	cout<<p2-p1<<endl;
	cout<<p3-p2<<endl;
	cout<<p4-p3<<endl;
	cout<<p5-p4<<endl;
	
	*/
	
	cout<<"\naverage turn around time: "<<ave_turn<<endl;
	cout<<"\naverage waiting time: "<<ave_wait<<endl; 
	
	int a5=sum-p4-p3-p2-p1-p0;
	int s1=sum-p4-p3-p2-p5-p0;
	int s2=sum-p4-p3-p1-p5-p0;
	int s4=sum-p2-p3-p1-p5-p0;
	cout<<"p0 = "<<a5<<endl;
	cout<<"p1 = "<<s1<<endl;
	cout<<"p2 = "<<s2<<endl;
	cout<<"p5 = "<<s4<<endl;
	
	return 0;
}

void swap(int a, int b) {
  int c = a;
  a = b;
  b = c;
}
