//
//  Command.cpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/31.
//

#include "Command.hpp"

Command::Command(string codeLine) : ready(false) {
    nextCommand = NULL;
    parser(codeLine);
}

Command::~Command() {}

void Command::split(string& s, string& delim, vector<string>* ret) {
    size_t last = 0;
    size_t index=s.find_first_of(delim, last);
    
    while (index != string::npos) {
        ret->push_back(s.substr(last, index-last));
        last = index+1;
        index = s.find_first_of(delim, last);
    }
    
    if (index-last>0) {
        ret->push_back(s.substr(last, index-last));
    }
}

void Command::parser(string codeLine) {
    string delim = ",";
    vector<string> program;
    split(codeLine, delim, &program);
    
    if (program.size() >= 4) {
        preStatus = program[0];
        preValue = program[1].c_str()[0];
        setValue = program[2].c_str()[0];
        move = program[3].c_str()[0];
        setStatus = program[4];
        ready = true;
    }
}

bool Command::isReady() {
    return ready;
}

string Command::print() {
    string str = preStatus + " " +  preValue +  ", " + setValue +  " " + move + " " + setStatus;
    return str;
}

void Command::setNext(Command& c) {
    nextCommand = &c;
}

void Command::exec(TuringModel& t) {
    if (t.isHandler(preStatus, preValue)) {
        t.write(setValue);

        switch (move) {
            case LEFT:
                t.moveLeft();
                break;
            case RIGHT:
                t.moveRight();
                break;
                
            default:
                break;
        }
        
        t.setStatus(setStatus);
    }
}
