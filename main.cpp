#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QString>
#include <MyApplication.h>

#include <iostream>

#include "ClassExample/ExampleClassStatic.h"
#include "ClassExample/ExampleClassSingleton.h"

static const unsigned long RoopNum = 10000 * 10000 * 10;

static unsigned long mValByCopy = 0;
static unsigned long mValByPointer = 0;
static unsigned long mValByReference = 0;

static void execCopy(const int aa)
{
    mValByCopy += aa;
}

static void execPointer(const int *aa)
{
    mValByPointer += *aa;
}

static void execReference(const int &aa)
{
    mValByReference += aa;
}


int main(int argc, char *argv[])
{
    MyApplication a(argc, argv);
    MainWindow w;
    QString str;

    // 関数読み出しのオーバーヘッド検証.
    long noFuncVal = 1;

    clock();
    qDebug() << RoopNum;

    clock_t start,end;

    // べた書き.
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        noFuncVal++;
    }
    end = clock();
    str = QString("べた書き %1").arg((double)(end-start)/CLOCKS_PER_SEC);
    qDebug() << str;

    std::string timeStr = std::to_string((double)(end-start)/CLOCKS_PER_SEC);
    w.setLabelNoFunc(timeStr);

    // ファイル内static関数(copy).
    long FileStaticFunc = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        execCopy(FileStaticFunc);
    }
    end = clock();
    str = QString("ファイル内static関数(copy) %1").arg((double)(end-start)/CLOCKS_PER_SEC);
    qDebug() << str;

    // ファイル内static関数(pointer).
    int FileStaticFuncPointer = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        execPointer(&FileStaticFuncPointer);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;

    // ファイル内static関数(reference).
    int FileStaticFuncRef = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        execReference(FileStaticFuncRef);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;

    // クラス内static関数(copy).
    long classStaticFuncCopy = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        ExampleClassStatic::execCopy(classStaticFuncCopy );
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC / RoopNum;


    // クラス内static関数(Pointer).
    int classStaticFuncPointer = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        ExampleClassStatic::execPointer(&classStaticFuncPointer);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC / RoopNum;

    // クラス内static関数(Pointer).
    int classStaticFuncReference = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        ExampleClassStatic::execReference(classStaticFuncReference);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC / RoopNum;

    ExampleClassSingleton& examCalss = ExampleClassSingleton::getInstance();

    // クラス内static関数(copy).
    long singltonCopy = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        examCalss.execCopy(singltonCopy);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC / RoopNum;


    // クラス内static関数(Pointer).
    int singltonPointer = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        examCalss.execCopy(singltonPointer);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC / RoopNum;

    // クラス内static関数(Pointer).
    int singltonRefernce  = 1;
    start = clock();
    for(unsigned long i = 0; i < RoopNum; i++){
        examCalss.execReference(singltonRefernce);
    }
    end = clock();
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC;
    qDebug() << (double)(end-start)/CLOCKS_PER_SEC / RoopNum;

    str += str.arg(singltonRefernce);
    qDebug() << str;

    w.show();

    return a.exec();
}
