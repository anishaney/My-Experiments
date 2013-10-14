#include<iostream>
#include<algorithm>
#include<conio.h>

struct ListNode {

  int value;

  ListNode * next;

}

bool hasLoops( ListNode * myList ) {
    
    if (myList == NULL)
        return false;
    else{
        //Define two pointers *head and *tail
        ListNode *head, *tail;
        head = tail = myList; //Point these to the start of the List
        
        //Two conditions are validated since the List may just have "myList" node or two nodes
        while (head != NULL && tail != NULL){
            head = head->next->next;
            tail = tail->next;
            
            if (head == tail){
                return true;
            }
        }
			
        return false;
    }
}