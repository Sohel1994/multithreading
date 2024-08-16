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
        cout << " i am hello class calling by thread "<< "\n";
    }
};

int main()
{
     hello h;
    //thred for class member function 
    //pass address of member function and address of object of class

    thread thr ( &hello::fun,&h);
    thr.join();

    //for lambda expression 
    int i = 3;
    thread thr1([&i](){
        cout << " thread lambda expression i is : "<<i*3<<"\n";
    });

    thr1.join();
 
      // for lambda with expresion.
     thread thr2([](int n1, int n2) {
        cout << "Thread n1 is " << n1 << " and thread n2 is " << n2 
             << ". Sum of n1 and n2 is: " << n1 + n2 << "\n";
    }, 5, 6);

  
    
    thr2.join();



    // std::vector<int> nums {1, 2, 3, 4, 5, 3, 2, 6, 7, 8, 6}; // Example array with duplicates
    // std::set<int> seen;

    // for ( int &n : nums )
    // {
    //     seen.insert(n);
    // }

    // for (int s : seen)
    // {
    //      cout  << s << " ";
    // }
}