// COMSC-210 | Lab 25 | Huiluan Yie

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;
using namespace std::chrono;

int main() {
    // Start timing
    auto start = high_resolution_clock::now();

    // measure
    // file input
    ifstream fin;
    fin.open("210-lab-15-movie.txt");
    if (fin.good()) {
        
    fin.close();
    } else
        cout << "File not found.\n";

    // End timing
    auto end = high_resolution_clock::now();
    // Calculate duration
    auto duration = duration_cast<nanoseconds>(end - start);

    
    
    
    // Output the duration in nanoseconds
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/