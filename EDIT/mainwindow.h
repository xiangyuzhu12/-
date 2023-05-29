#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QTextEdit>
#include <QVector>
#include <QFileDialog>
#include <QColorDialog>
#include "glwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setMode(Mode m);

public slots:
    void on_changeMode(Mode m);

private slots:
    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionClose_triggered();

    void on_actionactionLine_triggered();

    void on_actionLine_2_triggered();

    void on_actionCircle_triggered();

    void on_actionEllipse_triggered();

    void on_actionPolygon_triggered();

    void on_actionCut_triggered();

    void on_actionFill_triggered();

    void on_actionCurve_triggered();

    void on_actionZoomin_triggered();

    void on_actionZoomout_triggered();

    void on_actionPickColor_triggered();

    void on_actionDelete_triggered();

private:
    Ui::MainWindow *ui;
    Mode m;

};

#endif // MAINWINDOW_H
