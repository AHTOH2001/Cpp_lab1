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
    this->resize(1200,800);
    this->setFixedSize(1200,800);
     //qDebug() << "Widget have focus - " << qApp->focusWidget()->objectName();
    //qDebug() << "focus widget: " << this->focusWidget()->objectName();
    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(730,730);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //ui->graphicsView->setFocusPolicy(Qt::ClickFocus);
    //ui->graphicsView->setFocus(Qt::TabFocusReason);
    //qDebug() << "fg" << ui->graphicsView->hasFocus();
    scene->setSceneRect(0,0,700,700);

   // rectangle *item = new rectangle(300,200);
    //ellipse *item = new ellipse();
    /*item->setPos(350,720);
    scene->addItem(item);
    item = new rectangle(100,500);
    //ellipse *item = new ellipse();
    item->setPos(100,100);
    scene->addItem(item);*/
}
int p = 0;
void MainWindow::paintEvent(QPaintEvent *event)
{

    if (p==1)
    {
        int x = ui->rect_x->text().toInt();
        int y = ui->rect_y->text().toInt();
        rectangle *item = new rectangle();
        item->setPos(x,y);
        item->w = ui->rect_w->text().toInt();
        item->h = ui->rect_h->text().toInt();
        item->R = ui->pen_color_R->text().toInt();
        item->G = ui->pen_color_G->text().toInt();
        item->B = ui->pen_color_B->text().toInt();
        item->size = ui->pen_size->text().toInt();
        item->setFlag(QGraphicsItem::ItemIsFocusable, true);
        //item->setFocus();
        //qDebug() << "item " << item->hasFocus();
        //item->setFocus(Qt::ActiveWindowFocusReason);
        //item->setFocusPolicy(Qt::StrongFocus);
        //item->setFocus(Qt::MouseFocusReason);
        //qDebug() << "Focus " << item->hasFocus();
        //scene->setFocus(Qt::MouseFocusReason);
        //qDebug() << "scene focus1 " << scene->hasFocus();
        scene->addItem(item);
        //qDebug() << "scene focus2 " << scene->hasFocus();
        //qDebug() << "Rect focus: " << this->hasFocus();
        //scene->removeItem(item);
        p = 0;
    }
    else
    if (p==2)
    {
        int x = ui->elips_x->text().toInt();
        int y = ui->elips_y->text().toInt();
        ellipse *item = new ellipse();
        item->setPos(x,y);
        item->w = ui->rect_w->text().toInt();
        item->h = ui->rect_h->text().toInt();
        item->R = ui->pen_color_R->text().toInt();
        item->G = ui->pen_color_G->text().toInt();
        item->B = ui->pen_color_B->text().toInt();
        item->size = ui->pen_size->text().toInt();
        scene->addItem(item);
        p = 0;
     //   painter.drawEllipse(x,y,w,h);
    }
    else
    if (p==3)
    {
        QPolygon poly;
        ui->polygon_xy->redo();
        QStringList str = ui->polygon_xy->toPlainText().split(" ");
        while (str[str.length()-1].toInt()==0) str.pop_back();
        if (str.length()>=6 && (str.length())%2==0)
        {
        for (int i = 0;i<str.length();i+=2)
            poly << QPoint(str[i].toInt(),str[i+1].toInt());
       // poly << QPoint (str[0].toInt(),str[1].toInt());
       // painter.drawPolygon(poly);
        poly.clear();
        str.clear();
        }
    }

}

/*void MainWindow::keyPressEvent(QKeyEvent *event)
{

    qDebug() << "Mainkey " << event->key();
    //item->keyPressEvent(event);
}*/

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_rect_2_clicked()
{
    p = 1;
}

void MainWindow::on_pushButton_elips_clicked()
{
    p = 2;
}

void MainWindow::on_pushButton_polygon_clicked()
{
    p = 3;
}


