#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,limit;
  cin >> a>>b>>c>>d>>limit;
  int Nikky = 0;
  int Byron = 0;
  int C = 0;
  int C1 = 0;
  int C2 = 0;
  while (C < limit){
    C1 = int(C/(a+b));
    C2 = int(C/(c+d));
    int S1 = C-(C1*(a+b));
    int S2 = C - (C2*(c+d));
    if (S1 < a){
      Nikky+=1;
    }
    else{
      Nikky-=1;
    }
    if (S2 < c){
      Byron +=1;
    }
    else{
      Byron -=1;
    }
    C+=1;
  }
  
  if (Nikky > Byron)
    cout << "Nikky";
  else if (Nikky < Byron)
    cout << "Byron";
  else
    cout << "Tied";
}
