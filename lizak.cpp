#include <bits/stdc++.h>
using namespace std;

//preprocesing | przyklad : sumy prefiksowe
//patrzymy na konce

const int N = 2e6 + 10;
pair<int,int> ans[N];

string liz;

void setANS(int s,int e){
	if(!s) return;

	int k=0;
	for(int i=s ; i<=e ; i++) k += (liz[i] == 'T' ? 2 : 1);
	while(k > 0){
		ans[k] = {s,e};

		if(liz[s] == 'T') s++;
		else if(liz[e] == 'T') e--;
		else{
			s++;
			e--;
		}

		k-=2;
	}

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;

	cin >> n >> m;
	cin >> liz;

	liz = '*' + liz;

	int s=1,e=n;

	//1 parzystosc
	setANS(s,e);
	
	s = e = 0;
	for(int i=1;i<=n;i++){
		if(liz[i] == 'T') continue;
		if(!s) s = i;
		e = i;
	}
	if(s){
		if(s - 1 <= n - e){
			s++;
			e = n;
		}
		else{
			s = 1;
			e--;
		}
	}
	//2 parzystosc
	setANS(s,e);

	int k;
	while(m--){
		cin >> k;
		if(!ans[k].first) cout << "NIE\n";
		else cout << ans[k].first << ' ' << ans[k].second << '\n';
	}

}
