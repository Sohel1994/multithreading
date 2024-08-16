
#include <iostream>
#include <thread>
#include<vector>
#include<set>
using namespace std;

class hello
{

    public:
    void fun()
    {
        cout << " thraed id for fun() function "<<  this_thread::get_id() <<" \n";
        cout << " I am hello fun  class calling by thread "<< "\n";
    }
};

int main()
{
      hello h;

      cout << "main thraed id is "<<  this_thread::get_id() <<" \n" ; // for main thread.

      thread thr (&hello::fun , &h);  

      cout <<"thread id for thr object hello  class fun() "<< thr.get_id()<<"\n"; // for thr object.

      cout << "thread handle {pointer} by system for thr object hello class fun() " << thr.native_handle() << "\n"; // execution thread has handle used by system 
                                                                                                              // which is some kind of pointer.

      thr.join(); // thread to join main thread after execution.

      cout <<"thread id for  thr hello class fun() "<< thr.get_id()<<"\n"; //non executing thread so no handle.

      cout << "thread handle {pointer} by system after execution " << thr.native_handle() << "\n"; // it gives null pointer after execution thread.



}