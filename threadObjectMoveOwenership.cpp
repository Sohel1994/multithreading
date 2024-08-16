#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout << " hello thread " << "\n";
}

void fun(thread thr)
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
}