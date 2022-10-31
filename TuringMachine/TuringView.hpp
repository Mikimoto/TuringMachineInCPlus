//
//  TuringView.hpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/31.
//

#ifndef TuringView_hpp
#define TuringView_hpp

#include <stdio.h>
#include "Share.h"
#include "TuringModel.hpp"
#include "Command.hpp"

using namespace::std;

class TuringView {
private:
    void printUpperLine();
    void printData(TuringModel& data);
    void printUnderLine();
    void printReadWriteHeader(TuringModel& data, Command& command);
    
public:
    TuringView();
    ~TuringView();
    
    void refresh(TuringModel& model, Command& command);
};

#endif /* TuringView_hpp */
