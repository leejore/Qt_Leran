#include "mainwindow.h"
#include <QApplication>
#include <QByteArray>
#include <QDebug>

#define  LOG_FILE_PATH  "D:\\QtLog\\log.txt"
static FILE* g_log_fp=0;
static void closLogFile(){
    fclose(g_log_fp);//main函数退出关闭日志文档

}
static void myMessageOutPut(QtMsgType type,const QMessageLogContext &contex,const QString &msg){
    QByteArray localMsg=msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(g_log_fp,"Debug :%s(%s:%u,%s)\n",localMsg.constData(),contex.file,contex.line,contex.function);

        break;
    case QtWarningMsg:
        fprintf(g_log_fp,"Waring :%s(%s:%u,%s)\n",localMsg.constData(),contex.file,contex.line,contex.function);

        break;
    case QtCriticalMsg:
        fprintf(g_log_fp,"Critical :%s(%s:%u,%s)\n",localMsg.constData(),contex.file,contex.line,contex.function);

        break;
    case QtFatalMsg:
        fprintf(g_log_fp,"Fatal :%s(%s:%u,%s)\n",localMsg.constData(),contex.file,contex.line,contex.function);
        abort();// 致命错误，程序停止退出
        break;

    default:
        break;
    }


}
int main(int argc, char *argv[])
{

    g_log_fp=fopen(LOG_FILE_PATH,"wt");
    atexit(closLogFile);//程序结束执行关闭文件
    qInstallMessageHandler(myMessageOutPut);
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    qDebug()<<"I am debug;";
    qWarning()<<"I am waring";
    qCritical()<<"I am critical";
qFatal("I am  fatal");

    return a.exec();
}
