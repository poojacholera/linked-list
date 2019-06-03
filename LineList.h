//
// Created by pooja on 16/05/19.
//

#ifndef ASSIGNMENT1_LINELIST_H
#define ASSIGNMENT1_LINELIST_H

#include "Line.h"

class LineList{
    class Node{
        public:
            Line data;
            Node* prev;
            Node* next;
            Node(const Line& ln, Node* prv, Node* nxt);
    };
    private:
        int theSize;
        Node* head;
        Node* tail;
        class Node;
    public:
        LineList();
        virtual ~LineList(); //destructor
        LineList(const LineList& rhs);//copy ctor
        const LineList& operator=(const LineList& rhs); //copy assignment
        void push_front(const Line& line );
        void push_back(const Line& line );
        void pop_front();
        void pop_back(); //Remove the last node in this list
        int size() const; //Returns the size of this list
        bool empty() const; // Returns whether this list is empty
        void insert(const Line& line, int k); //Inserts a new line at position k in this list
        void remove(int k);  //Removes node at position k in this list
        Line get(int k) const; //Line Returns the line at position k in this list
        void print();
};
#endif //ASSIGNMENT1_LINELIST_H
