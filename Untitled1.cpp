#include<iostream>
using namespace std;

int circles(float p,float a,float b,float k[]){
	float power = p;
	float temp;
	for(int i=0;i<11;i++){
		temp=k[i];
		if(p<k[i] && a>0){
			temp=0;
			a--;
		}
		else if(p<k[i] && b>0){
			p=power;
			b--;
		}
		if(i==2 || i==6){
			k[i+1]=k[i+1]+k[i]/2;
		}
		
		cout<<"Inner circle :"<<i+1<<endl;
		cout<<"Enemy power k[i] :"<<k[i]<<endl;
		cout<<"Abhimanyu power before p :"<<p<<endl;
		cout<<"Skip power a :"<<a<<endl;
		cout<<"Recharge power b :"<<b<<endl;
		p=p-temp;
		cout<<"Abhimanyu power after fight p :"<<p<<endl<<endl;
		temp=0;
		
		if(p<0){
			cout<<"Abhimanyu lost at circle : "<<i+1;
			return -1;
		}
	}
	
	return p;
}

int main(){
	float abhimanyu_power;
	float skip;
	float power_recharge;
	float enemy_power[11]={10,20,30,40,50,60,70,80,90,100,110};
	
	cout<<"Enter Abhimanyu power p :";
	cin>>abhimanyu_power;
	cout<<"Enter Abhimanyu skip power a :";
	cin>>skip;
	cout<<"Enter Abhimanyu recharge power b :";
	cin>>power_recharge;
	cout<<endl;
	
	int isWon = circles(abhimanyu_power,skip,power_recharge,enemy_power);
	
	if(isWon>0){
		cout<<"Abhimanyu won the fight ";
	}
	
	return 0;
}
