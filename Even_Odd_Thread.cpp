// Printing even and odd numbers using two threads in C++
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex m;
condition_variable cv;
int counter = 1;

void PrintOdd(int num)
{
    for (int i = 0;i < num;i++)// Printing even and odd numbers using two threads in C++
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex m;
condition_variable cv;
int counter = 1;

void PrintOdd(int num)
{
    for (int i = 0;i < num;i++)
    {
        unique_lock< mutex> lock(m);
        cv.wait(lock, []()
            {
                return (counter % 2 == 1);
            });

        if (counter > num)
            break;

        cout << " Odd Thread : " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}
void PrintEven(int num)
{
    for (int i = 0;i < num;i++)
    {
        unique_lock< mutex> lock(m);
        cv.wait(lock, []()
            {
                return (counter % 2 == 0);
            });
        
        if(counter > num) 
			break;

        cout << " Even Thread : " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}

int main()
{
    int num = 10;
    thread t1(PrintOdd, num);
    thread t2(PrintEven, num);
    t1.join();
    t2.join();
    return 0;
}

    {
        unique_lock< mutex> lock(m);
        cv.wait(lock, []()
            {
                return (counter % 2 == 1);
            });

        if (counter > num)
            break;

        cout << " Odd Thread : " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}
void PrintEven(int num)
{
    for (int i = 0;i < num;i++)
    {
        unique_lock< mutex> lock(m);
        cv.wait(lock, []()
            {
                return (counter % 2 == 0);
            });
        
        if(counter > num) 
			break;

        cout << " Even Thread : " << counter << endl;
        counter++;
        lock.unlock();
        cv.notify_all();
    }
}

int main()
{
    int num = 10;
    thread t1(PrintOdd, num);
    thread t2(PrintEven, num);
    t1.join();
    t2.join();
    return 0;
}
