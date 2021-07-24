#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
int MCB;

//function to check current state 
	int check(){
	char *filename = "State.txt";
	FILE *fp = fopen(filename, "r");
	int i =0, k=0;
	int x;
	std::string Message[9] ={"An kesici devrenin TCU ile yapılandırılması mümkün değil.", "APU sigortası atık.", "TCU Ana devre kesiciyi çözdü", "Kumanda anahtarı 'ON' konumunda değil","Ana trafo basıncı yüksek.", "Pantograf aşağıda.", "Hat gerilimi sınırların dışında", "Acil durdurma uygulandı.",  "Ana trafo gaz basıncı 2. seviyede."};
	
	
	if(fp == NULL){
	printf("Error: could not open the state file ");
	fclose(fp);
	return -2;
	}
 
	const unsigned MAX_LENGTH =256;
	char buffer[MAX_LENGTH];

	while(fgets(buffer,MAX_LENGTH, fp)){
	sscanf(buffer, "%d", &x)<1;
	k+= x;
	if(x<1){
	cout<<Message[i]<<endl;
	MCB =-1;}
	i++;
	
	} if(k==9 & MCB==-1){
	MCB=0;}

	k=0;
	fclose(fp);
	return 0;

	}

int main(){
string command;
while(cin>>command){
if(command == "exit")
	break;
check();
if(command == "çöz"){
	if(MCB==-1)cout<<"MCB çözük ve arızalı"<<endl;
	if(MCB== 0)cout<<"MCB çözük durumda"<<endl;
	if(MCB== 1){ MCB =0;cout<<"MCB çözüldü."<<endl;}
}
	
if(command == "kapat"){
	if(MCB==-1)cout<<"MCB çözük ve arızalı"<<endl;
	if(MCB== 1)cout<<"MCB kapalı durumda"<<endl;
	if(MCB== 0){ MCB =1; cout<<"MCB kapandı."<<endl;}

}

}


return 0;
}
