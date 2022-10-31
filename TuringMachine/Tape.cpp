//
//  Tape.cpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/30.
//

#include "Tape.h"

using namespace::std;

Tape::Tape() {
    for( int i=0; i<TAPELENGTH; i++) {
        tapeData[i] = '0';
    }
}

Tape:: ~Tape() {}
    
char Tape::getData(int i) {
    return tapeData[i];
}

void TapeView::printUpperLine() {
    cout << LEADSTR; // 前面有八個空格
    for (int i=0; i<TAPELENGTH; i++ ) {
        printf("＿＿");
    }
    cout << endl;
}

void TapeView::printData(Tape& data) {
    cout << LEADSTR << "|";
    for (int j=0; j<TAPELENGTH; j++ ) {
        printf(" %c |",data.getData(j));
    }
    cout << endl;
}

void TapeView::printUnderLine() {
    cout << LEADSTR;
    for (int k=0; k<TAPELENGTH; k++ ) {
        printf("￣￣");
    }
    cout << endl;
}

TapeView::TapeView() {}
    
TapeView:: ~TapeView() {}
    
void TapeView::draw(Tape &data) {
    printUpperLine();
    printData(data);
    printUnderLine();
}

TapeController::TapeController() {}
    
TapeController::~TapeController() {}
    
void TapeController::refresh() {
    view.draw(model);
}

void TapeController::initTape(string& s) {
}

