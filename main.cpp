#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::array;
using std::string;
using std::cout;
using std::cin;
using std::endl;

constexpr unsigned SIZE = 30000;

bool check_code(vector<char>& code){
    if(code.front() == '[' || code.front() == ']')
        return false;
    
}

void process(array<char,SIZE>::iterator& ite, char& c){
    if(c=='+')
        ++(*ite);
    if(c=='-')
        --(*ite); 
    if(c=='>')
        ++ite;
    if(c=='<')
        --ite;
    if(c=='.')
        cout << *ite;
    if(c==','){
        cout << endl;
        cin >> *ite;
    }
}

int main(){
    #include <fstream>
    std::ifstream file("source");
    char c;
    array<char,SIZE> table;
    vector<char> code;
    int bracket_check=0,pos_check=0;
    while(file.get(c)){
        if(c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == ',' || c == '.' ){
            if(c == '[')
                ++bracket_check;
            if(c == ']')
                --bracket_check;
            if(c == '>')
                ++pos_check;
            if(c == '<')
                --pos_check;
            if(pos_check>=SIZE || pos_check<0)
                throw std::runtime_error("Pointer going out of memory");
            if(bracket_check<0)
                throw std::runtime_error("Too many closing brackets");
            code.emplace_back(c);
        }
    }
    if(bracket_check)
        throw std::runtime_error("Unclosed brakcet");

    array<char,SIZE>::iterator ite = table.begin();
    array<char,SIZE>::iterator saved_ite;
    unsigned saved_pos;
    for(unsigned i=0;i<code.size();++i){
        if(code[i]=='['){
            saved_ite = ite;
            ++i;
            saved_pos = i;
            while(*saved_ite){
                if(code[i]==']'){
                    i = saved_pos;
                } else {
                    process(ite,code[i]);
                    ++i;
                } 
            }
        } else{
            process(ite,code[i]);
        }
    }
    return 0;
}