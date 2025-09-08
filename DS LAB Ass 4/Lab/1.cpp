#include<iostream>
using namespace std;
#define size 50
class queue{
	int arr[size];
	int f,r;
	public:
		queue(){
			f=-1;
			r=-1;
		}
		bool isempty(){
			return (f==-1||f>r);
		}
		bool isfull(){
			return r==size-1;
		}
		void enqueue(int n){
			if(isfull())  {
				cout<<"can't enter full";
				return;
			}
			if(isempty()){
				f=0;
			}
			arr[++r]=n;
			cout<<n<<" entered\n";
		}
		void dequeue(){
			if(isempty()){
				cout<<"empty can't dequeue\n";
				return;
			} 
			cout<<arr[f]<<" dequeued\n";
			f++;
			if(f>r){
				f=r=-1;
			}
		}
		void peek(){
			if(isempty()){
				cout<<"empty can't peek\n";
				return;
			} 
			else{
				cout<<arr[f]<<endl;
			}
		}
		void display(){
			if(isempty()){
				cout<<"empty can't display\n";
				return;
			} 
			for(int i=f;i<=r;i++){
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
			return;
		}
};
int main(){
	queue q;
	int n,choice;
	while(1){
		cout<<"\nMENU\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.check if empty\n6.check if full\n7.exit\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter to enqueue:";
				cin>>n;
				q.enqueue(n);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.peek();
				break;
			case 4:
				cout<<"\nqueue:\n";
				q.display();
				break;
			case 5:
				cout<<(q.isempty()?"empty\n":"not empty\n");
				break;
			case 6:
				cout<<(q.isfull()?"full\n":"not full\n");
				break;
			case 7:
				cout<<"exited\n";
				break;
			default:
				cout<<"invalid\n";	
		}
	}
return 0;
}

