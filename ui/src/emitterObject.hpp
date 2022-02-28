#ifndef EMITTEROBJECT_HPP
#define EMITTEROBJECT_HPP

#include <QObject>

class EmitterObject : public QObject
{
    Q_OBJECT
public:
    explicit EmitterObject(QObject *parent = nullptr);

signals:
    void graphicNodePressedSignal(const QString&);
};

#endif // EMITTEROBJECT_HPP
