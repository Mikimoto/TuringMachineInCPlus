//
//  Command.hpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/31.
//

#ifndef Command_hpp
#define Command_hpp

#include "Share.h"
#include "TuringModel.hpp"

using namespace::std;

class Command {
private:
    string preStatus;
    char preValue;
    char move;
    char setValue;
    string setStatus;
    bool ready;
    Command* nextCommand;
    
    void split(string& s, string& delim, vector<string>* ret);
    
public:
    Command(string codeLine);
    ~Command();
    
    void parser(string codeLine);
    bool isReady();
    string print();
    void setNext(Command& c);
    void exec(TuringModel& t);
};

#endif /* Command_hpp */
