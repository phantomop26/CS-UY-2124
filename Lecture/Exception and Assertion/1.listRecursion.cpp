// 1.listRecursion
// -jbs
//   - A "few' list functions implemented recursively.

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};
Node* buildList(const vector<int>& vals);


//
// recursive list functions
//

void listPrint(Node* p){
    if (p != nullptr) {
        cout<<p->data<<" ";
        listPrint(p->next);
    }
}

// listPrintReverse
void listPrintReverse(Node* p) {
    if (p != nullptr) {
	listPrintReverse(p->next);
	cout << p->data << ' ';
    }
} // listPrintReverse


// listDup
Node* listDup(const Node* p) {
    if (p == nullptr) return nullptr;
    // Node* result = listDup(p->next);
    // // Node* first = new Node{p->data};
    // // first->next = result;
    // Node* first = new Node{p->data, result};
    //Node* first = new Node{p->data, listDup(p->next)};
    //return first;
    return new Node{p->data, listDup(p->next)};

} // listDup

// listClear
// void listClear(Node*& p) {
//     if (p == nullptr) return;
//     listClear(p->next);
//     delete p;
//     p = nullptr;
// } // listClear

// void listClear(Node*& p) {
//     while (p != nullptr) {
// 	listRemoveHead(p);
//     }
// } // listClear

// End of recursive list functions


int main() {
    Node* myList = buildList({1, 1, 2, 3, 5, 8, 13, 21, 34, 55});

    //listPrint(myList);
    //Node* otherList = listDup(myList);
    //listPrint(myList);
    //listPrint(otherList);
    listDup(myList);
    listPrint(myList);
    listPrintReverse(myList);
}

Node* buildList(const vector<int>& vals) {
    Node* head = nullptr;
    for (size_t i = vals.size(); i > 0; --i) {
        head = new Node(vals[i-1], head);
    }
    return head;
}

