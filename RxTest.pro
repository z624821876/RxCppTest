QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += src/Rx
INCLUDEPATH += src/Rx/rxqt

SOURCES += \
    main.cpp \
    src/YSLoginModel.cpp \
    src/YSLoginView.cpp \
    src/YSLoginViewController.cpp \
    src/YSLoginViewModel.cpp \
    src/YSMainView.cpp \
    src/YSMainViewController.cpp \
    src/YSMainViewModel.cpp \
    src/YSMainWindow.cpp \
    src/YSMainCellViewModel.cpp \
    src/YSRouter.cpp \
    src/demo/Combining/YSCombineLatest.cpp \
    src/demo/Combining/YSMerge.cpp \
    src/demo/Combining/YSSwitch.cpp \
    src/demo/Combining/YSZip.cpp \
    src/demo/Conditional/YSAll.cpp \
    src/demo/Conditional/YSAmb.cpp \
    src/demo/Conditional/YSContains.cpp \
    src/demo/Conditional/YSDefaultIsEmpty.cpp \
    src/demo/Conditional/YSSequenceEqual.cpp \
    src/demo/ErrorHandling/YSError.cpp \
    src/demo/Filtering/YSDebounce.cpp \
    src/demo/Filtering/YSDistinct.cpp \
    src/demo/Filtering/YSElementAt.cpp \
    src/demo/Filtering/YSFilter.cpp \
    src/demo/Filtering/YSIgnoreElements.cpp \
    src/demo/Filtering/YSSample.cpp \
    src/demo/Filtering/YSSkip.cpp \
    src/demo/Filtering/YSTake.cpp \
    src/demo/Math/YSConcat.cpp \
    src/demo/Math/YSMath.cpp \
    src/demo/Published/YSPublished.cpp \
    src/demo/Scheduler/YSScheduler.cpp \
    src/demo/Transforming/YSBuffer.cpp \
    src/demo/Transforming/YSFlatMap.cpp \
    src/demo/Transforming/YSGroupBy.cpp \
    src/demo/Transforming/YSMap.cpp \
    src/demo/Transforming/YSScan.cpp \
    src/demo/Transforming/YSWindow.cpp \
    src/demo/Utility/YSDelay.cpp \
    src/demo/Utility/YSFinally.cpp \
    src/demo/Utility/YSObserveOn.cpp \
    src/demo/Utility/YSScope.cpp \
    src/demo/Utility/YSSubscribeOn.cpp \
    src/demo/Utility/YSTap.cpp \
    src/demo/Utility/YSTimeInterval.cpp \
    src/demo/Utility/YSTimeOut.cpp \
    src/demo/Utility/YSTimestamp.cpp \
    src/demo/YSObservable.cpp \
    src/demo/YSSubject.cpp

HEADERS += \
    src/Global.h \
    src/YSLoginModel.h \
    src/YSLoginView.h \
    src/YSLoginViewController.h \
    src/YSLoginViewModel.h \
    src/YSMainView.h \
    src/YSMainViewController.h \
    src/YSMainViewModel.h \
    src/YSMainWindow.h \
    src/YSMainCellViewModel.h \
    src/YSRouter.h \
    src/demo/Combining/YSCombineLatest.h \
    src/demo/Combining/YSMerge.h \
    src/demo/Combining/YSSwitch.h \
    src/demo/Combining/YSZip.h \
    src/demo/Conditional/YSAll.h \
    src/demo/Conditional/YSAmb.h \
    src/demo/Conditional/YSContains.h \
    src/demo/Conditional/YSDefaultIsEmpty.h \
    src/demo/Conditional/YSSequenceEqual.h \
    src/demo/ErrorHandling/YSError.h \
    src/demo/Filtering/YSDebounce.h \
    src/demo/Filtering/YSDistinct.h \
    src/demo/Filtering/YSElementAt.h \
    src/demo/Filtering/YSFilter.h \
    src/demo/Filtering/YSIgnoreElements.h \
    src/demo/Filtering/YSSample.h \
    src/demo/Filtering/YSSkip.h \
    src/demo/Filtering/YSTake.h \
    src/demo/Math/YSConcat.h \
    src/demo/Math/YSMath.h \
    src/demo/Published/YSPublished.h \
    src/demo/Scheduler/YSScheduler.h \
    src/demo/Transforming/YSBuffer.h \
    src/demo/Transforming/YSFlatMap.h \
    src/demo/Transforming/YSGroupBy.h \
    src/demo/Transforming/YSMap.h \
    src/demo/Transforming/YSScan.h \
    src/demo/Transforming/YSWindow.h \
    src/demo/Utility/YSDelay.h \
    src/demo/Utility/YSFinally.h \
    src/demo/Utility/YSObserveOn.h \
    src/demo/Utility/YSScope.h \
    src/demo/Utility/YSSubscribeOn.h \
    src/demo/Utility/YSTap.h \
    src/demo/Utility/YSTimeInterval.h \
    src/demo/Utility/YSTimeOut.h \
    src/demo/Utility/YSTimestamp.h \
    src/demo/YSObservable.h \
    src/demo/YSSubject.h \

FORMS += \
    src/YSLoginView.ui \
    src/YSMainView.ui \
    src/YSMainWindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
