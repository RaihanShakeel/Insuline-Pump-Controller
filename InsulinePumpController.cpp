#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;
bool Button;
int insuline = 100;


//The Logic Method is used to start and quit the program
void Logic(){
	if(_kbhit){
		switch(_getch()){
			case 's':
				Button = false;
				break;			
		}	
	}
	
}

void sugarLevel(){	
	time_t tt; //Declaring arguement for time function
	
	struct tm * ti; //Declaring variable to store the returned value from localtime() function
	
	time(&tt); //This function apply the time 
	
	ti = localtime(&tt); //This function is used to return the localtime
	
	int randomNumber; // variable randomNumber is used to store the returned value from rand() function
	srand(time(0));
	randomNumber = rand() % 6;
	
	if(randomNumber<=1){
		
		cout<<"Sugar Level is Low take some sugar" << endl;
		cout << endl;
	}
	else if (randomNumber == 2){
		cout <<"Congratulation your sugar level is normal" << endl;
		cout << endl;
	}
	else if (randomNumber == 3 ){
		insuline = insuline - 3;
		cout << "Your sugar level was at 200 on " << asctime(ti) <<"and 3 ml insoline was injected" <<endl;
		cout << endl;
	}
	else if(randomNumber == 4){
		insuline = insuline - 8;
		cout << "Your sugar level was at 300 on " << asctime(ti) << "and 8 ml insuline was injected " << endl;
		cout << endl;
	}
		else if (randomNumber == 5){
			insuline = insuline - 12;
			cout << "Your sugar level was at 400 on " << asctime(ti) << "and 12 ml insuline was injected"<<endl;
			cout << endl;		
	}
	
	
	Sleep(5000);
	
	if(insuline > 0){
		sugarLevel();
	}
	else{
		cout << "Insufficient insuline level please refill your insuline pump ";
		Button = true;
	}
}
int main(int argc, char** argv) {
	cout <<"press 's' to start: " << endl;
	cout << endl;
	
	Logic();
	while(!Button){	
		sugarLevel();
		}
	}
