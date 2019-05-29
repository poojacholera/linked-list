//
// Created by meet on 16/05/19.
//

#ifndef ASSIGNMENT1_LINE_H
#define ASSIGNMENT1_LINE_H

#include <iostream>
#include <cstring>
using namespace std;

class Line{
    private:
        char * linePtr; // Stores a pointer to the first character in a dynamically created array of char, effectively representing the underlying line of text.
        int lineLength;  // Length of this line
        int capacity;
    public:
        Line(const char* text);
        Line(const Line&);//Copy Constructor
        const Line& operator= ( const Line& rhs);

        virtual ~Line();      //Releases dynamic memory created and owned by this line

        char* cstr() const; //Returns C-style version of this line
        const int length();
        const bool empty();
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
