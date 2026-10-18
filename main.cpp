// COMSC-210 | Lab 25 | Huiluan Yie

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
using namespace std::chrono;

const string TESTCODE = "6vHBe9^e";

int main() {
    // declaration
    string t;
    vector<string> v;
    list<string> l;
    set<string> s;

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
        
        //SORTING
        // vector:
        // Start timing
        start = high_resolution_clock::now();
        sort(v.begin(), v.end());
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto vec_sort = duration_cast<nanoseconds>(end - start);

        // list:
        // Start timing
        start = high_resolution_clock::now();
        l.sort();
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto lst_sort = duration_cast<nanoseconds>(end - start);
        
        // set:
        // the set's value is -1 since a set is already sorted.
        auto set_sort = -1;


        //INSERTING
        // vector:
        auto v_it = v.begin();
        // make the iterater point to the middle
        for (int i = 0; i < v.size() / 2; i++)
        {
            v_it++;
        }
        // Start timing
        start = high_resolution_clock::now();
        v.insert(v_it, TESTCODE);
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto vec_insert = duration_cast<nanoseconds>(end - start);

        // list:
        auto l_it = l.begin();
        // make the iterater point to the middle
        for (int i = 0; i < l.size() / 2; i++)
        {
            l_it++;
        }
        // Start timing
        start = high_resolution_clock::now();
        l.insert(l_it, t);
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto lst_insert = duration_cast<nanoseconds>(end - start);
        
        // set:
        // Start timing
        start = high_resolution_clock::now();
        
        // End timing
        end = high_resolution_clock::now();
        // Calculate duration
        auto lst_insert = duration_cast<nanoseconds>(end - start);
        
        
        
        
        // Output the duration in nanoseconds
        cout << "Time taken: " << duration.count() << " nanoseconds\n";


        fin.close();
    } else
        cout << "File not found.\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/