#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int>&q){
	int qsize=q.size();
	if(qsize%2!=0){
		cout<<"Odd sized queue can't be interleaved\n";
		return;
	}
	else{
		int half=qsize/2;
		queue<int>q1;
		for(int i=0;i<half;i++){
			q1.push(q.front());
			q.pop();
		}
		while(!q1.empty()){
			q.push(q1.front());
			q1.pop();
			q.push(q.front());
			q.pop();
		}
	}
}
int main(){
	queue<int>q;
	int n,num;
	cout<<"Enter num of elements:";
	
	cin>>n;
	cout<<"Enter "<<n<<" elements:";
	for(int i=0;i<n;i++){
		cin>>num;
		q.push(num);
	}
	interleave(q);
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}

