#include <bits/stdc++.h>
using namespace std;

const int S = 30'010;
int arr[S];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int w;
	int n;

	cin >> w >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];

	sort(arr+1,arr+n+1);

	int s=1,e=n,amm=0;

	while(s <= e){
		amm++;
		if(s==e) break;
		else if(arr[s] + arr[e] <= w){
			s++;
			e--;
		}
		else e--;
	}
	cout << amm << '\n';


}

