#include "researchWidget.hpp"

ResearchWidget::ResearchWidget(QWidget *parent)
    : QGraphicsView(parent), _scene(new QGraphicsScene(this))
{
    this->setScene(_scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCacheMode(CacheBackground);
    //setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setDragMode(QGraphicsView::ScrollHandDrag);
    QImage *image = new QImage(":images/wz_desert_ground");
    QBrush *brush = new QBrush(*image);
    this->setBackgroundBrush(*brush);

}

ResearchWidget::~ResearchWidget()
{
    for(auto& item : _nodeMap)
        delete item;
}

void ResearchWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow(2., -event->angleDelta().y() / 240.0));
}

void ResearchWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        break;
    case Qt::Key_Minus:
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void ResearchWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.01 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void ResearchWidget::addAllRes(QList<QPair<QString, QString>> data)
{
    qDebug() << "hjere";
    for(auto& resIDsAndNames : data ){
        qDebug() << resIDsAndNames;
        //TODO remove
        QPoint position = {0, 0};
        qint32 xPosOffset = QRandomGenerator::global()->generate() % 12500;
        qint32 yPosOffset = QRandomGenerator::global()->generate() % 12500;

        position += {xPosOffset, yPosOffset};
        GraphicsItemNode* itemPointer = new GraphicsItemNode(resIDsAndNames.second, resIDsAndNames.first, position, &_stringEmitter);
        _scene->addItem(itemPointer); //TODO delete later or use upointer
        _nodeMap.insert(resIDsAndNames.first, itemPointer);

    }
}

void ResearchWidget::manageNodesPos()
{
    int generation = 0;
    QVector<GraphicsItemNode*> startNodes;
    for(auto it = _nodeMap.begin(); it != _nodeMap.end(); it++){
        if((*it)->getInConnectionsCount() == 0){
            startNodes.append(*it);
        }
    }
    for(int i = 0; i < startNodes.size(); i++){
        startNodes[i]->setPos(generation * 2500, i % 2 ? i * 250 : -i * 250);
    }


}


void ResearchWidget::connectTwoGraphicItems(const QString& firstNodeID, const QString& secondNodeID)
{
    QPoint firstPos = _nodeMap[firstNodeID]->getPos();
    QPoint secondPos = _nodeMap[secondNodeID]->getPos();
    _nodeMap[firstNodeID]->insertOutConnection(secondNodeID, secondPos);
    _nodeMap[secondNodeID]->insertInConnection(firstNodeID, firstPos);
}
//void ResearchWidget::drawBackground(QPainter *painter, const QRectF &rect){}
