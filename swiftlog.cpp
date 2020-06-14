#include "swiftlog.h"
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QThread>
QString  SwiftLog::logFileName ="";
QMutex SwiftLog:: m_mutex;
SwiftLog::SwiftLog()
{

}

bool SwiftLog::init(QString logPath, QString &errorInfo)
{
    bool bsIsInit = false;
    try {
        QDir dir;
        QFileInfo fileInfo  = QFileInfo(logPath);
        QString absolutePath = fileInfo.absolutePath();
        QString absoluteFilePath = fileInfo.absoluteFilePath();
        QString baseName = fileInfo.baseName();

        if( !dir.exists(absolutePath))
        {
             dir.mkdir(absolutePath);
        }

        if (!absolutePath.endsWith('/'))
        {
            absolutePath.append('/');
        }

        logFileName= QString("%1%2%3.%4").arg(absolutePath).arg(baseName).arg(QDateTime::currentDateTime().toString("_yyyy_MM_dd_hh")).arg(QFileInfo(logPath).suffix());
        qInstallMessageHandler(&SwiftLog::customMessageHandle);
    } catch (...) {
       errorInfo = QString(LOGERROR);
        bsIsInit  = false;
    }

    return bsIsInit;
}


void SwiftLog::customMessageHandle(QtMsgType type, const QMessageLogContext &text, const QString &msg)
{


    QString  type_t;
    switch(type)
    {
        case QtMsgType::QtInfoMsg:
            type_t  = "[Info]";
            break;
        case QtMsgType::QtDebugMsg:
            type_t  = "[Debug]";
            break;
        case QtMsgType::QtFatalMsg:
            type_t  = "[Fatal]";
            break;

        case QtMsgType::QtWarningMsg:
            type_t  = "[Warn]";
            break;
        case QtMsgType::QtCriticalMsg:
            type_t  = "[Critical]";
            break;
        break;
    }

    QString logText = QString("%1 %2 %3 %4 %5").arg(TIMESTAMP).arg(type_t).arg(text.file).arg(text.line).arg(msg);

     QFile  file(logFileName);

    m_mutex.lock();
    if(!file.open(QIODevice::Append) && QIODevice::WriteOnly)
    {
        return ;
    }
    QTextStream stream(&file);
     stream << logText << "\r\n";
    file.flush();
    file.close();
    m_mutex.unlock();
}

