#include "node.hpp"

GraphicsItemNode::GraphicsItemNode(QString itemName, QString itemID, QPoint position, EmitterObject* eObj) :_itemName(itemName),
    _itemID(itemID), _position(position), _eObject(eObj)
{
    initConstruction();
    this->setPos(_position);
}

QRectF GraphicsItemNode::boundingRect() const
{

    return QRectF(-100, -100, 200, 200);
}

void GraphicsItemNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)
    QPen pen(Qt::gray, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);

    QPixmap pixmap = QPixmap (":images/" + _itemName);
    painter->drawPixmap(-100,-100, 200, 200, pixmap);
    painter->drawRect(-100, -100, 200, 200);
    painter->drawLine(-100,-100, 200, 200);
    painter->setPen(QPen(Qt::red, 3, Qt::SolidLine));


}

void GraphicsItemNode::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "entered node " << _itemName << " " << _itemID;
    QGraphicsItem::hoverEnterEvent(event);
}

void GraphicsItemNode::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->buttons() == Qt::RightButton){
        if(_eObject)
            emit _eObject->graphicNodePressedSignal(_itemID);
        for (const auto& id : _inputConnectionsSet)
            qDebug() << id;
        for (const auto& id : _outputConnectionsSet)
            qDebug() << id;
    }

}

void GraphicsItemNode::insertOutConnection(const QString& nodeID ,const QPoint& pos)
{
    _inputConnectionsSet.insert({nodeID, pos});
}

int GraphicsItemNode::getInConnectionsCount() const
{
    return _inputConnectionsSet.size();
}

int GraphicsItemNode::getOutConnectionsCount() const
{
    return _outputConnectionsSet.size();
}

QStringList GraphicsItemNode::getAllInConnections() const
{
    QStringList ans;
    //for(auto it = _inputConnectionsSet.begin(); it != _inputConnectionsSet.end(); it++)
}

QStringList GraphicsItemNode::getAllOutConnections() const
{
    QStringList ans;

}

QPoint GraphicsItemNode::getPos() const
{
    return _position;
}

void GraphicsItemNode::insertInConnection(const QString& nodeID ,const QPoint& pos)
{
    _outputConnectionsSet.insert({nodeID, pos});
}

void GraphicsItemNode::initConstruction()
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    setAcceptHoverEvents(true);
}

inline uint qHash (const QPoint & key)
{
    return qHash (QPair<int,int>(key.x(), key.y()) );
}
