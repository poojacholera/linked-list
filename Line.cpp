//
// Created by pooja on 16/05/19.
//


#include "Line.h"

/**
 * Conversion ctor : a new Line object is created with given value
 * This constructor uses push_back function to push each character.
 * @param text pointer to char array
 * */
Line::Line(const char *text){
    if(strlen(text)>0){
        lineLength=0;   //initially length is 0
        capacity=1;
        this->linePtr=new char[getCapacity()+1]{'\0'};//points to a new char array
        int i=0;
        while (i<=(strlen(text)-1)){
            this->push_back(text[i]);
            i++;
        }
    }else{
        lineLength=0;   //initially length is 0
        capacity=0;
        this->linePtr=new char[1]{'\0'};//points to a new char array
    }
}
/**
 * Copy ctor : Delegates the construction of Line object to the conversion constructor
 * @param line a reference of Line object to be copied
 * */
Line::Line(const Line& line):Line(line.linePtr){}

/**
 * Line Destructor : deallocates the array object pointed by linePtr and then frees the linePtr
 * */
 Line::~Line(){
   delete [] linePtr;
   linePtr= nullptr;
}
/**
 * Copy assignment : Overloads assignment operator to copy one Line object from another Line object
 * This function uses the Line::pop_back() function
 * @param rhs reference of Line object to be copied is passed
 * @return const reference of Line object copied from the @param rhs
 * */
const Line& Line::operator=(const Line& rhs){
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
/**
 * cstr() : Getter function to return c-style version of char array
 * @return the pointer to char array is return for the current object
 * */
char* Line::cstr() const{
    return linePtr;
}
/**
 * length() : Getter function to length of char array(counts number of elements inserted)
 * @return integer value of length
 * */
int Line::length() const{
    return lineLength;
}
/**
 * empty() : Function to check if the Line (char array) is empty
 * @return boolean value for if length of line is 0
 * */
bool Line::empty() const{
    return (lineLength==0);
}
/**
 * full() : Function to check if the Line (char array) is completely filled
 * @return boolean value for if length of line and capacity are equal
 * */
bool Line::full() const{
    return (lineLength==capacity);
}
/**
 * getCapacity() : getter function for capacity of current object
 * @return integer value for capacity
 * */
int Line::getCapacity() const{
    return capacity;
}
/**
 * resize() : Doubles capacity of char array(line) if the line is full
 * */
void Line::resize(){
    if(full()){
        this->capacity*=2;
        char *temp=new char[getCapacity()+1]{'\0'};
        strcpy(temp,linePtr);
        delete [] linePtr;
        linePtr=temp;
        temp=nullptr;
    }
}
/**
 * push_back() : Appends a character at he end of line(char array)
 * This function uses the resize function to check if the char array needs to be resized
 * @param ch  const reference of char ch to be appended
 * */
void Line::push_back(const char& ch){
    resize();
    linePtr[lineLength]=ch;
    lineLength++;
}
/**
 * pop_back() : Removes the last character from the char array (line)
 * */
void Line::pop_back(){
    linePtr[lineLength-1]='\0';
    lineLength--;
}
/**
 * Overloads out-stream operator << as a friend function
 * @param line  const reference of line object is the source for out stream
 * @param out  ostream reference
 * @return out  ostream reference
 * */
ostream& operator<<(ostream& out, const Line&  line){
    out<<line.linePtr;
    return out;
}
/**
 * Overloading in-stream operator >> as a friend function. Object's attributes are copied
 * @param line  const reference of line object as input for in-stream
 * @param in  istream reference
 * @return in   istream reference
 * */
istream& operator>>(istream& in, Line& line){
    //Overloads operator>> as a friend
    delete [] line.linePtr;
    in>>line.linePtr;
    line.lineLength=strlen(line.linePtr);
    line.capacity=line.lineLength;
    return in;
}
/**
 * Operator overloading (==) to check if one line object is equal to another
 * @return boolean value
 * */
bool operator==(const Line& line1, const Line& line2){
    return (
        (strcmp(line1.cstr(), line2.cstr())==0)
        && (line1.getCapacity()==line2.getCapacity())
        && (line1.length()==line2.length())
    );
}
/**
 * Operator overloading (!=) to check if one line object is NOT equal to another
 * This function re-uses the operator ==
 * @return boolean value
 * */
bool operator!=(const Line& line1, const Line& line2){
    return !(line1==line2);
}