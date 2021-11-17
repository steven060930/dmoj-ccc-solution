#include "bits/stdc++.h"
using namespace std;

pair<string, string> ROME_TO_INT(string s) {
    string rome1, rome2;
    for (int i=0; i<(int)(s.size()); ++i) {
        if (s[i] == '+') {
            rome1 = s.substr(0, i);
            for (int j=i+1; j < (int)(s.size()); ++j) {
                if (s[j] == '=') {
                    rome2 = s.substr(i+1, j-i-1);
                }
            }
        }
    }
    return make_pair(rome1, rome2);
}

int convert(string s) {
    int ans=0;
    for (unsigned short i = 0; i< s.size();i++){
        switch (s[i]){
            case 'I':
                if (s[i+1]=='V') ans--;
                else if (s[i+1]=='X') ans--;
                else ans++;
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (s[i+1]== 'L') ans-=10;
                else if (s[i+1]=='C') ans-=10;
                else ans += 10;
                break;
            case 'L': ans += 50;
                break;
            case 'C':
                if (s[i+1]=='D') ans-=100;
                else if (s[i+1]=='M') ans-=100;
                else ans += 100;
                break;
            case 'D': ans+=500;
                break;
            case 'M': ans+=1000;
                break;
        }
    }
    return ans;
}

string TO_ROME(int num) {
    vector<int> val={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    vector<string> roman={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string res;
    int i=val.size()-1;
    while(num>0) {
        int q=num/val[i];
        num=num%val[i];
        while(q--)
            res.append(roman[i]);
        i--;
    }
    return res;
}
    
void solve() {
    string s; cin >> s;
    pair<string, string> p = ROME_TO_INT(s);
    int s1 = convert(p.first); int s2 = convert(p.second);
    int ans = s1 + s2;
    if (ans > 1000) {cout << s << "CONCORDIA CUM VERITATE" << "\n"; return ;}
    else {
        string ss = TO_ROME(ans);
        cout << s << ss << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n; cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
