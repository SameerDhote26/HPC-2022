#include <iostream>
#include <omp.h>
using namespace std;

// Main function

int main()
{

    // specify the  block to be executed in parallel
#pragma omp parallel
    {
        // print hello world for each thread
        cout << "hello world" << endl;
    }
    return 0;
}