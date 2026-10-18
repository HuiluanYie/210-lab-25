// COMSC-210 | Lab 25 | Huiluan Yie

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;

int main() {
    // declaration
    string t;
    vector<string> v;
    list<string> l;
    set<string> s;

    

    // measure
    // file input
    ifstream fin;
    fin.open("codes.txt");
    if (fin.good()) {
        //READING
        // vector:
        // Start timing
        auto start = high_resolution_clock::now();
        while (getline(fin, t)) {
            v.push_back(t);
        }
        // End timing
        auto end = high_resolution_clock::now();
        // Calculate duration
        auto vec_read = duration_cast<nanoseconds>(end - start);

        // list:
        // Start timing
        start = high_resolution_clock::now();
        while (getline(fin, t)) {
            l.push_back(t);
        }
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto lst_read = duration_cast<nanoseconds>(end - start);

        // set:
        // Start timing
        start = high_resolution_clock::now();
        while (getline(fin, t)) {
            s.insert(t);
        }
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto set_read = duration_cast<nanoseconds>(end - start);

        fin.close();
    } else
        cout << "File not found.\n";

    

    
    
    
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