#ifndef TRACKING_GLOBAL_H
#define TRACKING_GLOBAL_H

#if defined(TRACKING_LIBRARY)
#  define TRACKINGSHARED_EXPORT __declspec(dllexport)
#else
#  define TRACKINGSHARED_EXPORT __declspec(dllimport)
#endif

#endif // TRACKING_GLOBAL_H
