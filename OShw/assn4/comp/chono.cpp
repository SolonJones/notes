
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
#include<unistd.h>

using namespace std;
using namespace std::chrono;
  
int main()
{
  
 
    // Get starting timepoint
    auto start = high_resolution_clock::now();
  
    // Call the function, here sort()
    sleep(10); 
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
  
    return 0;
}
