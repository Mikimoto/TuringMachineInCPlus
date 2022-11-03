//
//  main.cpp
//  Tuning
//
//  Created by Mikimoto on 2022/10/29.
//

#include "main.h"

using namespace::std;

int main(int argc, const char * argv[]) {
    if (argc > 0) {
        cout << "=== 圖靈機模擬器 ===" << endl << endl;
        Turing simulator(argv[1]);
        simulator.run();
    }
    return 0;
}
