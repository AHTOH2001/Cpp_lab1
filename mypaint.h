#ifndef mypaint_H
#define mypaint_H
#include <polygon.h>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <rectangle.h>
#include <QMouseEvent>
class mypaint : public QGraphicsView
{
    Q_OBJECT
public:
     explicit mypaint(QWidget *parent = 0);
    ~mypaint();
    void draw();
    QLineEdit *R,*G,*B,*PenSize;
    QLabel *out_area,*out_perimeter,*out_angle,*out_centerX,*out_centerY;
    QPushButton *Tgravity;
    QLineEdit *centergravity_x,*centergravity_y,*rotate_angle,*change_size;
    QGraphicsScene *main_scene;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
   // void mouseReleaseEvent(QMouseEvent *event);

signals:

private:
    QGraphicsScene      *scene;
    QVector<QPair<int,int>> cords;


public slots:
};

#endif // mypaint_H
