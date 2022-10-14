#include <iostream>
using namespace std;

struct node{
        int data;
        node* link;
};

node* head=NULL;
void InsertAtEnd(int d){
    node* n = new node(); 
    n->data=d;
    n->link=NULL;
    if(head==NULL){
        head=n;
        cout<<endl<<"Element Added!";
    }
    else{
        node* temp=head;
        while((temp->link)!=NULL){
            temp=temp->link;
        }
        temp->link=n; 
        cout<<endl<<"Element Added!";
    }
}

void InsertAtBeg(int d){
    node* n = new node;
    n->data=d;
    n->link=head;
    head=n;
    cout<<endl<<"Element Added!";
}

void DeleteBeg(){
    if(head==NULL){
        cout<<endl<<"List is empty!";
    }
    
    else{
        node* ptr=head;
        head=ptr->link;
        free(ptr);
        cout<<endl<<"Element Deleted!";
    }
}

void DeleteEnd(){
    if(head==NULL){
        cout<<endl<<"List is empty!";
    }
    
    else{
        node* temp=head;
        node* prev;
        while(temp->link!=NULL){
            prev=temp;
            temp=temp->link;
        }
        prev->link=NULL;
        free(temp);
        cout<<endl<<"Element Deleted!";
    }

} 

void MidDisplay(){
    if(head==NULL){
        cout<<endl<<"List is empty!";
    }
    
    else{
        /* Time Consuming method as 2 times iteration is happening.
        int count=0,mid=0;
        node* temp=head;
        while(temp->link != NULL){
            temp=temp->link;
            count++;
        }
        temp=head;
        mid=count/2;
        for(int i=0; i<mid; i++){
            temp=temp->link;
        }
        cout<<temp->data<<endl;
        */
       node* fast=head; //Moves 2 nodes at a time
       node* slow=head; //Moves a single node at a time
       while(fast!=NULL && fast->link!=NULL){
           slow=slow->link;
           fast=fast->link;
           fast=fast->link; //or instead of writng 2 times, write fast->link->link;
       }
       cout<<slow->data<<endl;
    }
}

void reverse(){
    if(head==NULL){
        cout<<endl<<"List is empty!";
    }
    
    else{
       node*prev = NULL;
       node* cur = head;
       node* next;
       while(cur!=NULL){
           next=cur->link;
           cur->link=prev;
           prev=cur;
           cur=next; 
       }
       head=prev;
    }
}

void display(){
    if(head==NULL){
        cout<<endl<<"The list is empty.";
    }
    else{
        node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp=temp->link;
        }
        cout<<"NULL";
    }    
}

int main(){
    int choice,d;
    char ans='y';
    while(ans=='y'){
        cout<<"1. Display Linked List"<<endl;
        cout<<"2. Add an element to the beginning"<<endl;
        cout<<"3. Add an element to the end"<<endl;
        cout<<"4. Delete the first element"<<endl;
        cout<<"5. Delete the last element"<<endl;
        cout<<"6. Display the middle element"<<endl;
        cout<<"7. Reverse the list"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                cout<<"Enter the value to be added: ";
                cin>>d;
                InsertAtBeg(d);
                break;
            case 3:
                cout<<"Enter the value to be added: ";
                cin>>d;
                InsertAtEnd(d);
                break;
            case 4:
                DeleteBeg();
                break;
            case 5:
                DeleteEnd();
                break;
            case 6:
                MidDisplay();
                break;
            case 7:
                reverse();
                break;
            default:
                cout<<"Invalid Choice!";
                break;
        }
        cout<<endl<<"Do you want to choose again(y/n): ";
        cin>>ans;
    }
}
