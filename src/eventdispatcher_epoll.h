#ifndef EVENTDISPATCHER_EPOLL_H
#define EVENTDISPATCHER_EPOLL_H

#include <QtCore/QAbstractEventDispatcher>

class EventDispatcherEPollPrivate;

class EventDispatcherEPoll : public QAbstractEventDispatcher {
	Q_OBJECT
public:
	explicit EventDispatcherEPoll(QObject* parent = 0);
    virtual ~EventDispatcherEPoll(void) override;

    virtual bool processEvents(QEventLoop::ProcessEventsFlags flags) override;
    virtual bool hasPendingEvents(void);

    virtual void registerSocketNotifier(QSocketNotifier* notifier) override;
    virtual void unregisterSocketNotifier(QSocketNotifier* notifier) override;

	virtual void registerTimer(
		int timerId,
#if QT_VERSION >= 0x060000
        qint64 interval,
#elif QT_VERSION >= 0x050000
        int interval,
#endif
#if QT_VERSION >= 0x050000
		Qt::TimerType timerType,
#endif
		QObject* object
    ) override;

    virtual bool unregisterTimer(int timerId) override;
    virtual bool unregisterTimers(QObject* object) override;
    virtual QList<QAbstractEventDispatcher::TimerInfo> registeredTimers(QObject* object) const override;
#if QT_VERSION >= 0x050000
    virtual int remainingTime(int timerId) override;
#endif

    virtual void wakeUp(void) override;
    virtual void interrupt(void) override;
    virtual void flush(void);

private:
	Q_DISABLE_COPY(EventDispatcherEPoll)
	Q_DECLARE_PRIVATE(EventDispatcherEPoll)
#if QT_VERSION >= 0x040600
	QScopedPointer<EventDispatcherEPollPrivate> d_ptr;
#else
	EventDispatcherEPollPrivate* d_ptr;
#endif
};

#endif // EVENTDISPATCHER_EPOLL_H
