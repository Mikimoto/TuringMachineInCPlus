//
//  TuringModel.hpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/31.
//

#ifndef TuringModel_hpp
#define TuringModel_hpp

#include <stdio.h>
#include "Share.h"

using namespace::std;

class TuringModel {
private:
    char tapeData[TAPELENGTH];  // 紙帶內容
    string reg; // 狀態暫存器
    int point = 0;
    
public:
    TuringModel();
    ~TuringModel();
    
    char getData(int i);
    int getPoint();
    void setupData(string var);
    bool isHandler(string status, char val);
    void moveLeft();
    void moveRight();
    void write(char v);
    void setStatus(string s);
};

#endif /* TuringModel_hpp */
