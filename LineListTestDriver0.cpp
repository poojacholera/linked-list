#include<iostream>
#include<iomanip>
#include<fstream>
#include<cassert>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

#include "Line.h"
#include "LineList.h"

// function prototypes
bool operator== (const LineList &, const LineList &);
bool operator!= (const LineList &, const LineList &);
void load_linked_list(const char * , LineList &);
void test_linked_list_operations(LineList&);

// -------

int main1(){

    //testing Line ctor
    /*const char *s = "meet";
    cout<< s <<endl;
    Line first(s);
    cout<<first.length()<<endl;
    cout<<first.cstr()<<endl;
*/
    //testing line copt ctor
    /* const char *s1 = "meet";
     Line line1(s1);
     cout<<line1.cstr()<<endl;
  //   const char *s2 = "meetoo";
     //test copy ctor
     Line line2(line1);
     cout<<line2.cstr()<< " " << line2.length()<<endl;
     Line line3(s2);
    */
 //  Line line2="abc";
    //test copy assignment
//    line2 = line1;
   // cout<<line2.cstr()<< " " << line2.length()<<endl;
/*

    // test pushback and popback-Line  and resize
    const char *s2 = "meeto";
    char c = 'p';
    //test copy ctor
    Line line2(s2);
    cout<< line2.cstr() << ":" <<line2.length()<< ":" <<line2.getCapacity()<<endl;
    line2.push_back(c);
    cout<< line2.cstr() << ":" <<line2.length()<< ":" <<line2.getCapacity()<<endl;
*/
    /*
    line2.pop_back();
    cout<< line2.cstr() << ":" <<line2.length()<< ":" <<line2.getCapacity()<<endl;
/*

    //test ==  !=   operator
    const char *s1 = "blasoo  2space";
    Line line1(s1);
    const char *s2 = "blahoo  2space";
    Line line2(s2);
    cout<< (line1 == line2) <<endl;
    cout << (line1 != line2) <<endl;
*/

  /*  //Testing pushback, push front, popback and pop front
  const char *s1 = "blaspoo jaoo";
    const char *s2 = "spoo jaoo";
    Line line1(s1);
    Line line2(s2);

    LineList list_a {};


    list_a.push_back(line1);
    list_a.push_back(line2);
    list_a.push_front("abc");
    list_a.push_front("pc");
    list_a.push_front("two");
    list_a.push_front("one");
    *//*  list_a.pop_back();
      list_a.pop_front();
  *//*
    list_a.print();
    *//*list_a.get(2)<*//*
    cout<<"GET :  "<<endl;
    //list_a.remove(6);
    list_a.insert(s1,2);
    list_a.print();
*/
    //Testing Copy Assignment
     /*     LineList list_b {};
            list_b.push_front("two");
            list_b.push_front("one");
          list_a=list_b;

          cout<<"after"<< list_a.size()<<endl;
          list_a.print();*/
    //Testing copy ctor LINLELIST
      /*      LineList list_b(list_a);
            list_b.print();
*/
    /*//Testing Pushback _ LineList
        list_a.push_back(line1);
    list_a.print();*/
  /*  char *lineptr="pooja";
    char temp[10];
    char *tempPtr=&temp[0];
    strcpy(tempPtr,lineptr);


    //temp=lineptr;  sizeof(lineptr)/

    cout<<temp <<strlen(temp)<< sizeof(temp)<<endl;
    cout<<lineptr<<strlen(lineptr)<< (sizeof(lineptr)/ sizeof(*lineptr))<<endl;*/

    /*const char *c_linea = "First Line";
    const char *c_lineb = "First Line";

    LineList lista{};
    LineList listb{};
    lista.push_back(c_linea);
    listb.push_back(c_lineb);
    lista.print();
    listb.print();
    assert(lista==listb);*/

//    Line someLine(c_line);          // lineLength = 2, capacity = 2
//    someLine.push_back('X');   // lineLength = 3, capacity = 4
//    someLine.push_back('Y');   // lineLength = 4, capacity = 4
//    someLine.push_back('Z');   // lineLength = 5, capacity = 8
//    cout << "someLine: " << someLine.cstr()                       << endl; // ABXYZ
//    cout << "len: "           << someLine.length()          << endl; // len: 5
//    cout << "cap: "          << someLine.getCapacity() << endl; // cap: 8

//    cout<<"end..."<<endl;
//    cout<<someLine<<endl;

//    Line newLine("ok");
//    cout<<newLine;
//    cin>>newLine;
//    cout<<"content of new line"<<endl;
//    cout<<newLine << " "<<newLine.getCapacity()<< " "<<newLine.length()<<endl;

    /*cout<<"test..."<<endl;
    char *temp{new char[5]{'\0'}};
    int j=0;
    while(j<=4){
        if(temp[j]=='\0')
        { cout<<"true"<<endl;}
        else{
            cout<<"false"<<endl;
        }
        j++;
    }*/



    /*Line newLine("pooja");
    int i=newLine.getCapacity()-1;
    while(i>=0){
        if(newLine.linePtr[i]=='\0')
        { cout<<newLine.linePtr[i]<<" true"<<endl;}
        else{
            cout<<newLine.linePtr[i]<<" false"<<endl;
        }
        i--;
    }*/

}

