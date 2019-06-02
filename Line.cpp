//
// Created by pooja on 16/05/19.
//

#include <iostream>
#include "Line.h"

Line::Line(const char *text){
    cout<<"received line: "<<text<<endl;
    /*if(strlen(text)>0){
        lineLength=0;
        capacity=1;//lineLength;
        this->linePtr=new char[1];//points to a new char array
        int i=0;
        while (i<=(strlen(text)-1)){
            this->push_back(text[i]);
            i++;
        }
    }
    cout<<"after ctor work... "<<linePtr<<endl;*/
//    cout<<" Line ctor"<<endl;
    capacity=strlen(text);
    lineLength=capacity;
    this->linePtr=new char[this->lineLength];//points to a new char array
    strcpy(linePtr,text);
}

Line::Line(const Line& l):Line(l.linePtr){

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
        this->linePtr=new char[rhs.getCapacity()]{'\0'};
        strcpy(this->linePtr,rhs.linePtr);
        this->capacity=rhs.getCapacity();
        this->lineLength=rhs.length();
    }
    return *this;
}
 char* Line::cstr() const{
    return linePtr;
    //Returns C-style version of this line
}
int Line::length() const{
    return lineLength;
}
bool Line::empty() const{
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
        char *temp=new char[getCapacity()]{'\0'};
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

    return (
        (strcmp(line1.cstr(), line2.cstr())==0)
        && (line1.getCapacity()==line2.getCapacity())
        && (line1.length()==line2.length())
    );
}
// free function
bool operator!= ( const Line & line1, const Line & line2) {
    return !(line1==line2);
}