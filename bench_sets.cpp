#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
#include <chrono>

using namespace std;

int main()
{
    unordered_set< string >  us;
    set< string >            os;

    string filename = "words.txt";
    ifstream file(filename);
    if( !file ) {
        cerr << "Unable to open the file: \"" << filename << "\"\n";
        return 1;
    }
    cout << "file opened\n";

    string word;
    while(file) {
        file >> word;
        us.insert(word);
        os.insert(word);
    }

    {
        cout << "Test ordered set: ";
        chrono::high_resolution_clock clk;
        auto t1 = clk.now();
        //auto os_end = os.end();
        for( string w : us ) {
            os.find(w);
        }
        auto dt = clk.now() - t1;

        int ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
        cout << ms << " ms.\n";
    }

    {
        cout << "Test unordered set: ";
        chrono::high_resolution_clock clk;
        auto t1 = clk.now();
        //auto os_end = os.end();
        for( string w : us ) {
            us.find(w);
        }
        auto dt = clk.now() - t1;

        int ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
        cout << ms << " ms.\n";
    }

    return 0;
}
