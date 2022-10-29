//Warren L. Ingente BSCPE 4B

#include<iostream>
#include<string.h>

using namespace std;

class Crc{
	private:
		string input,divisor,divident,result;
		string temp_div;
		string temp_divident;
		
		int lDivident,lGen,linp;
		
	public:
		void data();
		void sender();
		void receiver();
		void module_div();
		
		string xor_div(string a, string b){
			string result = "";
			if(a[0]=='0'){
				return a.substr(1);
			}
			else{
				for(int i=0;i<lGen;i++){
					result = result+(a[i]==b[i] ? '0':'1');
				}
				return result.substr(1);
			}
		}
};


void Crc::module_div(){
	int j;
	
	temp_div = divisor;
	temp_divident=divident.substr(0,lGen);
	
	j=lGen;
	while(j<lDivident){
		temp_divident = xor_div(temp_divident,temp_div);
		temp_divident = temp_divident+divident[j];
		j++;
	}
	
	result = input+xor_div(temp_divident,temp_div);
}

void Crc::data(){
	
	int r;
	cout<<"INPUT: ";
	cin>>input;
	cout<<"GENERATOR: ";
	cin>>divisor;
	
	lGen=divisor.length();
	linp=input.length();
	divident=input;
	r=lGen-1;
	
	for(int i=0;i<r;i++){
		divident=divident+'0';
	}
	lDivident=divident.length();
	
	module_div();

}

void Crc::sender(){
	cout<<"Input bits: "<<input<<"\n";
	cout<<"Polynomial: "<<divisor<<"\n";
	cout<<"Divident: "<<divident<<"\n";
	cout<<"Sended data: "<<result<<"\n";
}

void Crc::receiver(){
	string receive_data,error;
	int j;
	bool flag=false;
	
	cout<<"\nInput Data Received: ";
	cin>>receive_data;
	
	temp_div=divisor;
	temp_divident=receive_data.substr(0,lGen);
	j=lGen;
	
	while(j<receive_data.length()){
		temp_divident=xor_div(temp_divident,temp_div);
		temp_divident=temp_divident+receive_data[j];
		j++;
	}
	
	error=xor_div(temp_divident,temp_div);
	
	cout<<"remainder is: "<<error;
	for(int i=0;i<lGen-1;i++){
		if(error[i]=='1'){
			flag=true;
			break;
		}
	}
	
	if(flag==false){
		cout<<"\nData Received without Error";
	}
	else{
		cout<<"\nData Received with some Error";
	}

}


int main(){
	
	Crc results;
	
	results.data();
	results.sender();
	results.receiver();
	return 0;
}
