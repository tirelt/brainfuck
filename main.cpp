#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;

constexpr unsigned SIZE = 30000;

vector<char>  get_code(std::ifstream& file){
    int bracket_check=0,pos_check=0;
    char c;
    vector<char> code;
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
    return code;

}

void process(list<int>::iterator& ite, char& c,list<int>& list){
    if(c=='+')
        ++(*ite);
    if(c=='-')
        --(*ite); 
    if(c=='>'){
        if(ite == --list.end()){
            list.push_back(0);
            ite = --list.end();
        } else {
            ++ite;
        }
    }
    if(c=='<'){
        if(ite == list.begin()){
            list.push_front(0);
            ite = list.begin();
        } else {
            --ite;
        }
    }
    if(c=='.')
        cout << char(*ite);
    if(c==','){
        cout << endl;
        cin >> *ite;
    }
}

vector<char>::iterator find_closing(vector<char>::iterator begin, vector<char>::iterator end, char target){
    unsigned counter = 1;  
    while(begin != end && counter != 0){
        ++begin;
        if(*begin=='[')
            counter += 1;
        if(*begin==']')
            counter -= 1;
    }
    return begin;
}
void process_code(vector<char>::iterator begin, vector<char>::iterator end,list<int>::iterator& ite,list<int>& list){
    for(auto ite_code=begin;ite_code!=end;++ite_code){
        if(*ite_code=='['){
            ++ite_code;
            auto new_end = find_closing(ite_code,end,']');
            while(*ite){
                process_code(ite_code,new_end,ite,list);
            }
            ite_code = new_end;
        } else{
            process(ite,*ite_code,list);
        }
    }
}
int main(){
    std::ifstream file("source");
    vector<char> code = get_code(file);
    file.close();

    list<int> table(1,0);
    list<int>::iterator ite = table.begin();
    process_code(code.begin(),code.end(),ite,table);
    return 0;
}