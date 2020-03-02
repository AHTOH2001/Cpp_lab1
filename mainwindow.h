#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *event);
private slots:

    void on_pushButton_rect_2_clicked();
    void on_rect_x_editingFinished();
    void on_rect_y_editingFinished();
    void on_rect_w_editingFinished();
    void on_rect_h_editingFinished();
    void on_elips_x_editingFinished();
    void on_elips_y_editingFinished();
    void on_elips_w_editingFinished();
    void on_elips_h_editingFinished();
    void on_pushButton_elips_clicked();
    void on_pen_size_editingFinished();
    void on_pen_color_R_editingFinished();
    void on_pen_color_G_editingFinished();
    void on_pen_color_B_editingFinished();
    void on_pushButton_polygon_clicked();
    void on_polygon_xy_textChanged();
};
#endif // MAINWINDOW_H
