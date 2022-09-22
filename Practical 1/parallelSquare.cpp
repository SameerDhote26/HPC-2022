#include <iostream>
#include <omp.h>
using namespace std;
#define THREAD_CNT 4
// Main function

int main()
{
    // specify the  block to be executed in parallel
    int i = 0;
    omp_set_num_threads(THREAD_CNT);
#pragma omp parallel
    {

        while (i <= 100)
        {
            cout << "Thread No: " << omp_get_thread_num() << ": ";
            cout << i * i << endl;
            i++;
        }
    }
    return 0;
}