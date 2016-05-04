#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPair>
#include <QColor>
#include <QMouseEvent>
#include <QApplication>
#include <QUuid>
//#include "node.h"
#include "edge.h"

class drawedLinesOptions;

class graphicsScene
        : public QGraphicsScene
{
    Q_OBJECT
public:
    graphicsScene(QObject* parent = 0);
    virtual ~graphicsScene();
public slots:
    void clearAll();
    void createNode();
    void setTabWidget(int);
signals:
    void zoomChanged(double);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void wheelEvent(QGraphicsSceneWheelEvent *wheelEvent);
private:
    unsigned tabWidget;
private:
    Node* currNode;
    bool firstIsNode;
    QVector< Node* > nodes;
};

#endif // GRAPHICSSCENE_H
