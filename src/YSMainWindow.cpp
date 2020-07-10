#include "YSMainWindow.h"
#include "ui_YSMainWindow.h"

#include "demo/Transforming/YSBuffer.h"
#include "demo/Transforming/YSFlatMap.h"
#include "demo/Transforming/YSGroupBy.h"
#include "demo/Transforming/YSMap.h"
#include "demo/Transforming/YSScan.h"
#include "demo/Transforming/YSWindow.h"

#include "demo/ErrorHandling/YSError.h"

#include "demo/Published/YSPublished.h"

#include "demo/Math/YSConcat.h"
#include "demo/Math/YSMath.h"

#include "demo/Filtering/YSDebounce.h"
#include "demo/Filtering/YSDistinct.h"
#include "demo/Filtering/YSElementAt.h"
#include "demo/Filtering/YSFilter.h"
#include "demo/Filtering/YSIgnoreElements.h"
#include "demo/Filtering/YSSample.h"
#include "demo/Filtering/YSSkip.h"
#include "demo/Filtering/YSTake.h"

#include "demo/Combining/YSCombineLatest.h"
#include "demo/Combining/YSMerge.h"
#include "demo/Combining/YSSwitch.h"
#include "demo/Combining/YSZip.h"

#include "demo/Utility/YSDelay.h"
#include "demo/Utility/YSFinally.h"
#include "demo/Utility/YSObserveOn.h"
#include "demo/Utility/YSScope.h"
#include "demo/Utility/YSSubscribeOn.h"
#include "demo/Utility/YSTap.h"
#include "demo/Utility/YSTimeInterval.h"
#include "demo/Utility/YSTimeOut.h"
#include "demo/Utility/YSTimestamp.h"

#include "demo/Conditional/YSAll.h"
#include "demo/Conditional/YSAmb.h"
#include "demo/Conditional/YSContains.h"
#include "demo/Conditional/YSDefaultIsEmpty.h"
#include "demo/Conditional/YSSequenceEqual.h"

#include "demo/Scheduler/YSScheduler.h"

#include "demo/YSObservable.h"
#include "demo/YSSubject.h"

#include <QDebug>

YSMainWindow::YSMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::YSMainWindow)
{
    ui->setupUi(this);

    //    YSObservable observable;

    //    YSSubject subject;

    //    YSBuffer buffer;
    //    YSFlatMap flatmap;
    //    YSGroupBy groupBy;
    //    YSMap map;
    //    YSScan scan;
    //    YSWindow window;

    //    YSError error;

    //    YSMath math;
    //    YSConcat concat;

    //    YSPublished published;

    //    YSDebounce debounce;
    //    YSDistinct distinct;
    //    YSElementAt elementAt;
    //    YSFilter filter;
    //    YSIgnoreElements ignore;
    //    YSSample sample;
    //    YSSkip skip;
    //    YSTake take;

    //    YSCombineLatest combineLatest;
    //    YSMerge merge;
    //    YSSwitch swith;
    //    YSZip zip;

    //    YSDelay delay;
    //    YSTap tap;
    //    YSObserveOn observeOn;
    //    YSSubscribeOn subscribeOn;
    //    YSTimeInterval timeInterval;
    //    YSTimeOut timeOut;
    //    YSTimestamp timestamp;
    //    YSScope scope;
    //    YSFinally finally;

    //    YSAll all;
    //    YSAmb amb;
    //    YSContains contains;
    //    YSDefaultIsEmpty defaultIsEmpty;
    //    YSSequenceEqual sequenceEqual;

    //    YSScheduler scheduler;
}

YSMainWindow::~YSMainWindow()
{
    delete ui;
}
