#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QBrush>
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,800);
    this->setFixedSize(1200,800);
}
int p = 0;
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int R = ui->pen_color_R->text().toInt();
    int G = ui->pen_color_G->text().toInt();
    int B = ui->pen_color_B->text().toInt();
    int size = ui->pen_size->text().toInt();
    painter.setPen(QPen(QColor(R,G,B),size));
    if (p==1)
    {
        int x = ui->rect_x->text().toInt();
        int y = ui->rect_y->text().toInt();
        int w = ui->rect_w->text().toInt();
        int h = ui->rect_h->text().toInt();
        painter.drawRect(x,y,w,h);
    }
    if (p==2)
    {
        int x = ui->elips_x->text().toInt();
        int y = ui->elips_y->text().toInt();
        int w = ui->elips_w->text().toInt();
        int h = ui->elips_h->text().toInt();
        painter.drawEllipse(x,y,w,h);
    }
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
        painter.drawPolygon(poly);
        poly.clear();
        str.clear();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_rect_2_clicked()
{
    p = 1;
    repaint();
}

void MainWindow::on_rect_x_editingFinished()
{
    repaint();
}

void MainWindow::on_rect_y_editingFinished()
{
    repaint();
}

void MainWindow::on_rect_w_editingFinished()
{
    repaint();
}

void MainWindow::on_rect_h_editingFinished()
{
    repaint();
}

void MainWindow::on_elips_x_editingFinished()
{
    repaint();
}

void MainWindow::on_elips_y_editingFinished()
{
    repaint();
}

void MainWindow::on_elips_w_editingFinished()
{
    repaint();
}

void MainWindow::on_elips_h_editingFinished()
{
    repaint();
}

void MainWindow::on_pushButton_elips_clicked()
{
    p = 2;
    repaint();
}

void MainWindow::on_pen_size_editingFinished()
{
    repaint();
}

void MainWindow::on_pen_color_R_editingFinished()
{
    repaint();
}

void MainWindow::on_pen_color_G_editingFinished()
{
    repaint();
}

void MainWindow::on_pen_color_B_editingFinished()
{
    repaint();
}

void MainWindow::on_pushButton_polygon_clicked()
{
    p = 3;
    repaint();
}

void MainWindow::on_polygon_xy_textChanged()
{
    repaint();
}
