#include <iostream>
#include <exception>
#include <thread>

using namespace std;

void fun()
{

    // thred exception within the task function block
    try
    {
        throw exception(); // exception object cerated.
    }

    catch (exception &e)
    {
        cout << " thread exception is " << e.what() << "\n";
    }

    cout << " Hello therad  fun()" << "\n";
}

void hello()
{

    throw exception();

    cout << " hello() therad " << "\n";
}

int main()
{

    // thread thr(fun);

    // thr.join();

    // cout << " programme finished\n";


//=================================================================================================================//

    // programme will terminate if exception not handle wihtin calling thread task function or any othrer thread.
    // output->
    // terminate called after throwing an instance of 'std::exception'
    // what():  std::exception

    try
    {

        thread th(hello);
        th.join();
    }

    catch (exception &e)
    {
        cout << " thread exception is " << e.what() << "\n";
    }

    cout << " programme check finished \n";
}