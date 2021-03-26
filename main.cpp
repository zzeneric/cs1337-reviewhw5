#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

using namespace std;

struct Node{ // Node structure, int variable and pointer to next node
    int num;
    Node *next;
};

void enQueue(int nextValue, Node *&header){ // Integer to add to list, node pointer that points to head of list
    Node *newNode = new Node; // Creates node
    newNode->num = nextValue; // Assigns node to back of list
    newNode->next = NULL; // Temporarily assigns node no next value

    if(header == NULL){ // If previous node doesn't exist
        header = newNode;
    }else{ // If header node exists
        Node *temp = header;
        while(temp->next != NULL){ 
            temp = temp->next;
        }
        temp->next = newNode; // Puts node all the way in the back
    }
}

void deQueue(Node *&header){ // Removes item from queue
    if(header->next == NULL){ // If no next node
        header = header->next;
    }else{ // If node exists
        Node *temp = header;

        while(temp->next->next != NULL){ // Checks for each variable
            temp = temp->next;
        }

        temp->next = NULL;
   }
}

void printQueue(Node *header) { // Function to print items, input header node
    if(header != NULL) { // If header doesn't exist
        cout << header->num << " ";
        printQueue(header->next); // Prints the next header
    }else{
        cout << endl; // Concludes the node's numbers
    }
}

int main(){
    Node *head = NULL;

    enQueue(2, head);
    printQueue(head);

    enQueue(5, head);
    printQueue(head);

    enQueue(1, head);
    printQueue(head);

    enQueue(5, head);
    printQueue(head);

    enQueue(1, head);
    printQueue(head);

    deQueue(head);
    printQueue(head);

    deQueue(head);
    printQueue(head);

    enQueue(3, head);
    printQueue(head);

    enQueue(2, head);
    printQueue(head);

    return 0;
}