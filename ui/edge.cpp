#include "edge.h"

Edge::Edge(Node* bNode, Node* eNode)
    : beginNode(bNode)
    , endNode(eNode)
{
    setFlag(ItemIsSelectable, true);
    setZValue(-5);
}

QRectF Edge::boundingRect() const
{
    return QRectF(beginNode->sceneBoundingRect().center(), endNode->sceneBoundingRect().center());
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    painter->setPen(QPen(Qt::red, 4));
    painter->setBrush(Qt::green);
    painter->drawLine(beginNode->sceneBoundingRect().center(), endNode->sceneBoundingRect().center());
}

Edge::~Edge()
{

}
