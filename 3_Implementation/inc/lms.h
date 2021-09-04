#ifndef LMS_H // include guard
#define LMS_H

class Lib
{
   public:
       char bookname[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       
          void get();
          void student();
          void pass();
          void librarian();
          void password();
          void getdata();
          void show(int);
          void booklist(int);
          void modify();
          void see(int);
          int branch(int);
          void issue();
          void der(char[],int,int);
          void fine(int,int,int,int,int,int);
};


#endif
