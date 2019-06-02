//
// Created by pooja on 16/05/19.
//

#include <iostream>
#include "Line.h"

Line::Line(const char *text){
    if(strlen(text)>0){
        lineLength=1;
        capacity=lineLength;
        this->linePtr=new char[getCapacity()];//points to a new char array
        linePtr[0]=text[0];

        int i=1;
        while (i<=(strlen(text)-1)){
            cout<<text[i]<< " at pos"<<i<<endl;
            this->push_back(text[i]);
            i++;
        }
    }
}

Line::Line(const Line& l):Line(l.linePtr){
   cout<<"in Line copy ctor"<<endl;
}
 Line::~Line(){
   delete [] linePtr;
   linePtr= nullptr;
}
const Line& Line::operator=(const Line& rhs){
    //cout<<"in Line copy assignment"<<endl;
    if (this == &rhs) return *this;
    else{
        while(!empty()){
            pop_back();
        }
        delete [] this->linePtr;
        this->linePtr=new char[strlen(rhs.linePtr)+1];
        strcpy(this->linePtr,rhs.linePtr);
        cout<<"in copy assign : "<<this->linePtr<<endl;
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
        this->capacity*=2;
        char *temp=new char[getCapacity()];
        strcpy(temp,linePtr);
        delete [] linePtr;
        linePtr=temp;
        temp=nullptr;
 }
}
// Appends ch to the end of this line
void Line::push_back(const char& ch){
    resize();
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
    delete [] line.linePtr;
    in>>line.linePtr;
    line.lineLength=strlen(line.linePtr);
    line.capacity=line.lineLength;
    return in; // returns the istream&
}
bool operator==(const Line & line1, const Line & line2){
    /*strcmp(line1.cstr(), line2.cstr());*/
    cout<<line1.cstr()<<endl;
    cout<<line2.cstr()<<endl;
    cout<<"comparison: "<<strcmp(line1.cstr(), line2.cstr())<<endl;
    return (strcmp(line1.cstr(), line2.cstr())==0);//!(strlen(line1.cstr())!= strlen(line2.cstr()));
}
// free function
bool operator!= ( const Line & line1, const Line & line2) {
    return !(line1==line2);
}