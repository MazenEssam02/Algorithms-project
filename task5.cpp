#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;
int min_no_of_moves=0;

void initialize(int n){
    for(int i=0; i<n; i++){
      coins.push_back(1);
    }
}


int find_right_most_single_coin (int x){
for(int k=x ; k >=0; k--){
if (coins[k]==1)
{
    return k;
}
}
return -1; // cannot find the right most single coin with n coins
}

void jump(int from ,int to){
coins[from]=0;
coins[to]= 2;
min_no_of_moves++;
}

int count_empty_space_from_right_to_left(int z){
int count_empty_space =0;

for(int j=z-1 ; j >=0; j-- ){

if(coins[j]==0){
    count_empty_space++;
}

}
return count_empty_space;
}

int main()
{
  int n ;
  cout <<"enter n coins placed in a row ";
  cin>>n;

  if(n%4 !=0){
    cout <<"cannot solve the task the number of coins must be divisible by 4";
  }
  else{

    initialize(n);

    for(int i =0 ;i < n/4 -1; i++){

        int right_most_single_coin=find_right_most_single_coin (n-(i+1));
        if(right_most_single_coin!=-1){
            jump((right_most_single_coin-i-2-count_empty_space_from_right_to_left(right_most_single_coin)),right_most_single_coin);
        }

    }
    for(int s = n/4 -1 ; s< n/2 ;s++  ){

        int left_most_single_coin = s-(n/4 -1) ;
    if (left_most_single_coin!=-1){
        int count_no_of_moves=0;
        int sum=0 ;
        for(int l=left_most_single_coin+1 ; l < n ; l++)
        {
            if(sum+coins[l] <= s+1){
                sum =sum + coins[l];
                count_no_of_moves++;
            }
            else{
                break;
            }
        }

        jump(left_most_single_coin, left_most_single_coin+count_no_of_moves+1);
    }
    }
    cout <<"the final array \n";
    cout<< "[ ";
    for(int v=0 ; v< n ; v++){
        cout <<coins[v];
    }
    cout << " ]\n";
    cout <<"with min number of moves ";
    cout << min_no_of_moves;
  }

}
