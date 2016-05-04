#ifndef EDGE_H
#define EDGE_H

#include "node.h"

class Edge
        :public QGraphicsItem
{
public:
    Edge(Node*, Node*);
    virtual ~Edge();
protected:
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    Node* beginNode;
    Node* endNode;
};

#endif // EDGE_H
