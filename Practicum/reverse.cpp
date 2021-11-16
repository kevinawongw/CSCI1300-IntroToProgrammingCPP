#include <iostream>
using namespace std;

struct node
{
    int key;
    node *next;
};

node* reverse(node *head)
{
    if(head==NULL){
        return NULL;
    }
    else {
    	node* previous=NULL;;
    	node* current=head;
    	node* following=head->next;
    
    	while (current!=NULL){
           following=current->next;
           current->next=previous;
           previous=current;
           current=following;
    	}
    	head=previous;
    }
    // cout << head->key << endl;
    return head;
}

int main(){
    node* head= new node;
    head->key=5;
    node* a= new node;
    a->key=2;
    node* b= new node;
    b->key=9;
    
    head->next=a;
    a->next=b;
    b->next=NULL;
    
    cout << reverse(head);
}