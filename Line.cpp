//
// Created by meet on 16/05/19.
//

#include <iostream>
#include "Line.h"

//Line::Line() = default;

Line::Line(const char *text) {
    cout<<" Line ctor"<<endl;
    capacity=strlen(text);
    lineLength=capacity;
    this->linePtr=new char[lineLength];//points to a new char array
    strcpy(linePtr,text);
}

Line::Line(const Line& l):Line(l.linePtr){
    cout<<"in Line copy ctor"<<endl;
//    lineLength=l.lineLength;
//    capacity=l.capacity;
//    linePtr=new char[lineLength+1];
//    strcpy(linePtr,l.linePtr);
}
 Line::~Line(){
   delete [] linePtr;
   linePtr= nullptr;
}
const Line& Line::operator=(const Line& rhs) {
    cout<<"in Line copy assignment"<<endl;
    if (this == &rhs) return *this;
    else{
        delete [] this->linePtr;
        this->linePtr=new char[strlen(rhs.linePtr)+1];
        strcpy(this->linePtr,rhs.linePtr);
    }
    return *this;
}
 char* Line::cstr() const{
    return linePtr;
    //Returns C-style version of this line
}
const int Line::length(){
    return lineLength;
}
const bool Line::empty(){
    return (lineLength==0);
}
bool Line::full() const{
    return (lineLength==capacity);
}
int Line::getCapacity() const{
    return capacity;
}
// Doubles capacity if this line is full
void Line::resize(){
    if(full()){
        capacity*=2;
        char *temp=new char[getCapacity()];
        strcpy(temp,linePtr);
        cout<<temp<<endl;
        delete[] linePtr;
        linePtr=temp;
        temp=nullptr;
    }
}
// Appends ch to the end of this line
void Line::push_back(const char& ch ){
    resize();
    cout<<linePtr<<endl;
    linePtr[lineLength]=ch;
    lineLength++;
}
//Removes the last character in this line
void Line::pop_back(){
    linePtr[lineLength-1]='\0';
    lineLength--;
}
// Overloads operator << as a friend
 ostream& operator<<(ostream &out, const Line&  line){
    out<<line.linePtr;
    return out;
}
 istream& operator>>( istream &in, Line& line){
    //Overloads operator>> as a friend
     in>>line.linePtr;
     return in; // returns the istream&
}
bool operator== ( const Line & line1, const Line & line2){
    return strcmp(line1.cstr(), line2.cstr());//!(strlen(line1.cstr())!= strlen(line2.cstr()));
}
// free function
bool operator!= ( const Line & line1, const Line & line2) {
    return !(line1==line2);
}