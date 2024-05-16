// linked-list.cpp
#include <iostream>
using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
};

/*
  display
  length/size
  add, remove at front / back / etc.
  clear
  duplicate
 */

void listDisplay(const Node* headPtr) {
    //while(*headPtr->next != nullptr) {
    const Node* p = headPtr;
    //while(headPtr != nullptr) {
    while(p != nullptr) {
        //cout << headPtr->data << ' ';
        cout << p->data << ' ';
        //headPtr = headPtr->next; // Bump
        p = p->next; // Bump
    }
    cout << endl;
}

int listLength(const Node* headPtr) {
    int len = 0;
    const Node* p = headPtr;
    while(p != nullptr) {
        ++len;
        p = p->next; // Bump
    }
    return len;
}

//void listAddHead(Node* headPtr, int data) {
void listAddHead(Node*& headPtr, int data) {
    // // create a new node for the data
    // Node* p  = new Node{data};

    // // Make that new node point to the old head node
    // p->next = headPtr;
    //    Node* p  = new Node{data, headPtr};

    // Make the head pointer point to the new head node
    //headPtr = p;
    headPtr = new Node{data, headPtr};
}

Node* listFindTail(Node* headPtr) {
//const Node* listFindTail(const Node* headPtr) {
    if (headPtr == nullptr) return nullptr;
    while (headPtr->next != nullptr) {
        headPtr = headPtr->next;
    }
    return headPtr;
}

void listAddTail(Node*& headPtr, int data) {
    // 0. Did they pass an empty list?
    if (headPtr == nullptr) {
        //headPtr = new Node{data, headPtr};
        listAddHead(headPtr, data);
    } else {
        // 1. find the end of the list
        Node* tailPtr = listFindTail(headPtr);

        // 2. Add the data after the last node
        tailPtr->next = new Node{data};
    }
}

void listRemoveHead(Node*& headPtr) {
    // Empty list?
    if (headPtr != nullptr) {
        // Remember?
        Node* victim = headPtr;
        // Bump the head pointer
        headPtr = headPtr->next;
        // Free the original head node
        delete victim;
    }
}

void listRemoveTail(Node*& headPtr) {
    if (headPtr == nullptr) {
        return;
    } else if (headPtr->next == nullptr) {
        delete headPtr;
        headPtr = nullptr;
    } else {
        // Find the second to last node
        Node* secondToLast = headPtr;
        while(secondToLast->next->next != nullptr) {
            secondToLast = secondToLast->next;
        }


        // Free up the last node
        delete secondToLast->next;
        secondToLast->next = nullptr;
    }
}

Node* listDup(const Node* headPtr) {
    if (headPtr == nullptr) return nullptr;

    Node* result = new Node{headPtr->data};
    Node* last = result;

    const Node* p = headPtr->next;
    while (p != nullptr) {
        last->next = new Node{p->data};
        p = p->next;
        last = last->next;
    }
    return result;
}

int main() {
    // Empty list
    Node* myList = nullptr;
    cout << "Displaying an empty list: ";
    listDisplay(myList);

    // Add first node to list
    //    myList = new Node{17};
    listAddHead(myList, 17);
    cout << "Displaying the list with one item added to the front: ";
    listDisplay(myList);
    
    // Add second node to list
    myList->next = new Node{28};

    // Display the list.
    //    cout << myList->data << ' ' << myList->next->data << endl;
    cout << "Displaying the list with another item added to the back: ";
    listDisplay(myList);

}