int main()
{
   //const char * filename_a{ "C:\\input_a.txt" };
   const char * filename_a{ "/home/meet/Documents/5421/input_a.txt" };
   //const char * filename_b{ "C:\\input_b.txt" };
   const char * filename_b{ "/home/meet/Documents/5421/input_b.txt" };

   LineList list_a {};
   load_linked_list(filename_a, list_a);      // load our first list list_a
   cout << "list_a loaded" << "\n";
   list_a.print();                           // print list_a

   test_linked_list_operations(list_a);      // manipulate lines in list_a
   cout << "\n" << "list_a rearranged" << "\n";
   list_a.print();                           // print manipulated list_a

   LineList list_b {};
   load_linked_list(filename_b, list_b);     // load our second list list_b
   assert(list_a == list_b);                 // test operator=

   cout << "Done!" << endl;
   return 0;                                // report success
}

/*
Loads the supplied line_list  with the lines of a given text file.
@ filename The name of the given text file.
@ line_list The LineList object to load.
*/
void load_linked_list(const char *filename, LineList & line_list)
{
   std::ifstream ifs(filename, std::ifstream::in);
   if (!ifs.is_open())
   {
      cout << "Unable to open file" << filename << endl;
      exit(0);
   }

   int lineno = 0;
   std::string line;
   while (getline(ifs, line)) // Read until end of file
   {
      ++lineno;
      //cout << "(" << lineno << ") " << line << endl;
      const char *c_line = line.c_str(); // const makes this a safe idea.
      // Get a pointer to the c-string represented by the C++ string object
      // ONLY because Line's Ctor in the call below expects a char *
      line_list.push_back(Line(c_line));
   }
}

/*
Tests opeations provided by a given LineList object.
@ line_list The LineList object to use troughout the test.
*/
void test_linked_list_operations(LineList& line_list)
{

   if (line_list.empty()) return;                   // test empty()

   int lastPos = line_list.size();                  // size
   line_list.remove(lastPos);                       // remove
   if (line_list.empty()) return;                   // empty

   line_list.remove(1);                             // remove
   if (line_list.empty()) return;                   // empty

   Line lastline = line_list.get(line_list.size()); // get, copy ctor
   line_list.pop_back();                            // pop_back
   if (line_list.empty()) return;                   // empty

   Line line1 = line_list.get(1);                   // get
   line_list.pop_front();                           // pop_front()
   if (line_list.empty()) return;                   // empty

   line1 = line_list.get(1);                        // get, operator=
   line_list.pop_front();                           // pop_front();
   line_list.push_front(lastline);                  // push_front
   line_list.push_back(line1);                      // push_back
   if (line_list.size() >= 3)                       // size
      line_list.insert(Line("Line  3"), 3);         // insert

   line_list.insert(Line("Welcome to C++"), 1);     // insert
   line_list.push_back(Line("Have fun!"));          // push_back
}

/*
An oveload for operator==. Considers two lists equal
if they each have the same number of lines and same lines.
@ list1 The left hand side operand.
@ list2 The right hand side operand.
*/
bool operator== (const LineList &list1, const LineList &list2)
{
   if (list1.size() != list2.size()) return false;
   for (size_t i{ 1 }; i <= list1.size(); ++i)
   {
      if (list1.get(i) != list2.get(i)) return false;
   }
   return true;
}
/*
An oveload for operator!=. Considers two lists unequal
if they they are not equal.
@ list1 The left hand side operand.
@ list2 The right hand side operand.
*/
bool operator!= (const LineList &list1, const LineList &list2)
{
    return !(list1 == list2);
}


