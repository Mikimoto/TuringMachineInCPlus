//
//  TuringModel.cpp
//  TuringMachine
//
//  Created by Mikimoto on 2022/10/31.
//

#include "TuringModel.hpp"

using namespace::std;

TuringModel::TuringModel() {
    for (int i=0; i<TAPELENGTH; i++) {
        tapeData[i] = '0';
    }
}

TuringModel::~TuringModel() {}

char TuringModel::getData(int i) {
    return tapeData[i];
}

int TuringModel::getPoint() {
    return point;
}

string TuringModel::getStatus() {
    return reg;
}

void TuringModel::setupData(string var) {
    for (int i=0; i<var.size(); i++) {
        tapeData[i] = var.c_str()[i];
        point = i;
    }
}

bool TuringModel::isHandler(string status, char val) {
    if (reg.empty()) {
        reg = status;
    }

    if (reg == status && tapeData[point] == val) {
        return true;
    }
    
    return false;
}

void TuringModel::moveLeft() {
    point--;
    if (point < 0) {
        point = 0;
    }
}

void TuringModel::moveRight() {
    point++;
    if (point > TAPELENGTH) {
        point = TAPELENGTH;
    }
}

void TuringModel::write(char v) {
    tapeData[point] = v;
}

void TuringModel::setStatus(string s) {
    reg = s;
}
