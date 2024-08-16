#include<iostream>
#include<thread>
using namespace std;

class hello 
{
    public :
     
    void fun()
    {
          this_thread::sleep_for(2s); //std::chrono::seconds()
          cout<< " thread hello fun() "<<"\n";
    }

};

int main()
{
     hello h;


    this_thread::sleep_for(2s); // main thread sleeps for 2 seconds
    cout<<"starting thread ......."<< "\n";
    thread thr(&hello::fun, &h);

     thr.join();

}