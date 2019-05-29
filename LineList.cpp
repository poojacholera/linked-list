//
// Created by pooja on 16/05/19.
//
#include "LineList.h"
#include "Line.h"

using namespace std;

LineList::Node::Node(const Line &ln, LineList::Node *prv, LineList::Node *nxt): data(ln), prev(prv), next(nxt) {}

//default ctor
LineList::LineList() {
    cout<<"in default LINELIST ctor"<<endl;
    this->theSize = 0;
//    const char *s1 = "\0";
    Line dummyLine("hh");
    Node *dummyHead = new Node(dummyLine, nullptr, nullptr);
    Node *dummyTail = new Node(dummyLine, nullptr, nullptr);
    this->head = dummyHead;
    this->tail = dummyTail;
    this->head->next = tail;
    this->tail->prev = head;
    /*Node *n=new Node("abc",head,tail);*/
    dummyHead= nullptr;
    dummyTail= nullptr;
}
//Print the list nodes data
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
//copy ctor
LineList::LineList(const LineList &rhs) {
    //TODO
    cout<<"in cpy LINELIST ctor"<<endl;
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
//copy assignment
const LineList& LineList::operator=(const LineList& rhs){
    //Todo
    cout<<"in copy assignment"<<endl;
    if(&rhs != this) {// to prevent self-assignment
        while (!empty()){
            pop_front();
        }
       // new (this) LineList (rhs);
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
//Destructor
LineList::~LineList(){
    while (!empty()){
        pop_front();
    }
    delete head,tail;
    head = nullptr;
    tail= nullptr;
}
/**Push Line object from the head node*/
void LineList::push_front(const Line& line ){
    //Todo
        Node *first = this->head->next;
        first->prev = new Node(line, this->head, this->head->next);
        this->head->next = first->prev;
        first = nullptr;
        delete first;
        theSize++;
    cout<<size()<<" : "<<line.cstr()<<endl;
}
void LineList::push_back(const Line& line){
    //Todo
        Node *last = this->tail->prev;
        last->next = new Node(line, this->tail->prev, this->tail); // create a new node before tail node
        this->tail->prev = last->next;
        last = nullptr;
        delete last;
        theSize++;
    cout<<size()<<" : "<<line.cstr()<<endl;
}
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
//Returns the size of this list
int LineList::size() const {
    return theSize;
}
// Returns whether this list is empty
bool LineList::empty() const{
    return (head->next == tail);
}
//Inserts a new line at position k in this list
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
//Removes node at position k in this list
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
//Line Returns the line at position k in this list
Line LineList::get(int k) const{
    //TODO
    cout<<"in get "<<k <<" the size :"<<size()<<endl;
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
