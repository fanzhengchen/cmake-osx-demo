#include "foo.h"
#include <iostream>
#include <fstream>
using namespace std;
void print_file(const char *name){
    char buf[256];
    ifstream in(name, ios::in);

    
    while(!in.eof()){
        in.getline(buf, 100);
        cout<<buf<<endl;
    }
    in.close();
}
