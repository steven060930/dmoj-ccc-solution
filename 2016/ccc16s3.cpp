#pragma GCC target ("avx2")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define gcd(a, b) (b == 0) ? a : gcd(b, a%b)
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpair make_pair
#define pb push_back
#define nl cout << "\n"
#define scan(x) { while((x=getchar())<'0'); for (x-='0'; '0'<= (_=getchar()); x = (x<<3)+(x<<1)+_-'0');} while(0)
char _;

#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;

const ll INF = 0x3f3f3f3f;	const ll LLINF = 0x3f3f3f3f3f3f3f3f;	const ll MOD = 1e9 +7;

template <typename C> void UNIQUE(vector<C> &v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); } 
template <typename U> void DECREASING(vector<U> &v) { sort(all(v), greater<U>()); }

template<class T> void read(T& x) {
	cin >> x;
} 
void read(double &d) {
	string t;
	read(t);
	d = stod(t);
}
void read(ld &d) {
	string t;
	read(t);
	d = stold(t);
}
template<class H, class... T> void read(H& h, T&...t) {
	read(h);
	read(t...);
}
template<class A> void read(vector<A> &x) {
	for (auto &a : x) { read(a); }
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	for (int i=0; i < (int)v.size(); i++)
		res+=char('0'+v[i]);
	return res;
}

template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for (auto &x :v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class C> void write(vt<C> &v) {
	for (auto &x : v) { cout << x << " "; }
	nl;
}
template<class A> void write(vt<vt<A>> &v) {
	for (auto x : v) { for (auto y : x) { cout << y << " "; } nl; }
}

const int MM = 1e5+2;
int N, M, st, far, dia, cnt; 
vector<int> adj[MM]; bool pho[MM];

void dfs1(int u, int pa){
    for(int v: adj[u]){
        if(v == pa) continue;
        dfs1(v, u);
        if(pho[v]) pho[u] = true;
    }
}
void dfs2(int u, int pa, int dis){
    if(dis > dia) { dia = dis; far = u; }
    for(int v : adj[u]){
        if(v == pa || !pho[v]) continue;
        dfs2(v, u, dis+1);
    }
}

int main(){
	cin.tie(nullptr) -> ios::sync_with_stdio(0);
    read(N, M);
    for(int i = 1; i <= M; i++){
        read(st); pho[st] = true;
    }
    for(int i = 1; i < N; i++){
        int u, v; read(u, v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
  
    dfs1(st, -1); dfs2(st, -1, 0); dia=0; dfs2(far, -1, 0);
    for(int i=0; i<N; i++)
        if(pho[i]) cnt++;
    print(2*(cnt-1) - dia);
    
	return 0;
}
