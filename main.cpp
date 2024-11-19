#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;

int main(){
    #include <fstream>
    std::ifstream file("test_input");
    char c;
    vector<char> code;
    while(file>>c){
        if(c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == ',' || c == '.' ){
            code.push_back(c);
        }
    }
    return 0;
}