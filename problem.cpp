#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;


static int maze[1000][1000];

int main () {
  cout<<"Enter the size of the matrix: "<<endl;
  long SIZE;
  cin>>SIZE;
  ofstream myfile ("matrix.txt");
  if (myfile.is_open())
  {
	srand (time(NULL));
        for (long long j=0;j<SIZE;j++){
            for(long long k=0;k<SIZE;k++){
               if(rand() % 100 < 20){
                maze[j][k] = 1;
            }
            else{
                maze[j][k] = 0;
            }
            }
        }
	/*
	for (long long j=0;j<SIZE;j++){ 
		myfile<<endl;
            for(long long k=0;k<SIZE;k++){
                myfile<<setw(3)<<maze[j][k];
            }

        }
    	*/

	myfile << endl<<endl<<"Problem:"<<endl<<SIZE<<endl;
	for (long long j=0;j<SIZE;j++){
            for(long long k=0;k<SIZE;k++){
                myfile<<maze[j][k]<<endl;
            }

        }
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
