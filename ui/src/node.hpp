#ifndef NODE_HPP
#define NODE_HPP

#include <QGraphicsItem>
#include <QPainter>
//#include <QPixmap>
#include <QRandomGenerator>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "emitterObject.hpp"
class GraphicsItemNode : public QGraphicsItem
{
public:
    //ctors
    GraphicsItemNode(QString itemName, QString itemID, QPoint position, EmitterObject* eObj);
    //overridden funcs
//protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent  *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void insertInConnection(const QString& nodeID,const QPoint& pos);
    void insertOutConnection(const QString& nodeID,const QPoint& pos);
    int getInConnectionsCount() const;
    int getOutConnectionsCount() const;
    QStringList getAllInConnections() const;
     QStringList getAllOutConnections() const;
    QPoint getPos() const;
    enum { Type = UserType + 1 };
    int type() const override { return Type; }
private:
    //utilFuncs
    void initConstruction();
    //data
    QString _itemName = "no_name", _itemID = "no_data";
    QSet<QPair<QString, QPoint>> _inputConnectionsSet, _outputConnectionsSet; //TODO check to not connect to itself
    QPoint _position;
    EmitterObject* _eObject = nullptr;
    //TODO perhaps it wil be good to  add slots and events to track addition and deletion of conections in model
};

#endif // NODE_HPP
