#ifndef SWIFTCORE_GLOBAL_H
#define SWIFTCORE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QUuid>
#if defined(SWIFTCORE_LIBRARY)
#  define SWIFTCORE_EXPORT Q_DECL_EXPORT
#else
#  define SWIFTCORE_EXPORT Q_DECL_IMPORT
#endif


//UUID
#define UUID        QUuid::createUuid().toString().mid(1,36)

#endif // SWIFTCORE_GLOBAL_H
