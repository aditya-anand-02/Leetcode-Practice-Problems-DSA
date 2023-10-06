//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
#include<bits/stdc++.h>
class Solution
{
    public:
    Node * reverse(Node * head)
    {
        Node * curr=head;
        Node* prev=NULL;
        while(curr!=NULL)
        {
            Node* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd==NULL || odd->next==NULL)
        return;
        Node* oddhead=odd;
        Node* evenhead=odd->next;
        Node* oddcurr=oddhead;
        Node* evencurr=evenhead;
        while(oddcurr && evencurr && oddcurr->next && evencurr->next)
        {
            oddcurr->next=evencurr->next;
            oddcurr=oddcurr->next;
            evencurr->next=oddcurr->next;
            evencurr=evencurr->next;
        }
        oddcurr->next=reverse(evenhead);
        return;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends