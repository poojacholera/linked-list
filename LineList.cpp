//
// Created by pooja on 16/05/19.
//
#include "LineList.h"
#include "Line.h"
using namespace std;
/**
 * Node constructor to create a node
 * @param ln Line object is set as data of the current node
 * @param prv pointer to the previous node of the current node
 * @param nxt pointer to the next node of the current node
 * */
LineList::Node::Node(const Line &ln, LineList::Node *prv, LineList::Node *nxt): data(ln), prev(prv), next(nxt) {}

/**
 * LineList : Default constructor
 * This initializes dummy Head and Tail nodes using Node constructor
 * */
LineList::LineList() {
    this->theSize = 0;
//    const char *s1 = "\0";
    Line dummyLine("\0");
    Node *dummyHead = new Node(dummyLine, nullptr, nullptr);
    Node *dummyTail = new Node(dummyLine, nullptr, nullptr);
    this->head = dummyHead;
    this->tail = dummyTail;
    this->head->next = tail;
    this->tail->prev = head;
    dummyHead= nullptr;
    dummyTail= nullptr;
}
/**
 * Copy constructor : creates object of LineList and copies the supplied object and its attributes
 *  @param rhs reference of LineList
 * */
LineList::LineList(const LineList& rhs) {
    //TODO
    if(!rhs.empty()){
        this->head = new Node(rhs.head->data, nullptr, nullptr);
        Node *current = rhs.head->next;
        Node *last = this->head;
        while(current != nullptr){
            last->next = current;
            last = last->next;
            current = current->next;
        }
        this->theSize = rhs.theSize;
        delete current,last;
        current = nullptr;
        last = nullptr;
    }return;
}
/**
 * Copy assignment : copies one object of LineList to another
 * @param rhs the object to be copied
 * */
const LineList& LineList::operator=(const LineList& rhs){
    if(&rhs != this) {//  condition to prevent self-assignment
        while (!empty()){
            pop_front();
        }
        Node *temp = this->head;
        theSize = rhs.theSize;
        Node *current = rhs.head->next;
        while (current != nullptr){
            temp->next = current;
            temp = temp->next;
            current = current->next;
        }
        delete current,temp;
        current = nullptr;
        temp= nullptr;
    }
    return *this;
}
/**
 * Destructor : de-allocates the LineList object
 * This function uses LineList::pop_front() function
 * */
LineList::~LineList(){
    while (!empty()){
        pop_front();
    }
    delete head,tail;
    head = nullptr;
    tail= nullptr;
}
/** push_front() : creates new node with supplied Line object
 * and pushes into LineList from the head node
 * @param line object of Line to be inserted
 * */
void LineList::push_front(const Line& line){
    //Todo
        Node *first = this->head->next;
        first->prev = new Node(line, this->head, this->head->next);
        this->head->next = first->prev;
        first = nullptr;
        delete first;
        theSize++;
}
/** push_back() : creates new node with supplied Line object
 * and pushes into LineList from the tail node
 * @param line object of Line to be inserted
 * */
void LineList::push_back(const Line& line){
    //Todo
        Node *last = this->tail->prev;
        last->next = new Node(line, this->tail->prev, this->tail); // create a new node before tail node
        this->tail->prev = last->next;
        last = nullptr;
        delete last;
        theSize++;
}
/** pop_front() : removes node from the head node in LineList
 * */
void LineList::pop_front(){
    //Todo
    if(!empty()){
        Node *temp = head->next;
       // if(temp==tail) return;
        temp->next->prev = head;
        head->next = temp->next;
        delete temp;
        temp = nullptr;
        theSize--;
    }
}
/** pop_back() : removes node from the tail node in LineList
 * */
void LineList::pop_back(){
    //todo
    if(!empty()){
        Node *last = tail->prev;
       // if(current==head)return;
        last->prev->next = tail;
        tail->prev = last->prev;
        delete last;
        last = nullptr;
        theSize--;
    }
}
/**
 * size() : Returns the size of this LineList
 * @return integer value of size
 * */
int LineList::size() const{
    return theSize;
}
/**
 * empty() : Returns whether this LineList is empty
 * * @return boolean value
 * */
bool LineList::empty() const{
    return (head->next == tail);
}
/**
 * insert() : Inserts a new line at position k in this list
 * If the @param k is in first half of List, the search will start from head otherwise from tail
 * This function uses push_front function to to insert if the @param k is next to head
 * @param line reference of object of class Line
 * @param k position at which the new Line Object to be added
 * */
void LineList::insert(const Line& line, int k){
    //Todo
    if (k < 1 || k > size()) return;
    else if(empty()){
        push_front(line);
        return;
    }
    Node *temp;
    int count;
    if (k <= (size()/ 2)){
        temp = head;
        count = 0;
        while(temp->next!= nullptr && k!=count){
            temp = temp->next;
            count++;
        }
    }else{
        temp = tail;
        count = size()+1;
        while(temp->prev!= nullptr && k!=count){
            temp = temp->prev;
            count--;
        }
    }
    if(k == count){
        temp->prev->next = new Node(line, temp->prev, temp);
        temp->prev = temp->prev->next;
        theSize++;
    }
    temp = nullptr;
}
/**
 * reomve() : Removes node at position k in this list
 * @param k the position of the node to be removed
 * */
void LineList::remove(int k){
    //Todo
    if (k < 1 || k > size()) return;
    Node *temp;
    if (k <= (size()/ 2)){
        temp = head;
        int count = 0;
        while(temp){
            if(k == count){
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                theSize--;
                return;
            }
            temp = temp->next;
            count++;
        }
    }else{
        temp = tail;
        int count = size()+1;
        while(temp){
            if(k == count){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                theSize--;
                return;
            }
            temp = temp->prev;
            count--;
        }
    }
    delete temp;
    temp = nullptr;
}
/**
 * get() : searches the node at position supplied to get Line Object of that node
 * If the @param k is in first half of List, the search will start from head otherwise from tail
 * @return returns the line at position k in this list
 * */
Line LineList::get(int k) const{
    //TODO
    if (k == 1) return this->head->next->data;
    else if(k == size()) return this->tail->prev->data;
    else if (k < 1 || k > size()) return NULL;
    Node *temp; // temporary node
    if (k <= (size())/ 2){
        temp=head;
        int count=0;
        while(temp){
           if(k == count) return temp->data;
           temp=temp->next;
           count++;
        }
    }else{
        temp = tail;
        int count = size()+1;
        while(temp){
            if(k == count) return temp->data;
            temp = temp->prev;
            count--;
        }
    }
    delete temp;
    temp = nullptr;
}
/**
 * print() : Print the list nodes data using loop
 * */
void LineList::print(){
    Node *temp = head->next;
    int i=1;
    while (temp->next != nullptr){
        cout<<"( "<<i<<" )"<<"  "<<temp->data.cstr()<<endl;
        temp=temp->next;
        i++;
    }
    temp= nullptr;
}