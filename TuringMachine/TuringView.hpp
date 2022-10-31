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

using namespace::std;

class TuringView {
private:
    void printUpperLine();
    void printData(TuringModel& data);
    void printUnderLine();
    void printReadWriteHeader(TuringModel& data);
    
public:
    TuringView();
    ~TuringView();
    
    void refresh(TuringModel& model);
};

#endif /* TuringView_hpp */
