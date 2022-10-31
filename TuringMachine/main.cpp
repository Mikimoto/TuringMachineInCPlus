//
//  main.cpp
//  Tuning
//
//  Created by Mikimoto on 2022/10/29.
//

#include "main.h"

using namespace::std;

class Register {
    Register() {}
    ~Register() {}
    
    void put() {}
    void get() {}
};

class Controller {
private:
    string inputVar;
    string inputAnotherVar;
    string status;
    vector<string> codes;
    TapeController tape;

    void split(string& s, string& delim, vector<string>* ret) {
        size_t last = 0;
        size_t index=s.find_first_of(delim, last);
        
        while (index != string::npos) {
            ret->push_back(s.substr(last, index-last));
            last = index+1;
            index = s.find_first_of(delim, last);
        }
        
        if (index-last>0) {
            ret->push_back(s.substr(last, index-last));
        }
    }
        
public:
    Controller() {
    }
    
    ~Controller() {
    }
    
    void run() {
        // 先印出被加數
        // 解析 code
        // 依序執行
        
//        auto *code = codes[0].c_str();      // 程式碼
        string delim = ",";
        vector<string> program;
        split(codes[0], delim, &program);
        
        status = program[0];
        // header->var == program[1]
        // header->move( program[2] )
        // header->write( program[3] )
        // status = program[4]
        
//        for (int i=0; i<program.size(); i++) {
//            cout << program[i] << endl;
//        }
    }
};


/*   变量定义   */
char gcDateStrip[DATESTRIPS] ;            /*    数据符号位    */
    //'111R1","1b1R2","211R2","2bbL3","31bH3","3bbH3"
char gcWorkCodes[CODELINES][CONTROLSTEPS] = {{'1', '1', '1', 'R', '1'},
    {'1', 'b', '1', 'R', '2'},
    {'2', '1', '1', 'R', '2'},
    {'2', 'b', 'b', 'L', '3'},
    {'3', '1', 'b', 'H', '3'},
    {'3', 'b', 'b', 'H', '3'}};
char gcMatchCodes[CONTROLSTEPS]= "";              /*    匹配代码    */
char gcControlState ;      /*    控制器状态    */
char gcControlStrip ;    /*    控制器符号    */
int  giControlPoint = 0;    /*    控制器位置    */

void ReadWorkCodes(void)
{
    int i=0;
    while ( gets(gcWorkCodes[i]) != NULL)
        {
        if (gcWorkCodes[i][0] != '\0')
            i++;
        }
    printf("工作代码为:\n");
    for ( int j=1; j<i ; j++)
        {
        printf("        %s\n",gcWorkCodes[1]);
        }
    
}

void ReadStrip(void)
{
    gcControlStrip = gcDateStrip[giControlPoint];
}

void LookUpCode(void)
{
    int i,j=0;
    for ( i=0 ; i<CODELINES ; i++ )
        {
        if ( (gcWorkCodes[i][0] == gcControlState) && (gcWorkCodes[i][1] == gcControlStrip) )
            {
            gcMatchCodes[0] = gcWorkCodes[i][0];
            gcMatchCodes[1] = gcWorkCodes[i][1];
            gcMatchCodes[2] = gcWorkCodes[i][2];
            gcMatchCodes[3] = gcWorkCodes[i][3];
            gcMatchCodes[4] = gcWorkCodes[i][4];
            }
        }
}

void WriteStrip(void)
{
    gcDateStrip[giControlPoint] = gcMatchCodes[2];
}

void ControlMovment(void)
{
    int iChangePos = 0;
    switch( gcMatchCodes[3] )
        {
            case L:    iChangePos = -1; break;
            case R: iChangePos = 1; break;
            default: ; break;
        }
    giControlPoint += iChangePos;
    
}

void SetControlState(void)
{
    gcControlState = gcMatchCodes[4];
}

int main(int argc, const char * argv[]) {
    cout << "圖靈機模擬器" << endl << endl;

    Turing simulator;
    simulator.run();
//    simulator->output();
//    sleep(SLEEPTIME);

//    for (int i=1; i<TAPELENGTH; i++) {
//        simulator->next();
//        sleep(SLEEPTIME);
//    }
    
//    simulator->run();
    
//    delete simulator;
//    char c = 'y';
//    printf("开始工作\n");
//
//    printf("请输入数据符号\n");
//    InitDateStrip();
//    printf("当前数据符号为:%s\n",gcDateStrip);
//
//    printf("请输入控制器初始状态：");
//    InitControlState();
//    printf("控制器初始状态为:%c\n",gcControlState);
//
//
//    printf("请输入控制器初始位置: ");
//    InitControlPos();
//    printf("控制器初始位置为:%d\n",giControlPoint+1);
//
//    printf("请输入工作程序：Ctrl+Z结束输入");
//        //ReadWorkCodes();    /* 自定义工作程序请启用此代码 */
//
//
//    scanf("%c",&c);
//    while ( 1 )
//        {
//        scanf("%c",&c);
//
//        ReadStrip();
//        RefreshStrip();
//        printf("       [ 状态 ]:%c     [ 位置 ]:%d        [*读取*]:%c         [ 写入 ]:    无    ",
//               gcControlState,giControlPoint+1,gcControlStrip);
//
//
//        scanf("%c",&c);
//        LookUpCode();
//        printf("\n");
//        printf("       [ 代码 ]:");
//        for (int i=0; i<CONTROLSTEPS; i++ )
//            {
//            printf(" %c ", gcMatchCodes[i]);
//            }
//        printf("\n");
//
//        WriteStrip();
//        RefreshStrip();
//        printf("       [ 状态 ]:%c     [ 位置 ]:%d        [ 读取]:%c         [*写入*]:    %c    ",
//               gcControlState,giControlPoint+1,gcControlStrip, gcMatchCodes[CONTROLSTEPS-1]);
//
//
//        scanf("%c",&c);
//        ControlMovment();
//        RefreshStrip();
//        printf("       [ 状态 ]:%c     [*位置*]:%d        [ 读取 ]:%c         [ 写入 ]:    无    ",
//               gcControlState,giControlPoint+1,gcControlStrip);
//
//        scanf("%c",&c);
//        SetControlState();
//        RefreshStrip();
//        printf("       [*状态*]:%c     [ 位置 ]:%d        [ 读取 ]:%c         [ 写入 ]:    无    ",
//               gcControlState,giControlPoint+1,gcControlStrip);
//
//        printf("\n\n");
//
//
//        }
    return 0;
}
