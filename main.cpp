#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;

int main(){
    #include <fstream>
    std::ifstream file("source");
    char c;
    vector<char> code;
    while(file.get(c)){
        if(c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == ',' || c == '.' ){
            code.push_back(c);
        }
    }
    return 0;
}