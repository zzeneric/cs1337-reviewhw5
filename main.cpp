#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

using namespace std;

struct Node{ // Node structure, int variable and pointer to next node
    int num;
    Node *next;
};

void enQueue(int nextValue, Node **header){ // Integer to add to list, node pointer that points to head of list
    struct Node *newNode = new Node; // Creates node
    newNode->num = nextValue; // Assigns node to back of list
    newNode->next = nullptr; // Temporarily assigns node no next value

    if(*header == nullptr){ // If previous node doesn't exist
        *header = newNode;
    }else{ // If header node exists
        struct Node *current = *header;

        while(current->next != nullptr){ 
            current = current->next;
        }
        current->next = newNode;// Puts node all the way in the back
    }
}

void deQueue(Node **header){
    if(header == nullptr){ // If header doesn't exist
        return;
    }

    Node *tempNum = *header; // New temporary header
    *header = tempNum->next; // Removes the number from list
    
    delete tempNum; // Deletes the temporary number
}

void printQueue(Node *header) { // Function to print items, input header node
    if(header != nullptr) { // If header doesn't exist
        cout << header->num << " ";
        printQueue(header->next); // Prints the next header
    }else{
        cout << endl; // Concludes the node's numbers
    }
}

int main(){
    struct Node *head = nullptr;

    enQueue(1, &head);
    printQueue(head);

    enQueue(2, &head);
    printQueue(head);

    deQueue(&head);
    printQueue(head);

    return 0;
}