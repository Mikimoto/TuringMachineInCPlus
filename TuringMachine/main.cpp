//
//  main.cpp
//  Tuning
//
//  Created by Mikimoto on 2022/10/29.
//

#include "main.h"

using namespace::std;

static string LEADSTR = "        ";

class Tape {
private:
    char tapeData[TAPELENGTH];  // 紙帶內容
    
public:
    Tape() {
        for( int i=0; i<TAPELENGTH; i++) {
            tapeData[i] = '0';
        }
    }
    
    ~Tape() {}
    
    char getData(int i) {
        return tapeData[i];
    }
};

class TapeView {
private:
    void printUpperLine() {
        cout << LEADSTR; // 前面有八個空格
        for (int i=0; i<TAPELENGTH; i++ ) {
            printf("＿＿");
        }
        cout << endl;
    }
    
    void printData(Tape& data) {
        cout << LEADSTR << "|";
        for (int j=0; j<TAPELENGTH; j++ ) {
            printf(" %c |",data.getData(j));
        }
        cout << endl;
    }
    
    void printUnderLine() {
        cout << LEADSTR;
        for (int k=0; k<TAPELENGTH; k++ ) {
            printf("￣￣");
        }
        cout << endl;
    }
    
public:
    TapeView() {}
    
    ~TapeView() {}
    
    void draw(Tape &data) {
        printUpperLine();
        printData(data);
        printUnderLine();
    }
};

class TapeController {
private:
    
public:
    TapeController() {}
    ~TapeController() {}
};

class RWHeader {
private:
    int controlPoint = 0;
    
public:
    RWHeader() {}
    ~RWHeader() {}
    
    void read() {}
    void write() {}

    void next() {
        controlPoint++;
    }
    
    void output() {
        cout << LEADSTR;
        for (int l=0;  l<=controlPoint; l++) {
            if (l == 0) {
                printf("  ");   // 2個字元
            } else {
                printf("    "); // 4個字元
            }
        }
        printf("▲");
        cout << endl << endl;
        
        cout << "[ 狀態 ]:" << ' ' << "     [ 位置 ]:" << controlPoint+1 << "        [*讀取*]:" << ' ' << "         [ 寫入 ]:    無    " << endl;
    }
};

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
    Tape *displayTape = new Tape();
    RWHeader *header = new RWHeader();

    void readCode(const char* file) {
        system("pwd");
        std::ifstream infile(file);
        if (infile.is_open()) {
            std::string line;
            int rLine = 0;
            while (std::getline(infile, line)) {
                if (rLine == 0) {
                    inputVar = line;
                } else if (rLine == 1) {
                    inputAnotherVar = line;
                } else {
                    codes.push_back(line);
                }
                rLine++;
            }
            infile.close();
        }
        
//        for (int i=0; i<codes.size(); i++) {
//            cout << codes[i] << endl;
//        }
    }
    
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
        readCode("/Users/mikimoto/Developer/DeepThought/TuringMachine/code.txt");
    }
    
    ~Controller() {
        delete displayTape;
        delete header;
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
    
    void next() {
        header->next();
        output();
    }
    
    void output() {
        system("clear");
//        displayTape->output();
        header->output();
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



void InitDateStrip(void)
{
    if ( gets(gcDateStrip) == NULL )
        {
            printf("错误：无法初始化数据符号");
            exit(0);
        }
    for (int i=strlen(gcDateStrip); i<DATESTRIPS+1; i++)
        {
        gcDateStrip[i] = 'b';
        }
}

void InitControlState(void)
{
    
    if ( scanf("%c",&gcControlState) == EOF )
        {
        printf("错误：无法初始化控制器状态");
        exit(0);
        }
}

void InitControlPos(void)
{
    
    if ( scanf("%d",&giControlPoint) == EOF )
        {
        printf("错误：无法初始化控制器位置");
        exit(0);
        }
    
    giControlPoint -= 1;
}

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

void RefreshStrip()
{
        //system("cls");     /* Windows */
    system("clear");    /* Linux */
    printf("    ");
    for (int i=0; i<DATESTRIPS; i++ )
        {
        printf("＿＿");
        }
    
    printf("\n       |");
    for (int j=1; j<=DATESTRIPS; j++ )
        {
        printf(" %c |",gcDateStrip[j]);
        }
    
    printf("\n    ");
    for (int k=0; k<DATESTRIPS; k++ )
        {
        printf("￣￣");
        }
    printf("\n");
    for (int l=0;  l<=giControlPoint+1; l++)
        printf("￣￣");
    printf(" ▲ ");
    for (int l=0;  l<=giControlPoint+1; l++)
        printf("￣￣");
    printf("\n\n");
}

int main(int argc, const char * argv[]) {
    cout << "圖靈機模擬器" << endl << endl;

    Controller *simulator = new Controller();
    simulator->output();
    sleep(SLEEPTIME);

//    for (int i=1; i<TAPELENGTH; i++) {
//        simulator->next();
//        sleep(SLEEPTIME);
//    }
    
    simulator->run();
    
    delete simulator;
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
