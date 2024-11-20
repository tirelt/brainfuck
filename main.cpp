#include <vector>
#include <string>
#include <fstream>
#include <utility>

using std::vector;
using std::pair;
using std::string;

bool check_code(vector<char>& code){
    if(code.front() == '[' || code.front() == ']')
        return false;
    
}

void process(vector<pair<char,char>>::iterator& ite){
    if(ite->first=='+')
            ite++->second++;
        if(ite->first=='-')
            ite++->second--; 
        if(ite->first=='>')
            ++ite;
        if(ite->first=='<')
            --ite;
        if(ite->first=='.')
            putchar(ite->second);
        if(ite->first==',')
            ite->second = getchar();
}

int main(){
    #include <fstream>
    std::ifstream file("source");
    char c;
    constexpr unsigned size = 30000;
    vector<pair<char,char>> code;
    while(file.get(c)){
        if(c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == ',' || c == '.' ){
            code.emplace_back(c,0);
        }
    }
    vector<pair<char,char>>::iterator ite = code.begin();
    vector<pair<char,char>>::iterator saved_ite;
    while(ite!=code.end()){
        if(ite->first=='['){
            saved_ite = ite;
            --saved_ite;
            ++ite;
            while(saved_ite->second){
                if(ite->second==']'){
                    if(saved_ite->second){
                        ite = saved_ite;
                        ++++ite;
                    } else{
                        ++ite;
                        continue;
                    }
                } else {
                    process(ite);
                } 
            }
        } else{
            process(ite);
        }
    }
    return 0;
}