#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<climits>
#include<math.h>
#include<string>
#include<unordered_map>
#define ll long long
#define sc(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define fo( i, n) for(int i = 0;i<n;i++)
using namespace std;


struct thread{
	int rank=0;
	ll job_time = 0;

	thread(int a,ll b){   
		rank = a;
		job_time = b;
	}
};

vector <int> leftstore;
vector <int> rightstore;
// void Hpy(vector <thread> &arr,int ind){
// 	int siz = arr.size();

// 	int left = 2*ind +1;
// 	int right = 2*ind +2;
// 	int big = ind;

// 	if(left<siz){
// 		if(arr[left].job_time<arr[big].job_time){
// 			big = left;
// 		}else{}
// 	}

// 	if(right<siz){
// 		if(arr[right].job_time<arr[big].job_time){
// 			big = right;
// 		}
// 	}

// 	if(big!=ind){
// 		//cout<<arr[ind]<<" "<<arr[big]<<endl;
// 		leftstore.push_back(ind);rightstore.push_back(big);
// 		thread temp = arr[ind];
// 		arr[ind]=arr[big];
// 		arr[big] = temp;
// 		Hpy(arr,big);

// 	}
// }

 
void shiftDown(vector <thread> &arr, int i){
	int sml  = i;
	int left = 2*i+1;
	int right = 2*i+2;
	int siz = arr.size();

	if(left<siz){
		if(arr[sml].job_time>arr[left].job_time){
			sml = left;// cout<<"check 1"<<endl;


			if(right<siz){
				//cout<<arr[right].rank<<"and"<<arr[sml].rank<<"----"<<i<<endl;
				if(arr[right].job_time<arr[sml].job_time){sml = right;/*cout<<"check 2"<<endl*/;}else 
				if(arr[right].job_time==arr[sml].job_time){if(arr[right].rank<arr[sml].rank){sml=right;}}
			}
		}else if(arr[sml].job_time==arr[left].job_time && arr[sml].rank>arr[left].rank ){
			sml = left;

			if(right<siz){
				if(arr[right].job_time<arr[sml].job_time){sml = right;}else 
				if(arr[right].job_time==arr[sml].job_time){if(arr[right].rank<arr[sml].rank){sml=right;}}
			}


		} else{
			if(right<siz){
				if(arr[sml].job_time>arr[right].job_time){ sml = right;}else 
					if(arr[sml].job_time==arr[right].job_time&&arr[sml].rank>arr[right].rank){
						sml = right;
					}
			}
		}
	}

	// if(right<siz){
	// 	if(arr[sml].job_time>arr[right].job_time&&arr[left].job_time==arr[right].job_time&& arr[left].rank>arr[right].rank){
	// 		sml = right;
	// 	}else if(arr[sml].job_time==arr[right].job_time &&arr[left].job_time==arr[right].job_time && arr[left].rank>arr[right].rank){
	// 		sml = right;
	// 	}
	// }

	if(sml!=i){

		//cout<<"swapped"<<arr[sml].rank<<":"<<arr[sml].job_time<<"::"<<arr[i].rank<<":"<<arr[i].job_time<<endl;

		thread temp = arr[i];
		arr[i]=arr[sml];
		arr[sml] = temp;
		shiftDown(arr,sml);


	}

}

	
// void bH(vector <thread> &arr){
// 	int n = arr.size();

// 	int k = (n/2)-1;

// 	while(k>=0){
		
// 		Hpy(arr,k);k--;       
// 	}
// }



int main(){
	int m,n;
	sc(n);sc(m);

	vector <thread> arr;
	vector <ll>arrb;

	int k = 0;
	while(k<m){
		//cout<<k<<"ii "<<m<<endl;
		k++;
		ll a;sl(a);//arr.push_back(thread(k,a));
		arrb.push_back(a);
	}

	for(int i = 0;i<n;i++){

		arr.push_back(thread(i,0));
		//cout<<arr[i].rank<<" "<<arr[i].job_time<<endl;

		
	}

	for(int i = 0;i<m;i++){


		printf("%d %lld",arr[0].rank,arr[0].job_time);
		cout<<endl;
		arr[0].job_time = arr[0].job_time+arrb[i];
		shiftDown(arr,0);
		// cout<<"here is shifted therad"<<endl;
		// for(int j = 0;j<n;j++){
		// 	cout<<arr[j].rank<<"-"<<arr[j].job_time<<"::";
		// }
	}



	// for(int i = 0;i<t;i++){
	// 	cout<<arr[i]<<" ";
	// }cout<<endl;

	//bH(arr);




	// for(int i = 0;i<n;i++){
	// //	arr.push_back(thread(i,0));
	// 	cout<<arr[i].rank<<" "<<arr[i].job_time<<endl;
	// }

	// for(int i = 0;i<m;i++){
		
	// }
	//cout<<leftstore.size()<<endl;

	//cout<<"swappings: "<<endl;

	// for(int i =0;i<leftstore.size();i++){
	// 	cout<<leftstore[i]<<" "<<rightstore[i]<<endl;

	// }


	// for(int i = 0;i<t;i++){
	// 	cout<<arr[i]<<" ";
	// }cout<<endl;
	




	// while(t--){
	// }
	return 0;
}

//help//....................
/*For those using C++,
 you could construct a priority_queue on the pair<index,finishing Time>.
  You need construct a comparator CompareTime for this built-in priority_queue (google, you wil find how to contruct it)

priority_queue<pair<int,long long>, vector<pair<int, long long>>, CompareTime> next_fee_time
*/


/*For every job, get heap[0]
upgrade job processing time
insert at heap[0]
shiftDown(heap,0)*/