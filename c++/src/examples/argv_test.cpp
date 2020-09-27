#include<iostream>
#include "constant.cpp"
using namespace std;

extern char **environ;

void printArgv(int argc, char *argv[], char *&end){
    if (!(end = argv[3])){
        return;
    }
    cout<<SplitLine;
    for(int idx = 0; idx < argc || (idx >=argc && argv[idx]); idx++){
        end += strlen(argv[idx])+1;
        cout<<static_cast<void*>(argv[idx]) << " = "<<argv[idx]<<" end_addr: "<<static_cast<void*>(end)<<endl;
    }
    cout<<SplitLine;
}

void printEnviron(char *&end){
        for(int idx = 0; environ[idx]; idx++){
            end += strlen(environ[idx]) + 1;
            cout<<static_cast<void*>(environ[idx])<<" = "<<environ[idx]<<" end_addr: "<<static_cast<void*>(end)<<endl;
    }
}

int main(int argc, char *argv[]){
    char *end = (char *)"";
    char *argv2[1];
    printArgv(argc, argv2, end);
    printEnviron(end);
}