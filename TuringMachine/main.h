//
//  main.h
//  Tuning
//
//  Created by Mikimoto on 2022/10/29.
//

#ifndef main_h
#define main_h

#include <stdio.h>
    //#include <TCHAR.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <unistd.h>
#include <term.h>
#include <fstream>
#include <vector>

#define TAPELENGTH 4
#define SLEEPTIME 2
#define CODELINES 48
#define RIGHT 'r'
#define LEFT 'l'
#define HOLD 'h'

#define DATESTRIPS 16
#define CONTROLSTEPS 5
#define R 'R'
#define L 'L'
#define H 'H'

void InitDateStrip(void);            /*    初始化数据符号    */
void InitControlState(void);        /*    初始化控制器状态    */
void InitControlPos(void);             /*        初始化控制器    */
void ReadWorkCodes(void);            /*    读取工作代码    */
void LookUpCode(void);                /*    查找代码    */

void StartMachine();                /*    运行图灵机    */
void StopMachine();                    /*    停止图灵机    */

void ReadStrip();                    /*    读取符号    */
void WriteStrip();                    /*    写入符号    */

void ControlMovment();                /*    控制器动作    */
void SetControlState();                /*    设置控制器状态    */
void IsStopMachine();                /*    是否停机        */
void RefreshStrip();                /*    刷新数据符号        */

#endif /* main_h */
