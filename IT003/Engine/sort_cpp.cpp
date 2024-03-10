#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

string get_file_name(int fd){
    string filename = (string)"../TestCase/random_case" + to_string(fd) + (string)".txt";
    return filename;
}

int main(){

    cout << "[Sortcpp] Sortcpp engine starting ...\n";
    double *array = new double[sizeof(double) * 1000000];
    cout << fixed << setprecision(15);

    for (int fd = 1; fd < 11; ++fd){
        string filename = get_file_name(fd);
        ifstream testcase(filename); //read

        if (testcase.is_open()){

            for (int j = 0; j < 1000000; ++j){
                testcase >> array[j];
            }
            auto begin = high_resolution_clock::now();
            sort(array, array + 1000000);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - begin);
            cout << "[Sortcpp] Testcase no." << fd << " took " << duration.count() << " ms\n";
        }

        else{
            cout << "[Sortcpp] Error occured! Can't open random_case" << fd << ".txt" << ". Aborting ...\n";
            return 0;
        }

    }

    cout << "[Sortcpp] Task completed!\n";
    delete[] array;
    return 1;
}
