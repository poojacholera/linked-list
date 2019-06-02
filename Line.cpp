//
// Created by meet on 16/05/19.
//

#include <iostream>
#include "Line.h"

//Line::Line() = default;

Line::Line(const char *text) {
 //   cout<<" Line ctor"<<endl;
    capacity=strlen(text);
    lineLength=capacity;
    /*lineLength=1;
    capacity=lineLength;*/
    this->linePtr=new char[this->lineLength];//points to a new char array
    strcpy(linePtr,text);

    /*cout<<strlen(text)<<endl;
    int i=0;
    while (i!=(strlen(text))){
        cout<<text[i]<< " at pos"<<i<<endl;
        this->push_back(text[i]);
        cout<<" len: "<<this->lineLength<<"  cap :"<< getCapacity()<< " value : " <<this->linePtr[i] <<endl;;
        i++;
    }*/
}

Line::Line(const Line& l):Line(l.linePtr){
   cout<<"in Line copy ctor"<<endl;
}
 Line::~Line(){
   delete [] linePtr;
   linePtr= nullptr;
}
const Line& Line::operator=(const Line& rhs) {
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
        //cout<<"cap: "<<getCapacity()<<" : in resize"<<endl;
        char *temp=new char[getCapacity()];
        //temp=linePtr;
        strcpy(temp,linePtr);
        delete [] linePtr;
        linePtr=temp;
        temp=nullptr;
 }
}
// Appends ch to the end of this line
void Line::push_back(const char& ch ){
    cout<<linePtr[lineLength]<<" Last value : "<<ch<<endl;
    resize();
    linePtr[lineLength]=ch;
    lineLength++;
    /*if( linePtr[lineLength]!= NULL){
        cout<< "is full so resize"<<endl;

    }*/
    //copy array to new array of modified capacity
    /*char *temp=new char[getCapacity()];
    cout<<temp<<" :temp print"<<endl;
    temp=linePtr;
    unsigned int i = 0;
    for( ;i < lineLength; i++){
        temp[i] = linePtr[i];
    }
    //add new element at last and increase linlength
    temp[i+1]=ch;
    temp[lineLength]=ch;
    cout<<temp<<" :temp print"<<endl;
    lineLength++;
    //deleting previous assignment of linePtr and then copying new temp to linePtr
    delete[] linePtr;
    linePtr=temp;
    // remove temporary array pointer after its use
    temp=nullptr;
*/
    //cout<<this->linePtr[lineLength]<<" Length: "<<length()<<"--"<<endl;


}
//Removes the last character in this line
void Line::pop_back(){
    linePtr[lineLength-1]='\0';
    lineLength--;
}
// Overloads operator << as a friend
 ostream& operator<<(ostream &out, const Line&  line){
    //out<<line.linePtr;
    return out;
}
 istream& operator>>( istream &in, Line& line){
    //Overloads operator>> as a friend
     in>>line.linePtr;
     //line.linePtr[line.lineLength+1]='\r';
     return in; // returns the istream&
}
bool operator== ( const Line & line1, const Line & line2){
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