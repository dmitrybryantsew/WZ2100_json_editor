#ifndef RESEARCHWIDGET_HPP
#define RESEARCHWIDGET_HPP

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QDebug>
#include <cmath>
#include "node.hpp"
#include "emitterObject.hpp"

class ResearchWidget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit ResearchWidget(QWidget *parent = nullptr);
    ~ResearchWidget();
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    //void drawBackground(QPainter *painter, const QRectF &rect) override;
    void scaleView(qreal scaleFactor);
    //remove later
    void addAllRes(QList<QPair<QString, QString>> data);
    void manageNodesPos();
    //slot for processing event from connection between nodes
    EmitterObject _stringEmitter;
public slots:
    void connectTwoGraphicItems(const QString& firstNodeID, const QString& secondNodeID);
private:
    QGraphicsScene* _scene;
    QMap<QString, GraphicsItemNode*> _nodeMap;

};

#endif // RESEARCHWIDGET_HPP
