#ifndef ALTREPOAPI_GLOBAL_H
#define ALTREPOAPI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ALTREPOAPI_LIBRARY)
#  define ALTREPOAPI_EXPORT Q_DECL_EXPORT
#else
#  define ALTREPOAPI_EXPORT Q_DECL_IMPORT
#endif

#endif // ALTREPOAPI_GLOBAL_H
