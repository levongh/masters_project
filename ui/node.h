#ifndef NODE_H
#define NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QStaticText>
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QDebug>

//class graphicsScene;

class Node
        :public QGraphicsItem
{
public:
    Node(QPointF, QString);
    virtual ~Node();
    QString getNodeName() const;
    void setNodeCenter(QPointF);
protected:
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    QPointF nodeCenter;
    QString nodeName;
    QRectF bRect;
    const unsigned radius;
};

#endif // NODE_H
