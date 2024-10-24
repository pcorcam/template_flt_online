// #include <iostream>
#include <fstream>
#include "template_FLT.h"
#include "utils.h"
#include <chrono>

using namespace std;

Eigen::ArrayXi load_test_trace(string test_trace_file_name){
    
    Eigen::ArrayXi trace(1024);

    ifstream test_trace_file(test_trace_file_name);
    string line;

    int i = 0;
    while( getline(test_trace_file, line) ){

        istringstream iss(line);
        int value;

        while(iss>>value){
            trace[i] = value;
        }

        i += 1;
    }

    return trace;
}

int main() {
    Eigen::ArrayXi test_trace = load_test_trace("test_trace.txt");

    string template_file_name = "/sps/grand/pcorrea/nutrig/template/lib/templates_96_XY_rfv2.txt";

    TemplateFLT flt(template_file_name);

    int t_max;
    int trace_max = test_trace.maxCoeff(&t_max);
    // --> this we will want to do in the object?

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    flt.template_fit(test_trace,
                     t_max);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();      

    cout<<"t_peak_best = "<<flt.t_peak_best<<"\t";
    cout<<"corr_max_best = "<<flt.corr_max_best<<"\t";
    cout<<"template_id_best = "<<flt.template_id_best<<"\t";
    cout<<"idx_template_desampled_best = "<<flt.idx_template_desampled_best<<endl;
    cout << "Computation time = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " µs" << endl;

    return 0;
};