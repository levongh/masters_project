#include "graphicsscene.h"

graphicsScene::graphicsScene(QObject* parent)
    : QGraphicsScene(parent)
    , tabWidget(0)
    , firstIsNode(false)
{
    setBackgroundBrush(Qt::Dense7Pattern);
}

void graphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(0 == tabWidget)  // graph
    {
        if(mouseEvent->button() == Qt::RightButton)
        {
            currNode = dynamic_cast<Node*>(itemAt(mouseEvent->scenePos(), QTransform()));
            if(currNode)
            {
                firstIsNode = true;
            }
        }
        update();
    }

    if(1 == tabWidget)  // draw
    {}
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void graphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(0 == tabWidget)  // graph
    {
        if(mouseEvent->button() == Qt::LeftButton)
        {
            Node* moveNode = dynamic_cast<Node*>(itemAt(mouseEvent->scenePos(), QTransform()));
            if( moveNode )
            {
                moveNode->setNodeCenter(mouseEvent->scenePos());
                update();
            }
        }

        if(mouseEvent->button() == Qt::RightButton)
        {
            Node* secondNode = dynamic_cast<Node*>(itemAt(mouseEvent->scenePos(), QTransform()));
            if( secondNode && firstIsNode && (currNode != secondNode) )
            {
                Edge* ed = new Edge(currNode, secondNode);
                addItem(ed);
            }
            currNode = nullptr;
            firstIsNode = false;
        }
        update();
    }

    if(1 == tabWidget)  // draw
    {}
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void graphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(0 == tabWidget) // graph
    {
        update();
    }
    if(1 == tabWidget)  // draw
    {}
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void graphicsScene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent)
{
    if( Qt::ControlModifier == wheelEvent->modifiers() && wheelEvent->orientation() == Qt::Vertical )
    {
        emit zoomChanged( wheelEvent->delta() );
    }
    update();
    QGraphicsScene::wheelEvent(wheelEvent);
}

/////////////// PUBLIC SLOTS /////////////////////////

void graphicsScene::clearAll()
{
    clear();
    update();
}

void graphicsScene::createNode()
{
    Node* n = new Node(QPointF( qrand() % 500, qrand() % 500), "Node");
    addItem(n);
    nodes.push_back(n);
}

void graphicsScene::setTabWidget(int tab)
{
    tabWidget = tab;
}

/////////////////////////////////////////////////////

graphicsScene::~graphicsScene()
{
}
