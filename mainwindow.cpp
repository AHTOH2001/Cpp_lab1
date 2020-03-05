#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800,800);
    this->setFixedSize(800,800);

    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(800,800);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,790,790);
    rocket *item = new rocket();
    item->setPos(350,720);
    scene->addItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

