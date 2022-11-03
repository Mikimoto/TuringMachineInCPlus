//
//  Turing.hpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/30.
//

#ifndef Turing_hpp
#define Turing_hpp

#include <stdio.h>
#include "Share.h"
#include "TuringModel.hpp"
#include "TuringView.hpp"
#include "Command.hpp"

using namespace::std;

class Turing {
private:
    TuringModel model;
    TuringView viewer;
    vector<Command> commands;
 
    void readCode(const char* file);
    void handle(Command& command);

public:
    Turing(const char* file);
    ~Turing();
    
    void run();
};

#endif /* Turing_hpp */
