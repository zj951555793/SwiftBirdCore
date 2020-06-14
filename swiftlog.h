#ifndef SWIFTLOG_H
#define SWIFTLOG_H
#include "SwiftCore_global.h"
#include <QString>
#include <QMutex>

class SWIFTCORE_EXPORT SwiftLog
{
public:
    SwiftLog();

    static  bool init(QString logPath,QString &errorInfo);

private:
    static  void customMessageHandle(QtMsgType type, const QMessageLogContext &text, const QString &msg);

    static  QString logFileName;

    static QMutex m_mutex;
};

#endif // SWIFTLOG_H
