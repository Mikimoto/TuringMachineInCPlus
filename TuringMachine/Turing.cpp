//
//  Turing.cpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/30.
//

#include "Turing.hpp"

//void printCommandVector(Command& command) {
//    command.print();
//}

Turing::Turing() {
    readCode("/Users/mikimoto/Developer/DeepThought/TuringMachine/code.txt");
    viewer.refresh(model);
}

Turing::~Turing() {
    
}

void Turing::readCode(const char* file) {
    system("pwd");
    std::ifstream infile(file);
    if (infile.is_open()) {
        std::string line;
        int rLine = 0;
        while (std::getline(infile, line)) {
            if (rLine == 0) {
                model.setupData(line);
            } else {
                Command command(line);
                if (command.isReady()) {
                    commands.push_back(command);
                }
            }
            rLine++;
        }
        infile.close();
    }
//    for_each(commands.begin(), commands.end(), printCommandVector);
}

void Turing::handle(Command& command) {
    command.exec(model);
    sleep(1);
    viewer.refresh(model);
}

void Turing::run() {
    while ( 1 ) {
        for_each(commands.begin(), commands.end(), bind_front(&Turing::handle, this));
    }
}
