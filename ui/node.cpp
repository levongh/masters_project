#include "node.h"

Node::Node(QPointF cen, QString name)
    : nodeCenter(cen)
    , nodeName(name)
    , radius(50)
{
    setFlag(ItemIsMovable, true);
    setFlag(ItemIsSelectable, true);

    bRect = QRectF(nodeCenter.x() - radius/2, nodeCenter.y() + radius/2, radius, radius);
}

QRectF Node::boundingRect() const
{
    return bRect;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    painter->setPen(QPen(Qt::red, 3));
    painter->setBrush(Qt::green);
    painter->drawEllipse(bRect);
    painter->drawText(bRect, Qt::AlignCenter, nodeName);
}

QString Node::getNodeName() const
{
    return nodeName;
}

void Node::setNodeCenter(QPointF newCenter)
{
    nodeCenter = newCenter;
}

Node::~Node()
{

}
