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
			return (f==-1);
		}
		bool isfull(){
			return ((r+1)%size==f);
		}
		void enqueue(int n){
			if(isfull())  {
				cout<<"can't enter full";
				return;
			}
			if(isempty()){
				f=r=0;
			}
			else{
				r=(r+1)%size;
			}
			arr[r]=n;
			cout<<n<<" entered\n";
		}
		void dequeue(){
			if(isempty()){
				cout<<"empty can't dequeue\n";
				return;
			} 
			int e=arr[f];
			if(f==r){
				f=r=-1;
			}
			else{
				f=(f+1)%size;
			}
			cout<<e<<" dequeued\n";
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
			int i=f;
			while(true){
			cout<<arr[i]<<" ";
			if(i==r)
				break;
			i=(i+1)%size;
			}
			cout<<endl;
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


