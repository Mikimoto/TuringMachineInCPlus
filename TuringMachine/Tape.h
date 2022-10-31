//
//  Tape.h
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/30.
//

#ifndef Tape_h
#define Tape_h

#include "Share.h"

using namespace::std;

class Tape {
private:
    char tapeData[TAPELENGTH];  // 紙帶內容
    
public:
    Tape();
    ~Tape();
    
    char getData(int i);
};

class TapeView {
private:
    void printUpperLine();
    void printData(Tape& data);
    void printUnderLine();
    
public:
    TapeView();
    ~TapeView();
    void draw(Tape &data);
};

class TapeController {
private:
    Tape model;
    TapeView view;
public:
    TapeController();
    ~TapeController();
    void refresh();
    void initTape(string& s);
};


#endif /* Tape_h */
