#include <iostream>
#include <thread>

using namespace std;

void fun( int );
int main()
{
   int n = 20;
   thread thr(fun, n);  // Pass the argument to the thread
   thr.join();  // Wait for the thread to finish
    return 0;
}

void fun( int n )
{
      for ( int i = 0 ; i < n; ++i)
      {
         if ( (i % 3 == 0) && (i % 5 == 0))
         {
            cout << " fizzbuzz "<< " \n";
         }
         else if(i % 3 == 0)
         {
            cout << " fizz "<< " \n";
         }
         else if(i % 5 == 0)
         {
            cout << " buzz "<< " \n";
         }
         else 
         cout << " no :" << i << " \n";
         
        } 
}