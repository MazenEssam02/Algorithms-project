#include<iostream>
#include <time.h>
using namespace std;

// initialize the boxes with known weight w
void intialization(int arr[50][50],int b,int n,int w){
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if((i+1)==b){           // in case of the fake box
           arr[i][j]=w-1;
        }else{               // in case of real boxes
           arr[i][j]=w;
        }
    }
}
}

int main(){
int n;
int w=5;
cout<<"Enter number of boxes (1:50) "<<endl;
cin>>n;

// Get the number of the box randomly each time /////////
srand(time(0));              //change seed according to time
int b=(rand()%n)+1;        // get the number of the box contain fake metal randomly from(1 to 50)
////////////////////////////////////////////////////////
//cout<<"the number of the box before the code: "<<b<<endl<<endl;

int arr[50][50];
float sum=0;
float optimal_weight =((n*(n+1))/2*w);

// filling the boxes with metals
intialization(arr,b,n,w);

//taking number of metals from each box according to its number
for(int i=0;i<n;i++){
        sum+=(i+1)*arr[i][0];
    }

// get the number of the box by taking module to sum
cout<<"The box having the fake metal is "<<(optimal_weight-sum);

}




