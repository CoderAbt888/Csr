#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findd(vector<int> &parent,int a){
	if(parent[a]==-1){
		return a;
	}

	return findd(parent,parent[a]);
}

int main(){
	int n,q;
	cin>>n>>q;

	vector<int>arr(n+1);
	vector<int>parcom(n+1);
	vector<int>parent(n+1);
	vector<int>rank(n+1);

	for(int i = 0;i<n+1;i++){
		parent[i]=-1;
		rank[i]=0;
		parcom[i]=1;
	}


	for(int i = 0;i<q;i++)
	{
		char c;
		cin>>c;

		if(c=='M'){
		int a,b;
		cin>>a>>b;

		int a_parent = findd(parent,a);

		int b_parent = findd(parent,b);

		if(a_parent==b_parent)continue;

		int ranka = rank[a_parent];
		int rankb = rank[b_parent];

		if(ranka>rankb){
			parent[b_parent]=a_parent;
			parcom[a_parent]=parcom[b_parent]+parcom[a_parent];


		}else if(ranka<rankb){
			parent[a_parent]=b_parent;
			parcom[b_parent]=parcom[b_parent]+parcom[a_parent];

		}else{
			parent[b_parent]=a_parent;
			rank[a]++;
			parcom[a_parent]=parcom[b_parent]+parcom[a_parent];

		}
		}else{

			int a;cin>>a;
			int ap = findd(parent,a);
			cout<<parcom[ap]<<endl;

			map<int,int>mp;
			int count = 0;

			for(int i = 1;i<n+1;i++){
				int x = findd(parent,i);
				if(x==ap){count++;}
				// mp[x]++;
			}
		

		// map<int,int>::iterator itr;
		// itr = mp.begin();
		// int min = itr->second;

		// for(itr = mp.begin();itr!=mp.end();itr++){
		// 	// cout<<itr->second<<"*"<<endl;
		// 	if(itr->second<min){
		// 		min= itr->second;
		// 	}

		// }

		// cout<<count<<endl;

	}




	}
	

	return 0;
}

    // cout << "\nMax Element = "
    //      << *max_element(a.begin(), a.end()); 