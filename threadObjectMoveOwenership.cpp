#include <iostream>
#include <thread>

using namespace std;

void helloNumber( int n)
{
    cout <<" hello thread " << "\n";
    cout <<" number is "<< n << "\n";
}


void hello( )
{
    cout << " hello thread " << "\n";\
}

thread funReturn()
{
       thread threturn(helloNumber , 12);

       cout << " threturn id : "<< threturn.get_id() << "\n";

       return threturn;

}

void fun(thread &&thr)
{

    cout << " movin owenrship of thread \n";
    cout << "id in fun for thread: " << thr.get_id() << "\n";
    thr.join();
}

int main()
{
    thread th(hello);

    cout << " main thread id: " << this_thread::get_id() << "\n";
    cout << "id for thr for in main: " << th.get_id() << "\n";

    fun(move(th)); // moving owener ship of thread object

    cout << "id for thr for in main after moving: " << th.get_id() << "\n";

    fun(thread(hello)); // temporary object.


    thread getthr = funReturn();

    cout << " thReturn id gethtr : "<< getthr.get_id() << "\n";

    getthr.join();

}