#include "ui/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , zoomFactor(1)
    , zoomStep(1.1)
    , logIsHidden(true)
{
    mainLayout = new QVBoxLayout;
    cWidget = new QWidget;
    myScene = new graphicsScene;
    view = new QGraphicsView(myScene);
    connect(myScene, SIGNAL(zoomChanged(double)), this, SLOT(updateZoomFactor(double)));

    configureMainWindow();
    createActions();
    createMenus();
    createBars();
    createDockWidget();

    mainLayout->addWidget(view);
    cWidget->setLayout(mainLayout);
    setCentralWidget(cWidget);
}

void MainWindow::configureMainWindow()
{
    setWindowTitle(tr("Drow"));
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    setStyleSheet("QMainWindow::separator { background-color: black; width: 1px; border: solid black; }");
    setMinimumSize(800,600);
}

void MainWindow::createActions()
{
    readGraphFromFileAction = new QAction(/*QIcon(":/Icons/clear.png"),*/ tr("&Read from file"), this);
    connect(readGraphFromFileAction, SIGNAL(triggered(bool)), this, SLOT(readGraph()));

    clearAction = new QAction(QIcon(":/Icons/Icons/clear.png"), tr("&Clear"), this);
    connect(clearAction, SIGNAL(triggered()), myScene, SLOT(clearAll()));

    helpAction = new QAction(QIcon(":/Icons/Icons/help.png"), tr("&Help"), this);
    connect(helpAction, SIGNAL(triggered()), this, SLOT(helpSlot()));

    saveAction = new QAction(QIcon(":/Icons/Icons/save.png"), tr("&Save"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveSlot()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(saveAction);

    graphMenu = menuBar()->addMenu(tr("&Graph"));
    graphMenu->addAction(readGraphFromFileAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAction);
}

void MainWindow::createBars()
{
    toolBar = addToolBar(tr("Tool Bar"));
    toolBar->addAction(clearAction);

    logButton = new QPushButton(tr("Log"));
    logButton->setStyleSheet("QPushButton{background-color: rgba(0 ,0 ,0 ,0%); font-weight: bold;} QPushButton:hover{background-color: lightBlue;}");
    connect(logButton, SIGNAL(clicked(bool)), this, SLOT(showHideLog()));
    statusBar()->setMaximumHeight(27);
    statusBar()->addWidget(logButton);
}

QWidget* MainWindow::createGraphTab()
{
    tab1Widget = new QWidget;
    newNodeButton = new QPushButton(QIcon(":/Icons/Icons/node.png"), tr("New Node"));
    tab1Layout = new QVBoxLayout;
    tab1Layout->addWidget(newNodeButton);
    tab1Layout->addStretch();
    tab1Widget->setLayout(tab1Layout);
    connect(newNodeButton, SIGNAL(clicked(bool)), myScene, SLOT(createNode()));
    return tab1Widget;
}

QWidget* MainWindow::createDrawTab()
{
    tab2Widget = new QWidget;
    return tab2Widget;
}

void MainWindow::createDockWidget()
{
    rightDock = new QDockWidget(tr("Propereties"));
    rightDock->setAllowedAreas( Qt::RightDockWidgetArea);
    rightDock->setFeatures( QDockWidget::NoDockWidgetFeatures );
    rightDock->setMinimumWidth(150);
    rightDockTabWidget = new QTabWidget(this);
    rightDockTabWidget->addTab(createGraphTab(), "Graph");
    rightDockTabWidget->addTab(createDrawTab(), "Drow");
    connect(rightDockTabWidget, SIGNAL(currentChanged(int)), myScene, SLOT(setTabWidget(int)));
    connect(rightDockTabWidget, SIGNAL(currentChanged(int)), myScene, SLOT(clearAll()));
    rightDock->setWidget(rightDockTabWidget);
    addDockWidget(Qt::RightDockWidgetArea, rightDock);

    bottomLogDock = new QDockWidget(tr("Log"));
    bottomLogDock->setAllowedAreas( Qt::BottomDockWidgetArea);
    bottomLogDock->setFeatures( QDockWidget::NoDockWidgetFeatures );
    logWidget = new QWidget(this);
    logLayout = new QVBoxLayout;
    logData = new QTextEdit;
    logLayout->addWidget(logData);
    logWidget->setLayout(logLayout);
    bottomLogDock->setWidget(logWidget);
    bottomLogDock->setHidden(true);
    addDockWidget(Qt::BottomDockWidgetArea, bottomLogDock);
}

//////////////// PRIVATE SLOTS //////////////////

void MainWindow::updateZoomFactor(double zoom)
{
    if( zoom > 0 && zoomFactor < 20 )
    {
        zoomFactor += zoomStep;
        view->scale( zoomStep, zoomStep );
        myScene->update();
    }
    else if ( zoom < 0 && zoomFactor > -12 )
    {
        zoomFactor -= zoomStep;
        view->scale( 1.0 / zoomStep , 1.0 / zoomStep);
        myScene->update();
    }
    myScene->update();
}

void MainWindow::readGraph()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Read from file", QDir::currentPath(), "*.vl");
    if( "" != fileName )
    {
        qDebug() << "Parsing: " << fileName;
    }
}

void MainWindow::showHideLog()
{
    logIsHidden = !logIsHidden;
    bottomLogDock->setHidden(logIsHidden);
}

void MainWindow::helpSlot()const
{
    QMessageBox::information(0, tr("Help"), tr("<H1>da da da ddaaaaaammmm</H1>"), QMessageBox::Ok);
}

void MainWindow::saveSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save file",QDir::currentPath(), "*.png");
    QPixmap pixMap = QPixmap::grabWidget(view);
    pixMap.save(fileName + ".png");
}

MainWindow::~MainWindow()
{

}
