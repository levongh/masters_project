#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QDockWidget>
#include <QTabWidget>
#include <QBoxLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QTextEdit>
#include <QFileDialog>
#include "graphicsscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateZoomFactor(double);
    void readGraph();
    void showHideLog();
    void helpSlot() const;
    void saveSlot();
private:
    void configureMainWindow();
    void createMenus();
    void createActions();
    void createBars();
    QWidget* createGraphTab();
    QWidget* createDrawTab();
    void createDockWidget();
private:
    QGraphicsView* view;
    QVBoxLayout* mainLayout;
    graphicsScene* myScene;
    QWidget* cWidget;
private:
    QDockWidget *rightDock;
    QTabWidget* rightDockTabWidget;
    QWidget* tab1Widget;
    QPushButton* newNodeButton;
    QVBoxLayout* tab1Layout;
    QWidget* tab2Widget;

    QDockWidget *bottomLogDock;
    QWidget* logWidget;
    QVBoxLayout* logLayout;
    QTextEdit* logData;
private:
    QMenu* fileMenu;
    QMenu* helpMenu;
    QMenu* graphMenu;
    QToolBar* toolBar;
    QAction* readGraphFromFileAction;
    QAction* clearAction;
    QAction* helpAction;
    QAction* saveAction;
private:
    QPushButton* logButton;
    bool logIsHidden;
private:
    double zoomFactor;
    double zoomStep;
};

#endif // MAINWINDOW_H
