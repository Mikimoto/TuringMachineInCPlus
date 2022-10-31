//
//  TuringView.cpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/31.
//

#include "TuringView.hpp"

using namespace::std;

TuringView::TuringView() {}

TuringView::~TuringView() {}

void TuringView::printUpperLine() {
    cout << LEADSTR; // 前面有八個空格
    for (int i=0; i<TAPELENGTH; i++ ) {
        printf("＿＿");
    }
    cout << endl;
}

void TuringView::printData(TuringModel& data) {
    cout << LEADSTR << "|";
    for (int j=0; j<TAPELENGTH; j++ ) {
        printf(" %c |",data.getData(j));
    }
    cout << endl;
}

void TuringView::printUnderLine() {
    cout << LEADSTR;
    for (int k=0; k<TAPELENGTH; k++ ) {
        printf("￣￣");
    }
    cout << endl;
}

void TuringView::printReadWriteHeader(TuringModel& data, Command& command) {
    cout << LEADSTR;
    for (int l=0;  l<=data.getPoint(); l++) {
        if (l == 0) {
            printf("  ");   // 2個字元
        } else {
            printf("    "); // 4個字元
        }
    }
    printf("▲");
    cout << endl << endl;
    
    cout << "[ 狀態 ]:" << data.getStatus() << "     [ 位置 ]:" << data.getPoint()+1 <<  "         [ 指令 ]:" << command.print() << endl;
}

void TuringView::refresh(TuringModel& data, Command& command) {
    system("clear");
    
    printUpperLine();
    printData(data);
    printUnderLine();
    printReadWriteHeader(data, command);
}
