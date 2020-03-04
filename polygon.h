#ifndef polygon_H
#define polygon_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QCoreApplication>
#include <QApplication>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui>
#include <QTimer>
#include <qglobal.h>
#include <QApplication>
#include <QKeyEvent>
#include <QVector>
#include <QtGlobal>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class polygon : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit polygon();
    ~polygon();
    void init();
    int R,G,B,PenSize;

    QVector<QPair<int,int>> cords;
    QPair<int,int> Center = {0,0};
    double area;
    QLabel *out_area,*out_perimeter,*out_angle,*out_centerX,*out_centerY;
    QPushButton *Tgravity;
    QLineEdit *centergravity_x,*centergravity_y,*rotate_angle,*change_size;


signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void Output();
    double ang = 0,now_ang = 0,size = 1,now_size = 1,perimeter = 0,now_perimeter = 0,now_area = 0;
    int maxX = 0,maxY = 0,minX = 2000000000,minY = 2000000000,w = 0,h = 0;
    QPolygon poly;
public slots:
};

#endif // polygon_H
