// Doubly linked list
//  Test code
#include <cstdlib>
#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* head;
    Node* trailer;
    size_t mySize;
public:
    List() {
        head = new Node{0,nullptr,nullptr};
        trailer = new Node{0,nullptr,nullptr};
        head->next = trailer;
        trailer->prev = head;
        mySize = 0;
    }
    ~List(){
        clear();
        delete head;
        delete trailer;
    }
    List(const List &rhs){
        head = new Node;
        trailer = new Node;
        head->next = trailer;
        trailer->prev = head;
        mySize = 0;
        for (Node* p = rhs.head->next; p != rhs.trailer; p = p->next) {
            push_back(p->data);
        }
    }
    List& operator=(const List &rhs){
        if (this != &rhs){
            clear();
            for (Node* p = rhs.head->next; p != rhs.trailer; p = p->next) {
                push_back(p->data);
            }
        }
        return *this;
    }
    
    void push_front(const int& theData) {
        Node* newNode = new Node;
        newNode->data = theData;
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        ++mySize;
    }
    void pop_front() {
        Node* temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        --mySize;
    }

    void push_back(int theData) {
        Node* newNode = new Node;
        newNode->data = theData;
        newNode->next = trailer;
        newNode->prev = trailer->prev;
        trailer->prev->next = newNode;
        trailer->prev = newNode;
        ++mySize;
    }
    void pop_back() {
        Node* temp = trailer->prev;
        trailer->prev = temp->prev;
        temp->prev->next = trailer;
        delete temp;
        --mySize;
    }

    int& front() {
        return head->next->data;
    }

    const int& front() const {
        return head->next->data;
    }

    int& back() {
        return trailer->prev->data;
    }

    const int& back() const {
        return trailer->prev->data;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    bool empty() const {
        return mySize == 0;
    }

    size_t size() const {
        return mySize;
    }

    int& operator[](size_t position) {
        if (position >= mySize) {
            cout << "Index out of range\n";
        }
        Node* p = head->next;
        for (size_t i = 0; i < position; ++i) {
            p = p->next;
        }
        return p->data;
    }

    const int& operator[](size_t position) const {
        if (position >= mySize) {
            cout << "Index out of range\n";
        }
        Node* p = head->next;
        for (size_t i = 0; i < position; ++i) {
            p = p->next;
        }
        return p->data;
    }

    class iterator {
        friend class List; // so iterator can access Node* current
    public:
        // iterator() {
        //     current = nullptr;
        // }

        iterator(Node* theNode) {
            current = theNode;
        }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int unused) {
            iterator clone(*this);
            current = current->next;
            return clone;
        }

        iterator& operator--() {
            current = current->prev;
            return *this;
        }

        bool operator==(const iterator& rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator& rhs) const {
            return current != rhs.current;
        }

        int& operator*() const {
            return current->data;
        }

    private:
        Node* current;
    };

    iterator begin() {
        return iterator(head->next);
    }

    iterator end() {
        return iterator(trailer);
    }

    void insert(iterator iter, const int& theData) {
        Node* newNode = new Node;
        newNode->data = theData;
        newNode->next = iter.current;
        newNode->prev = iter.current->prev;
        iter.current->prev->next = newNode;
        iter.current->prev = newNode;
        ++mySize;
    }

    void erase(iterator iter) {
        Node* temp = iter.current;
        iter.current->prev->next = iter.current->next;
        iter.current->next->prev = iter.current->prev;
        iter.current = iter.current->next;
        delete temp;
        --mySize;
    }

    friend ostream& operator<<(ostream& os, const List& theList) {
        // alternative to while (p != theList.trailer)
        for (Node* p = theList.head->next; p != theList.trailer; p = p->next) {
            os << p->data << ' ';
        }
        return os;
    }
};

// Task 1
void printListInfo(const List& myList) {
    cout << "size: " << myList.size()
        << ", front: " << myList.front()
        << ", back(): " << myList.back()
        << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList) {
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList) {
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i * i << ");\n";
        myList.push_back(i * i);
        printListInfo(myList);
    }
    cout << "===================\n";

    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i * i << ");\n";
        myList.push_front(i * i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    printListInfo(myList);
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i * i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i * i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
        << "the data in the third item in the list\n"
        << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);


    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i * i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
        << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i * i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // // // Task 8
    // cout << "\n------Task Eight------\n";
    // cout << "Copy control\n";
    // cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    // myList.clear();
    // for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
    // printListInfo(myList);
    // cout << "Calling doNothing(myList)\n";
    // doNothing(myList);
    // cout << "Back from doNothing(myList)\n";
    // printListInfo(myList);

    // cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    // List listTwo;
    // for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i * i);
    // printListInfo(listTwo);
    // cout << "listTwo = myList\n";
    // listTwo = myList;
    // cout << "myList: ";
    // printListInfo(myList);
    // cout << "listTwo: ";
    // printListInfo(listTwo);
    // cout << "===================\n";
}