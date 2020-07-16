// Given n people standing in a circle where 1st is having sword, find the luckiest person in the circle, 
// if from 1st soldier who is having a sword each have to kill the next soldier and handover the sword to next soldier, in turn, 
// the soldier will kill the adjacent soldier and handover the sword to next soldier such that one soldier remains in this war who is not killed by anyone.

// Example:
// Input
// 2
// 5
// 10
// Output
// 3
// 5
// Explanation:
// 1.In first go 1 3 5 (remains) as 2 and 4 killed by 1 and 3. In second go 3 will remain as 5 killed 1 and 3rd killed 5 hence, 3 remains alive.
// 2. In first 1 3 5 7 9 remains as 2 4 6 8 10 were killed by 1 3 5 7 and 9. In second 1 5 9 are left as 1 kills 3 and  5 kill the 7th soldier.In third 5th soldiers remain alive as 9 kills the 1st soldier and 5 kill the 9th soldier.

// Approach
// The idea is to use circular linked list. A circular linked list is made based on number of soldier N. 

#include<iostream>
using namespace std;

class Node{
    public:
    Node *next;
    int data;
    Node(int data){
        next=NULL;
        this->data=data;
    }
};

class LinkedList{
  Node *head;
  public:
  LinkedList(int n){
      Node *tail;
      head = tail = new Node(1);
      for(int i=2;i<=n;i++){
          tail->next = new Node(i);
          tail=tail->next;
      }
      tail->next=head;
  }
  int kill(){
      Node *temp=head;
      while(temp->next!=temp){
          temp->next=temp->next->next;
          temp=temp->next;
      }
      return temp->data;
  }
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    LinkedList circle(n);
	    cout<<circle.kill()<<"\n";
	}
	return 0;
}