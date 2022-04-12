#include <bits/stdc++.h>

using namespace std;

int played[5][5], score[5], t, g, remain, cnt=0, A, B, a, b;

bool checkWin() {
    for(int i = 1; i <= 4; i++)
        if(i!=t && score[t]<=score[i]) return false;
    return true;
}

void findPossibleWays(){
    int backup[5][5];
    if(remain==0){
        if(checkWin()) cnt++;
    }
    else{
        memcpy(backup, played, sizeof(played));
        for(int x = 1; x <= 4; x++)
            for(int y = x+1; y <= 4; y++) {
                if(played[x][y]) continue;
                
                played[x][y] = played[y][x] =1;
                --remain;
                for(int p = 1; p <= 3; p++) {
                    if(p == 1){ //win
                        score[x]+=3;
                        findPossibleWays();
                        score[x]-=3;
                    }
                    else if(p == 2){ //lose
                        score[y]+=3;
                        findPossibleWays();
                        score[y]-=3;
                    }
                    else{ //tie
                        score[x]+=1; score[y]+=1;
                        findPossibleWays();
                        score[x]-=1; score[y]-=1;
                    }
                }
                ++remain;
            }
        memcpy(played, backup, sizeof(played));
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    cin >> t >> g;
    remain = 6 - g;
    for(int i = 0; i < g; i++){
        cin >> A >> B >> a >> b;
        played[A][B] = played[B][A] = 1;
        
        if(a>b) score[A]+=3;
        else if (a<b) score[B]+=3;
        else {score[A]+=1; score[B]+=1;}
    }
    findPossibleWays();
  
    cout << cnt << endl;
    return 0;
}
