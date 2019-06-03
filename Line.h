//
// Created by pooja on 16/05/19.
//

#ifndef ASSIGNMENT1_LINE_H
#define ASSIGNMENT1_LINE_H

#include <iostream>
#include <cstring>
using namespace std;
class Line{
    private:
        char * linePtr;
        int lineLength;
        int capacity;
    public:
        Line(const char* text);
        Line(const Line&);
        const Line& operator= ( const Line& rhs);

        virtual ~Line();

        char* cstr() const;
        int length() const;
        bool empty() const;
        bool full() const;
        int getCapacity() const;
        void resize(); // Doubles capacity if this line is full
        void push_back(const char& ch ); // Appends ch to the end of this line
        void pop_back(); //Removes the last character in this line
        friend ostream& operator<<(ostream &out, const Line&  line); // Overloads operator << as a friend
        friend istream& operator>>( istream &in, Line& line); //Overloads operator>> as a friend
};
bool operator==( const Line &, const Line &); // free function
bool operator!=( const Line &, const Line &); // free function

#endif //ASSIGNMENT1_LINE_H
