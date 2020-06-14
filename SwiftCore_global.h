
#ifndef SWIFTCORE_GLOBAL_H
#define SWIFTCORE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QUuid>
#include <QDateTime>

//#if defined(SWIFTCORE_LIBRARY)
//#  define SWIFTCORE_EXPORT Q_DECL_EXPORT
//#else
//#  define SWIFTCORE_EXPORT Q_DECL_IMPORT
//#endif


#ifndef BUILD_STATIC
# if defined(SWIFTCORE_LIBRARY)
#  define SWIFTCORE_EXPORT Q_DECL_EXPORT
# else
#  define SWIFTCORE_EXPORT Q_DECL_IMPORT
# endif
#else
# define SWIFTCORE_EXPORT
#endif


//UUID
#define UUID        QUuid::createUuid().toString().mid(1,36)

//TIMESTAMP
#define TIMESTAMP   QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzzzzz")
#define _TIMESTAMP   QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzzzzz")


#define LOGERROR  "Log Initialization FAIL"
#endif // SWIFTCORE_GLOBAL_H
